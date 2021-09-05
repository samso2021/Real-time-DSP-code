/*
 * floatPoint_aec_util.c
 *
 *  Created on: Oct 26, 2012
 *      Author: BLEE
 *
 *  Description: This file contains the support functions for Leaky Normalized LMS based AEC
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

/**************************************************************************
*  URAN - This function generates pseudo-random numbers                   *
**************************************************************************/
#include "tistdtypes.h"

static  Int32  n = (Int32)12357;   // Seed I(0) = 12357
float uran(void)
{
  Int16 ran;                     // Random noise r(n)
    
  n = 2045*n;                    // I(n) = 2045 * I(n-1) + 1
  n = n&0xFFFFF000;              // I(n) = I(n) - INT[I(n)/1048576] * 1048576
  ran = (Int16)(n>>20);          // r(n) = FLOAT[I(n) + 1] / 1048577
  return ((float)ran / 32767.0); // Return r(n) to main function
  
}

/**************************************************************************
*  SHIFT - This function updates signal vector                            *
*          data stored as [x(n)  x(n-1) ... x(n-N+1)]                     *
**************************************************************************/
void  shift(float *x, Int16 N, float newSample)
{
  Int16 i;                    // Index
  for (i=N-1; i>0; --i)
  {
    x[i] = x[i-1];            // Shift old data x(n-i), i = 1, 2, ... N-1
  }
  x[0] = (float)newSample;    // Insert new data x(n)
}

/**************************************************************************
*  FIR - This function performs FIR filtering                             *
*          ntap-1                                                         *
*    y(n) = sum  wi * x(n-i)                                              *
*           i=0                                                           *
**************************************************************************/
float fir(float *x, float *w, Int16 ntap)
{
  float yn;                    // Output of FIR filter
  Int16 i;                     // Index

  yn = 0.0;                    // y(n) = 0.
  for (i=0; i<ntap; ++i)
  {
    yn += w[i]*x[i];           // FIR filtering of x(n) to get y(n)
  }
  return(yn);                  // Return y(n) to main function
}

