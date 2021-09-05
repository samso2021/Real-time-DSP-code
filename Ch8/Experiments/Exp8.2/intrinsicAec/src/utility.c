/*
 * utility.c
 *
 *  Created on: Aug 4, 2012
 *      Author: BLEE
 *
 *  Description: This program performs long division for fixed-point AEC experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include "tistdtypes.h"
#include "gsm.h"

Int16 div_l( Int32  L_num, Int16 den )
{

	Int16   var_out = (Int16)0;
    Int32    L_den;
    Int16   i;

    L_den = (Int32)den << 16 ;

    if ( L_num >= L_den ){
        return MAX_16 ;
    }
    else {
        L_num = L_num >>1;
        L_den = L_den >>1;
        for(i= 0; i< 15; i++) 
        {
            var_out = var_out<<(Int16)1;
            L_num   = L_num << 1;
            if (L_num >= L_den) {
                L_num = L_num-L_den;
                var_out = var_out+ (Int16)1;
            }
        }

        return var_out;
    }
}
