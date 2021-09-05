/*
 * dtmfFreq.c
 *
 *  Created on: Jul 15, 2012
 *      Author: BLEE
 *
 *  Description: C program to find DTMF frequencies using Goertzel algorithm
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include "dtmfDetect.h"

void dtmfFreq(Int16 *data, Int16 *d, Int16 *c, Int16 frameSize)
{
	Int16 i,j,x;
	Int16 *dd;

	for (j=0; j<frameSize; j++)
	{
		x = *data++;
		dd = d;
		for (i=0; i<8; i++)
		{
			gFilter(dd, x, c[i]);
			dd += 3;
		}
	}
}
