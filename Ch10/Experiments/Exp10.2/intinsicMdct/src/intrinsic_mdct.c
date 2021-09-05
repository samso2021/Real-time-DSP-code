// 
/*
 * intrinsic_mdct.c
 *
 *  Created on: Oct 26, 2012
 *      Author: BLEE
 *
 *  Description: This program calculates direct MDCT and inverse MDCT using intrinsics
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include "gsm.h"
#include "tistdtypes.h"
#include "intrinsic_mdct.h"

Int16 win[FRAME];
Int16 cos_enc[FRAME>>1][FRAME];
Int16 cos_dec[4*FRAME];

/*------------------------------------------------------------------*/
/*                                                                  */
/*    Function: Calculation of the direct MDCT                      */
/*                                                                  */
/*------------------------------------------------------------------*/

void mdct(Int16 *in, Int16 *out, Int16 N)
{
    Int32 acc0;
    Int16 k,j;
    Int16 temp16;

    for (j = 0; j < (N>>1); j++)
    {
        acc0 = 0;
        for (k = 0; k < N; k++)  		// Calculate the j component
        {
            temp16 = mult_r(win[k],(in[k]));
            acc0 = L_mac(acc0,temp16, cos_enc[j][k]);
        }
        out[j] = (short)round(acc0);	// Convert to 16-bit word with rounding
    }
}


/*------------------------------------------------------------------*/
/*                                                                  */
/*    Function: Calculation of the inverse MDCT                     */
/*                                                                  */
/*------------------------------------------------------------------*/

void inv_mdct(Int16 *in, Int16  *out, Int16 N)
{
    Int32  acc0;
    Int16  i,j,k;

    for(j = 0; j < N; j++)
    {
        acc0 = 0; 
        for(k = 0; k < (N>>1); k++)
        {
          i = (j<<1)+1+(N>>1);
          i *= ((k<<1)+1);
          i %= (N<<2);
          acc0 = L_mac(acc0, in[k], cos_dec[i]);
        }
        out[j] = mult_r((Int16)round(acc0), win[j]) ;
    }
}
