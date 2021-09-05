/*
 * realtime_flanger.c
 *
 *  Created on: Oct 28, 2012
 *      Author: BLEE
 *
 *      Description: This program contains functions for flanger effect experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#include <stdio.h>
#include <math.h>
#include "tistdtypes.h"
#include "dma.h"
#include "dmaBuff.h"
#include "realtime_flanger.h"

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

void flanger(void);
void flanger_init(void);
void process(Int16 *, Int16 *, Int16 *, Int16 *);

Int16     delay,firstTime;
float     depth = 1.0;
flangerRT param;
flangerRT *t;

void flagerInit(float depth, flangerRT *t);

void flanger_init(void)
{
    Int16 i;
    for (i=0; i<XMIT_BUFF_SIZE; i++)
    {
        XmitL1[i]=0;
        XmitL2[i]=0;
        XmitR1[i]=0;
        XmitR2[i]=0;
    }

    t = &param;
	flagerInit(depth, t);
    firstTime = 1;
}

void flagerInit(float depth, flangerRT *t)
{
    t->delay = 100; 			// Average delay
    t->A_maxSwing = 0.5;		// Max swing
    t->G_depth = depth;			// Depth
    t->n = 0;
}

void flanger(void)
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
            	if (j) // process the input audio data and send to output
            	{
            		process(RcvL1, XmitL1, RcvR1, XmitR1);
            	}
            	else  // without filter, pass through the audio
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
            	if (j) // process the input audio data and send to output
            	{
            		process(RcvL2, XmitL2, RcvR2, XmitR2);
            	}
            	else  // without filter, pass through the audio
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
    Uint16 i,j;

    if(firstTime)
    {
    	firstTime = 0;
        for(j=0, i=XMIT_BUFF_SIZE-1; i> 0; i--)
        {
            d_buffer[i] = (inDataPtrL[j++]>>1)+(inDataPtrR[j++]>>1);
        }
    }
    else
    {
    	for(i=0; i<XMIT_BUFF_SIZE; i++)
    	{
    		d_buffer[0] = (*(inDataPtrL+i)>>1)+(*(inDataPtrR+i)>>1);

    		*(outDataPtrL+i) = Flanger_process(d_buffer[0], t);
    		*(outDataPtrR+i) = *(outDataPtrL+i);

    		Flanger_sweep(t);
    	}
	}
}

extern void dataMove(Int16 *);

/* This is the flanging process task  that uses the delay task inside */
Int16 Flanger_process(Int16 xinp, flangerRT *t)
{
	float y0, y1;
	float fracY,yout;
	Int16 iy0, iy1;

	iy0 = (Int16)(t->var_delay);		// Latest
	iy1 = (Int16)(t->var_delay +1.0);	// History

	/* two points linear interpolation */
	y0 = (float)d_buffer[iy0];
	y1 = (float)d_buffer[iy1];
	fracY = (float)(1.0 - (t->var_delay - (float)iy0));

	yout = fracY*y0 + (1.0-fracY)*y1;

	/* apply Sweep depth and normalize*/
	yout = xinp + t->G_depth * yout ;
	yout = yout / (1.0+t->G_depth);

	/* rotate buffer ready for next new sample in */
	//	for(i=XMIT_BUFF_SIZE-1; i> 0; i--)
	//		d_buffer[i] = d_buffer[i-1];
	dataMove(d_buffer);		// Implement above data shift in assembly

	return(Int16)yout;
}

/*  This sweep function creates a low frequency oscillator with sine  */
#define W (2.0*3.1415926*LFO_F/8000.0)
void Flanger_sweep(flangerRT *t)
{
	t->var_delay = t->delay * (1.0 + t->A_maxSwing * sin(W*t->n));
}
