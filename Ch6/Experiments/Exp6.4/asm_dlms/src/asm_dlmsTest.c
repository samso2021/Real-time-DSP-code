/*
 * asm_dlmsTest.c
 *
 *  Created on: June 6, 2012
 *      Author: BLEE
 *
 *  Description: This is the test program for LMS experiment in assembly language implementation
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
#include "asm_dlms.h"

// Adaptive filter delay line
#pragma DATA_SECTION (x,".bss:dbuffer")
Int16 x[L+1];

// Adaptive coefficients
#pragma DATA_SECTION (w,".data:coeffs")
Int16 w[L];

// Adaptive object and pointer
LMS lmsObj;
LMS *lms = &lmsObj;

// Data arrays for test
Int16 in[N];
Int16 out[N];
Int16 des[N];
Int16 err[N];

// Temp arrays for file-IO 
Int8  temp1[2*N],temp2[2*N];

    
void main()
{  
    Int16  i,j,c;
    FILE   *fpIn,*fpDes,*fpOut,*fpErr;
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

    // Initialize LMS object for the experiment
    lms->in    = in;           // Input array pointer
    lms->des   = des;          // Desired array pointer
    lms->out   = out;          // Output array pointer
    lms->e     = err;	       // Error array pointer
    lms->w     = w;            // Adaptive filter coefficients pointer
    lms->x     = x;	           // Filter delay line pointer
    lms->order = L;            // Adaptive filter length
    lms->step  = (Int16)STEP;  // Adaptive filter step size
    lms->size  = N;            // Data sample block size
    lms->index = 0;            // Delay line start position index
    	
    for (i=0;i<L;i++)          // Clear coefficient buffer
    {
        lms->w[i] =0;	        
    }
               
    for (i=0; i<=L; i++)       // Clear delay buffer 
    {
        lms->x[i] = 0;         
    }
	
    // Start filter test
    printf("Exp --- started\n");
    while ((fread(temp1, sizeof(Int8), (2*N), fpIn)  == (2*N)) &&
           (fread(temp2, sizeof(Int8), (2*N), fpDes) == (2*N)) )
    {

        // Get 16-bit PCM input and desired data  
        for (j=0, i=0; i<N; i++)
        {
            lms->in[i]   = (temp1[j]&0xFF)|(temp1[j+1]<<8);   
            lms->des[i]  = (temp2[j]&0xFF)|(temp2[j+1]<<8);
            j += 2;            
        }

        // Filter the data and update delay line index
        lms->index = asm_dlms(lms);
        
        // Write the output and error data  to 16-bit PCM
        for (j=0, i=0; i<N; i++)
        {      
            temp1[j]   = (lms->out[i]&0xFF);
            temp1[j+1] = (lms->out[i]>>8)&0xFF; 
            temp2[j]   = (lms->e[i]&0xFF);
            temp2[j+1] = (lms->e[i]>>8)&0xFF;
            j += 2;          
        }

        fwrite(temp1, sizeof(Int8), (2*N), fpOut);
        fwrite(temp2, sizeof(Int8), (2*N), fpErr);
        printf("%ld\n",++n*N);
    }

    fclose(fpIn);
    fclose(fpDes);
    fclose(fpOut);
    fclose(fpErr);
    printf("Exp --- completed\n");
}

