/*
 * g711Test.c
 *
 *  Created on: Nov 4, 2012
 *      Author: BLEE
 *
 *  Description: This is the test program for ITUT G.711 experiment
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
#include "g711.h"

#define	FRAMESIZE	256

Int16 input[FRAMESIZE];
Int16 output[FRAMESIZE];
Int8  charBuf[2*FRAMESIZE];
Uint8 waveHeader[44];

void wHeader(Uint8 *w, float f1, float f2, Uint32 bytes);


void main(void)
{
    FILE    *fpIn,*fpOut,*fpCod;     // Input and output file pointers
    Int16   i;
    Uint32  n;

    if ((fpIn = fopen("..//data//c55DSPAudioTest.wav","rb")) == NULL )
    {
        printf("Can't open input file\n");
        exit(0);
    }
    fpCod = fopen("..//data//g711Compressed.cod","wb");
    fpOut = fopen("..//data//g711Expanded.wav","wb");

    printf("Exp --- G.711 experiment\n");
    n = 0;

    fread(waveHeader, sizeof(Int8), 44, fpIn);
    fwrite(waveHeader,sizeof(Int8), 44, fpOut);

    while(fread(charBuf, sizeof(Int8), FRAMESIZE*2, fpIn) == FRAMESIZE*2)
    {
        for (i=0;i<FRAMESIZE;i++)           			// Get PCM input data
        {
            input[i] = (charBuf[2*i]&0xFF)|(charBuf[2*i+1]<<8);
        }

        ulaw_compress(FRAMESIZE, input, charBuf);

        fwrite(charBuf,sizeof(Int8),FRAMESIZE*2,fpCod); // Save G711 codec bits

        ulaw_expand(FRAMESIZE, charBuf, output);

        for (i=0;i<FRAMESIZE;i++)           			// Get PCM input data
        {
        	charBuf[2*i] = input[i]&0xFF;
        	charBuf[2*i+1] = (input[i]>>8)&0xFF;
        }
        fwrite(charBuf,sizeof(Int8),FRAMESIZE*2,fpOut);	// Save G711 decoded PCM

        n += FRAMESIZE;
        printf("%ld data words processed\n", n);
    }

    wHeader(waveHeader, 8000, 8000, n<<1);
    rewind(fpOut);
    fwrite(waveHeader, sizeof(Int8), 44, fpOut);

    fclose(fpOut);
    fclose(fpCod);
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

