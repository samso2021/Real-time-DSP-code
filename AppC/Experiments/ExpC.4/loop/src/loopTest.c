/*
 * loopTest.c
 *
 *  Created on: Apr 1, 2012
 *      Author: BLEE
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */
#include <stdio.h>
#include "tistdtypes.h"

extern void asmLoop(Int16 *);

Int16 a[2][300];

void main (void)
{
	Int16 i, j;
	Int16 *p;

	printf("Exp C.4 --- C Loop and assembly loop\n");

	for (i=0; i<2; i++)				// <-set break point #1 at this line
	{
		for (j=0; j<300; j++)
		{
			a[i][j] = 0xffff;
		}
	}

	p = (short *)a;					// <-set break point #2 at this line
	asmLoop(p);

	printf("\nExp --- completed\n");	// <-set break point #3 at this line
}
