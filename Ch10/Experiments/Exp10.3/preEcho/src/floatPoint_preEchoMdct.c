/*
 * floatPoint_preEchoMdct.c
 *
 *  Created on: Oct 26, 2012
 *      Author: BLEE
 *
 *  Description: This program calculate floating-point MDCT/IMDCT
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include <math.h>
#include "tistdtypes.h"
#include "floatPoint_preEcho.h"

float win[FRAME];
float cos_dec[4*FRAME];

static Int16 float2short(float acc0);

/*------------------------------------------------------------------*/
/*                                                                  */
/*    Function: Calculation of the direct MDCT                      */
/*                                                                  */
/*------------------------------------------------------------------*/

void mdct(Int16 *in, Int16 *out, Int16 N)
{
    Int16 k,j;
    float acc0, cosCoef;

    for (j=0; j<(N>>1); j++)
    {
      for ( acc0 = 0.0, k = 0; k < N; k++ )
      {
        cosCoef = ((float)cos((PI/(2*N))*(2*k+1+N/2)*(2*j+1))/(N/4));
        acc0 += win[k] * (float)in[k] * cosCoef;
      }
	  out[j] = float2short(acc0/4.0);         // Prevent overflow
    }
}

/*------------------------------------------------------------------*/
/*                                                                  */
/*    Function: Calculation of the inverse MDCT                     */
/*                                                                  */
/*------------------------------------------------------------------*/

void inv_mdct(Int16 *in, Int16 *out, Int16 N)
{
    Int16   j,k;
    float   acc0;
    Int32   index;

    for(j= 0;j<N; j++)
    {
        acc0 = 0.0;

        for(k=0;k<N/2;k++)
        {
          index = ((2*j+1+(N>>1))*(2*k+1))%(4*N); 
          index = (index+4*N)%(4*N);              // Prevent negative
          acc0 += (float)in[k] * (float)cos_dec[index];
        }
        acc0 = acc0 * win[j];
        out[j] = float2short(acc0*4.0);
    }
}

static Int16 float2short(float acc0)
{
	Int16 temp16;
	
	if (acc0 >=0) 
	{
	  acc0 +=0.5;
	}
	else 
	{
	  acc0 -=0.5;
    }
    if (acc0 > 32767.0) 
    {
      temp16 = (Int16)32767;
    }
    else if (acc0 < -32768.0) 
    {
      temp16 = (Int16)-32768;
    }
    else
    {
      temp16 = (Int16) acc0 ;
    }
	return (temp16);
}
