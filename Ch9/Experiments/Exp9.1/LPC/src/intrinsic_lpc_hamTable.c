/*
 * intrinsic_lpc_hamTable.c
 *
 *  Created on: Dec 6, 2012
 *      Author: BLEE
 *
 *  Description: This is the Hamming window Table generation for LPC experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include <stdlib.h>
#include "tistdtypes.h"
#include <math.h>
#include "lpc.h"

void hmwindowGen(Int16 N, Int16 *HammingWindow)
{
    Int16 k;

    for (k=0;k<N;k++)     // Compute Hamming window coefficients
    {
        HammingWindow[k] = (Int16)((0.54-0.46*(cos(2*PI*k/(N-1))))*32767.);
    }

}

