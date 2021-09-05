/*
 * fixPoint_nlp.c
 *
 *  Created on: Aug 4, 2012
 *      Author: BLEE
 *
 *  Description: This program performs NLP function for fixed-point AEC experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

/**************************************************************************
*           C program simulation of acoustic echo canceler using          *
*         1. mode detector (with near-end & far-end speech detectors)     *
*         2. on-line adaptation using normalized LMS algorithm            *                                               *
*         3. residual error of AEC is used for near-end speech detector   *
*            The first 2 seconds of receive signal is considered in the   *
*            receive mode with additional 12 dB residual echo reduction   *
*         4. residual echo suppressor using center clipper when echo      *
*            return loss enhancement (ERLE) > 18 dB                       *
*         5. comfort noise is injected when center clipper is enabled     *
*         6. Attenuator on transmit is used for receive mode when         *
*            ERLE < 18 dB and for double-talk mode                        *
*                                                                         *
***************************************************************************
*--------------------------------------------------------------------------
*  Functions called by this program
*
*    fir, shift, uran
*
**************************************************************************/

#include "tistdtypes.h"
#include "fixPoint_nlms.h"
#include "gsm.h"

void fixPoint_nlp(DTALK *dtObj, LMS *lmsObj)
{
	DTALK  *dt=(DTALK *)dtObj;
	LMS    *lms=(LMS *)lmsObj;

	if 	(dt->nearFlag == 0 && dt->farFlag == 1 )		// Far only speech
	{
		if ( dt->micInPowS >= (dt->errorAECpowS<<2))
			  lms->err =  lms->err>>2;
	}

	
  
}
