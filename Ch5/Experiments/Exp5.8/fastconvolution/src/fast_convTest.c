/*
 * fast_convTest.c
 *
 *  Created on: Oct 14, 2012
 *      Author: BLEE
 *
 *  Description: This is the test program for fast convolution
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#include <stdio.h>
#include <stdlib.h>
#include "tistdtypes.h"
#include "icomplex.h"
#include "fast_convolution.h"

void wHdUpdt(Uint8 *w, Uint32 bytes);

#pragma DATA_SECTION(H,      ".bss:fft_coef");
#pragma DATA_SECTION(coeffs, ".bss:fft_coef");
#pragma DATA_SECTION(U,      ".bss:fft_twd");
#pragma DATA_SECTION(X,      ".bss:fft_temp");
#pragma DATA_SECTION(OVRLAP, ".bss:fft_in");
#pragma CODE_SECTION(main,   ".text:fft_code");
#pragma DATA_ALIGN(X,2); /* Alignment is needed for dual accumulator store in bit_rev.asm */


/* Low-pass FIR filter coefficients */
#include "fdacoefs1k_8k_511.h"

complex U[EXP];                  /* Twiddle e^(-j2pi/FFT_PTS) table */
complex X[FFT_PTS];              /* Signal buffer */
complex H[FFT_PTS];              /* Frequency domain Filter */
//Int16   OVRLAP[FFT_PTS-FLT_LEN]; /* Frequency domain overlap buffer */
Int16   OVRLAP[FFT_PTS-DATA_LEN]; /* Frequency domain overlap buffer */
Int8    temp[FFT_PTS*2];

void main(void)
{ 
    Int16 i,k,c;
    FILE  *fpIn,*fpOut;
    Uint8  waveHeader[44];
    Uint32 cnt;

    printf("Enter 1 for using PCM file, enter 2 for using WAV file\n");
    scanf ("%d", &c);

    if (c == 2)
    {
    	fpIn = fopen("..\\data\\input.wav", "rb");
    	fpOut = fopen("..\\data\\output.wav", "wb");
    }
    else
    {
    	fpIn = fopen("..\\data\\input.pcm", "rb");
    	fpOut = fopen("..\\data\\output.pcm", "wb");
    }
    // Open file for read input data
    if (fpIn == NULL)
    {
        printf("Can't open input data file\n");
        exit(0);
    }

    if (c == 2)							/* Create WAVE data file header */
    {
    	fread(waveHeader, sizeof(Int8), 44, fpIn);
    	fwrite(waveHeader, sizeof(Int8), 44, fpOut);
    }
    
    /* Initialization */
    for (i=0; i<(FFT_PTS-DATA_LEN); i++)	/* Initialize overlap buffer */
        OVRLAP[i] =0;                                    
    
    for (i=0; i<FLT_LEN; i++)			/* Copy filter coefficient to work buffer */
    {
        X[i].re = coeffs[i];
        X[i].im = 0;
    }

    for (i=i; i<FFT_PTS; i++)    		/* Fill zeros to the remaining work buffer */
    {
        X[i].re = 0;                                               
        X[i].im = 0;
    }
    cnt = 0;
    w_table(U,EXP);        				/* Create Twiddle lookup table for FFT */
    bit_rev(X,EXP);        				/* Bit reversal arrange the coefficient */
    fft(X,EXP,U,FFT_FLAG,NOSCALE_FLAG); /* FFT to the filter coefficients */

    for (i=0; i<FFT_PTS; i++)    		/* Save frequency domain coefficients */
    {
        H[i].re = X[i].re; 
        H[i].im = X[i].im; 
    }

    for (i=0; i<FFT_PTS; i++)           /* Clear the X[] */
    {
        X[i].re = 0;
        X[i].im = 0;
    }

    /* Start FFT Convolution test */   
    while (fread(temp, sizeof(Int8), DATA_LEN*2, fpIn) == (DATA_LEN*2))
    {
        for (k=0, i=0; i<DATA_LEN; i++)
        {
            X[i].re = (Int16)((temp[k]&0xFF)|(temp[k+1]<<8)); /* Generate input samples */
            X[i].im = 0;
            k += 2;
        }
    	
    	for (i=i; i<FFT_PTS; i++)       /* Fill zeros to data buffer */
        {
            X[i].re = 0;
            X[i].im = 0;
        }    	
    	
        /* Start FFT convolution */
        bit_rev(X,EXP);           		/* Arrange sample in bit reversal order */
        fft(X,EXP,U,FFT_FLAG,SCALE_FLAG); /* Perform FFT */
        
        freqflt(X,H,FFT_PTS);           /* Perform frequency domain filtering */
        for (i=0; i<FFT_PTS; i++)
        {
        	X[i].im = -X[i].im;
        }

        bit_rev(X,EXP);           		/* Arrange sample in bit reversal order */
        fft(X,EXP,U,IFFT_FLAG,NOSCALE_FLAG); /* Perform IFFT */

        olap_add(X,OVRLAP,DATA_LEN,FFT_PTS); /* Overlap and add algorithm */
        /* End of FFT convolution */

        for (k=0, i=0; i<DATA_LEN; i++)
        {
            temp[k++] = (X[i].re&0xFF);
            temp[k++] = (X[i].re>>8)&0xFF;
            cnt += 2;
        }
        fwrite(temp, sizeof(Int8), DATA_LEN*2, fpOut);
        printf("%ld data bytes processed\n", cnt);
    }    

    if (c == 2)		/* Based on input WAVE file to generate output */
    {
    	wHdUpdt(waveHeader, cnt);
    	rewind(fpOut);
    	fwrite(waveHeader, sizeof(Int8), 44, fpOut);
    }

	fclose(fpIn);
	fclose(fpOut);
  	printf("Exp --- experiment completed\n");
}

// Update the wave file header
void wHdUpdt(Uint8 *w, Uint32 bytes)
{
	Int32 t;

	t = bytes;
	w[40] = (t>>0)&0xff;	// Set up output file size
	w[41] = (t>>8)&0xff;
	w[42] = (t>>16)&0xff;
	w[43] = (t>>24)&0xff;
	t += 36;
	w[4] = (t>>0)&0xff;
	w[5] = (t>>8)&0xff;
	w[6] = (t>>16)&0xff;
	w[7] = (t>>24)&0xff;
}

