/*
 * intrinsic_pwf_wz.c
 *
 *  Created on: Dec 6, 2012
 *      Author: BLEE
 *
 *  Description: This program calculates perceptual weighting filter coefficients
 *               based on lpc coefficients
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include "tistdtypes.h"
#include "pwf.h"
#include "gsm.h"

/*---------------------------------------------------------------
|   calc_wz()              : perceptual weighting filter        |
|                            W(Z)=(wf1[z])/(wf2[z])             |
|    Input      lpc        : lpc[0,.,p_order]                   |
|               gamma1     : gamma1                             |
|               gamma2     : gamma2                             |
|               p_order    : Lpc order                          |
|    Output     wf1        : wf1[0,.,p_order]                   |
|               wf2        : wf2[0,.,p_order]                   |
|                                                               |
---------------------------------------------------------------*/

void  calc_wz (Int16 *lpc, Int16 gamma1, Int16 gamma2, Int16 p_order, Int16 *wf1, Int16 *wf2)
{
    Int16 i,gam1,gam2;
       
    wf1[0]=32767;				// Constant 1.0 in Q15
    wf2[0]=32767;				// Constant 1.0 in Q15
    gam1 = gamma1;				// Bandwidth expansion factor in Q15
    gam2 = gamma2;				// Bandwidth expansion factor in Q15

    for (i=1; i<=p_order; i++) 	// Calculate weighting filter coefficients
    {   
        wf1[i] = mult_r(lpc[i],gam1);
        wf2[i] = mult_r(lpc[i],gam2);
        gam1 = mult_r(gam1, gamma1);
        gam2 = mult_r(gam1, gamma2);
    }    
}


