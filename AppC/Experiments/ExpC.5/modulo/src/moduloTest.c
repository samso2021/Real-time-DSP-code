/*
 * moduloTest.c
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

void main()
{
	Int16 a1,a2,a3;

	printf("Exp C.5 --- Modulo operation\n");

	a1=a2=a3=30;
	// Modulo operation calls library function
   	a1 = a1 % 7;					// <- set breakpoint #1 at this line
   	// Inefficient modulo operation of a power of 2 number
 	a2 = a2 % 8;					// <- set breakpoint #2 at this line
   	// Efficient modulo operation of a power of 2 number
   	a3 = a3 & (8-1);				// <- set breakpoint #3 at this line

    printf("\nExp --- completed\n");	// <- set breakpoint #4 at this line
}
