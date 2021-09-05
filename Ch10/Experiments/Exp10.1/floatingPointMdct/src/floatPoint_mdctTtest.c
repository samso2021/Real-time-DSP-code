/*
 * floatPoint_mdctTest.c
 *
 *  Created on: Oct 26, 2012
 *      Author: BLEE
 *
 *  Description: This is the test program for floating-point MDCT/IMDCT experiment
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
#include "floatPoint_mdct.h"

/**********************************************************************
 Test for N-point MDCT with direct or inverse MDCT
 with 50% overlap
 **********************************************************************/
Int16  pcm_data_in[FRAME];        // 16 bit pcm data input
Int16  mdct_enc16[FRAME>>1];      // 16 bit MDCT coefficients
Int16  mdct_proc[FRAME];          // 16 bit processed data
static Int16 prevblck[FRAME];     // 16 bit processed data
Int16  tempOut[FRAME>>1];         //  point data
Int8   temp[2*FRAME];
Uint8  waveHeader[44];

void wHeader(Uint8 *w, float f1, float f2, Uint32 bytes);

void main(void)
{
    Int16  j,M,init,c;
    FILE   *f_org;                  // File of input speech data
    FILE   *f_enc;                  // File of serial (coded bits) for transmission
    FILE   *f_prc;                  // File of inverse MDT data output
    Uint32 cnt;

    //  Open data files
    printf("Enter 1 for using PCM file, enter 2 for using WAV file\n");
    scanf ("%d", &c);

    if (c == 2)
    {
    	f_org = fopen("..\\data\\input.wav", "rb");
    	f_prc = fopen("..\\data\\MdctProc.wav", "wb");
    }
    else
    {
    	f_org = fopen("..\\data\\input.pcm", "rb");
    	f_prc = fopen("..\\data\\MdctProc.pcm", "wb");
    }

    if (f_org== NULL)
    {
        printf("Can't open input speech data file\n");
        exit(0);
    }
    f_enc = fopen("..\\data\\EncOutput.cod", "wb");

    if (c == 2)
    {
      fread(waveHeader, sizeof(Int8), 44, f_org);		// Advance input to speech data
      fwrite(waveHeader, sizeof(Int8), 44, f_prc);		// Write header for output file
    }

    for (j=0;j <FRAME; j++)
    {
        pcm_data_in[j] = 0;
        mdct_proc[j] = 0;
        prevblck[j] = 0;
    }
    for (j=0;j <(FRAME>>1); j++)
    {
    	mdct_enc16[j] = 0;
    }

    init = 0;
    M = FRAME>>1;                             			// Half of the frame length
    mdct_init(FRAME);

    printf("Exp --- floating-point MDCT/IMDCT experiment\n");
    cnt = 0;
    while (fread(temp, sizeof(Int8), 2*M, f_org) == (2*M))
    {
        for (j=0;j<M;j++)                       		// Get 16-bit PCM input
        {
            pcm_data_in[j+M] = (temp[2*j]&0xFF)|(temp[2*j+1]<<8);
        }
        
        mdct(pcm_data_in, mdct_enc16, FRAME);   		// Perform MDCT of N samples
    
        // Save latest subband samples to be used in the next MDCT call
        for (j=0; j<M; j++) 
        {
            pcm_data_in[j] = pcm_data_in[j+M];
        }

        for (j=0;j<M;j++) {
            temp[2*j] = (mdct_enc16[j]&0xFF);
            temp[2*j+1] = (mdct_enc16[j]>>8)&0xFF;
        }
        fwrite(temp, sizeof(Int8),(FRAME),f_enc);

        inv_mdct(mdct_enc16, mdct_proc, FRAME);  		// Inverse MDCT
        
        for(j=0; j<M; j++)                        		// Overlap addition
        {
          tempOut[j] = (Int16) mdct_proc[j] + (Int16)prevblck[j];
          prevblck[j] = mdct_proc[j+M];
        }
        
        for (j=0;j<M;j++) {                       		// Output the processed data
            temp[2*j] = (tempOut[j]&0xFF);
            temp[2*j+1] = (tempOut[j]>>8)&0xFF;
        }

        if (init !=0)
        {
            fwrite(temp, sizeof(Int8),FRAME,f_prc);
            cnt += M;
            printf("%ld data samples processed\n", cnt);
        }
        init = 1;
    }

    if (c == 2)		// Based on input WAVE file to generate output
    {
      wHeader(waveHeader, 8000, 8000, cnt<<1);
      rewind(f_prc);
      fwrite(waveHeader, sizeof(Int8), 44, f_prc);
    }

    fclose(f_org);
    fclose(f_enc);
    fclose(f_prc);
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
