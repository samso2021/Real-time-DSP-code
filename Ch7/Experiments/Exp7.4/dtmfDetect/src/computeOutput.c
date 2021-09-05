/*
 * computeOutput.c
 *
 *  Created on: Jul 15, 2012
 *      Author: BLEE
 *
 *  Description: C program to compute DTMF decode output
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include "dtmfDetect.h"

Int16 computeOutput(Int16 *d, Int16 coef)
{
  Int32 AC0, AC1;
  Int16 out;
 
  AC0  = (Int32) d[1] * d[1];  // Square d[1]
  AC0 += (Int32) d[2] * d[2];  // Add square d[2]
  AC1  = (Int32) d[1] * coef;
  AC1 >>= 14;
  AC1  = AC1 * d[2]; 
  AC0 -= AC1;
  out  = (Int16)(AC0 >> 14);
 
  d[1] = 0;
  d[2] = 0;
		 
  return (out);
}


