/*
 * fixPoint_aec_init.c
 *
 *  Created on: Aug 4, 2012
 *      Author: BLEE
 *
 *  Description: This program performs the initialization for fixed-point AEC experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "tistdtypes.h"
#include "fixPoint_nlms.h"


void aec_init(LMS *lms,DTALK *dt)
{
	
    lms->order = L;
    lms->mu = MU;

    dt->nearHangCount = HANGOVER_TIME;
    dt->farHangCount  = HANGOVER_TIME;

    dt->farInPowS = 1;
    dt->farInPowM = 1;
    dt->micInPowS = 1;       
    dt->errorAECpowS = 1;    
	
    dt->trainTime = 2000;
    dt->nfNear = 6000;
    dt->nfFar = 6000;
}
