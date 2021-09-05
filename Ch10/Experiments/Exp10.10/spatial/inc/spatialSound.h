/*
* spatialSound.h
*
*  Created on: Oct 28, 2012
*      Author: BLEE
*
*  Description: This is the C header file for floating-point spatial sound effect experiment
*
*  For the book "Real Time Digital Signal Processing:
*                Fundamentals, Implementation and Application, 3rd Ed"
*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
*                Publisher: John Wiley and Sons, Ltd
*
*/

#ifndef __SPATIALSOUND_H__
#define __SPATIALSOUND_H__
 
#define MAX_BUF_SIZE 2048
#define ONESECOND 8000	// number of samples per sec
#define SAMPLEPOINTS 11
#define LEFT  0
#define RIGHT 1
#define SIDES 2
#define SEGMENTSAMPLES 16000

typedef struct {
	float Gain[SAMPLEPOINTS];
	float mIID[2];
	float mITD[2];
	Int32 n;
	Uint32 segmentSamples;
} spatial;


void  spatialInit(spatial *t, Uint32 samples);
void  procSpatialSound(Int16 *out16, spatial *t);
void  CalculateIID(spatial *t);
void  CalculateITD(spatial *t);
float interpolate (float var_delay);

extern Int16 d_buffer[MAX_BUF_SIZE];

#endif
