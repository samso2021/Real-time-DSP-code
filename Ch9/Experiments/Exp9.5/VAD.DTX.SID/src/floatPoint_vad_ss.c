/*
 * floatPoint_vad_ss.c
 *
 *  Created on: Sep 11, 2012
 *      Author: BLEE
 *
 *  Description: This function performs spectrum component calculation
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include <math.h>
#include "tistdtypes.h"
#include "floatPoint_vad.h"

Int16 vad_ss(VAD_VAR *pvad)
{
    Int16 k,L,N;
    Int16 *inputbuf;
    float *pwindow,*pHBV;

    VAD_VAR *p = (VAD_VAR *)pvad;

    inputbuf = p->pIn;
    L = p->L;
    N = p->N;
    pwindow = p->pwindow;
    pHBV = p->HBV;

    for (k=0;k<N;k++)
    {
        p->D[k].real = *pHBV++;               // Load the first L/2 complex data
        p->D[k].imag = 0.0;
        p->D[k+N].real = (float) *inputbuf++; // Load the second L/2 complex data
        p->D[k+N].imag = 0.0;
    }

    for (k=0;k<N;k++)                         // Performing Hanning window
    {
        p->D[k].real *= *pwindow;
        p->D[L-k-1].real *= *pwindow++;
    }

    vad_fft(p->D, p->L, FFT);                // Performing FFT of input signal

    for (k=0; k<L;k++)                       // Scale down here
    {
        p->D[k].real = p->D[k].real/p->L;
        p->D[k].imag = p->D[k].imag/p->L;
    }

    for (k=0;k<=N;k++)                        // Compute magnitude spectrum
    {
        p->TB[k] = (float)(sqrt(p->D[k].real*p->D[k].real 
                 + p->D[k].imag*p->D[k].imag)+0.1);
    }

    return(vad_vad(pvad));
}

