/*
* fixPoint_directIIRTest.c
*
*  Created on: May 25, 2012
*      Author: BLEE
*
*  Description: This is the test program for fixed-point direct form-I IIR filter
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
#include "fixPointIIR.h"

// Coefficient length
#define NL  13
#define DL  13
#define Q11 2048    // For making Q11 format filter coefficients
#define RND 0.5

// Filter coefficients obtained from MATLAB script
/* 
   Rp=0.1;                                    % Passband ripple
   Rs=60;                                     % Stopband attenuation
   [N,Wn]=ellipord(836/4000,1300/4000,Rp,Rs); % Filter order & scaling factor
   [b,a]=ellip(N,Rp,Rs,Wn);                   % Lowpass IIR filter
   [num,den]=iirlp2bp(b,a,0.5,[0.25, 0.75]);  % Bandpass IIR filter
*/

Int16 num[NL] = {(Int16)(0.0039*Q11+RND), (Int16)(0.0000*Q11+RND),
		(Int16)(0.0028*Q11+RND),  (Int16)(0.0000*Q11+RND),
		(Int16)(0.0074*Q11+RND),  (Int16)(0.0000*Q11+RND),
		(Int16)(0.0025*Q11+RND),  (Int16)(0.0000*Q11+RND),
		(Int16)(0.0074*Q11+RND),  (Int16)(0.0000*Q11+RND),
		(Int16)(0.0028*Q11+RND),  (Int16)(0.0000*Q11+RND),
		(Int16)(0.0039*Q11+RND)};

Int16 den[DL] = {(Int16)(1.0000*Q11+RND), (Int16)(0.0000*Q11+RND),
		(Int16)(4.2912*Q11+RND),  (Int16)(0.0000*Q11+RND),
		(Int16)(8.2629*Q11+RND),  (Int16)(0.0000*Q11+RND),
		(Int16)(8.9932*Q11+RND),  (Int16)(0.0000*Q11+RND),
		(Int16)(5.7991*Q11+RND),  (Int16)(0.0000*Q11+RND),
		(Int16)(2.0930*Q11+RND),  (Int16)(0.0000*Q11+RND),
		(Int16)(0.3300*Q11+RND)};

// Filter delay lines
Int16 x[NL],y[DL];

void main()
{

    Int16  in,i,c;
    FILE   *fpIn,*fpOut;
    Int8   temp[2];
    Uint8  waveHeader[44];

    printf("Enter 1 for using PCM file, enter 2 for using WAV file\n");
    scanf ("%d", &c);

    if (c == 2)
    {
    	fpIn = fopen("..\\data\\input.wav", "rb");
    	fpOut = fopen("..\\data\\output.wav", "wb");
    }
    else
    {
    	fpIn = fopen("..\\data\\input.pcm", "rb");
    	fpOut = fopen("..\\data\\output.pcm", "wb");
    }
    // Open file for read input data
    if (fpIn == NULL)
    {
        printf("Can't open input data file\n");
        exit(0);
    }

    if (c == 2)        // Create WAVE data file header
    {
    	fread(waveHeader, sizeof(Int8), 44, fpIn);
    	fwrite(waveHeader, sizeof(Int8), 44, fpOut);
    }

    // Clear delay lines
    for(i=0; i<NL; i++)
    {
        x[i] = 0;
    }
    for(i=0; i<DL; i++)
    {
        y[i] = 0;
    }

    printf("Exp --- IIR filter experiment\n");

    // Filter test
    while (fread(temp, sizeof(Int8), 2, fpIn) == 2)
    {
        in = (temp[0]&0xFF)|(temp[1]<<8);

        // Filter the data
        fixPoint_IIR(in, x, y, num, NL, den, DL);

        temp[0] = (y[0]&0xFF);
        temp[1] = (y[0]>>8)&0xFF;
        fwrite(temp, sizeof(Int8), 2, fpOut);
    }
    fclose(fpIn);
    fclose(fpOut);
    printf("Exp --- completed\n");
}
