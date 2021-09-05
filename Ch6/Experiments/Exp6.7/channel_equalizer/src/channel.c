/*
 * channel.c
 *
 *  Created on: Oct 20, 2012
 *      Author: BLEE
 *
 *  Description: This is a simplified channel model
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
// Simple channel
//
#define  ONE  32767
Int16 b1[3] = {(Int16)(0.13*ONE), (Int16)(0.31*ONE), (Int16)(0.13*ONE)};
Int16 b2[3] = {(Int16)(0.15*ONE), (Int16)(0.51*ONE), (Int16)(0.15*ONE)};

void channel(COMPLEX in, COMPLEX *x, COMPLEX *y)
{
	Int32  z1,z2;

    x[2] = x[1];					// Update the delay line x[]
	x[1] = x[0];
	x[0] = in;						// Insert new data to delay line x[0]

	y[2] = y[1];					// Update the y delay line
    y[1] = y[0];

	z1 = _lsmpy(b1[0], x[0].re);	// Filter real x[] component with b1[]
    z1 = _smac(z1, b1[1], x[1].re);
    z1 = _smac(z1, b1[1], x[2].re);

	z2 = _lsmpy(b2[0], x[0].im);	// Filter imag x[] component with b2[]
    z2 = _smac(z2, b2[1], x[1].im);
    z2 = _smac(z2, b2[1], x[2].im);

	z1 = _rnd(z1)>>15;
	z2 = _rnd(z2)>>15;

	y[0].re = (Int16)z1;			// Place the real result into y[0].re
	y[0].im = (Int16)z2;			// Place the real result into y[0].im
}
