/*
 * cng_mainTest.c
 *
 *  Created on: Sep 16, 2012
 *      Author: BLEE
 *
 *  Description: This is the test program for floating-point CNG experiment
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
#include "cng.h"
#include "g711.h"

#define HZ8k	8000	// sampling frequency
#define DATASIZE  16	// 16 bit PCM data format
void wHeaderUpdate(Uint8 *, Uint32, Uint32, Uint8);
Uint8 waveHeader[44]={
		0x52,0x49,0x46,0x46,0x0E,0xAA,0x05,0x00,
		0x57,0x41,0x56,0x45,0x66,0x6D,0x74,0x20,
		0x10,0x00,0x00,0x00,0x01,0x00,0x01,0x00,
		0x40,0x1F,0x00,0x00,0x80,0x3E,0x00,0x00,
		0x02,0x00,0x10,0x00,0x64,0x61,0x74,0x61,
		0xEA,0xA9,0x05,0x00};

Int16 output[BLOCKSIZE];
Int8  charBuf[2*BLOCKSIZE];

void main(void)
{   
    FILE    *fpIn;                  // Input signal in PCM format
    FILE    *fpOut;                 // Output signal in ASCII format
    Int16   i,j;
    Int16   frameSize;
    Int16   gain;
    Uint8   frameType,noiseLevel,temp8;
    Uint32  n;

    if ((fpIn = fopen("..//data//parameter.dtx","rb")) == NULL )
    {
        printf("Can't open input file\n");
        exit(0);
    } 
    fpOut = fopen("..//data//result.wav","wb");
    fwrite(waveHeader, sizeof(Int8), 44, fpOut);

    frameSize = 128;
    gain = 0;
    n = 0;
    for(i=0; i<frameSize; i++)
    {
        output[i] = 0;
    }

    printf("Exp --- CNG\n");
    while(fread(&temp8, sizeof(Int8), 1, fpIn) == 1)
    { 
		if ((Uint8)temp8 == frameSize)
		{
			frameType = VOICE;
		}
		else if (temp8 == 1)
		{
			frameType = SID;
		}
		else if (temp8 == 0)
		{
			frameType = UNTX;
		}
		else
		{
			frameType = REPT;
		}

		switch(frameType)
		{
			case UNTX:
			{
				noise_gen(gain, output, frameSize);
				break;
			}
			case SID:
			{
				fread(&noiseLevel, sizeof(Int8), 1, fpIn);
				gain = sid_dec(noiseLevel);
				noise_gen(gain, output, frameSize);
				break;
			}
			case VOICE:
			{
				fread(charBuf, sizeof(Int8), frameSize, fpIn);
				ulaw_expand(frameSize, charBuf, output);
				break;
			}
			case REPT:
			{
				// Repeat previous one
				break;
			}
			default:
				break;
		}
 
		for (j=0, i=0; i<frameSize; i++)
		{
			charBuf[j++] = output[i]&0xff;
			charBuf[j++] = output[i]>>8;
		}
		fwrite(charBuf, sizeof(Int8), frameSize<<1, fpOut);    // Save PCM data

        n += frameSize;
        printf("%ld data words processed\n", n);
    }

    wHeaderUpdate(waveHeader, HZ8k, n<<1, DATASIZE);
    rewind(fpOut);
    fwrite(waveHeader, sizeof(Int8), 44, fpOut);

    fclose(fpOut);
    fclose(fpIn);
    printf("Exp --- completed\n");
}

// Update the wave file header
void wHeaderUpdate(Uint8 *w, Uint32 hz, Uint32 bytes, Uint8 dataSize)
{
	Uint32 t;

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
	t = hz;
	w[24] = (t>>0)&0xff;	// Set up output file frequency
	w[25] = (t>>8)&0xff;
	w[26] = (t>>16)&0xff;
	w[27] = (t>>24)&0xff;
	t = (hz*dataSize)>>3;
	w[28] = (t>>0)&0xff;	// Set up output file byte rate
	w[29] = (t>>8)&0xff;
	w[30] = (t>>16)&0xff;
	w[31] = (t>>24)&0xff;

	return;
}

