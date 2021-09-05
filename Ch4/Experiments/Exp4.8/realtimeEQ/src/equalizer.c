/*
 * equalizer.c
 *
 *  Created on: May 28, 2012
 *      Author: BLEE
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tistdtypes.h"
#include "dma.h"
#include "dmaBuff.h"
#include "asmIIR.h"

void equalizer_init(void);
void equalizer(void);
void coefGen(double (*gainTbl)[2], Int16 gain, Int16 *c, float freq);


/* Define DSP system memory map */
#pragma DATA_ALIGN(XmitL1,2);	// Alignment is needed for dual accumulator store
#pragma DATA_ALIGN(XmitL2,2);
#pragma DATA_ALIGN(XmitR1,2);
#pragma DATA_ALIGN(XmitR2,2);

Int16 XmitL1[XMIT_BUFF_SIZE];
Int16 XmitR1[XMIT_BUFF_SIZE];
Int16 XmitL2[XMIT_BUFF_SIZE];
Int16 XmitR2[XMIT_BUFF_SIZE];

Int16 RcvL1[XMIT_BUFF_SIZE];
Int16 RcvR1[XMIT_BUFF_SIZE];
Int16 RcvL2[XMIT_BUFF_SIZE];
Int16 RcvR2[XMIT_BUFF_SIZE];

// IIR filter related variables
#include "asmIIR.h"

#define SECTIONS    2  // Number of 2nd order sections
Int16   C1[SECTIONS*5]; // C[]=A[i][1], A[i][2], B[i][2], B[i][0], B[i][1]...
Int16   C2[SECTIONS*5]; // C[]=A[i][1], A[i][2], B[i][2], B[i][0], B[i][1]...
Int16   wl1[SECTIONS*2]; // Filter delay line
                       // w[]=w[i][n-1],w[i+1][n-1],...,w[i][n-2],w[i+1][n-2],...
Int16   wl2[SECTIONS*2]; // Filter delay line
                       // w[]=w[i][n-1],w[i+1][n-1],...,w[i][n-2],w[i+1][n-2],...
Int16   wr1[SECTIONS*2]; // Filter delay line
                       // w[]=w[i][n-1],w[i+1][n-1],...,w[i][n-2],w[i+1][n-2],...
Int16   wr2[SECTIONS*2]; // Filter delay line
                       // w[]=w[i][n-1],w[i+1][n-1],...,w[i][n-2],w[i+1][n-2],...

double gain200[13][2]={ // parameter at 200 Hz
	// rz     rp
	{0.8900, 0.8000},  // -6 dB
	{0.8775, 0.8000},  // -5 dB
	{0.8640, 0.8000},  // -4 dB
	{0.8495, 0.8000},  // -3 dB
	{0.8340, 0.8000},  // -2 dB
	{0.8174, 0.8000},  // -1 dB
	{0.8000, 0.8000},  // 0 dB
	{0.8000, 0.8174},  // 1 dB
	{0.8000, 0.8340},  // 2 dB
	{0.8000, 0.8495},  // 3 dB
	{0.8000, 0.8640},  // 4 dB
	{0.8000, 0.8775},  // 5 dB
	{0.8000, 0.8900}}; // 6 dB

double gain1000[13][2]={ // parameter at 1000 Hz
	// rz     rp
	{0.9048, 0.8000},  // -6 dB
	{0.8925, 0.8000},  // -5 dB
	{0.8784, 0.8000},  // -4 dB
	{0.8627, 0.8000},  // -3 dB
	{0.8445, 0.8000},  // -2 dB
	{0.8238, 0.8000},  // -1 dB
	{0.8000, 0.8000},  // 0 dB
	{0.8000, 0.8238},  // 1 dB
	{0.8000, 0.8445},  // 2 dB
	{0.8000, 0.8627},  // 3 dB
	{0.8000, 0.8784},  // 4 dB
	{0.8000, 0.8925},  // 5 dB
	{0.8000, 0.9048}}; // 6 dB

enum {
	NEG_6dB=0,NEG_5dB,NEG_4dB,NEG_3dB,NEG_2dB,NEG_1dB,
	ZERO_dB,POS_1dB,POS_2dB,POS_3dB,POS_4dB,POS_5dB,POS_6dB
};

void equalizer_init(void)
{
	Int16 i;

	for (i=0; i<XMIT_BUFF_SIZE; i++)
	{
		XmitL1[i]=XmitR1[i]=XmitL2[i]=XmitR2[i]=0;
	}
    // Initialize IIR filter delay line
    for (i=0; i<SECTIONS*2;i++)
	{
        wl1[i] = 0;
        wl2[i] = 0;
        wr1[i] = 0;
        wr2[i] = 0;
	}

	// Generate filter coefficients Ch for high band with gain1000
	coefGen(gain1000, POS_6dB, &C1[0], 1000);

	// Generate filter coefficients Ch for low band with gain200
	coefGen(gain200, NEG_6dB, &C1[5], 200);

	// Generate filter coefficients Cl for high band with gain1000
	coefGen(gain1000, NEG_6dB, &C2[0], 1000);

	// Generate filter coefficients Cl for low band with gain200
	coefGen(gain200, POS_6dB, &C2[5], 200);
}


