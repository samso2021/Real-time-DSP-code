/*
 * lpc_lpc_mainTest.c
 *
 *  Created on: Dec 6, 2012
 *      Author: BLEE
 *
 *  Description: This is the test program for LPC experiment
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
#include "lpc.h"

// Arrays for experiment
Int16 input[FRAMESIZE];
Int16 ws[FRAMESIZE];
Int16 HammingWindow[FRAMESIZE];
Int16 R[LPCORDER+1];
Int16 lpc[LPCORDER+1];

void main()
{   
    FILE    *fpIn;          // Input signal 
    FILE    *fpOut;         // Output signal 
    Int16   i;
    Int32   counter;
    Int16   temp[FRAMESIZE*2];
    Int16   p_order,N;      // LPC order

    if ((fpIn = fopen("..\\data\\voice4.wav", "rb"))== NULL)
    {
        printf("Can't open input data file\n");
        exit(0);
    }
    fpOut = fopen("..\\data\\lpcCoeff.txt", "wt");
    fread(temp, sizeof(Int8), 44, fpIn);    // Skip WAV header

    counter = 0;
    p_order = LPCORDER;
    N = FRAMESIZE;

    printf("\n\tLPC computation experiment \n");
    printf("\tLPC order   : %i\n",p_order);
    printf("\tFrame Size  : %i\n",N);
    fprintf(fpOut, "\n\tLPC computation experiment \n");
    fprintf(fpOut, "\tLPC order   : %i\n",p_order);
    fprintf(fpOut, "\tFrame Size  : %i\n",N);
    
    hmwindowGen(N,HammingWindow);              // Generate Hamming window

    while (fread(temp, sizeof(Int8), 2*N, fpIn) == (Uint8)(2*N))
    {
        for (i=0;i<N;i++)                      // Get PCM input data
        {
            input[i] = (temp[2*i]&0xFF)|(temp[2*i+1]<<8);
        }
        
        hmwindowing(N,input,ws,HammingWindow); // Windowing
        calc_autoc(ws, p_order, N,R);          // Auto correlation
        calc_lpc(R, lpc, p_order);             // Levension_Durbin

        printf("%ld, LPC: ",counter);
        fprintf(fpOut, "%ld, LPC: ",counter++);
        for(i=1;i<=LPCORDER;i++)
        {
        	printf("%i,  ",(Int16)lpc[i]);
            fprintf(fpOut, "%i ",(Int16)lpc[i]);
        }
        fprintf(fpOut, "\n");
        printf("\n");
    }

    fclose(fpIn);
    fclose(fpOut);
    printf("\tExp --- completed\n");
}


