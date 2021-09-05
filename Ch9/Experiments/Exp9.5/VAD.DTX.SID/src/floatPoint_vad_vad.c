/*
 * floatPoint_vad_vad.c
 *
 *  Created on: Sep 11, 2012
 *      Author: BLEE
 *
 *  Description: This is the VAD function
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

Int16 vad_vad(VAD_VAR *pvad)
{
    Int16 k,VAD;
    float   En;                               // Current frame power
    VAD_VAR *p = (VAD_VAR *)pvad;
    
    En = 0;                                   // VAD algorithm
    for (k=p->ss; k<=p->ee; k++)              // Power from 250Hz to 820Hz
    {
        En += (float)(sqrt(p->D[k].real*p->D[k].real 
           + p->D[k].imag*p->D[k].imag)); 
    }
    
    p->Em = p->am1*p->Em + p->alpham*En;

    if (p->Nf < p->Em)                         // Update noise floor
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
		VAD=1;

    if (VAD)                // Speech is detected since Em >= threshold
        p->hov = HOV;

    else                    // Silence is detected since Em < threshold
    {  
        if (p->hov-- <=0)
            p->hov =0;
        else
           VAD=1;
    }
    return VAD;
}
