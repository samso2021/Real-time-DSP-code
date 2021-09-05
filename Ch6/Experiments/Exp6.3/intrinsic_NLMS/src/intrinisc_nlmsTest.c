/*
 * intrinsic_nlmsTest.c
 *
 *  Created on: June 5, 2012
 *      Author: BLEE
 *
 *  Description: This is the test program for intrinsic normalized LMS experiment
 *
 *               The input is a 1kHz sine wave sampling rate 8kHz with noise
 *               The output is the sine wave
 *               The error is the noise
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#include <stdio.h>
#include <stdlib.h>
#include "tistdtypes.h"
#include "intrinsic_nlms.h"

LMS lmsObj;
LMS *lms = &lmsObj;

Int16 w[L+1];
Int16 x[L+1];


void main()
{  
    Int16  i,c;
    FILE   *fpIn,*fpDes,*fpOut,*fpErr;
    char   temp1[2],temp2[2];
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
    lms->alpha = ALPHA;
    lms->power = (short)0x32767;
    lms->c = C;
    lms->w = w;
    lms->x = x;	

    // Clear data and tap delay lines
    for (i=0; i<=lms->order; i++)
    {
        lms->w[i] = 0;
        lms->x[i] = 0;
    }
	
    // Filter test
    printf("Exp --- started\n");
    while ((fread(temp1, sizeof(Int8), 2, fpIn) == 2)&&
           (fread(temp2, sizeof(Int8), 2, fpDes)== 2) )
    {
    	// Get 16-bit PCM input and desired data
        lms->in  = (temp1[0]&0xFF)|(temp1[1]<<8);
        lms->des = (temp2[0]&0xFF)|(temp2[1]<<8);

        // Filter the data
        intrinsic_nlms(lms);

    	// Write the output and error data  to 16-bit PCM
    	temp1[0] = (lms->out&0xFF);
        temp1[1] = (lms->out>>8)&0xFF;
    	temp2[0] = (lms->err&0xFF);
        temp2[1] = (lms->err>>8)&0xFF;
        fwrite(temp1, sizeof(Int8), 2, fpOut);
        fwrite(temp2, sizeof(Int8), 2, fpErr);
        printf("%ld\n",++n);
    }

    fclose(fpIn);
    fclose(fpDes);
    fclose(fpOut);
    fclose(fpErr);
    printf("Exp --- completed\n");
}