void equalizer(void)
{
    Int32 n=0;
    Int16 j=0,k,i;

    printf("EQ status:\n");
    printf("Pass through\n");
    k = 0;
    while (1)			// Forever loop for the demo if status is set
    {
    	if (n++ == (0x4000000))
    	{
    		n = 0;
    		if (k++ == 3)
    		{
    			k = 0;
    		}

    		if (k==2)
    		{
    			printf("Bass\n");
    			j = 2;
    		}
    		if (k==1)
    		{
    			printf("Treble\n");
    			j = 1;
    		}
    		if (k==0)
    		{
    			printf("Pass through\n");
    			j = 0;
    		}
    	}

        if(leftChannel == 1)
        {
            leftChannel = 0;
            if (CurrentRxL_DMAChannel == 2)
            {
            	if (j==2) // Filter the input audio data and send BASS to output
            	{
            		asmIIR(RcvL1,XMIT_BUFF_SIZE,XmitL1,C2,SECTIONS,wl1);
            	}
            	if (j==1) // Filter the input audio data and send TREBLE to output
            	{
            		asmIIR(RcvL1,XMIT_BUFF_SIZE,XmitL1,C1,SECTIONS,wl2);
            	}
            	else      // Pass through audio
            	{
            		for(i=0; i<XMIT_BUFF_SIZE; i++)
            		{
            			XmitL1[i] = RcvL1[i]>>1;
            		}
            	}
            }
            else
            {
            	if (j==2) // Filter the input audio data and send BASS to output
            	{
            		asmIIR(RcvL2,XMIT_BUFF_SIZE,XmitL2,C2,SECTIONS,wl1);
            	}
            	if (j==1) // Filter the input audio data and send TREBLE to output
            	{
            		asmIIR(RcvL2,XMIT_BUFF_SIZE,XmitL2,C1,SECTIONS,wl2);
            	}
            	else      // Pass through audio
            	{
            		for(i=0; i<XMIT_BUFF_SIZE; i++)
            		{
            			XmitL2[i] = RcvL2[i]>>1;
            		}
            	}
            }
        }
        if(rightChannel == 1)
        {
            rightChannel= 0;
            if (CurrentRxR_DMAChannel == 2)
            {
            	if (j==2) // Filter the input audio data and send BASS to output
            	{
            		asmIIR(RcvR1,XMIT_BUFF_SIZE,XmitR1,C2,SECTIONS,wr1);
            	}
            	if (j==1) // Filter the input audio data and send TREBLE to output
            	{
            		asmIIR(RcvR1,XMIT_BUFF_SIZE,XmitR1,C1,SECTIONS,wr2);
            	}
            	else      // Pass through audio
            	{
            		for(i=0; i<XMIT_BUFF_SIZE; i++)
            		{
            			XmitR1[i] = RcvR1[i]>>1;
            		}
            	}
            }
            else
            {
            	if (j==2) // Filter the input audio data and send BASS to output
            	{
            		asmIIR(RcvR2,XMIT_BUFF_SIZE,XmitR2,C2,SECTIONS,wr1);
            	}
            	if (j==1) // Filter the input audio data and send TREBLE to output
            	{
            		asmIIR(RcvR2,XMIT_BUFF_SIZE,XmitR2,C1,SECTIONS,wr2);
            	}
            	else      // Pass through audio
            	{
            		for(i=0; i<XMIT_BUFF_SIZE; i++)
            		{
            			XmitR2[i] = RcvR2[i]>>1;
            		}
            	}
            }
        }
    }
}

// Generate coefficient using the following equations, for 8000Hz sampling rate
//  b = [1, -2*rz*cos(w), rz*rz];
//  a = [1, -2*rp*cos(w), rp*rp];

void coefGen(double (*gainTbl)[2], Int16 gain, Int16 *c, float freq)
{
	double rz,rp,temp,omega, filtgain;

	filtgain = 0.725;

	rz = gainTbl[gain][0];              // Get rz from the lookup table
	rp = gainTbl[gain][1];              // Get rp from the lookup table

	omega = 2.0*3.1415926*freq/8000.0;  // This example uses 8kHz sampling rate

	c[3] = (Int16)(0x4000*filtgain);             // b[0] Q14 coefficient
	temp = -2.0*rz*cos(omega);
	c[4] = (Int16)(temp*16384.0+0.5)*filtgain;   // b[1]
	c[2] = (Int16)(rz*rz*16384.0+0.5)*filtgain;  // b[2]

	temp = -2.0*rp*cos(omega);
	c[0] = (Int16)(temp*16384.0+0.5);   // a[1]
	c[1] = (Int16)(rp*rp*16384.0+0.5);  // a[2]
}
