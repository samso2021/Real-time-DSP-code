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
 
#define ONESECOND 8000	// number of samples per sec
#define SAMPLEPOINTS 11
#define LEFT  0
#define RIGHT 1
#define SIDES 2
#define SEGMENTSAMPLES (ONESECOND*2)

typedef struct {
	float Gain[SAMPLEPOINTS];
	float mIID[2];
	float mITD[2];
	Int32 n;
} spatialRT;


void  spatialInit(spatialRT *t);
void  procSpatialSound(Int16 *out16, spatialRT *t);
void  CalculateIID(spatialRT *t);
void  CalculateITD(spatialRT *t);
float interpolate (float var_delay);

#endif
