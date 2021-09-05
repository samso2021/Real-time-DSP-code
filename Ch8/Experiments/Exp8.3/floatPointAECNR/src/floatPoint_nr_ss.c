/*
 * floatPoint_nr_ss.c
 *
 *  Created on: Oct 26, 2012
 *      Author: BLEE
 *
 *  Description: This is the spectrum subtraction window and FFT functions
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

/***************************************************************
*      Spectral Subtraction
*
*         |---------|    |-----|
*  x(n)-->|windowing|-|->| FFT |-----|-------|----------|
*         |---------| |  |-----|     |       |          |
*                     |              |    |-----| speech|
*                    (a)..................| VAD |.......\
*                     |   noise      |    |-----|       |
*                     |              |                  |
*                     |          |-------|        |-----------|
*                     |          | Phase |        | spectral  |
*                     |          |-------|        |subtraction|
*                     |              |            |-----------|
*         |--------|  |   |------|   |                  |
*  x(n)<--| overlap|<-|---| IFFT |<----------------------
*         |--------|      |------|
*
*    a. Using modified algorithm for speech detection
*    b. Noise spectrum is estimated during the silence frame
*    c. Attenuate noise frame in time domain
*    d. There is no signal spectral averaging
*
***************************************************************/

#include <math.h>
#include "tistdtypes.h"
#include "nr.h"

Int16 nr_ss(NR_VAR *pnr)
{
    Int16 k,L,N;
    Int16 *inputbuf;
    float *pwindow,*pHBV;

    NR_VAR *p = (NR_VAR *)pnr;

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

    nr_fft(p->D, p->L, FFT);                 // Performing FFT of input signal

    for (k=0; k<L;k++)                       // Scale down here
    {
        p->D[k].real = p->D[k].real/p->L;
        p->D[k].imag = p->D[k].imag/p->L;
    }

    for (k=0;k<=N;k++)                       // Compute magnitude spectrum
    {
        p->TB[k] = (float)(sqrt(p->D[k].real*p->D[k].real 
                 + p->D[k].imag*p->D[k].imag)+0.1);
    }

    return(nr_vad(pnr));
}

