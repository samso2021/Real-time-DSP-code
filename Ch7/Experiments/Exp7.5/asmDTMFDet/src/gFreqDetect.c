/*
 * gFreqDetect.c
 *
 *  Created on: Jul 15, 2012
 *      Author: BLEE
 *
 *  Description: C program to detect DTMF frequencies
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include "dtmfDetect.h"

void gFreqDetect(Int16 *keyIndex, Int16 *d, Int16 *c, Int16 threshold)
{
	Int16 i,j;

  for (j=1, i=0; i<8; i++)
  {
    if (computeOutput(d, c[i]) > threshold)
	{
      *keyIndex |= j; 
	}
    else
	{
      *keyIndex &= ~j; 
	}  
	j <<= 1;
	d += 3;
  }
}
