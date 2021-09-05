/*
 * adaptiveEQ.c
 *
 *  Created on: Oct 20, 2012
 *      Author: BLEE
 *
 *  Description: This is a complex adaptive channel equalizer
 *               It uses simplified ITU V.29 9600 bps force training sequence
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#include "tistdtypes.h"
#include "complexEQ.h"
#include <gsm.h>

// 
// Adaptive channel equalizer
//
void equalizer(COMPLEX *rx, COMPLEX *out, COMPLEX *error)
{
	COMPLEX y,err;
    Int32   temp32,urer,urei,uier,uiei;
    Int16   j;
	
    // Update data delay line
    for(j=EQ_ORDER-1; j>0; j--)
	{
        x[j] = x[j-1];
	}
    x[0] = *rx;

	// Get the real adaptive filter output from complex symbols
    for(temp32=0, j=0; j<EQ_ORDER; j++)
	{
        temp32 = _smac(temp32, w[j].re, x[j].re);
        temp32 = _smas(temp32, w[j].im, x[j].im);
    }
    y.re = (Int16)(_rnd(temp32)>>15);

	// Get the image adaptive filter output from complex symbols
    for(temp32=0, j=0; j<EQ_ORDER; j++)
	{
        temp32 = _smac(temp32, w[j].im, x[j].re);
        temp32 = _smac(temp32, w[j].re, x[j].im);
    }
    y.im = (Int16)(_rnd(temp32)>>15);

	// Compute error term from complex data
    err.re = _ssub(rxDesire[txCnt].re, y.re);
    err.im = _ssub(rxDesire[txCnt++].im, y.im);

	// Coefficients update - using complex error and data
    urer = _lsmpy(err.re, mu.re)>>15;
    urei = _lsmpy(err.im, mu.re)>>15;
    uier = _lsmpy(err.re, mu.im)>>15;
    uiei = _lsmpy(err.im, mu.im)>>15;

    for(j=0; j<EQ_ORDER ; j++)
	{
        temp32 = _lsmpy(urer, x[j].re);
		temp32 = _smas(temp32, urei, x[j].im);
        temp32 = _rnd(temp32)>>15;
		w[j].re = _ssub(w[j].re, (Int16)temp32);

        temp32 = _lsmpy(uiei, x[j].re);
		temp32 = _smac(temp32, uier, x[j].im);
        temp32 = _rnd(temp32)>>15;
		w[j].im = _ssub(w[j].im, (Int16)temp32);
    }

	// Return the output and error
    *error = err;
	*out   = y;
}
