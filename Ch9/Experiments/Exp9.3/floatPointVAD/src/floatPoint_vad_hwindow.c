/*
 * floatPoint_vad_hwindow.c
 *
 *  Created on: Sep 10, 2012
 *      Author: BLEE
 *
 *  Description: This is the Hanning Window program for floating-point VAD (voice activity detection) experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include <math.h>
#include "tistdtypes.h"
#include "floatPoint_vad.h"

void vad_hwindow(VAD_VAR *pvad)
{
    Int16 k,L;
    L = pvad->L;

	for (k=0;k<L/2;k++)     // Compute Hanning window coefficients
    {
		pvad->window[k] = (float)(0.5*(1-cos(2*PI*k/(L-1))));
    }

}

