/*
 * asmDTMFDetTest.c
 *
 *  Created on: Jul 15, 2012
 *      Author: BLEE
 *
 *  Description: Test program for DTMF detection using Goertzel algorithm
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
#include "dtmfDetect.h"

#define FRAME       255
#define THRESHOLD (1<<8) 

Int16 d[8][3];
Int16 coef[8];
Int16 dtmfData[FRAME];
Int8  temp[FRAME*2];

void main(void)
{
  FILE    *fpIn,*fpOut;
  Int16   index,i,k,c;
  Int8    key[2],prevKey;
  char    n;

  printf("Use noisy data file?   Y or N\n");
  scanf ("%c", &n);

  printf("Enter 1 for using PCM input file, enter 2 for using WAV input file\n");
  scanf ("%d", &c);

  if (c == 2)
  {
    if ((n == 'Y')||(n =='y'))
      fpIn = fopen("..\\data\\DTMF_with_noise.wav", "rb");
    else
      fpIn = fopen("..\\data\\DTMF16digits.wav", "rb");
  }
  else
  {
    if ((n == 'Y')||(n =='y'))
      fpIn = fopen("..\\data\\DTMF_with_noise.pcm", "rb");
    else
      fpIn = fopen("..\\data\\DTMF16digits.pcm", "rb");
  }
  // Open file for read input data
  if (fpIn == NULL)
  {
      printf("Can't open input data file\n");
      exit(0);
  }

  if (c == 2)				// Skip WAVE data file header
  {
  	fread(temp, sizeof(Int8), 44, fpIn);
  }

  fpOut = fopen("..\\data\\DTMFKEY.txt","w");
  fprintf(fpOut,"DTMF keys detected: ");
  
  // Variable and coefficients initialization
  init(&d[0][0], coef);
  prevKey = 0;
  
  printf("Exp7.5 - DSP assembly function based DTMF detection\n DTMF digits detected: ");
  // Start the experiment
  while( fread(temp,sizeof(Int8),FRAME*2,fpIn)==(FRAME*2))
  {
	// Get input data
	for(k=0, i=0; i<FRAME; i++)
	{
      dtmfData[i] = temp[k]|temp[k+1]<<8;
	  k += 2;
	}

    // Goertzel frequency computation
    dtmfFreq(dtmfData, &d[0][0], coef, FRAME);

	// Goertzel frequency detection
	index = 0;
	gFreqDetect(&index, &d[0][0], coef, THRESHOLD);

    // Decode DTMF key entered 
    checkKey(key, index);                
	
	// Record the keys pressed  
    if (key[0] != prevKey)
	{
      fprintf(fpOut,"%s ", key);
      prevKey = key[0];
      printf("%s ", key);
    }
  }  

  fclose(fpIn);
  fclose(fpOut);
  printf("\nExp --- completed\n");

}
    




