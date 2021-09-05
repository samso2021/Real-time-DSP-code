/*
 * init.c
 *
 *  Created on: Jul 15, 2012
 *      Author: BLEE
 *
 *  Description: C program for variables and coefficients initialization
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include <math.h>
#include "dtmfDetect.h"

#define TWO_PI  (3.1415926*2.0)
#define Fs       8000             // Sampling frequency

void init(Int16 *d, Int16 *c)
{
	Int16  i,j;
	double t;

	// Initialize the filter delayline
	// 8 rows are used as following
	// 697 Hz
	// 770 Hz
	// 852 Hz
	// 941 Hz
	// 1209 Hz
	// 1336 Hz
	// 1477 Hz
	// 1633 Hz
	// with each row has 3 locations d[0],d[1], and d[2]
	for (i=0; i<8; i++)
	{
		for(j=0; j<3; j++)
		{
			*d++ = 0;
		}
	}

	// Generate Q14 coefficients
	// coef = 2*cos(2*pi*f/Fs)
	t = TWO_PI/Fs;
	c[0] = (short)(cos(t*697)  * 32768 + 0.5);
	c[1] = (short)(cos(t*770)  * 32768 + 0.5);
	c[2] = (short)(cos(t*852)  * 32768 + 0.5);
	c[3] = (short)(cos(t*941)  * 32768 + 0.5);
	c[4] = (short)(cos(t*1209) * 32768 + 0.5);
	c[5] = (short)(cos(t*1336) * 32768 + 0.5);
	c[6] = (short)(cos(t*1477) * 32768 + 0.5);
	c[7] = (short)(cos(t*1633) * 32768 + 0.5);
}
