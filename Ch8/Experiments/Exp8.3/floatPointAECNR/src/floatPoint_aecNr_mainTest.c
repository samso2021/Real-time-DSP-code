/*
 * floatPoint_aecNr_mainTest.c
 *
 *  Created on: Oct 26, 2012
 *      Author: BLEE
 *
 *  Description: This is the test program for Leaky Normalized LMS based AEC with NR experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

//
/**************************************************************************
*  Real-time system configuration:
*
*                      ______________
*           farEndIn   |            |   speakerOut 
*           ---------->|            |------------->
*                      |            |
*                      |            |
*                      | Speakphone |
*                      |   System   |
*                      |            |
*           farEndOut  |            |  microphoneIn
*           <----------|            |<-------------
*                      |____________|
*
*  where
*    farEndIn is the received signal from far-end by telephone interface
*    farEndOut is the signal transmit to far-end by telephone interface
*    speakerOut is the signal send to drive loudspeaker in room
*    microphoneIn is the signal pickup by the microphone in room
*************************************************************************
*  Synopsis
*
*    This program is executed by keying in the following command:
*
*        aec.exe micFile farFile txFile <enter>
*
*    where
*      micFile  - file name of microphoneIn signal
*      farFile  - file name of signal receive from far-end, farEndIn
*      txFile   - file name of signal transmit to far-end, farEndOut
*
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tistdtypes.h"
#include "aec.h"
#include "nr.h"

#define  NUM_DATA  256

AEC_STR  aec;
NR_VAR   nrvar;
NR_VAR   *pnr;

Int8  temp1[NUM_DATA*2];
Int8  temp2[NUM_DATA*2];
Int8  temp3[NUM_DATA*2];
Int16 input[NUM_DATA];
Uint8 waveHeader[44];

void wHeader(Uint8 *w, float f1, float f2, Uint32 bytes);

void main(void)
{
  Int16 farEndIn;          // New data from the far-end
  Int16 microphoneIn;      // Signal pick up by microphone
  Int16 i,j,count,c;
  Uint32 cnt;
  FILE  *farIn;            // File pointer of farEndIn signal
  FILE  *micIn;            // File pointer of microphoneIn signal
  FILE  *txOut;            // File pointer of farEndOut signal

  //  Open data files
  printf("Enter 1 for using PCM file, enter 2 for using WAV file\n");
  scanf ("%d", &c);;

  if (c == 2)
  {
	  micIn = fopen("..//data//mic.wav","rb");  // Open microphone signal file
	  farIn = fopen("..//data//far.wav","rb");  // Open far-end speech file
	  txOut = fopen("..//data//out.wav","wb");  // Open AEC output file
  }
  else
  {
	  micIn = fopen("..//data//mic.pcm","rb");  // Open microphone signal file
	  farIn = fopen("..//data//far.pcm","rb");  // Open far-end speech file
	  txOut = fopen("..//data//out.pcm","wb");  // Open AEC output file
  }

  if (micIn== NULL)
  {
    printf("Can't open mic input file\n");
    exit(0);
  }     
  if (farIn == NULL)
  {
    printf("Can't open far-end input file\n");
    exit(0);
  } 

  if (c == 2)
  {
    fread(waveHeader, sizeof(Int8), 44, micIn);		// Advance to micIn data
    fread(waveHeader, sizeof(Int8), 44, farIn);		// Advance to farIn data
    fwrite(waveHeader, sizeof(Int8), 44, txOut);	// Put header for txOut
  }

  nrvar.L = 256;                         // Length of FFT
  nrvar.Atten = 0.1;                     // NR attenuation factor

  aec_param_init(&aec);                  // Initialization for AEC
  pnr = &nrvar;      
  nrvar.N = nrvar.L >> 1;                // Frame size = 1/2 window size
  nr_hwindow(pnr);                       // Generate Hanning window
  nrvar.pwindow = nrvar.window;
  nrvar.pIn = input;
  nr_init(pnr);                          // Initialization for NR
  count = 0;
  for(i=0; i<nrvar.L; i++)               // Zero data buffer
  {
    input[i] = 0;
  }

  printf("Exp ---- float-point ACE+NR\n");
  cnt = 0;
  while( (fread(temp1,sizeof(Int8),2*nrvar.L,farIn)==(2*nrvar.L))) // Read farEndIn
  {
    fread(temp2,sizeof(Int8),2*nrvar.L,micIn);	// Read microphoneIn
    for (i=0; i<2*nrvar.L; i+=2)
    {
      farEndIn     = (temp1[i]&0xFF)|(temp1[i+1]<<8);
      microphoneIn = (temp2[i]&0xFF)|(temp2[i+1]<<8);
		  
      for (j=0;j<nrvar.L-1;j++)                  // Buffer data for NR
	  {
		input[j] = input[j+1];
	  }
      input[j] = aecCalc(microphoneIn,farEndIn,&aec);

	  count++;                               
      if(count == nrvar.N)                       // Frame based noise reduction
	  {
		count = 0;
        nrvar.vadFlag = nr_ss(pnr);
        nr_proc(pnr);

		for (j=0; j<nrvar.N; j++)
		{
	      temp3[2*j]   = (input[j]&0xFF);
          temp3[2*j+1] = (input[j]>>8)&0xFF;
        }
        fwrite(temp3,sizeof(Int8),2*nrvar.N,txOut); // Write farEndOut
        cnt += nrvar.L;
        printf("%ld samples processed\n", cnt);
	  }
    }   
  }

  if (c == 2)		// Based on input WAVE file to generate output
  {
      wHeader(waveHeader, 8000, 8000, cnt);
      rewind(txOut);
      fwrite(waveHeader, sizeof(Int8), 44, txOut);
  }

  fclose(farIn);
  fclose(micIn);
  fclose(txOut);
  printf("Exp ---- completed\n");
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

