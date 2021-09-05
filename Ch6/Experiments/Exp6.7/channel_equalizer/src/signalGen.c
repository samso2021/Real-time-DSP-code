/*
 * signalGen.c
 *
 *  Created on: June 7, 2012
 *      Author: BLEE
 *
 *  Description: This is a training signal generator
 *               It uses simplified ITU V.29 9600 bps force training sequence
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#include "tistdtypes.h"
#include "complexEQ.h"

//
// Generate 2-D symbols for equalizer training
// Reference: ITU V.29 Section 8.2
// Mode: 9600 bits / second 
//
void signalGen(COMPLEX *s)
{
    Int16   x;
    Int16   i,j;
    COMPLEX c,d;

	x    = INIT_X;       // Set initial value for the pseudo random number
	c.re = C_REAL;       // Set initial values of real and imaginary points
	c.im = C_IMAG;
	d.re = D_REAL;
	d.im = D_IMAG;

    for(j=0, i=0; i<NUM_SIMBOL; i++)
	{
		if (randGen(&x))
		{
		   s[j++] = d;
		}
        else
		{
		   s[j++] = c;
		}
	}
}


//
// Pseudo random sequence generator
// Reference: ITU V.29 Appendix I
// Polynomial: 1+x^-6+x^-7
// Implemented as left shift register
//
Int16 randGen(Int16 *x)
{
	Int16 b6,b7;

    b7 = *x&1;
	*x >>= 1;
    b6 = *x&1;

	b6 ^= b7;
	*x |= b6<<6;

    return(b7);
}

