/*
 * intrinsic_nlms.c
 *
 *  Created on: June 5, 2012
 *      Author: BLEE
 *
 *  Description: This is the intrinsic normalized LMS algorithm
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#include <gsm.h>             // GSM.h maps ETSI functions to TI intrinsics
#include "tistdtypes.h"
#include "intrinsic_nlms.h"

void intrinsic_nlms(LMS *lmsObj)
{ 
    LMS    *lms=(LMS *)lmsObj;
    Int32   temp32;
    Int16  j,n,mu,ue,*x,*w;
	
    n = lms->order;
    w = &lms->w[0];
    x = &lms->x[0];

    // Update data delay line
    for(j=n-1; j>0; j--)
    {
        x[j] = x[j-1];
    }
    x[0] = lms->in;
    
    // Compute normalized mu
//  temp32 = (((long)lms->x[0] * lms->x[0])+0x4000)>>15;  
    temp32 = mult_r(lms->x[0],lms->x[0]);  
		
//  temp32 = ((temp32 * ONE_MINUS_BETA)+0x4000)>>15;           
    temp32 = mult_r((Int16)temp32, ONE_MINUS_BETA);
		
//  lms->power = (short)(((lms->power * (long)BETA)+0x4000)>>15);  
    lms->power = mult_r(lms->power, BETA);  
		
//  temp32 += (lms->power+lms->c);            
    temp32 = add(lms->power, (Int16)temp32);
    temp32 = add(lms->c, (Int16)temp32);
    temp32 >>= 1;                   
    mu = lms->alpha / (Int16)temp32;
    
    // Get adaptive filter output 
//  temp32 = (long)w[0] * x[0];  
    temp32 = L_mult(w[0], x[0]); 	
    for(j=1; j<n; j++)
    {
//      temp32 += (long)w[j] * x[j];
        temp32 = L_mac(temp32, w[j], x[j]);        
    }
//  lms->out = (short)((temp32+ROUND)>>15);
    lms->out = round(temp32);
    
    // Compute error term 
//  lms->err = lms->des - lms->out;
    lms->err = sub(lms->des, lms->out);
    
    // Update coefficients 
//  ue = (long)(((lms->err * (long)mu)+ROUND)>>15); 
    ue = mult_r(lms->err, mu); 	
    for(j=0; j<n ; j++)
    {
//      w[j] += (short)((((long)ue * x[j])+ROUND)>>15);     
        w[j] = add(w[j], mult_r(ue, x[j]));        
    }
}

