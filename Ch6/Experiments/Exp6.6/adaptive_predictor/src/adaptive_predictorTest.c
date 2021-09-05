/*
 * adaptive_predictorTest.c
 *
 *  Created on: Oct 21, 2012
 *      Author: BLEE
 *
 *  Description: This is the test program for adaptive line predictor experiment
 *
 *               The input is a sine wave with white noise interference
 *               The adaptive line predictor will output both s(n) and v(n)
 *
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */


#include <stdio.h>
#include <stdlib.h>
#include "tistdtypes.h"
#include "adaptive_predictor.h"

void wHdUpdt(Uint8 *w, Uint32 bytes);

ADAPTLP linePredictor;      // Adaptive line predictor object
ADAPTLP *alp = &linePredictor;

#pragma DATA_ALIGN(w,2);
#pragma DATA_ALIGN(y,2);
#pragma DATA_ALIGN(x,2);
#pragma DATA_ALIGN(in,2);
#pragma DATA_ALIGN(e,2);

Int16 e[Ns],              // Error signal buffer
      y[Ns],              // Output signal buffer
      in[Ns],             // Input signal buffer 
      w[L],               // Adaptive filter coefficients 
      x[L];               // Filter delayline buffer   
    
Int8 temp1[2*Ns],temp2[2*Ns]; // Temp array for reading data from a file

void main()
{
    Int16  i,j,c;
    FILE   *fpIn,*fpOut;
    Uint8  waveHeader[44];
    Uint32 cnt;

    printf("Enter: 1 for wide-band output in PCM format\n");
    printf("Enter: 2 for narrow-band output in PCM format\n");
    printf("Enter: 3 for wide-band output in WAV format\n");
    printf("Enter: 4 for narrow-band output in WAV format\n");
    scanf ("%d", &c);

    switch (c)
    {
    	case 1:
     		fpIn = fopen("..\\data\\speech.pcm", "rb");
     		fpOut = fopen("..\\data\\wideband.pcm", "wb");
    		break;
    	case 2:
    		fpIn = fopen("..\\data\\tone.pcm", "rb");
    		fpOut = fopen("..\\data\\narrowband.pcm", "wb");
    		break;
    	case 3:
    		fpIn = fopen("..\\data\\speech.wav", "rb");
    		fpOut = fopen("..\\data\\wideband.wav", "wb");
    		break;
    	case 4:
    	default:
    		fpIn = fopen("..\\data\\tone.wav", "rb");
    		fpOut = fopen("..\\data\\narrowband.wav", "wb");
    		break;
    }

    if (fpIn == NULL)
    {
        printf("Can't open input data file\n");
        exit(0);
    }

    if (c > 2)		// Create WAV file header
    {
    	fread(waveHeader, sizeof(Int8), 44, fpIn);
    	fwrite(waveHeader, sizeof(Int8), 44, fpOut);
    }
	
    // Initialize adaptive filter object
    alp->in = in;
    alp->y = y;
    alp->e = e;
    alp->x = x;
    alp->w = w;
    alp->size = Ns;
    alp->order = L;
    alp->index = 0;     

    for (i=0; i<L; i++)
    {
        w[i] = 0;          // Initialize adaptive filter coefficients  
        x[i] = 0;          // Initialize adaptive filter delay-line  
    }
    cnt = 0;

    printf("Exp --- started\n");
    while (fread(temp1, sizeof(Int8), (2*Ns), fpIn)  == (2*Ns))
    {                                                             
        for (j=0, i=0; i<Ns; i++) 
        {
            in[i]  = (temp1[j]&0xFF)|(temp1[j+1]<<8);
            j += 2;
        }
        cnt += 2*Ns;

        // Run adaptive line enhancement
        alp->index = adaptivePredictor(alp);

        // Write the result to 16-bit PCM
        if (c&1)
        {
        	for (j=0, i=0; i<Ns; i++)
        	{
        		e[i] <<= 1;		// Scale up for output
        		temp2[j++] = (e[i]&0xFF);
        		temp2[j++] = (e[i]>>8)&0xFF;
        	}
        }
        else
        {
        	for (j=0, i=0; i<Ns; i++)
        	{
        		temp2[j++] = (y[i]&0xFF);
        		temp2[j++] = (y[i]>>8)&0xFF;
        	}
        }
        fwrite(temp2, sizeof(Int8), (2*Ns), fpOut);
        printf("%ld data samples are processed\n", cnt);
    }

    if (c > 2)		// Based on input WAV file to generate output
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
