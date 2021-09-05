/*
 * float_lmsTest.c
 *
 *  Created on: June 5, 2012
 *      Author: BLEE
 *
 *  Description: This is the test program for LMS experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#include <stdio.h>
#include <stdlib.h>
#include "tistdtypes.h"
#include "float_lms.h"

LMS lmsObj;
LMS *lms = &lmsObj;

double w[L+1];
double x[L+1];


void main()
{  
    Int16  i,z,c;
    FILE   *fpIn,*fpDes,*fpOut,*fpErr;
    Int8   temp[2];
    Uint8  waveHeader[44];
    Uint32 n=0;

    printf("Enter 1 for using PCM file, enter 2 for using WAV file\n");
    scanf ("%d", &c);

    if (c == 2)
    {
    	// Open input file for read input data
    	fpIn = fopen("..\\data\\input.wav", "rb");
    	// Open desired file for read desired input data
    	fpDes = fopen("..\\data\\desired.wav", "rb");
    	// Open file for write output
    	fpOut = fopen("..\\data\\output.wav", "wb");
    	// Open file for write error
        fpErr = fopen("..\\data\\error.wav", "wb");
    }
    else
    {
    	// Open input file for read input data
    	fpIn = fopen("..\\data\\input.pcm", "rb");
    	// Open desired file for read desired input data
    	fpDes = fopen("..\\data\\desired.pcm", "rb");
    	// Open file for write output
    	fpOut = fopen("..\\data\\output.pcm", "wb");
    	// Open file for write error
        fpErr = fopen("..\\data\\error.pcm", "wb");
    }

    if (fpIn == NULL)
    {
        printf("Can't open input data file\n");
        exit(0);
    }
    if (fpDes == NULL)
    {
        printf("Can't open desired input data file\n");
        exit(0);
    }

    if (c == 2)		// Create WAVE data file header, use the short of the input or desired input file
    {
    	fread(waveHeader, sizeof(Int8), 44, fpIn);	// Assume input is shorter or equal to desired input file
    	fwrite(waveHeader, sizeof(Int8), 44, fpOut);
    	fwrite(waveHeader, sizeof(Int8), 44, fpErr);
    }

    lms->order = L;
    lms->mu    = MU;
    lms->w     = w;
    lms->x     = x;

    // Clear data and tap delay lines
    for (i=0; i<=lms->order; i++)
    {
    	lms->w[i] = 0.0;
    	lms->x[i] = 0.0;
    }
	
    printf("Exp --- started\n");
    // Filter test
    while (fread(temp, sizeof(Int8), 2, fpIn) == 2)
    {
    	// Convert 16-bit PCM input data to floating-point format
        z = (temp[0]&0xFF)|(temp[1]<<8);
        lms->in = (double)z/32767.0;

    	// Convert 16-bit PCM desired data to floating-point format
    	fread(temp, sizeof(Int8), 2, fpDes);
        z = (temp[0]&0xFF)|(temp[1]<<8);
        lms->des = (double)z/32767.0;

    	// Filter the data
    	float_lms(lms);

    	// Convert the floating-point data back to 16-bit PCM data format
    	z = (Int16)(lms->out*32767.0 + 0.5);
    	temp[0] = (z&0xFF);
        temp[1] = (z>>8)&0xFF;
        fwrite(temp, sizeof(Int8), 2, fpOut);

    	// Convert the floating-point error back to 16-bit data format
    	z = (Int16)(lms->err*32767.0 + 0.5);
    	temp[0] = (z&0xFF);
        temp[1] = (z>>8)&0xFF;
        fwrite(temp, sizeof(Int8), 2, fpErr);
        printf("%ld\n",++n);
    }

    fclose(fpIn);
    fclose(fpDes);
    fclose(fpOut);
    fclose(fpErr);
    printf("Exp --- completed\n");
}
