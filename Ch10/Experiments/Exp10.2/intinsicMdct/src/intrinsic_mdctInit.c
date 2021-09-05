/*
 * intrinsic_mdctInit.c
 *
 *  Created on: Oct 26, 2012
 *      Author: BLEE
 *
 *  Description: This program performs Initialization for MDCT and inverse MDCT experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include <math.h>
#include "tistdtypes.h"
#include "intrinsic_mdct.h"

void mdct_init(Int16 N)
{
    Int16 i,k;
    
    for (i = 0; i < N; i++)
    {
      win[i] = (Int16)(0.5+32767.0*sin( PI/N * (i + 0.5) ));
    }
    for ( i = 0; i < N / 2; i++ )
    {
      for ( k = 0; k < N; k++ )
      {
        cos_enc[i][k]=(Int16)(0.5+32767.0*cos((PI/(2*N))*(2*k+1+N/2)*(2*i+1))/(N/4));
      }
    }
    for (i=0; i<4*N; i++)
    {
      cos_dec[i] = (Int16)(0.5+32767.0*cos(PI/(2*N)*i));
    }
}

