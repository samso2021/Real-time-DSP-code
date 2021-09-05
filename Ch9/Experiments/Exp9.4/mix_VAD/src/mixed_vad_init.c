/*
 * mixed_vad_init.c
 *
 *  Created on: Dec 5, 2012
 *      Author: BLEE
 *
 *  Description: This is the initialization program for VAD experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include "tistdtypes.h"
#include "mixed_vad.h"

MIXVAD  mixVad;

void vad_init(Int16 N)
{
	Int16 k;

    for (k=0;k<N;k++)                    // Clear data buffers
    {
        HBV[k]=0;
        DV[k]=0;
    }

    mixVad.hov = 0;
    mixVad.margin = (Uint32)32<<15;
    mixVad.Em = (Uint32)32<<15;
    mixVad.Nf = (Uint32)64<<15;          // Init noise floor
    mixVad.ss = SS;                      // Starting freq. bin
    mixVad.ee = EE;                      // Ending freq. bin
    mixVad.Lm = 4;
    mixVad.alpham = (Int16)((32767 / mixVad.Lm));
    mixVad.am1 = (32767 - mixVad.alpham);
    mixVad.Ll = 16;
    mixVad.alphal = (Int16)((32767 / mixVad.Ll));
    mixVad.al1 = (32767 - mixVad.alphal);
}
