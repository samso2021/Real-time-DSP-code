/*
 * hwfftTest.c
 *
 *  Created on: June 13, 2012
 *      Author: BLEE
 *
 *  Description: This is the test program for HW accelerator based FFT implementation.
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include <stdio.h>
#include "tistdtypes.h"

struct cmpx						/* Q15 format */
{
	Int16 re;
	Int16 im;
};
typedef struct cmpx complex;

#define FFT_FLAG        0		/* HWA to perform FFT */
#define IFFT_FLAG       1		/* HWA to perform IFFT */
#define SCALE_FLAG      0		/* HWA to scale butterfly output */
#define NOSCALE_FLAG    1		/* HWA not to scale butterfly output */

#define	FFT_PTS 128				/* This is for 128 FFT case */

#pragma DATA_SECTION(X, "data_br_buf");
#pragma DATA_ALIGN(X, 2*FFT_PTS);	/* Align for hwafft_br() */
complex X[FFT_PTS];

#pragma DATA_SECTION(temp, "scratch_buf");
#pragma DATA_ALIGN(temp, 2*FFT_PTS); /* Align for hwafft_br() */
complex temp[FFT_PTS];

#pragma DATA_SECTION(output, ".data:output");
#pragma DATA_SECTION(error, ".data:error");
Int16 output[13*FFT_PTS];		/* FFT - IFFT final output */
Int16 error[13*FFT_PTS];		/* IFFT output error from input */

#pragma DATA_SECTION(input, ".const:input");
#include "input.dat"			/* Integer FFT test data file, sweep frequency */


extern   Uint16 hwafft_128pts(Int32 *, Int32 *, Int16, Int16);
extern   Uint16 hwafft_br(Int32 *, Int32 *, Int16);


void main()
{
    Int16  i,j;
    Int16  *inDataPtr,*outDataPtr,*errPtr;
    Uint16 fftOut;
    complex *data, *data2;
    FILE   *fp;

    printf("Exp --- started\n");
    /* Start FFT test */
    inDataPtr = input;
    outDataPtr = output;
    errPtr = error;

    for (j=0; j<(13*FFT_PTS); j+=FFT_PTS)    /* Data file has 1664 = 13*128 data */
    {
        for (i=0; i<FFT_PTS; i++)
        {
            X[i].re = *inDataPtr++;
            X[i].im = 0;
    	}

        /* Start FFT */
        hwafft_br((Int32 *)X, (Int32 *)temp, FFT_PTS); /* Arrange X[] in bit reversal order and store in temp */
        fftOut = hwafft_128pts((Int32 *)temp, (Int32 *)X, FFT_FLAG, SCALE_FLAG);

        /* Inverse FFT */
        data = X;
        data2 = temp;
        if (!fftOut)
        {
            data = temp;
            data2 = X;
        }

        hwafft_br((Int32 *)data, (Int32 *)data2, FFT_PTS);
        fftOut = hwafft_128pts((Int32 *)data2, (Int32 *)data, IFFT_FLAG, NOSCALE_FLAG);

        /* Store IFFT output samples for verification */
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

    // Check for errors, we can display output[] and error[] to verify the result
    inDataPtr = input;
    outDataPtr = output;
    errPtr = error;
    fp = fopen("..\\data\\HW_FFT_IFFT.xls", "wt");
    fprintf(fp, "n\t input\t output\t error\n");
    for (j=0; j<(13*FFT_PTS); j++)
    {
      	fprintf(fp, "%d\t%d\t%d\t%d\n", j, *inDataPtr, *outDataPtr, *inDataPtr-*outDataPtr);
        *errPtr++ = *inDataPtr++ - *outDataPtr++;
    }
    fclose(fp);
    printf("Exp --- completed\n");

}
