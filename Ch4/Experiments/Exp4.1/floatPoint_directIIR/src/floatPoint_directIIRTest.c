/*
* floatPoint_directIIRTest.c
*
*  Created on: May 25, 2012
*      Author: BLEE
*
*  Description: This is the test program for floating-point direct form-I IIR filter
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
#include "floatPointIIR.h"

// Coefficient length
#define NL  13
#define DL  13

// Filter coefficients obtained from MATLAB script
/* 
   Rp=0.1;                                    % Passband ripple
   Rs=60;                                     % Stopband attenuation
   [N,Wn]=ellipord(836/4000,1300/4000,Rp,Rs); % Filter order & scaling factor
   [b,a]=ellip(N,Rp,Rs,Wn);                   % Lowpass IIR filter
   [num,den]=iirlp2bp(b,a,0.5,[0.25, 0.75]);  % Bandpass IIR filter
*/

double num[NL] = {0.0039, 0.0000, 0.0028, 0.0000, 0.0074, 0.0000,
                  0.0025, 0.0000, 0.0074, 0.0000, 0.0028, 0.0000, 0.0039};

double den[DL] = {1.0000, 0.0000, 4.2912, 0.0000, 8.2629, 0.0000,
                  8.9932, 0.0000, 5.7991, 0.0000, 2.0930, 0.0000, 0.3300};

// Filter delay lines
double x[NL],y[DL];

void main()
{
    double in;
    Int16  i,z,c;
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

    if (c == 2)									// Create WAVE data file header
    {
    	fread(waveHeader, sizeof(Int8), 44, fpIn);
    	fwrite(waveHeader, sizeof(Int8), 44, fpOut);
    }

    // Clear delay lines
    for(i=0; i<NL; i++)
    {
        x[i] = 0.0;
    }
    for(i=0; i<DL; i++)
    {
        y[i] = 0.0;
    }

	printf("Exp --- IIR filter experiment\n");

	// Filter test
    while (fread(temp, sizeof(Int8), 2, fpIn) == 2)
    {
        // Convert 16-bit PCM data to floating-point format
        z = (temp[0]&0xFF)|(temp[1]<<8);
        in = (double)z/32767.0;

        // Filter the data
        floatPoint_IIR(in, x, y, num, NL, den, DL);

        // Convert the floating-point data back to 16-bit PCM data format
        z = (Int16)(y[0]*32767.0 + 0.5);
        temp[0] = (z&0xFF);
        temp[1] = (z>>8)&0xFF;
        fwrite(temp, sizeof(Int8), 2, fpOut);
    }
  
    fclose(fpIn);
    fclose(fpOut);
    printf("Exp --- completed\n");

}
