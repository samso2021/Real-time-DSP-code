/*
 * floatPoint_mdct.c
 *
 *  Created on: Oct 26, 2012
 *      Author: BLEE
 *
 *  Description: This program calculates direct MDCT and inverse MDCT
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include "tistdtypes.h"
#include "floatPoint_mdct.h"

float win[FRAME];
float cos_enc[FRAME>>1][FRAME];
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
    float acc0;

    for (j=0; j<N/2; j++)                        // Calculate N/2 MDCT coefficients
    {
      acc0 = 0.0; 
      for (k = 0; k<N; k++)                      // Calculate j coefficient
      {
        acc0 += in[k]*(float)win[k] * cos_enc[j][k];
      }
      out[j] = float2short(acc0);                // Convert j coefficient to 16-bit word
    }
}


/*------------------------------------------------------------------*/
/*                                                                  */
/*    Function: Calculation of the inverse MDCT                     */
/*                                                                  */
/*------------------------------------------------------------------*/

void inv_mdct(Int16 *in, Int16  *out, Int16 N)
{
    Int16   j,k;
    float   acc0;

    for(j= 0;j<N;j++)
    {
        acc0 = 0.0;
        for(k=0;k<N/2;k++)  			// Calculate the j component
        {
          acc0 += (float)in[k] * cos_dec[((2*j+1+N/2)*(2*k+1))%(4*N)];
        }
        acc0 = acc0 * win[j];			// Windowing
        out[j] = float2short(acc0);             // Convert to 16 bit word
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
