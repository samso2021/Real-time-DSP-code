/*
 * realtime_hwfft.c
 *
 *  Created on: June 13, 2012
 *      Author: BLEE
 *
 *      Description: This is the test program for FFT-iFFT experiment
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

// FFT related variables
#include "icomplex.h"    		/* Integer complex.h header file */

#define	FFT_PTS 512				/* This is for FFT size */

#pragma DATA_SECTION(x, "data_br_buf");
#pragma DATA_ALIGN(x, 2*FFT_PTS);
complex x[FFT_PTS];

#pragma DATA_SECTION(temp, "scratch_buf");
#pragma DATA_ALIGN(temp, 2*FFT_PTS);
complex temp[FFT_PTS];

void hwFFT(void);
void hwFFT_init(void);
void hwFFT_iFFT(Int16 *, Int16 *, complex *, complex *);
extern void bit_rev(complex *, Uint16);
extern Int16 hwafft_512pts(Int32 *, Int32 *, Uint16, Uint16);
extern void hwafft_br(Int32 *, Int32 *, Uint16);

#define FFT_FLAG        0        /* HWA to perform FFT */
#define IFFT_FLAG       1        /* HWA to perform IFFT */
#define SCALE_FLAG      0        /* HWA to scale butterfly output */
#define NOSCALE_FLAG    1        /* HWA not to scale butterfly output */

void hwFFT_init(void)
{
	Int16 i;
	for (i=0; i<XMIT_BUFF_SIZE; i++)
	{
		XmitL1[i]=0;
		XmitL2[i]=0;
		XmitR1[i]=0;
		XmitR2[i]=0;
	}
}

void hwFFT(void)
{
	Int32 n=0;
	Int16 i,j=0;

	printf("Hardware FFT status:\n");
	printf("off\n");
    while (1)			/* Forever loop for the demo if status is set */
    {
    	if (n++ == (0x4000000))
    	{
    		n = 0;
    		j++;
    		if (j &= 1)
    			printf("on\n");
    		else
    			printf("off\n");
    	}

        if(leftChannel == 1)
        {
        	leftChannel = 0;
            if (CurrentRxL_DMAChannel == 2)
            {
            	if (j) /* Filter the input audio data and send to output */
            	{
            		hwFFT_iFFT(RcvL1, XmitL1, x, temp);
            	}
            	else  /* Without filter, pass through the audio */
            	{
            		for(i=0; i<XMIT_BUFF_SIZE; i++)
            		{
            			XmitL1[i] = RcvL1[i];
            		}
            	}
            }
            else
            {
            	if (j) /* Filter the input audio data and send to output */
            	{
            		hwFFT_iFFT(RcvL2, XmitL2, x, temp);
            	}
            	else  /* Without filter, pass through the audio */
            	{
            		for(i=0; i<XMIT_BUFF_SIZE; i++)
            		{
            			XmitL2[i] = RcvL2[i];
            		}
            	}
             }
        }
        if(rightChannel == 1)
        {
        	rightChannel= 0;
            if (CurrentRxR_DMAChannel == 2)
            {
            	if (j) /* Filter the input audio data and send to output */
            	{
            		hwFFT_iFFT(RcvR1, XmitR1, x, temp);
            	}
            	else  /* Without filter, pass through the audio */
            	{
            		for(i=0; i<XMIT_BUFF_SIZE; i++)
            		{
            			XmitR1[i] = RcvR1[i];
            		}
            	}
            }
            else
            {
            	if (j) /* Filter the input audio data and send to output */
            	{
            		hwFFT_iFFT(RcvR2, XmitR2, x, temp);
            	}
            	else  /* Without filter, pass through the audio */
            	{
            		for(i=0; i<XMIT_BUFF_SIZE; i++)
            		{
            			XmitR2[i] = RcvR2[i];
            		}
            	}
            }
        }
    }
}

void hwFFT_iFFT(Int16 *inDataPtr, Int16* outDataPtr, complex *x, complex *temp)
{
    Uint16 i;
    Int16 fftOut;
    complex *data, *data2;

    for (i=0; i<FFT_PTS; i++)
    {
        x[i].re = *inDataPtr++;
        x[i].im = 0;
    }

    /* Start FFT */
    hwafft_br((Int32 *)x, (Int32 *)temp, FFT_PTS); /* Arrange X[] in bit reversal order and store in temp */
    fftOut = hwafft_512pts((Int32 *)temp, (Int32 *)x, FFT_FLAG, SCALE_FLAG);

    /* Inverse FFT */
    data = x;
    data2 = temp;
    if (!fftOut)
    {
        data = temp;
        data2 = x;
    }

    hwafft_br((Int32 *)data, (Int32 *)data2, FFT_PTS);
    fftOut = hwafft_512pts((Int32 *)data2, (Int32 *)data, IFFT_FLAG, NOSCALE_FLAG);

    if (!fftOut)
    {
    	for (i=0; i<FFT_PTS; i++)
    	{
    		*outDataPtr++ = data2[i].re;
    	}
    }
    else
    {
    	for (i=0; i<FFT_PTS; i++)
    	{
    		*outDataPtr++ = data[i].re;
    	}
    }
}

