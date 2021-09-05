/*
 * mixed_vad_wtable.c
 *
 *  Created on: Dec 5, 2012
 *      Author: BLEE
 *
 *  Description: This program generates twiddle factor lookup table
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include <math.h>
#include "tistdtypes.h"
#include "mixed_vad.h"

void w_table(complex *U)
{
    complex W;         			// Twiddle factor W^k
    Uint16 i,j,l;
    Uint16 SL;         			// Number of points in sub DFT at stage L
                       			//   and offset to next DFT in stage
    Uint16 SL1;        			// Number of butterflies in one DFT at
                       	   	    //   stage L.  Also is offset to lower point
                       	   	    //   in butterfly at stage L

    for (i=0, l=1; l<=EXP; l++) 
    {
        SL=1<<l;               // LE=2^L=points of sub DFT 
        SL1=SL>>1;             // Number of twiddle factors in sub-DFT  
        for (j=0; j<SL1; j++)
        {                             
            W.re = (Int16)(0x7fff*cos(j*PI/SL1));
            W.im = -(Int16)(0x7fff*sin(j*PI/SL1));
            U[i++] = W;
        }
    }
}
