/*
 * mixed_vad_tableGen.c
 *
 *  Created on: Dec 5, 2012
 *      Author: BLEE
 *
 *  Description: This program generates table data for VAD experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include  <math.h>
#include "tistdtypes.h"
#include  "mixed_vad.h"

void hmwindow(Int16 L)
{
    Int16 k;

    for (k=0;k<L/2;k++)     /* Compute Hanning window coefficients */
    {
        window[k] = (Int16)((0.5*(1-cos(2*PI*k/(L-1))))*32767.+0.5);
    }

}

