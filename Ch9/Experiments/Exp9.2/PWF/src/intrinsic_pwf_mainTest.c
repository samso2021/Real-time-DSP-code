/*
 * intrinsic_pwf_mainTest.c
 *
 *  Created on: Dec 6, 2012
 *      Author: BLEE
 *
 *  Description: This is the test program for PWF experiment
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
#include "pwf.h"

// arrays for experiment
Int16 input[FRAMESIZE];
Int16 ws[FRAMESIZE];
Int16 HammingWindow[FRAMESIZE];
Int16 R[LPCORDER+1];
Int16 lpc[LPCORDER+1];
Int16 wf1[LPCORDER+1];
Int16 wf2[LPCORDER+1];

void main()
{   
    FILE    *fpIn;          // Input signal
    FILE    *fpOut;         // Output signal
    Int16   i;
    Int32   counter;
    Int16   temp[FRAMESIZE*2];
    Int16   p_order,N;      // LPC order
    Int16   gamma1,gamma2;
    
    if ((fpIn = fopen("..\\data\\voice4.wav", "rb"))== NULL)
    {
        printf("Can't open input data file\n");
        exit(0);
    }

    fpOut = fopen("..\\data\\pwfCoeff.txt", "wt");
    fread(temp, sizeof(Int8), 44, fpIn);    // Skip WAV header

    counter =0;                    //  Initialization
    p_order = LPCORDER;
    N = FRAMESIZE;
    
    hmwindowGen(N,HammingWindow);  // Generate Hamming window

    printf("\n\tPWF computation experiment \n");
    printf("\tLPC order   : %i\n",p_order);
    printf("\tFrame Size  : %i\n",N);
    fprintf(fpOut, "\n\tPWF computation experiment \n");
    fprintf(fpOut, "\tLPC order   : %i\n",p_order);
    fprintf(fpOut, "\tFrame Size  : %i\n",N);
    while (fread(temp, sizeof(Int8), 2*N, fpIn) == (Uint8)(2*N))
    {
        for (i=0;i<N;i++)          // Form 16-bit PCM input
        {
            input[i] = (temp[2*i]&0xFF)|(temp[2*i+1]<<8);
        }
        
        hmwindowing(N,input,ws,HammingWindow);  // Windowing
        calc_autoc(ws, p_order, N,R);           // Auto correlation
        calc_lpc(R, lpc, p_order);              // Levension_Durbin
        gamma1 = GAMMA1;                        // Default gamma
        gamma2 = GAMMA2;
        calc_wz (lpc,gamma1,gamma2,p_order,wf1,wf2);

        printf("%ld,  LPC:", counter) ;
        fprintf(fpOut, "%ld, LPC:  ", counter) ;
        for(i=1;i<=p_order;i++)
        {
        	printf("  %i, ",lpc[i]);
            fprintf(fpOut, "%i, ",lpc[i]);
        }
        printf("\n");
        fprintf(fpOut, "\n");
        printf("%ld,  WF1:", counter) ;
        fprintf(fpOut, "%ld, WF1:  ", counter) ;
        for(i=1;i<=p_order;i++)
        {
            printf("  %i, ",wf1[i]);
            fprintf(fpOut, "%i, ",wf1[i]);
        }
        printf("\n");
        fprintf(fpOut, "\n");
        printf("%ld,  WF2:", counter) ;
        fprintf(fpOut, "%ld, WF2:  ", counter++) ;
        for(i=1;i<=p_order;i++)
        {
            printf("  %i, ",wf2[i]);
            fprintf(fpOut, "%i, ",wf2[i]);
        }
        printf("\n\n");
        fprintf(fpOut, "\n\n");
    }
    fclose(fpIn);
    printf("\tExp --- completed\n");
}


