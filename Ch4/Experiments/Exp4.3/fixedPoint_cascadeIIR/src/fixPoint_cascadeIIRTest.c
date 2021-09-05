/*
* fixPoint_cascadeIIRTest.c
*
*  Created on: May 25, 2012
*      Author: BLEE
*
*  Description: This is the test program for fixed-point direct form-II IIR filter
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
#include "cascadeIIR.h"
#include "fdacoefsMATLAB.h"

void wHdUpdt(Uint8 *w, Uint32 bytes);

#define SECTIONS       ((MWSPT_NSEC-1)/2)     // Number of 2nd order sections
Int16   C[SECTIONS*5]; // Filter coefficients obtained from example 5.14 MATLAB FDATool
                       // C[]=A[i][1], A[i][2], B[i][2], B[i][0], B[i][1]... 
Int16   w[SECTIONS*2]; // Filter delay line
                       // w[]=w[i][n-1],w[i+1][n-1],...,w[i][n-2],w[i+1][n-2],...

#define NUM_DATA       160                    // Number of samples per block
Int16   out[NUM_DATA]; // Filter output data buffer
Int16   in[NUM_DATA];  // Filter input data buffer

         
void main(void)
{
    Int16 i,k,n,c;
    Int16 gainNUM,gainDEN;
    Int32 temp32;
    Int8  temp[NUM_DATA*2];
    FILE  *fpIn,*fpOut;
    Uint8 waveHeader[44];
    Uint32 cnt;

    printf("Enter 1 for using PCM file, enter 2 for using WAV file\n");
    scanf ("%d", &c);

    if (c == 2)
    {
    	fpIn = fopen("..\\data\\in.wav", "rb");
    	fpOut = fopen("..\\data\\out.wav", "wb");
    }
    else
    {
    	fpIn = fopen("..\\data\\in.pcm", "rb");
    	fpOut = fopen("..\\data\\out.pcm", "wb");
    }
    // Open file for read input data
    if (fpIn == NULL)
    {
        printf("Can't open input data file\n");
        exit(0);
    }

    if (c == 2)									// Create WAVE data file header
    {
    	fread(waveHeader, sizeof(Int8), 44, fpIn);
    	fwrite(waveHeader, sizeof(Int8), 44, fpOut);
    }

	// Initialize IIR filter delay line
    for (i=0; i<SECTIONS*2;i++)
    {
        w[i] = 0; 
    }
    cnt = 0;

    // Get coefficients from DEN[][] and NUM[][]
    for(k=0, n=0, i=0; i<SECTIONS; i++)
    {
        gainDEN = DEN[k][0];
        gainNUM = NUM[k++][0];

        temp32 = (Int32)gainDEN * DEN[k][1];
        C[n++] = (Int16)(temp32>>14);
        temp32 = (Int32)gainDEN * DEN[k][2];
        C[n++] = (Int16)(temp32>>14);

        temp32 = (Int32)gainNUM * NUM[k][2];
        C[n++] = (Int16)(temp32>>14);
        temp32 = (Int32)gainNUM * NUM[k][0];
        C[n++] = (Int16)(temp32>>14);
        temp32 = (Int32)gainNUM * NUM[k++][1];
        C[n++] = (Int16)(temp32>>14);
    }

	printf("Exp --- IIR filter experiment\n");

    // IIR filter experiment start 
	while (fread(temp, sizeof(Int8), NUM_DATA*2, fpIn) == (NUM_DATA*2))
	{
            for (k=0, i=0; i<NUM_DATA; i++)
            {
                in[i] = (temp[k]&0xFF)|(temp[k+1]<<8);
                k += 2;
            }

            cascadeIIR(in,NUM_DATA,out,C,SECTIONS,w); // Filter a block of samples

            for (k=0, i=0; i<NUM_DATA; i++)
            {
                temp[k++] = (out[i]&0xFF);
                temp[k++] = (out[i]>>8)&0xFF;
                cnt += 2;
            }
            fwrite(temp, sizeof(Int8), NUM_DATA*2, fpOut);
    }

    if (c == 2)		// Based on input WAVE file to generate output
    {
    	wHdUpdt(waveHeader, cnt);
    	rewind(fpOut);
    	fwrite(waveHeader, sizeof(Int8), 44, fpOut);
    }

    fclose(fpIn);
    fclose(fpOut);
    printf("Exp --- completed\n");
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
