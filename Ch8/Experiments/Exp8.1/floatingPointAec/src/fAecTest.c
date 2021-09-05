/*
 * fAecTest.c
 *
 *  Created on: Aug 4, 2012
 *      Author: BLEE
 *
 *  Description: This is the test program for floating-point AEC experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

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
#include "tistdtypes.h"
#include "fAec.h"

#define NUM_DATA  1024

AEC_STR aec;

Int8  temp1[NUM_DATA*2];
Int8  temp2[NUM_DATA*2];
Uint8 waveHeader[44];

void wHeader(Uint8 *w, float f1, float f2, Uint32 bytes);

void main(void)
{
  Int16 farEndIn;         // New data from the far-end
  Int16 outaec;
  Int16 microphoneIn;     // Signal pick up by microphone
  Int16 i,c;
  Uint32 cnt;
  FILE *farin;            // File pointer of farEndIn signal
  FILE *micin;            // File pointer of microphoneIn signal
  FILE *txout;            // File pointer of farEndOut signal

  //  Open data files
  printf("Enter 1 for using PCM file, enter 2 for using WAV file\n");
  scanf ("%d", &c);;

  if (c == 2)
  {
    micin = fopen("..\\data\\rtmic.wav","rb");	// Open microphone signal file
    farin = fopen("..\\data\\rtfar.wav","rb");	// Open far-end speech file
    txout = fopen("..\\data\\aecout.wav","wb");	// Open AEC output data file for evaluation
  }
  else
  {
    micin = fopen("..\\data\\rtmic.pcm","rb");	// Open microphone signal file
    farin = fopen("..\\data\\rtfar.pcm","rb");	// Open far-end speech file
    txout = fopen("..\\data\\aecout.pcm","wb");	// Open AEC output data file for evaluation
  }

  if (micin == NULL)
  {
    printf("Can't open input mic input file\n");
    exit(0);
  }
  if (farin == NULL)
  {
    printf("Can't open input far-end input file\n");
    exit(0);
  }

  if (c == 2)
  {
    fread(waveHeader, sizeof(Int8), 44, micin);		// aAdvance to micin data
    fread(waveHeader, sizeof(Int8), 44, farin);		// Advance to farin data
    fwrite(waveHeader, sizeof(Int8), 44, txout);	// Put header for txout
  }
  
  printf("Exp --- floating-point C AEC\n");

  // Initialization
  aec_param_init(&aec);
  cnt = 0;

  while( (fread(temp1,sizeof(Int8),2*NUM_DATA,farin)) == 2*NUM_DATA) // Read farEndIn
  {
    fread(temp2,sizeof(Int8),2*NUM_DATA,micin);                      // Read microphoneIn
    
    for (i=0; i<2*NUM_DATA; i+=2)
    {
      farEndIn = (temp1[i]&0xFF)|(temp1[i+1]<<8);
      microphoneIn = (temp2[i]&0xFF)|(temp2[i+1]<<8);
		
      outaec = aecCalc(microphoneIn,farEndIn,&aec);

      temp1[i] = (outaec&0xFF);
      temp1[i+1] = (outaec>>8)&0xFF;
    }
    cnt += NUM_DATA;
    
    fwrite(temp1,sizeof(Int8),2*NUM_DATA,txout);     // Write farEndOut
    printf("%ld data samples processed\n", cnt);
  }

  if (c == 2)		// Based on input WAVE file to generate output
  {
    wHeader(waveHeader, 8000, 8000, cnt<<1);
    rewind(txout);
    fwrite(waveHeader, sizeof(Int8), 44, txout);
  }

  fclose(farin);
  fclose(micin);
  fclose(txout);
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
