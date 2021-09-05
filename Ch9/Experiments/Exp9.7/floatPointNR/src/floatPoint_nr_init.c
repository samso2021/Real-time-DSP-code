/*
 * floatPoint_nr_init.c
 *
 *  Created on: Sep 9, 2012
 *      Author: BLEE
 *
 *  Description: This program initializes spectrum subtraction noise reduction experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include <stdlib.h>
#include <math.h>
#include "tistdtypes.h"
#include "floatPoint_nr.h"

void nr_init(NR_VAR *pnr)
{
    Int16 k,N;
    float *pHBV,*pDV,*pNS;
    NR_VAR *p = (NR_VAR *)pnr;

    N = p->N;
    pHBV = p->HBV;
    pDV = p->DV;
    pNS = p->NS;

    for (k=0;k<N;k++)                        // Clear and init data buffers
    {
        *pHBV++ = 0.0;
        *pDV++ = 0.0;
        *pNS++ =1.0;
    }
    *pNS++=1.0;

    p->alpha =  (float)0.125;                // Start alpha
    p->alpha1 = (float)(1.0 - p->alpha);

    p->hov = 0;
    p->margin = 32.0;                        // Set a none zero value
    p->Em = 32.0;                            // Set a none zero value
    p->Nf = 64.0;                            // Init noise floor
    p->Lm = 8;                               
    p->Ll = 64;                              

    p->ss = (Int16)floor(Fl / (Fs / p->L));  // Starting freq. bin
    p->ee = (Int16) ceil(Fh / (Fs / p->L));  // Ending freq. bin
    p->alpham = (float)(1.0 / p->Lm);
    p->am1 = (float) (1. - p->alpham);
    p->alphal = (float)(1.0 /p-> Ll);
    p->al1 = (float)(1. - p->alphal);
	p->Noise_scale = (float)(63.0 / 64.0);
}
