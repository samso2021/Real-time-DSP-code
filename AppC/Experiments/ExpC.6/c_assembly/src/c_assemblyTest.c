/*
 * c_assemblyTest.c
 *
 *  Created on: Apr 7, 2012
 *      Author: BLEE
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */
#include <stdio.h>
#include "tistdtypes.h"

extern Int16 findMax(Int16 *, Int16 );
extern void arraySort(void);

Int16 a[8]={19, 55, 2, 28, 19, 84, 12, 10};
Int16 b[8];


void main()
{
	printf("Exp C.6 --- C and Assembly\n");

	printf("Max number in a[] = %d\n", findMax(a, 8));

	arraySort();

	printf("Original array a[] = {%d, %d, %d, %d, %d, %d, %d, %d}\n",
			a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7]);
	printf("Sorting result b[] = {%d, %d, %d, %d, %d, %d, %d, %d}\n",
			b[0],b[1],b[2],b[3],b[4],b[5],b[6],b[7]);

	printf("\nExp --- completed\n");
}

