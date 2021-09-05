/*
 * intrinsic_pwf_auto.c
 *
 *  Created on: Dec 6, 2012
 *      Author: BLEE
 *
 *  Description: This function computes auto correlation for PWF experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include <stdlib.h>
#include "tistdtypes.h"
#include "pwf.h"
#include "gsm.h"

/*---------------------------------------------------------------
|   calc_autoc()           : autocorrelation                    |
|    Input      ws         : ws[0,.,frame_size-1]               |
|               p_order    : Lpc order                          |
|               frame_size : frame_size                         |
|    Output     autoc      : aotoc[0,.,p_order]                 |
|                                                               |
---------------------------------------------------------------*/

void  calc_autoc(Int16 *ws, Int16 p_order, Int16 frame_size, Int16 *autoc)
{
    Int16  k,m,i;
    Int32   acc0,acc1;
    Int16  Exp;

    acc1 = (Int32) 0 ;           // Compute the energy
    for (i=0; i<frame_size; i++) 
    {
        acc0 = (Int32)ws[i]*ws[i];
        acc1 = L_add(acc1,acc0);
    }

    Exp = norm_l(acc1);         // Normalize the energy
    acc1 = L_shl(acc1, Exp);

    autoc[0] = round( acc1 );  
    for (k=1 ; k<=p_order; k++) // Compute autocorrelation coefficients.*/
    {
       acc1 = (Int32) 0 ;
       for (m=k; m<frame_size; m++)
       {
            acc0 = (Int32)ws[m]*ws[m-k];
            acc1 = L_add(acc1,acc0);
       }
    
       acc0 = L_shl(acc1, Exp);
       autoc[k] = round(acc0);  
    }
}
