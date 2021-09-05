/*
 * rtSRC.c
 *
 *  Created on: May 20, 2012
 *      Author: BLEE
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */
#include <stdio.h>
#include "tistdtypes.h"
#include "dma.h"
#include "dmaBuff.h"
#include "decimation.h"
#include "interpolation.h"

void rtSRC(void);
void rtSRC_init(void);

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

/* Define DSP system memory map */
#pragma DATA_SECTION(deciFilt48to24, ".const:fir");
#pragma DATA_SECTION(deciFilt24to8, ".const:fir");
#pragma DATA_SECTION(x1, ".bss:fir");
#pragma DATA_SECTION(x2, ".bss:fir");
#pragma DATA_SECTION(w1, ".bss:fir");
#pragma DATA_SECTION(w2, ".bss:fir");
#pragma DATA_ALIGN(x1, 2);       // Use dual MAC, align to 32 bits
#pragma DATA_ALIGN(x2, 2);       // Use dual MAC, align to 32 bits
#pragma DATA_ALIGN(w1, 2);       // Use dual MAC, align to 32 bits
#pragma DATA_ALIGN(w2, 2);       // Use dual MAC, align to 32 bits
#pragma DATA_SECTION(intpFilt8to16, ".bss:fir");
#pragma DATA_SECTION(intpFilt16to48, ".bss:fir");
#pragma DATA_SECTION(z1, ".bss:fir");
#pragma DATA_SECTION(z2, ".bss:fir");

// Decimation coefficients and variables
#include "coef48to24.h"
#include "coef24to8.h"

Int16 w1[TAPS48to24+1];          // Use dual MAC, add one space
Int16 w2[TAPS24to8+1];           // Use dual MAC, add one space
Int16 x1[DEC_NUM_DATA_IN],       // Input data
	  x2[DEC_NUM_DATA2];         // Intermediate data
Int16 index1,index2;             // Delay line w2 index

// Interpolation coefficients and variables
#include "coef8to16.h"
#include "coef16to48.h"

Int16 z1[(TAPS8to16/2)+1];
Int16 z2[(TAPS16to48/3)+1];

Int16 x3[INT_NUM_DATA_IN],       // Input data
      x4[INT_NUM_DATA2];
Int16 indx1,indx2=0,             // Delay line z2 index
      y2[INT_NUM_DATA_OUT];      // Output data



void rtSRC_init(void)
{
	Int16 i;
	// Initialize for filtering process
	for (i=0; i<=TAPS48to24; i++)
	{
        w1[i] = 0;
	}
	for (i=0; i<=TAPS24to8; i++)
	{
		w2[i] = 0;
	}
	for (i=0; i<TAPS8to16/2; i++)
	{
        z1[i] = 0;
	}
	for (i=0; i<TAPS16to48/3; i++)
	{
		z2[i] = 0;
	}
	indx1 = 0;
	indx2 = 0;
	index1 = 0;
	index2 = 0;
	for (i=0; i<XMIT_BUFF_SIZE; i++)
	{
		XmitL1[i]=XmitL2[i]=XmitR1[i]=XmitR2[i]=0;
		RcvL1[i]=RcvL2[i]=RcvR1[i]=RcvR2[i]=0;
	}
}

void rtSRC(void)
{
	Int16 i;

	printf("Left channel plays sample rate converted audio\n");
	printf("Right channel plays pass through audio\n");
    while (1)			// Forever loop for the demo
    {
        if(leftChannel == 1)
        {
        	leftChannel = 0;
            if (CurrentRxL_DMAChannel == 2)
            {
            	for(i=0; i<XMIT_BUFF_SIZE; i++)
            	{
            		x1[i] = RcvL1[i];
            	}
            }
            else
            {
            	for(i=0; i<XMIT_BUFF_SIZE; i++)
            	{
            		x1[i] = RcvL2[i];
            	}
             }

            // Sample rate conversion on left channel
	        decimator(x1, DEC_NUM_DATA2, deciFilt48to24, TAPS48to24, x2, w1, &index1, 2);
	        decimator(x2, DEC_NUM_DATA_OUT, deciFilt24to8, TAPS24to8, x3, w2, &index2, 3);

	        interpolate(x3, INT_NUM_DATA_IN, intpFilt8to16, TAPS8to16/2, x4, z1, &indx1, 2);
	        interpolate(x4, INT_NUM_DATA2, intpFilt16to48, TAPS16to48/3, y2, z2, &indx2, 3);

            if (CurrentRxL_DMAChannel == 2)
            {
            	for(i=0; i<XMIT_BUFF_SIZE; i++)
            	{
            		XmitL1[i] = y2[i]<<1;
            	}
            }
            else
            {
            	for(i=0; i<XMIT_BUFF_SIZE; i++)
            	{
            		XmitL2[i] = y2[i]<<1;
            	}
             }
        }

        // Right channel will only pass through the input to output
        if(rightChannel == 1)
        {
        	rightChannel= 0;
            if (CurrentRxR_DMAChannel == 2)
            {
            	for(i=0; i<XMIT_BUFF_SIZE; i++)
            	{
            		XmitR1[i] = RcvR1[i]>>2;
            	}
            }
            else
            {
             	for(i=0; i<XMIT_BUFF_SIZE; i++)
             	{
             		XmitR2[i] = RcvR2[i]>>2;
             	}
            }
        }
    }
}

