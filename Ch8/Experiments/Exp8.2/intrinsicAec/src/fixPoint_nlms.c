/*
 * fixPoint_nlms.c
 *
 *  Created on: Oct 25, 2012
 *      Author: BLEE
 *
 *  Description: This program is the fixed-point NLMS algorithm for fixed-point AEC experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include <gsm.h>
#include "tistdtypes.h"
#include "fixPoint_nlms.h"

void fixPoint_nlms(DTALK *dtObj, LMS *lmsObj)
{ 
    DTALK  *dt=(DTALK *)dtObj;
    LMS    *lms=(LMS *)lmsObj;
    Int32  temp32,ue;
    Int16  j,n,sign, step;
    Int16  *x,*w;
	
    n = lms->order;
    w = &lms->w[0];
    x = &lms->x[0];

    // Update data delay line
    for(j=n-1; j>0; j--)
    {
        x[j] = x[j-1];
    }
    x[0] = lms->in;
    
    // Get adaptive filter output
    temp32 = L_mult(w[0], x[0]);
    for(j=1; j<n; j++)
    {
        temp32 = L_mac(temp32, w[j], x[j]);
    }
    lms->out = round(temp32);

    // Compute error term
    lms->err = sub(lms->des, lms->out);

    // Coefficients update
    if(!lms->freez)
    {
        temp32 = L_shr(dt->farInPowM, 15);
        if ( temp32 >=32767)
        {
            temp32 =32767;
        }
        else if (temp32 <=1)
        {
            temp32=1;
        }

        ue = L_mult(lms->err, lms->mu);
        ue = L_shr(ue, 1);

        sign =1;
        if (ue <0) 
        {
            ue = -ue;
            sign = -1;
        }

        if (ue < dt->farInPowM) 
        {	
            step = div_l(ue, (Int16)temp32);
        }
        else if (ue >= L_shl(dt->farInPowM, 1))
        {
            step = (Int16)L_shr(ue, 14);
        }

        if (sign <0)
        {
            step = -step;
        }

        for(j=0; j<n ; j++)
        {
            temp32 = L_shl((Int32)w[j], 16);
            temp32 = L_mac(temp32, step, x[j]);
            w[j] = round(temp32);
        }
    }
}

