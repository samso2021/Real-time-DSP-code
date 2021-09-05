/*
 * gFilter.c
 *
 *  Created on: Jul 15, 2012
 *      Author: BLEE
 *
 *  Description: C program of the Goertzel algorithm filter
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include "dtmfDetect.h"

void gFilter (Int16 *d, Int16 in, Int16 coef)
{
	Int32 AC0;

	d[0]  = in >> 7;    // Get input with scale down by 7 bit
    AC0   = (Int32) d[1] * coef;
	AC0 >>= 14; 
    AC0  -= d[2];
	d[0] += (Int16)AC0;

	d[2] = d[1];        // Update the delay line
	d[1] = d[0]; 

} 



