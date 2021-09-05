/*
 * intrinsic_pwf_lpc.c
 *
 *  Created on: Dec 6, 2012
 *      Author: BLEE
 *
 *  Description: This is the Durbine recursive algorithm for PWF experiment
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

static Int16 signof(Int32 *acc0);
static Int16 div_l(Int32  L_num, Int16 den);

/*---------------------------------------------------------------
|   calc_lpc()              : lpc coefficients                  |
|    Input      autoc       : autoc[0,.,p_order]                |
|               p           : Lpc order                         |
|    Output     lpc         : lpc[0,.,p_order]                  |
|                                                               |
---------------------------------------------------------------*/

Int16 K[LPCORDER+1];                // Reflection coefficient        in Q13
Int16 a[(LPCORDER+1)*(LPCORDER+1)]; // Intermediate lpc coefficients in Q13
Int16 E[LPCORDER+1];                // Prediction error              in Q14

void calc_lpc(Int16 *autoc, Int16 *lpc, Int16 p)
{
    Int16 i,j,p1;
    Int32  acc0,acc1;
    Int16 *R;                       // Correlation     in Q14
    Int16 sign;

    p1 = p+1;                

    //  Calculate LPC parameters 
    R = autoc;                                      
    E[0] = R[0];
    acc0 = L_shl(R[1],13);

    sign = signof(&acc0);

    acc0 = L_shl(acc0,1);
    K[1] = div_l(acc0, E[0]);

    if(sign== (Int16)-1)
    {
        K[1] = negate(K[1]); 
    }
    a[1*p1+1]=K[1];
    
    // E[1]=((8192-((K[1]*K[1])>>13)) * E[0])>>13;
    acc0 = (Int32)K[1] * K[1];
    acc0 = L_shr(acc0,13);
    acc0 = L_sub(8192, acc0);
    acc0 = (Int32)E[0]* (Int16)(acc0);
    acc0 = L_shr(acc0,13);
    E[1] = (Int16) acc0;

    for (i=2;i<=p;i++)
    {
        acc0=0;
        for (j=1;j<i;j++)
        {
            acc1 = (Int32)a[j*p1+i-1] * R[i-j];
            acc0 = L_add(acc0,acc1);
        }
        
        acc1 = L_shl(R[i],13);
        acc0 = L_sub(acc1, acc0);

        sign = signof(&acc0);

        if ( acc0 > L_shl(E[i-1],13) ) {
            break ;
        }

        acc0 =L_shl(acc0,1);
        K[i] = div_l(acc0,E[i-1]);

        if(sign == (Int16)-1) K[i] = negate(K[i]);

        a[i*p1+i] = K[i];
        
        // a[j*p1+i] = a[j*p1+(i-1)] - ((K[i] * a[(i-j)*p1+(i-1)])>>13);
        for (j=1;j<i;j++)
        {
            acc0 = (Int32)K[i] * a[(i-j)*p1+(i-1)];
            acc1 = L_shl((Int32)a[j*p1+(i-1)],13);
            acc0 = L_sub(acc1,acc0);
            acc0 = L_shr(acc0,13);
            a[j*p1+i] = (Int16) acc0;
        }

        // E[i]=((8192-((K[i]*K[i])>>13)) * E[i-1])>>13;  
        acc0 = (Int32)K[i] * K[i];
        acc0 = L_shr(acc0,13);
        acc0 = L_sub((Int32)8192,acc0);
        acc0 = (Int32)E[i-1]*(Int16)(acc0);
        acc0 = L_shr(acc0,13);
        E[i] = (Int16) acc0;

    }

    for (j=1;j<=p;j++)
        lpc[j] = negate(a[j*p1+p]);                 // Same format as MatLab
    
}


static Int16 signof(Int32 *acc0)
{
    if (*acc0 < 0 ) 
    {
        *acc0 *=-1;
        return (Int16)-1;
    }
    else
    {
        return 0;
    }
}

static Int16 div_l(Int32  L_num, Int16 den)
{
    Int16   var_out = (Int16)0;
    Int32    L_den;
    Int16   i;

    L_den = (Int32)den << 16 ;

    if (L_num >= L_den)
    {
        return MAX_16 ;
    }
    else 
    {
        L_num = L_num >>1;
        L_den = L_den >>1;
        for(i=0; i<15; i++) 
        {
            var_out = var_out<<(Int16)1;
            L_num   = L_num << 1;
            if (L_num >= L_den) 
            {
                L_num = L_num - L_den;
                var_out = var_out + (Int16)1;
            }
        }

        return var_out;
    }
}
