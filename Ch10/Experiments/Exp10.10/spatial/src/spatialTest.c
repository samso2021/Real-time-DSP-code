/*
* spatialTest.c
*
*  Created on: Oct 28, 2012
*      Author: BLEE
*
*  Description: This is the test program for floating-point spatial sound effect experiment
*
*  For the book "Real Time Digital Signal Processing:
*                Fundamentals, Implementation and Application, 3rd Ed"
*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
*                Publisher: John Wiley and Sons, Ltd
*
*/

#include <stdlib.h>
#include <stdio.h>
#include "tistdtypes.h"
#include "spatialSound.h"

Int16 d_buffer[MAX_BUF_SIZE];
Int16 out16[2];

spatial param;
spatial *t;

#pragma DATA_SECTION(temp,"uxerData1");
#pragma DATA_SECTION(temp2,"uxerData2");
Int8   temp[2*MAX_BUF_SIZE];
Int8   temp2[4*MAX_BUF_SIZE];
Uint8  waveHeader[44];

void wHeader(Uint8 *w, float f1, float f2, Uint32 bytes);

void main()
{
    FILE    *fpOut,*fpIn;
    Int16   i,j,k,c;
    Uint32  cnt, samples;
  	
    //  Open data files
    printf("Enter 1 for using PCM file, enter 2 for using WAV file\n");
    scanf ("%d", &c);

    if (c == 2)
    {
    	fpIn = fopen("..\\data\\audioIn.wav", "rb");
    	fpOut = fopen("..\\data\\audioOut.wav", "wb");
    }
    else
    {
    	fpIn = fopen("..\\data\\audioIn.pcm", "rb");
    	fpOut = fopen("..\\data\\audioOut.pcm", "wb");
    }
    if (fpIn == NULL)
    {
        printf( "Problem opening the input audio file\n" );
        exit(0);
    }

	fseek(fpIn, 0L, SEEK_END);
	samples = ftell(fpIn);
	fseek(fpIn, 0L, SEEK_SET);

    if (c == 2)
    {
      fread(waveHeader, sizeof(Int8), 44, fpIn);		// Advance input to data section
      fwrite(waveHeader, sizeof(Int8), 44, fpOut);		// Write header for output file

      samples -=44;
    }

    // From the left to the right
    samples = (Uint32)((samples>>1)/SAMPLEPOINTS);		// Calculate number of samples per segment


    printf("Exp --- spatial experiment\n");
    cnt = 0;

    /* Initialization */
    t = &param;
    spatialInit(t,samples);

    // Read initial buffer
    fread(&temp, sizeof(Int8),2*MAX_BUF_SIZE, fpIn);
    for(j=0, i = MAX_BUF_SIZE-1; i > 0; i --)
    {
        d_buffer[i] = temp[j++]&0xFF;
        d_buffer[i] |= temp[j++]<<8;
    }

    while (fread(&temp, sizeof(Int8),2*MAX_BUF_SIZE, fpIn) == 2*MAX_BUF_SIZE)
    {
        for(k=0, j=0, i=0; i<MAX_BUF_SIZE; i++)
        {
            /* Construct 16-bit input data from bytes */
            d_buffer[0] = temp[j++]&0xFF;
            d_buffer[0] |= temp[j++]<<8;
            /* make the delay vary */
            CalculateIID(t);
            CalculateITD(t);
            t->n++;

            /* Apply the spatial sound process function to the sample */
            procSpatialSound(out16, t);
			
            /* save the output */
            temp2[k++] = out16[0]&0xFF;
            temp2[k++] = (out16[0]>>8)&0xFF;
            temp2[k++] = out16[1]&0xFF;
            temp2[k++] = (out16[1]>>8)&0xFF;
        }

        fwrite(&temp2, sizeof(Int8),4*MAX_BUF_SIZE, fpOut); // Stereo output
        cnt += MAX_BUF_SIZE;
        printf("%ld data samples processed\n", cnt);
    }
    if (c == 2)		// Based on input WAVE file to generate output
    {
        wHeader(waveHeader, 8000, 8000, cnt<<2); // Stereo so double the cnt
        waveHeader[22] *= 2; 		// Convert channel from mono to stereo output
        waveHeader[32] *= 2; 		// Double byte rate for stereo output
        rewind(fpOut);
        fwrite(waveHeader, sizeof(Int8), 44, fpOut);
    }
    fclose(fpOut);
    fclose(fpIn);
    printf("Exp --- completed\n");
}

// Create the wave file header
void wHeader(Uint8 *w, float f1, float f2, Uint32 bytes)
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
    t = w[24]|(w[25]<<8)|((Int32)w[26]<<16)|((Int32)w[27]<<24);
    t = (Int32)((float)t*f2/f1);
    w[24] = (t>>0)&0xff;	// Set up output file frequency
    w[25] = (t>>8)&0xff;
    w[26] = (t>>16)&0xff;
    w[27] = (t>>24)&0xff;
    t = w[28]|(w[29]<<8)|((Int32)w[30]<<16)|((Int32)w[31]<<24);
    t = (Int32)((float)t*f2/f1);
    w[28] = (t>>0)&0xff;	// Set up output file byte rate
    w[29] = (t>>8)&0xff;
    w[30] = (t>>16)&0xff;
    w[31] = (t>>24)&0xff;
    return;
}

