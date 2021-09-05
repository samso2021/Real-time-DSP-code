/*
 * floatPoint_nr_vad.c
 *
 *  Created on: Sep 9, 2012
 *      Author: BLEE
 *
 *  Description: This is the VAD for noise reduction experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include <math.h>
#include "tistdtypes.h"
#include "floatPoint_nr.h"

Int16 nr_vad(NR_VAR *pnr)
{
	Int16 k,VAD;
    float   En;                               // Current frame power
    NR_VAR *p = (NR_VAR *)pnr;
    
    En = 0;
    for (k=p->ss; k<=p->ee; k++)              // Power from 250Hz to 820Hz
    {
        En += (float)(sqrt(p->D[k].real*p->D[k].real 
           + p->D[k].imag*p->D[k].imag)); 
    }
    
    p->Em = p->am1*p->Em + p->alpham*En;

    if (p->Nf < p->Em)                        // Update noise floor
    {
        p->Nf = p->al1*p->Nf + p->alphal*En;
    }
    else
    {
        p->Nf = p->am1*p->Nf + p->alpham*En;
    }
    p->thres = p->Nf + p->margin;

    VAD = 0;
    if (p->Em >= p->thres) 
    {
		VAD=1;
    }
    if (VAD)                // Speech is detected since Em >= threshold
    { 
        p->hov = HOV;
    }
    else                    // Silence is detected since Em < threshold
    {  
        if (p->hov-- <=0)
        {
            p->hov =0;
        }
        else
        {
            VAD=1;
        }
    }

	p->En = En;
    return VAD;
}
