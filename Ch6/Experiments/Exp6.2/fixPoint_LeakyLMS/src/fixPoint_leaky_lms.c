/*
 * fixPoint_leaky_lms.c
 *
 *  Created on: June 5, 2012
 *      Author: BLEE
 *
 *  Description: This is the fixed-point leaky LMS algorithm implementation
 *
 *               The input is a 1kHz sine wave sampling rate 8kHz with noise
 *               The output is the sine wave
 *               The error is the noise
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#include "tistdtypes.h"
#include "fixPoint_leaky_lms.h"

void fixPoint_leaky_lms(LMS *lmsObj)
{ 
	LMS    *lms=(LMS *)lmsObj;
	Int32   ue,temp32;
    Int16  j,n;
    Int16  *x,*w;
	
	n = lms->order;
    w = &lms->w[0];
	x = &lms->x[0];

    // Update data delay line
    for(j=n-1; j>0; j--)
	{
        x[j] = x[j-1];
	}
    x[0] = lms->in;
    
	// Get adaptive filter output
	temp32 = (Int32)w[0] * x[0];
    for(j=1; j<n; j++)
	{
        temp32 += (Int32)w[j] * x[j];
    }
	lms->out = (Int16)((temp32+ROUND)>>15);

	// Compute error term
    lms->err = lms->des - lms->out;

	// Coefficients update
	ue = (Int32)(((lms->err * (Int32)lms->mu)+ROUND)>>15);
    for(j=0; j<n ; j++)
	{
	    temp32 = (((Int32)lms->leaky * w[j])+ROUND)>>15;
        w[j] = (Int16)temp32 + (Int16)(((ue * x[j])+ROUND)>>15);
    }
}

