/*
 * floatPoint_preEchoInit.c
 *
 *  Created on: Oct 26, 2012
 *      Author: BLEE
 *
 *  Description: This program initializes the floating-point MDCT/IMDCT/pre-echo experiment
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

void mdct_init(Int16 N)
{
    Int16   i;

    for ( i = 0; i < N; i++ )
    {
      win[i]=(float)sin(PI/N*(i+0.5));
    }

    
    for (i=0; i<4*N; i++)
    {
      cos_dec[i]=(float)cos(PI/(2*N)*i);
    }

#ifdef ENOUGH_MEM     
    for ( i = 0; i < N / 2; i++ )
    {
      for ( k = 0; k < N; k++ )
      {
        cos_enc[i][k]=(float)cos((PI/(2*N))*(2*k+1+N/2)*(2*i+1))/(N/4);
      }
    }
#endif

	QuantStep = (log10(32767.0)/(float)NUM_QNT );
}

