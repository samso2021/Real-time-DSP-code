/*
 * mix_VAD_mainTest.c
 *
 *  Created on: Dec 5, 2012
 *      Author: BLEE
 *
 *  Description: This is the test program for VAD experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "tistdtypes.h"
#include "mixed_vad.h"

Int16   input[FrameSize];
Int16   vadRef[FrameSize];
Int8    temp[2*FrameSize];

/*********************************************************************
*    Main function
*********************************************************************/

void main()
{
	Int16   L;              // Length of FFT and IFFT
	Int16   N;              // Length of overlap window
    FILE    *fpin;          // Input signal
    FILE    *fpout;         // Output signal
    Int16   i;              // For demo use only
    Int16   vadFlag;
    Uint32  n;

    if ((fpin = fopen("..\\data\\speech.wav", "rb"))== NULL)
    {
        printf("Can't open input data file\n");
        exit(0);
    }

    fpout = fopen("..\\data\\VAD_ref.xls","wt");

    fread(temp, sizeof(Int8), 44, fpin);    // Skip WAV header
    fprintf(fpout, "%s\t%s\n", "Original speech", "VAD flag");

    L = 1<<EXP;                // Window size
    N = (Int16)L>>1;           // Frame size = 1/2 window size
    mixVad.pwindow = window;   // Set window arrary pointer

    w_table(U);                // Create Twiddle lookup table for FFT
    hmwindow(L);               // Generate hanning window
    vad_init(N);               // Initialization

    // Start processing
    printf("Exp --- mixed VAD experiment\n");
    n = 0;

    while (fread(temp, sizeof(Int8), 2*N, fpin) == (Uint16)(2*N))
    {
        // Get 16-bit PCM input
        for (i=0;i<N;i++)
        {
            input[i] = (temp[2*i]&0xFF)|(temp[2*i+1]<<8);
        }

        vadFlag = vad_pre(input,L,N,mixVad.pwindow);

        if (vadFlag ==1)
        {
        	for(i=0;i<N;i++)
        	{
        		vadRef[i]=0x4000;
        	}
       	}
        else
        {
        	for(i=0;i<N;i++)
        	{
        		vadRef[i]=0;
        	}
       	}

        for (i=0; i<N; i++)
        {
            fprintf(fpout, "%d\t%d\n", input[i], vadRef[i]);
        }

        n += N;
        printf("%ld data words processed\n", n);
    }

    fclose(fpin);
    fclose(fpout);
    printf("Exp --- completed\n");
}
