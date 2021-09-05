/*
 * floatPoint_dtx_mainTest.c
 *
 *  Created on: Sep 11, 2012
 *      Author: BLEE
 *
 *  Description: This is the test program for floating-point DTX experiment
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
#include "floatPoint_vad.h"
#include "floatPoint_dtx.h"
#include "g711.h"

VAD_VAR vadvar;
VAD_VAR *pVad;
DTX_VAR dtxVar;
DTX_VAR *pDtx;

Int16 input[FrameSize];
Int8  charBuf[2*FrameSize];

void main(void)
{   
    FILE    *fpIn,*fpOut;     // Input and output file pointers
    Int16   i,vadFlag,framSize,payLoadLen;
    Uint32  n;

    pVad = &vadvar;
	pDtx = &dtxVar;

    if ((fpIn = fopen("..//data//speech.wav","rb")) == NULL )
    {
        printf("Can't open input file\n");
        exit(0);
    }
    fpOut = fopen("..//data//parameter.dtx","wb");


    vadvar.L = 256;							// FFT size
    dtxVar.dtxThre = 2;						// Threshold
    payLoadLen = 0;

    fread(charBuf, sizeof(Int8), 22*2, fpIn);	// Remove Wave Header from input file
    
    vadvar.N = vadvar.L >> 1;				// Frame size = 1/2 window size
    vad_hwindow(pVad);						// Generate Hanning window
    vadvar.pwindow = vadvar.window;
    vadvar.pIn = input;
    vad_init(pVad);
	framSize = vadvar.N;
	dtx_int(&dtxVar);
    n = 0;

    printf("Exp --- floating-point VAD/DTX/SID experiment\n");
    while(fread(charBuf, sizeof(Int8), vadvar.N*2, fpIn) == vadvar.N*2)
    { 
        for (i=0;i<vadvar.N;i++)           // Get PCM input data
        {
            input[i] = (charBuf[2*i]&0xFF)|(charBuf[2*i+1]<<8);;
        }
	    
        vadFlag = vad_ss(pVad);

        if(vadFlag)
		{
			ulaw_compress(framSize, input, &charBuf[1]);
			pDtx->frameType = VOICE;
		}
		else
		{
			dtx_proc(pVad,pDtx);

			if (pDtx->frameType == SID)
			{
				charBuf[1]= sid_enc(pDtx->sidEng,framSize);
			}
		}

		pDtx->preFrameType = pDtx->frameType;


        if (pDtx->frameType == VOICE)
        {
            charBuf[0] = framSize;
			payLoadLen = framSize + 1;

        }
        else if (pDtx->frameType == SID)
        {
            charBuf[0] = 1;
			payLoadLen =1 + 1;
        }
		else
		{
			charBuf[0] = 0;
			payLoadLen = 1;
		}
        
        fwrite(charBuf,sizeof(Int8),payLoadLen,fpOut);    // Save PCM data

        n += vadvar.N;
        printf("%ld data words processed\n", n);
    }

    fclose(fpOut);
    fclose(fpIn);
    printf("Exp --- completed\n");
}
