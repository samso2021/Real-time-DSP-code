/*
 * realtime_tremolo.c
 *
 *  Created on: Oct 31, 2012
 *      Author: BLEE
 *
 *      Description: This program contains functions for tremolo effect experiment
 *
 *      For the book "Real Time Digital Signal Processing:
 *                    Fundamentals, Implementation and Application, 3rd Ed"
 *                    By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                    Publisher: John Wiley and Sons, Ltd
 */

#include <stdio.h>
#include <math.h>
#include "tistdtypes.h"
#include "dma.h"
#include "dmaBuff.h"
#include "realtime_tremolo.h"

/* Define DSP system memory map */
#pragma DATA_SECTION(XmitL1, "XmitL1");
#pragma DATA_SECTION(XmitL2, "XmitL2");
#pragma DATA_SECTION(XmitR1, "XmitR1");
#pragma DATA_SECTION(XmitR2, "XmitR2");
#pragma DATA_ALIGN(XmitL1,2);
#pragma DATA_ALIGN(XmitL2,2);
#pragma DATA_ALIGN(XmitR1,2);
#pragma DATA_ALIGN(XmitR2,2);

Int16 XmitL1[XMIT_BUFF_SIZE];
Int16 XmitR1[XMIT_BUFF_SIZE];
Int16 XmitL2[XMIT_BUFF_SIZE];
Int16 XmitR2[XMIT_BUFF_SIZE];

#pragma DATA_SECTION(RcvL1, "RcvL1");
#pragma DATA_SECTION(RcvR1, "RcvR1");
#pragma DATA_SECTION(RcvL2, "RcvL2");
#pragma DATA_SECTION(RcvR2, "RcvR2");
#pragma DATA_ALIGN(RcvL1,2);
#pragma DATA_ALIGN(RcvR1,2);
#pragma DATA_ALIGN(RcvL2,2);
#pragma DATA_ALIGN(RcvR2,2);

Int16 RcvL1[XMIT_BUFF_SIZE];
Int16 RcvR1[XMIT_BUFF_SIZE];
Int16 RcvL2[XMIT_BUFF_SIZE];
Int16 RcvR2[XMIT_BUFF_SIZE];

// Flanger related variables
#pragma DATA_SECTION(d_buffer, "scratch_buf");
#pragma DATA_ALIGN(d_buffer, XMIT_BUFF_SIZE);
Int16  d_buffer[XMIT_BUFF_SIZE];


tremoloRt *t;
tremoloRt param;

void tremolo(void);
void tremolo_init(void);
void process(Int16 *, Int16 *, Int16 *, Int16 *);
Int16 tremoloProcess(Int16 xinp, tremoloRt *t);
void tremoloSweep(tremoloRt *t);

void tremoloInit(float depth, tremoloRt *t)
{
    t->dep     = depth;
    t->mod     = 0.0;
    t->offset  = 1 - t->dep;
    t->n       = 0;
    printf( "tremoloInit() at depth [%f]\n",t->dep);
}

void tremolo_init(void)
{
    Int16 i;
    float depth;

    for (i=0; i<XMIT_BUFF_SIZE; i++)
    {
        XmitL1[i]=0;
        XmitL2[i]=0;
        XmitR1[i]=0;
        XmitR2[i]=0;
    }

    /* Initialization */
    t = &param;
    depth = TDEPTH;
    tremoloInit(depth, t);
}

void tremolo(void)
{
    Int32 k=0;
    Int16 i,j=0;

    printf("flanger status:\n");
    printf("off\n");
    while (1)			// Forever loop for the demo if status is set
    {
    	if (k++ == (0x4000000))
    	{
    		k = 0;
    		j++;
    		if (j &= 1)
    			printf("on\n");
    		else
    			printf("off\n");
    	}

        if((leftChannel == 1)&&(rightChannel == 1))
        {
        	leftChannel = 0;
        	rightChannel= 0;
            if((CurrentRxL_DMAChannel == 2)&&(CurrentRxR_DMAChannel == 2))
            {
            	if (j) // Process the input audio data and send to output
            	{
            		process(RcvL1, XmitL1, RcvR1, XmitR1);
            	}
            	else  // Without filter, pass through the audio
            	{
            		for(i=0; i<XMIT_BUFF_SIZE; i++)
            		{
            			XmitL1[i] = RcvL1[i];
            			XmitR1[i] = RcvR1[i];
            		}
            	}
            }
            else
            {
            	if (j) // Process the input audio data and send to output
            	{
            		process(RcvL2, XmitL2, RcvR2, XmitR2);
            	}
            	else  // Without filter, pass through the audio
            	{
            		for(i=0; i<XMIT_BUFF_SIZE; i++)
            		{
            			XmitL2[i] = RcvL2[i];
            			XmitR2[i] = RcvR2[i];
            		}
            	}
             }
        }
    }
}

void process(Int16 *inDataPtrL, Int16 *outDataPtrL, Int16 *inDataPtrR, Int16 *outDataPtrR)
{
    Uint16 i;
    Int16  sample;

    for(i=0; i<XMIT_BUFF_SIZE; i++)
    {
        sample = (*(inDataPtrL+i)>>1)+(*(inDataPtrR+i)>>1);
        /* Apply the Tremolo_process function to the sample */
        *(outDataPtrL+i) = tremoloProcess(sample, t);
        *(outDataPtrR+i) = *(outDataPtrL+i);
        /* Makes LFO vary */
        tremoloSweep(t);
    }
}

// round to short
Int16 rounding16(float xd)
{
	Int16 y16;

	xd += 0.5;

	if(xd > 32767.0) y16 = 32767;
	else if (xd < -32768.0) y16 = -32768;
	else y16 = (Int16) xd;

	return y16;
}

/* This is the flanging process task  that uses the delay task inside */
Int16 tremoloProcess(Int16 xinp, tremoloRt *t)
{
	float xin;
	float yout;
	float m;

	xin = 0.7*xinp;
	m = (float)t->mod * t->dep;
	yout = (m + t->offset)*xin;

	return rounding16 (yout);
}

#define W (2.0*PI*FR/FS)
void tremoloSweep(tremoloRt *t)
{
	t->n++;
	t->mod = sin(W*t->n);
}
