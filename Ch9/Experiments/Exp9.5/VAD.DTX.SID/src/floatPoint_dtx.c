/*
 * floatPoint_dtx.c
 *
 *  Created on: Sep 11, 2012
 *      Author: BLEE
 *
 *  Description: This program contains the DTX functions
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include <math.h>
#include "tistdtypes.h"
#include "floatPoint_vad.h"
#include "floatPoint_dtx.h"

void dtx_proc(VAD_VAR *pVad, DTX_VAR *pDtx)
{
	if(pDtx->preFrameType == VOICE) {
		pDtx->frameType = SID;				// First Inactive frame
		pDtx->sidEng = pVad->Nf;
	}
	else {
		if ((pDtx->sidEng >= pDtx->dtxThre* pVad->Nf) || (pDtx->dtxThre* pDtx->sidEng <= pVad->Nf)){
			pDtx->frameType = SID;			// First Inactive frame
			pDtx->sidEng = pVad->Nf;
		}
		else
			pDtx->frameType = UNTX;
	}
}

void dtx_int(DTX_VAR *pDtx)
{
	pDtx->frameType = VOICE;     // Number of frames for hangover time
    pDtx->preFrameType = VOICE;  // Starting freq. bin for VAD
    pDtx->sidEng = 0.0;			 // Ending freq. bin for VAD
    pDtx->silEng = 0.0;			 // Length of FFT and IFFT
}
