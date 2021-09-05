/*
 * floatPoint_nr_hwindow.c
 *
 *  Created on: Oct 26, 2012
 *      Author: BLEE
 *
 *  Description: This program generates Hanning window table
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include <math.h>
#include "tistdtypes.h"
#include "nr.h"

void nr_hwindow(NR_VAR *pnr)
{
    Int16 k,L;
    L = pnr->L;

	for (k=0;k<L/2;k++)     // Compute Hanning window coefficients
    {
		pnr->window[k] = (float)(0.5*(1-cos(2*PI*k/(L-1))));
    }

}

