/*
 * mixed_vad_ss.c
 *
 *  Created on: Dec 5, 2012
 *      Author: BLEE
 *
 *  Description: This is the pre-VAD program for VAD experiment
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
*
***************************************************************/

#include <gsm.h>
#include "tistdtypes.h"
#include "mixed_vad.h"

Int16   inputbuf[LL/2]; 		 /* Input buffer */
Int16   HBV[LL/2];      		 /* Iinput buffer for previous frame */
Int16   DV[LL/2];       		 /* Buffer used for overlap */
Int16   window[LL/2];   		 /* Window coefficients */
complex D[LL];          		 /* Buffer used to store complex data */
complex U[LL];          		 /* Twiddle e^(-j2pi/N) table */

#define FFT_FLAG        1        /* perform FFT */
#define IFFT_FLAG       0        /* perform IFFT */
#define SCALE_FLAG      1        /* scale FFT butterfly output */
#define NOSCALE_FLAG    0        /* not to scale FFT butterfly output */

#pragma DATA_SECTION(inputbuf, ".bss:buffer");
#pragma DATA_SECTION(D,        ".bss:buffer");
#pragma DATA_SECTION(U,        ".bss:buffer");
#pragma DATA_SECTION(HBV,      ".bss:buffer");
#pragma DATA_SECTION(DV,       ".bss:buffer");
#pragma DATA_SECTION(window,   ".bss:buffer");

Int16 vad_pre(Int16 *inputbuf, Int16 L, Int16 N, Int16 *pwindow)
{
	Int16 k,VAD;

    for (k=0;k<N;k++)
    {
        D[k].re = HBV[k];          /* Load the first L/2 complex data */
        D[k].im = 0;
        D[k+N].re = inputbuf[k];   /* Load the second L/2 complex data */
        D[k+N].im = 0;
    }

    for (k=0;k<N;k++)              /* Performing Hanning window */
    {
        D[k].re = mult_r(D[k].re,  pwindow[k]);
        D[L-k-1].re = mult_r(D[L-k-1].re, pwindow[k]);
    }
        
    bit_rev(D, EXP);                  /* Arrange D[] in bit-reverse order */
    fft(D,EXP,U,FFT_FLAG,SCALE_FLAG); /* Perform FFT with scale */
    VAD = vad();                      /* Determine and return VAD */
    
    return(VAD);
}

