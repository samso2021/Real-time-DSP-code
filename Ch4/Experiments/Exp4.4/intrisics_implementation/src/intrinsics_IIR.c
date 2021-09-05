/*
* intrinsics_IIR.c
*
*  Created on: May 25, 2012
*      Author: BLEE
*
*  Description: Implementation of direct form-II IIR filter using intrinsics
*
*  For the book "Real Time Digital Signal Processing:
*                Fundamentals, Implementation and Application, 3rd Ed"
*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
*                Publisher: John Wiley and Sons, Ltd
*
*    intrinsics_IIR.c - IIR direct form II biquads implementation
*    prototype: void intrinsics_IIR(Int16 *, Int16, Int16 *, float *, Int16, float *);
*
*    Entry: arg0: pointer to the input sample buffer
*           arg1: size of the input sample buffer
*           arg2: pointer to the output sample buffer
*           arg3: pointer to the coefficients array
*           arg4: number of second-order IIR sections
*           arg5: pointer to the filter delay-line buffer
*
*    Return: None
*/

#include "tistdtypes.h"
#include <intrindefs.h>
#include "intrinsics_IIR.h"

void intrinsics_IIR(Int16 *x, Int16 Nx, Int16 *y, Int16 *coef, Int16 Ns, Int16 *w)
{      
    Int16 i,j,n,m,l,s;
    Int16 temp16;
    Int32 w_0;
        
    m=Ns*5;                            // Setup for circular buffer coef[]  
    s=Ns*2-1;                          // Setup for circular buffer w[]  

    for (j=0,l=0,n=0; n<Nx; n++)       // IIR filter begin 
    {
        w_0 = (Int32)x[n]<<12;         // Scale input to prevent overflow
        for (i=0; i<Ns; i++)
        {
            w_0 = _smas(w_0,*(w+l),*(coef+j)); j++; l=(l+Ns)&s;
            w_0 = _smas(w_0,*(w+l),*(coef+j)); j++; 

            temp16 = *(w+l);
            *(w+l) = (Int16)(w_0>>15); // Save in Q15

            w_0 = _lsmpy(   temp16,*(coef+j)); j++; 
            w_0 = _smac(w_0,*(w+l),*(coef+j)); j++; l=(l+Ns)&s; 
            w_0 = _smac(w_0,*(w+l),*(coef+j)); j=(j+1)%m; l=(l+1)&s;
		}
        y[n] = (Int16)(w_0>>12);       // Q15 format output
    }
}
