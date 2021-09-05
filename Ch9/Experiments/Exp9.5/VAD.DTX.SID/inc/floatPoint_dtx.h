/*
 * floatPoint_dtx.h
 *
 *  Created on: Sep 11, 2012
 *      Author: BLEE
 *
 *  Description: This is the C header file for DTX functions and variables
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include "floatPoint_vad.h"

enum {
	VOICE,
	SID,
	UNTX
};


typedef struct {
    Int16   frameType;      // Number of frames for hangover time
    Int16   preFrameType;   // Starting freq. bin for VAD
    float   sidEng;         // Ending freq. bin for VAD
    float   silEng;         // Length of FFT and IFFT
    Int16     dtxThre;      // Length of overlap window
} DTX_VAR;

extern DTX_VAR  *pDtx;

Uint8 sid_enc(float sidEng,Int16 frameSize);
void dtx_proc(VAD_VAR *pVad, DTX_VAR *pDtx);
void dtx_int(DTX_VAR *pDtx);
