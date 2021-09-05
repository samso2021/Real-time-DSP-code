/*
 * realtime_spatial.c
 *
 *  Created on: Nov 3, 2012
 *      Author: BLEE
 *
 *      Description: This program contains functions for spatial effect experiment
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
#include "realtime_spatial.h"

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

void spatial(void);
void spatial_init(void);
void process(Int16 *, Int16 *, Int16 *, Int16 *);

Int16     delay,firstTime;
float     depth = 1.0;
spatialRT param;
spatialRT *t;

void spatialInit(spatialRT *t);

void spatial_init(void)
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
    spatialInit(t);
    firstTime = 1;
}

void spatial(void)
{
	Int32 k=0;
	Int16 i,j=0;

	printf("spatial status:\n");
	printf("off\n");
    while (1)			// Forever loop for the demo if status is set
    {
    	if (k++ == (0x2900000))
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
    Uint16 i,j;
    Int16  out16[2];

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

            CalculateIID(t);
            CalculateITD(t);
            t->n++;
            if(t->n >= (Int32)SEGMENTSAMPLES*SAMPLEPOINTS)
            {
                t->n = 0;
            }
            /* Apply the spatial sound process function to the sample */
            procSpatialSound(out16, t);

    		*(outDataPtrL+i) = out16[0];
    		*(outDataPtrR+i) = out16[1];
    	}
	}
}

extern void dataMove(Int16 *);

/// L -90,-60,-30,0,+30,+60,+90
// Distant 20 meter
#define SCALE_FACTOR 0.8
static float IID[SAMPLEPOINTS][SIDES] =
{
	{0.80/SCALE_FACTOR,0.20/SCALE_FACTOR},	//-75	Left, Right
	{0.74/SCALE_FACTOR,0.26/SCALE_FACTOR},	//-60	Left, Right
	{0.68/SCALE_FACTOR,0.32/SCALE_FACTOR},	//-45	Left, Right
	{0.62/SCALE_FACTOR,0.38/SCALE_FACTOR},	//-30	Left, Right
	{0.56/SCALE_FACTOR,0.44/SCALE_FACTOR},	//-15	Left, Right
	{0.50/SCALE_FACTOR,0.50/SCALE_FACTOR},	// 0	center
	{0.44/SCALE_FACTOR,0.56/SCALE_FACTOR},	//+15	Left, Right
	{0.38/SCALE_FACTOR,0.62/SCALE_FACTOR},	//+30	Left, Right
	{0.32/SCALE_FACTOR,0.68/SCALE_FACTOR},	//+45	Left, Right
	{0.26/SCALE_FACTOR,0.74/SCALE_FACTOR},	//+60	Left, Right
	{0.20/SCALE_FACTOR,0.80/SCALE_FACTOR},	//+75	Left, Right
};

// Relative to the center of the head in ms
#define MULT_FACTOR  (ONESECOND/1000.0)
static float ITD[SAMPLEPOINTS][SIDES] =
{
	{0.0*MULT_FACTOR,1.0*MULT_FACTOR},	//Left, Right
	{0.1*MULT_FACTOR,0.9*MULT_FACTOR},	//Left, Right
	{0.2*MULT_FACTOR,0.8*MULT_FACTOR},	//Left, Right
	{0.3*MULT_FACTOR,0.7*MULT_FACTOR},	//Left, Right
	{0.4*MULT_FACTOR,0.6*MULT_FACTOR},	//Left, Right
	{0.5*MULT_FACTOR,0.5*MULT_FACTOR},  //Center
	{0.6*MULT_FACTOR,0.4*MULT_FACTOR},	//Left, Right
	{0.7*MULT_FACTOR,0.3*MULT_FACTOR},	//Left, Right
	{0.8*MULT_FACTOR,0.2*MULT_FACTOR},	//Left, Right
	{0.9*MULT_FACTOR,0.1*MULT_FACTOR},	//Left, Right
	{1.0*MULT_FACTOR,0.0*MULT_FACTOR},	//Left, Right
};

// This is the initialization function, to generate the gain table
#define W (3.1415926*15.0/180.0)
void spatialInit(spatialRT *t)
{
	float temp;
	Int16 i;
	t->Gain[SAMPLEPOINTS/2] = 1.0;
	for(i=1; i<=SAMPLEPOINTS/2; i++)
	{
		temp = cos(W*i);
		temp *= temp;
		t->Gain[(SAMPLEPOINTS/2) + i] = temp;
		t->Gain[(SAMPLEPOINTS/2) - i] = temp;
		t->n = 0;
	}
 }

// Round to Int16
Int16 rounding16(float xd)
{
	Int16 y16;

	xd = xd +0.5;

	if(xd > 32767.0) y16 = 32767;
	else if (xd < -32768.0) y16 = -32768;
	else y16 = (Int16) xd;

	return y16;
 }

// Spatial sound processing function
void procSpatialSound(Int16 *out16, spatialRT *t)
{
	float yL,yR;

	yL = interpolate(t->mITD[LEFT]);
	yR = interpolate(t->mITD[RIGHT]);

	yL *= t->mIID[LEFT];
	yR *= t->mIID[RIGHT];

	out16[0] = rounding16(yL);
	out16[1] = rounding16(yR);

	/* Two points linear interpolation */
	/* Rotate buffer ready for next new sample in */
	//	for(i = MAX_BUF_SIZE-1; i> 0; i--)
	//		d_buffer[i ] = d_buffer[i-1];
	dataMove(d_buffer);		// Implement above data shift in assembly
}

void CalculateIID(spatialRT *t)
{
	Int32 segment = (Int32)(t->n/SEGMENTSAMPLES);
	t->mIID[LEFT] = t->Gain[segment] * IID[segment][LEFT];
	t->mIID[RIGHT] = t->Gain[segment] * IID[segment][RIGHT];
}

void CalculateITD(spatialRT *t)
{
	Int32 segment = (Int32)(t->n/SEGMENTSAMPLES);
	t->mITD[LEFT] = ITD[segment][LEFT];
	t->mITD[RIGHT] = ITD[segment][RIGHT];
}

// Linear interpolation
float interpolate(float var_delay)
{
	Uint32 iy0, iy1;
	float  y0, y1;
	float  fracY,yout;

	iy0 = (Int32)(var_delay);			// Latest // MAXIMUM here is 8
	iy1 = (Int32)(var_delay +1.0);		// History

	/* two points linear interpolation */
	if (iy0 > XMIT_BUFF_SIZE)			// Why we must limit this? Can var_delay be bounded?
		iy0 = XMIT_BUFF_SIZE-1;			// This limiter causes clicking sound.
	if (iy1 > XMIT_BUFF_SIZE)
		iy1 = XMIT_BUFF_SIZE-1;

	y0 = (float)d_buffer[iy0];
	y1 = (float)d_buffer[iy1];
	fracY = (float)(1.0 - (var_delay - (float)iy0));
	yout = fracY*y0 + (1.0-fracY)* y1;

	return yout;
}
