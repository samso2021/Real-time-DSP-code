/*
 * sort.c
 *
 *  Created on: Apr 20, 2012
 *      Author: BLEE
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */
#include "tistdtypes.h"

void sort(Int16 *, Int16 *, Int16);

void sort(Int16 *p1, Int16 *p2, Int16 n)
{
	Int16 i,j,tmp;

	for (i=0; i<n; i++)
	{
		p2[i] = p1[i];
	}

	for (i=0; i<n-1; i++)
	{
		for (j=i+1; j<n; j++)
		{
			if (p2[i] > p2[j])
			{
				tmp = p2[i];
				p2[i] = p2[j];
				p2[j] = tmp;
			}
		}
	}
}
