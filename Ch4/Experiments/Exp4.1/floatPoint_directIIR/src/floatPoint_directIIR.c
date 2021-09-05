/*
* floatPoint_directIIR.c
*
*  Created on: May 25, 2012
*      Author: BLEE
*
*  Description: This is the floating-point direct form-I IIR filter realization
*
*  For the book "Real Time Digital Signal Processing:
*                Fundamentals, Implementation and Application, 3rd Ed"
*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
*                Publisher: John Wiley and Sons, Ltd
*
*/

#include "tistdtypes.h"
#include "floatPointIIR.h"


void floatPoint_IIR(double in, double *x, double *y, double *b, short nb, double *a, Int16 na)
{
    double z1,z2;
    Int16 i;

    for(i=nb-1; i>0; i--)         // Update the delay line x[]
    {
        x[i] = x[i-1];
    }
    x[0] = in;                    // Insert new data to delay line x[0]

    for(z1=0, i=0; i<nb; i++)     // Filter the x[] with coefficient b[]
    {
        z1 += x[i] * b[i];
    }
	
    for(i=na-1; i>0; i--)         // Update the y delay line
    {
        y[i] = y[i-1];
    }

    for(z2=0, i=1; i<na; i++)     // Filter the y[] with coefficient a[]
    {
        z2 += y[i] * a[i];
    }
    y[0] = z1 - z2;               // Place the result into y[0]

}
