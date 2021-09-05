/*
 * float_lms.c
 *
 *  Created on: June 5, 2012
 *      Author: BLEE
 *
 *  Description: This is the floating-point adaptive LMS program
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#include "tistdtypes.h"
#include "float_lms.h"

void float_lms(LMS *lmsObj)
{ 
    LMS    *lms=(LMS *)lmsObj;
    double *w,*x,y,ue;
    Int16  j,n;

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
    y = 0.0; 
    for(j=0; j<n; j++)
    {
        y += w[j] * x[j];
    }
    lms->out = y;

    // Compute error term
    lms->err = lms->des - y;

    // Update coefficients 
    ue = lms->err * lms->mu; 
    for(j=0; j<n ; j++)
    {
        w[j] += ue * x[j];
    }
}


