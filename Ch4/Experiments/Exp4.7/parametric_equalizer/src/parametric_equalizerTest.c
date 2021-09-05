/*
* parametric_equalizerTest.c
*
*  Created on: May 28, 2012
*      Author: BLEE
*
*  Description: This C test program for parametric equalizer experiment
*
*  For the book "Real Time Digital Signal Processing:
*                Fundamentals, Implementation and Application, 3rd Ed"
*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
*                Publisher: John Wiley and Sons, Ltd
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tistdtypes.h"
#include "cascadeIIR.h"

#define SECTIONS    2  // Number of 2nd order sections
Int16   C[SECTIONS*5]; // C[]=A[i][1], A[i][2], B[i][2], B[i][0], B[i][1]...
Int16   w[SECTIONS*2]; // Filter delay line
                       // w[]=w[i][n-1],w[i+1][n-1],...,w[i][n-2],w[i+1][n-2],...

#define NUM_DATA  160  // Number of samples per block
Int16   out[NUM_DATA]; // Filter output data buffer
Int16   in[NUM_DATA];  // Filter input data buffer

double gain200[13][2]={ // Parameter at 200 Hz
	// rz     rp
	{0.8900, 0.8000},  // -6 dB
	{0.8775, 0.8000},  // -5 dB
	{0.8640, 0.8000},  // -4 dB
	{0.8495, 0.8000},  // -3 dB
	{0.8340, 0.8000},  // -2 dB
	{0.8174, 0.8000},  // -1 dB
	{0.8000, 0.8000},  // 0 dB
	{0.8000, 0.8174},  // 1 dB
	{0.8000, 0.8340},  // 2 dB
	{0.8000, 0.8495},  // 3 dB
	{0.8000, 0.8640},  // 4 dB
	{0.8000, 0.8775},  // 5 dB
	{0.8000, 0.8900}}; // 6 dB

double gain1000[13][2]={ // Parameter at 1000 Hz
	// rz     rp
	{0.9048, 0.8000},  // -6 dB
	{0.8925, 0.8000},  // -5 dB
	{0.8784, 0.8000},  // -4 dB
	{0.8627, 0.8000},  // -3 dB
	{0.8445, 0.8000},  // -2 dB
	{0.8238, 0.8000},  // -1 dB
	{0.8000, 0.8000},  // 0 dB
	{0.8000, 0.8238},  // 1 dB
	{0.8000, 0.8445},  // 2 dB
	{0.8000, 0.8627},  // 3 dB
	{0.8000, 0.8784},  // 4 dB
	{0.8000, 0.8925},  // 5 dB
	{0.8000, 0.9048}}; // 6 dB

enum {
	NEG_6dB=0,NEG_5dB,NEG_4dB,NEG_3dB,NEG_2dB,NEG_1dB,
	ZERO_dB,POS_1dB,POS_2dB,POS_3dB,POS_4dB,POS_5dB,POS_6dB
};

    
void coefGen(double (*gainTbl)[2], Int16 gain, Int16 *c, float freq);
void wHdUpdt(Uint8 *w, Uint32 bytes);

void main(void)
{

    FILE *fpIn,*fpOut;
    Int8  temp[NUM_DATA*2];
    Uint8  waveHeader[44];
    Int16 i,k,c;
    Uint32 cnt;

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

    if (c == 2)                    // Create WAV data file header
    {
    	fread(waveHeader, sizeof(Int8), 44, fpIn);
    	fwrite(waveHeader, sizeof(Int8), 44, fpOut);
    }

    if (fpIn == NULL)
    {
        printf("Can't open input PCM file\n");
        exit(0);
    }

    // Generate filter coefficients for high band
    coefGen(gain1000, NEG_6dB, &C[0], 1000);
	
    // Generate filter coefficients for low band
    coefGen(gain200, POS_6dB, &C[5], 200);

    // Initialize IIR filter delay line 
    for (i=0; i<2*SECTIONS;i++)
    {
        w[i] = 0; 
    }
    cnt = 0;

    printf("Exp --- IIR filter EQ experiment\n");

    // Start equalizer test
    while (fread(temp, sizeof(Int8), NUM_DATA*2, fpIn) == (NUM_DATA*2))
    {
        for (k=0, i=0; i<NUM_DATA; i++)
        {
            in[i] = (temp[k]&0xFF)|(temp[k+1]<<8);
            k += 2;
        }

        cascadeIIR(in,NUM_DATA,out,C,SECTIONS,w); // Filter a block of samples  

        for (k=0, i=0; i<NUM_DATA; i++)
        {
            temp[k++] = (out[i]&0xFF);
            temp[k++] = (out[i]>>8)&0xFF;
            cnt += 2;
        }

        fwrite(temp, sizeof(Int8), NUM_DATA*2, fpOut);
    }

    if (c == 2)		// Based on input WAVE file to generate output
    {
    	wHdUpdt(waveHeader, cnt);
    	rewind(fpOut);
    	fwrite(waveHeader, sizeof(Int8), 44, fpOut);
    }
    fclose(fpIn);
	fclose(fpOut);
  	printf("Exp --- completed\n");
}


// Generate coefficient using the following equations
//  b = [1, -2*rz*cos(w), rz*rz];
//  a = [1, -2*rp*cos(w), rp*rp];
//  w = 2*PI*freq/F: F = 8000Hz

void coefGen(double (*gainTbl)[2], Int16 gain, Int16 *c, float freq)
{
	double rz,rp,temp,omega;

	rz = gainTbl[gain][0];              // Get rz from the lookup table
	rp = gainTbl[gain][1];              // Get rp from the lookup table

	omega = 2.0*3.1415926*freq/8000.0;  // This example uses 8kHz sampling rate

	c[3] = 0x4000;                      // b[0] Q14 coefficient
	temp = -2.0*rz*cos(omega);
	c[4] = (Int16)(temp*16384.0+0.5);   // b[1]
	c[2] = (Int16)(rz*rz*16384.0+0.5);  // b[2]

	temp = -2.0*rp*cos(omega);
	c[0] = (Int16)(temp*16384.0+0.5);   // a[1]
	c[1] = (Int16)(rp*rp*16384.0+0.5);  // a[2]
}

// Update the wave file header
void wHdUpdt(Uint8 *w, Uint32 bytes)
{
	Int32 t;

	t = bytes;
	w[40] = (t>>0)&0xff;	// Set up output file size
	w[41] = (t>>8)&0xff;
	w[42] = (t>>16)&0xff;
	w[43] = (t>>24)&0xff;
	t += 36;
	w[4] = (t>>0)&0xff;
	w[5] = (t>>8)&0xff;
	w[6] = (t>>16)&0xff;
	w[7] = (t>>24)&0xff;
}
