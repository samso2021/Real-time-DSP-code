/*
* fixPoint_directIIR.c
*
*  Created on: May 25, 2012
*      Author: BLEE
*
*  Description: This is the fixed-point IIR filter in direct form-I realization
*
*  For the book "Real Time Digital Signal Processing:
*                Fundamentals, Implementation and Application, 3rd Ed"
*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
*                Publisher: John Wiley and Sons, Ltd
*
*/

#include "tistdtypes.h"
#include "fixPointIIR.h"


void fixPoint_IIR(Int16 in, Int16 *x, Int16 *y, Int16 *b, Int16 nb, Int16 *a, Int16 na)
{
    Int32 z1,z2;
    Int16 i;

    for(i=nb-1; i>0; i--)         // Update the delay line x[]
    {
        x[i] = x[i-1];
    }
    x[0] = in;                    // Insert new data to delay line x[0]

    for(z1=0, i=0; i<nb; i++)     // Filter the x[] with coefficient b[]
    {
        z1 += (Int32)x[i] * b[i];
    }
	
    for(i=na-1; i>0; i--)         // Update the y delay line
    {
        y[i] = y[i-1];
    }
    
    for(z2=0, i=1; i<na; i++)     // Filter the y[] with coefficient a[]
    {
        z2 += (Int32)y[i] * a[i];
    }

    z1 = z1 - z2;                 // Q15 data filtered using Q11 coefficients
    z1 += 0x400;                  // Rounding
    y[0] = (Int16)(z1>>11);       // Place the Q15 result into y[0]
}
