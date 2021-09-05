/*
 * fixPoint_double_talk.c
 *
 *  Created on: Aug 4, 2012
 *      Author: BLEE
 *
 *  Description: This program performs the double-talk detection for fixed-point AEC experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include "tistdtypes.h"
#include "fixPoint_nlms.h"
#include "gsm.h"

void fixPoint_double_talk(DTALK *dtObj, LMS *lmsObj)
{ 
	DTALK  *dt=(DTALK *)dtObj;
	LMS    *lms=(LMS *)lmsObj;

	Int32 temp32a,temp32b;


/* Update far-end noise floor estimate of receiving far-end signal      */

		// temp = |farEndIn|, Estimate far end input power
		temp32a  = L_deposit_h(lms->in);
		// Estimate farEndIn power by short window
		dt->farInPowS = aec_power_estimate(
							    dt->farInPowS,
							    temp32a,ALPHA_SHIFT_SHORT);
		// Estimate farEndIn power by medium window
		dt->farInPowM = aec_power_estimate(
								dt->farInPowM,
								temp32a,ALPHA_SHIFT_MEDIUM);
                                     
		if (dt->nfFar < dt->farInPowS) {   
			// Onset of speech, slow update using long window
			dt->nfFar = aec_power_estimate(
								dt->nfFar,
								temp32a,ALPHA_SHIFT_MEDIUM);
		}              
		else {
			// Offset of speech, fast decay using medium window
			dt->nfFar = aec_power_estimate(
								dt->nfFar,
								temp32a,ALPHA_SHIFT_SHORT);
		}              

/* Update near-end noise floor estimate of signal pickup by microphone  */
		
		// temp = |microphoneIn|
		temp32a = L_deposit_h(lms->des);
		// Estimate microphone signal power by short window
		dt->micInPowS = aec_power_estimate(
								dt->micInPowS,
								temp32a,ALPHA_SHIFT_SHORT);
                                     
		if (dt->nfNear < dt->micInPowS) { 
			// Onset of speech, slow update using long window
			dt->nfNear = aec_power_estimate(
								 dt->nfNear,
								 temp32a,ALPHA_SHIFT_MEDIUM);
		}              
		else {  
			// Offset of speech, fast decay using medium window
			dt->nfNear = aec_power_estimate(
								 dt->nfNear,
								 temp32a,ALPHA_SHIFT_SHORT);
		}   


		/* Error power */
		// Estimate power of AEC error by short window
		temp32a = L_deposit_h(lms->err);

		dt->errorAECpowS = aec_power_estimate(
								   dt->errorAECpowS,
								   temp32a,ALPHA_SHIFT_SHORT);
		// Estimate power of AEC error by medium window
		dt->errorAECpowM = aec_power_estimate(
								   dt->errorAECpowM,
								   temp32a,ALPHA_SHIFT_MEDIUM);


		// Threshold for far-end detector
		temp32b = dt->nfFar;   
		temp32b = L_add(temp32b,(SAFE_MARGIN>>1));                 

		// Threshold for near-end detector
		temp32a = dt->nfNear<<2;
		temp32a = L_add(temp32a,SAFE_MARGIN);

		if(temp32b <= (200<<15))
			temp32b = (200<<15);
		//  Detect speech activity at far end
		if(dt->farInPowS > temp32b)			// temp32b = thresFar
		{   // Declare far-end speech
			dt->farFlag = 1;					    
			// Set hangover time counter
			dt->farHangCount = HANGOVER_TIME; 
		}
		else
		{
			if (dt->farHangCount-- < 0)// Decrement hangover counter
			{
				dt->farFlag = 0;
				dt->farHangCount = 0;	// Hangover counter expired
			}
		}
                          
		if(temp32a <= (400<<15))
			temp32a= (400<<15);
		if( (dt->micInPowS > temp32a) &&    // temp32a = thresNear
		    (dt->errorAECpowS > temp32a) ) 
		{
			dt->nearFlag = 1;				// Declare speech
			dt->nearHangCount = HANGOVER_TIME;	// Set hangover counter
		}
		else
		{
			if (dt->nearHangCount-- < 0)	// Decrement hangover counter
			{
				dt->nearFlag = 0;
				dt->nearHangCount = 0;		// Hangover counter expired
			}
		}


	if(dt->trainTime-- <= 1 )
	{
		if(dt->nearFlag == 0 && dt->farFlag ==1)
			lms->freez =0;
		else 
			lms->freez =1;
		
		dt->trainTime =0;
	}
	else
	{
		lms->freez =0;
	}


}

/**************************************************************************
*  POWER_ESTIMATE - function to estimate power using a losy accumulator   *
***************************************************************************
*  Algorithm:
*    p(n) = p(n-1) + alpha * (abs(x(n) - p(n-1))
*
*  where
*    p(n) is the estimated power of most recent N samples
*    alpha is lossy accumulator coefficient. alpha = 1/N
*    x(n) is the absolute of the most recent sample
*
*  When N = 2**n, p(n) can be expressed as
*
*    p(n) = p(n-1) + (abs(x(n) - p(n-1))>>n
*
*************************************************************************/

Int32 aec_power_estimate(Int32 pn, Int32 xn, Int16 n)
{
	Int32 p;

	p = L_abs(xn);
	p = L_sub(p,pn);
	p = L_shr_r(p,n);
	pn = L_add(pn,p);

	return(pn);
}

