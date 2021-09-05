/*
 * floatPoint_nr_mainTest.c
 *
 *  Created on: Sep 9, 2012
 *      Author: BLEE
 *
 *  Description: This is the test program for spectrum subtraction noise reduction experiment
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
#include "floatPoint_nr.h"

NR_VAR   nrvar;
NR_VAR   *pnr;

Int16   input1[FrameSize];
Int16   input2[FrameSize];
Int8    temp[2*FrameSize];

void main(void)
{   
    FILE    *fpIn,*fpOut1,*fpOut2;
    Int16   i,j;
    Uint32  n;

    pnr = &nrvar;

    if ((fpIn = fopen("..//data//speech.wav","rb")) == NULL )
    {
        printf("Can't open input wave file\n");
        exit(0);
    }
    fpOut1 = fopen("..//data//nr_output.wav","wb");
    fpOut2 = fopen("..//data//nr_ref.xls","wt");

    nrvar.L = 256;							// FFT size
    nrvar.Atten = (float)0.1;				// NR attenuation factor

    fread(temp,sizeof(Int8), 22*2, fpIn);	// Skip wave header
    fwrite(temp,sizeof(Int8), 22*2, fpOut1);	// Create wave header for output file
    fprintf(fpOut2, "%s\t%s\n", "Original speech", "SS NR result");

    nrvar.N = nrvar.L >> 1;					// Frame size = 1/2 window size
    nr_hwindow(pnr);						// Generate Hanning window
    nrvar.pwindow = nrvar.window;
    nrvar.pIn = input1;
    nr_init(pnr);
    n = 0;

    printf("Exp --- spectrum subtraction noise reduction\n");
    while(fread(temp, sizeof(Int8), nrvar.N*2, fpIn) == (Uint16)(2*nrvar.N))
    { 
        for (i=0;i<nrvar.N;i++)				// Get input data
        {
            input1[i] = (temp[2*i]&0xFF)|(temp[2*i+1]<<8);
            input2[i] = input1[i];
        }

        nrvar.vadFlag = nr_ss(pnr);
        nr_proc(pnr);

        for (j=0, i=0;i<nrvar.N;i++)                      
        {
            temp[j++] = input1[i]&0xFF;
            temp[j++] = (input1[i]>>8)&0xFF;
        }
        
        fwrite(temp, sizeof(Int8), nrvar.N*2, fpOut1);  // Save output wave data
        for (i=0; i<nrvar.N; i++)
        {
            fprintf(fpOut2, "%d\t%d\n", input2[i], input1[i]);
        }
        n += nrvar.N;
        printf("%ld data words processed\n", n);
	}

    fclose(fpOut1);
    fclose(fpOut2);
    fclose(fpIn);
    printf("Exp --- completed\n");
}
