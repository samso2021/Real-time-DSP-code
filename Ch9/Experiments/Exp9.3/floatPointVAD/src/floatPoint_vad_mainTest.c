/*
 * floatPoint_vad_mainTest.c
 *
 *  Created on: Sep 10, 2012
 *      Author: BLEE
 *
 *  Description: This is the test program for floating-point VAD (voice activity detection) experiment
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

VAD_VAR    vadvar;
VAD_VAR    *pvad;

Int16   input[FrameSize];
Int16   vadRef[FrameSize];
Int8    temp[2*FrameSize];

void main(void)
{   
    FILE    *fpIn, *fpOut;    // Input and output file pointers
    Int16   i;
    Int16   vadFlag;
    Uint32  n;

    if ((fpIn = fopen("..//data//speech.wav","rb")) == NULL )
    {
        printf("Can't open input file\n");
        exit(0);
    } 
    
    fpOut = fopen("..//data//VAD_ref.xls","wt");

    fread(temp,sizeof(Int8), 22*2, fpIn);	// Remove Wave Header from input file
    fprintf(fpOut, "%s\t%s\n", "Original speech", "VAD flag");
    
    pvad = &vadvar;
    vadvar.L = 256;                        // FFT size
    vadvar.N = vadvar.L >> 1;              // Frame size = 1/2 window size       
    vad_hwindow(pvad);                     // Generate Hanning window
    vadvar.pwindow = vadvar.window;
    vadvar.pIn = input;
    vad_init(pvad);
    n = 0;

    printf("Exp --- floating-point VAD experiment\n");
    while(fread(temp, sizeof(Int8), vadvar.N*2, fpIn) == (Uint16)(2*vadvar.N))
    { 
        for (i=0;i<vadvar.N;i++)           // Get PCM input data
        {
            input[i] = (temp[2*i]&0xFF)|(temp[2*i+1]<<8);;
        }
	    
        vadFlag = vad_ss(pvad);

        if (vadFlag ==1) 
        {
            for (i=0; i<vadvar.N; i++) 
            {
            	vadRef[i] = 0x4000;
            }
        }
        else 
        {
            for (i=0; i<vadvar.N; i++)
            {
            	vadRef[i] = 0;
            }
        }

        for (i=0; i<vadvar.N; i++)
        {
            fprintf(fpOut, "%d\t%d\n", input[i], vadRef[i]);
        }

        n += vadvar.N;
        printf("%ld data words processed\n", n);
    }
    fclose(fpOut);
    fclose(fpIn);
    printf("Exp --- completed\n");
}
