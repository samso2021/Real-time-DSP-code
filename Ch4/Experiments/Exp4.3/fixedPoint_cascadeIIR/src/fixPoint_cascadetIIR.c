/*
* fixPoint_cascadeIIR.c
*
*  Created on: May 25, 2012
*      Author: BLEE
*
*  Description: This is the fixed-point IIR filter in direct form-II realization
*
*  For the book "Real Time Digital Signal Processing:
*                Fundamentals, Implementation and Application, 3rd Ed"
*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
*                Publisher: John Wiley and Sons, Ltd
*
*    fixPoint_cascadeIIR.c - IIR direct form II biquads implementation
*    prototype: void cascadeIIR(Int16 *, Int16, Int16 *, float *, Int16, float *);
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

void cascadeIIR(Int16 *x, Int16 Nx, Int16 *y, Int16 *coef, Int16 Ns, Int16 *w)
{      
    Int16 i,j,n,m,l,s;
    Int16 temp16;
    Int32 w_0, temp32;
        
    m=Ns*5;                            // Setup for circular buffer coef[]  
    s=Ns*2;                            // Setup for circular buffer w[]  

    for (j=0,l=0,n=0; n<Nx; n++)       // IIR filter begin 
    {
        w_0 = (Int32)x[n]<<12;         // Scale input to prevent overflow
        for (i=0; i<Ns; i++)
        {
            temp32 = (Int32)(*(w+l)) * *(coef+j); j++; l=(l+Ns)%s;
            w_0   -= temp32<<1;
            temp32 = (Int32)(*(w+l)) * *(coef+j); j++;
            w_0   -= temp32<<1;
            w_0   += 0x4000;           // Rounding

            temp16 = *(w+l);
            *(w+l) = (Int16)(w_0>>15); // Save in Q15
 
            w_0    = (Int32)temp16 * *(coef+j); j++;
            w_0  <<= 1;
            temp32 = (Int32)*(w+l) * *(coef+j); j++; l=(l+Ns)%s;
            w_0   += temp32<<1;
            temp32 = (Int32)*(w+l) * *(coef+j); j=(j+1)%m; l=(l+1)%s;
            w_0   += temp32<<1;
            w_0   += 0x800;            // Rounding
        }
        y[n] = (Int16)(w_0>>12);       // Output in Q15 format
    }
}
