/*
 * fixPoint_nlmsTest.c
 *
 *  Created on: Aug 4, 2012
 *      Author: BLEE
 *
 *  Description: This is the test program for fixed-point AEC experiment
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
#include "fixPoint_nlms.h"

#define NUM_DATA  1024

Int8  temp1[NUM_DATA*2];
Int8  temp2[NUM_DATA*2];
Uint8 waveHeader[44];

LMS lmsObj;
LMS *lms = &lmsObj;
DTALK dtObj;
DTALK *dt = &dtObj;

Int16 w[L+1];
Int16 x[L+1];

void wHeader(Uint8 *w, float f1, float f2, Uint32 bytes);

void main()
{  
    Int16  i,c;
    FILE   *fpIn,*fpDes,*fpErr;
    Uint32 cnt;

    //  Open data files
    printf("Enter 1 for using PCM file, enter 2 for using WAV file\n");
    scanf ("%d", &c);;

    if (c == 2)
    {
      fpDes = fopen("..\\data\\rtmic.wav","rb");	// Open microphone signal file
      fpIn = fopen("..\\data\\rtfar.wav","rb");		// Open far-end speech file
      fpErr = fopen("..\\data\\aecout.wav","wb");	// Open AEC output data file for evaluation
    }
    else
    {
      fpDes = fopen("..\\data\\rtmic.pcm","rb");	// Open microphone signal file
      fpIn = fopen("..\\data\\rtfar.pcm","rb");		// Open far-end speech file
      fpErr = fopen("..\\data\\aecout.pcm","wb");	// Open AEC output data file for evaluation
    }

    if (fpDes == NULL)
    {
      printf("Can't open input mic input file\n");
      exit(0);
    }
    if (fpIn == NULL)
    {
      printf("Can't open input far-end input file\n");
      exit(0);
    }

    if (c == 2)
    {
      fread(waveHeader, sizeof(Int8), 44, fpDes);		// Advance to fpDes data
      fread(waveHeader, sizeof(Int8), 44, fpIn);		// Advance to far-en data
      fwrite(waveHeader, sizeof(Int8), 44, fpErr);		// Put header for error
    }

    printf("Exp --- Intrinsic AEC\n");

    // Initialization
    aec_init(lms,dt);

    // Clear data and tap delay lines
    lms->w = w;
    lms->x = x;	

    for (i=0; i<=lms->order; i++)
    {
        lms->w[i] = 0;
        lms->x[i] = 0;
    }
    cnt = 0;
	
    // Filter test
    while ((fread(temp1, sizeof(Int8), 2*NUM_DATA, fpIn) == 2*NUM_DATA)&&
            (fread(temp2, sizeof(Int8), 2*NUM_DATA, fpDes)== 2*NUM_DATA) )
    {
        for (i=0; i<2*NUM_DATA; i+=2)
        {
            // Get 16-bit PCM input and desired data
            lms->in  = (temp1[i]&0xFF)|(temp1[i+1]<<8);
            lms->des = (temp2[i]&0xFF)|(temp2[i+1]<<8);

            // double_talk detector
            fixPoint_double_talk(dt,lms);
            // Filter the data
            fixPoint_nlms(dt,lms);
            // Non linear processing
            fixPoint_nlp(dt,lms);

            // Write the output and error data  to 16-bit PCM
            temp2[i] = (lms->err&0xFF);
            temp2[i+1] = (lms->err>>8)&0xFF;
        }
        cnt += NUM_DATA;
        fwrite(temp2, sizeof(Int8), 2*NUM_DATA, fpErr);
        printf("%ld data samples processed\n", cnt);
    }

    if (c == 2)		// Based on input WAVE file to generate output
    {
        wHeader(waveHeader, 8000, 8000, cnt<<1);
        rewind(fpErr);
        fwrite(waveHeader, sizeof(Int8), 44, fpErr);
    }

    fclose(fpIn);
    fclose(fpDes);
    fclose(fpErr);
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
