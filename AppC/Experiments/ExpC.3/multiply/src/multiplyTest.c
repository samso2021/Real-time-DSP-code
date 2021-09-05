/*
 * multiplyTest.c
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

Int16 a=0x4000, b=0x6000;
static Int32  c1,c2,c3;

void main (void)
{
	printf("Exp C.3 --- C Multiplication\n");

	// Wrong: only the lower 16-bit result in AC0 is saved to c
	c1 = a * b;
	// Wrong: only the lower 16-bit result in AC0 is saved to c
	c2 = (Int32)(a * b);
	// Correct: 32-bit result in AC0 is saved to c
	c3 = (Int32)a * b;

	printf ("c1 = 0x%lX\n", c1);
	printf ("c2 = 0x%lX\n", c2);
	printf ("c3 = 0x%lX\n", c3);

	printf("\nExp --- completed\n");
}
