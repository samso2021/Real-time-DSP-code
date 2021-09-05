/*
 * mixed_vad_vad.c
 *
 *  Created on: Dec 5, 2012
 *      Author: BLEE
 *
 *  Description: This is the VAD program for VAD experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include <gsm.h>
#include "tistdtypes.h"
#include "mixed_vad.h"

Int16 vad(void)
{
	Int16 k,VAD;
	Int32 Acc0,Acc1;
    
    //   VAD algorithm
    mixVad.En = 0;
    for (k=mixVad.ss;k<=mixVad.ee;k++) // Power of signal from Fl to Fh
    {
        // En += (float)(sqrt(D[k].re*D[k].re + D[k].im*D[k].im)); 
        Acc0 = L_mult(D[k].re, D[k].re);
        Acc0 = L_mac(Acc0, D[k].im, D[k].im);
        Acc0 = (Int32)s_sqrt(Acc0);
        mixVad.En = L_add(mixVad.En, (Acc0<<7));
    }
    
    // Em = am1*Em + alpham*En
    Acc0 = (Int32)L_mls(mixVad.Em, mixVad.am1);
    Acc1 = (Int32)L_mls(mixVad.En, mixVad.alpham);
    mixVad.Em = L_add(Acc0, Acc1);

    // Update the threshold values
    if (mixVad.Nf < mixVad.Em)
    {
        // Nf = al1*Nf + alphal*En;
        Acc0 = L_mls(mixVad.Nf, mixVad.al1);
        Acc1 = L_mls(mixVad.En, mixVad.alphal);
        mixVad.Nf = L_add(Acc0, Acc1);
    }
    else
    {
        // Nf = am1*Nf + alpham*En;
        Acc0 = (Int32)L_mls(mixVad.Nf, mixVad.am1);
        Acc1 = (Int32)L_mls(mixVad.En, mixVad.alpham);
        mixVad.Nf = L_add(Acc0, Acc1);
    }

    mixVad.thres = L_add(mixVad.Nf, mixVad.margin);

    VAD = 0;
    if (mixVad.Em >= mixVad.thres)
    {
        VAD=1;              // Speech is detected since Em >= threshold
        mixVad.hov = HOV;
    }
    else                    // Silence is detected since Em < threshold
    {  
        if (mixVad.hov-- <=0)
            mixVad.hov =0;
        else
            VAD=1;
    }

    return VAD;
}


