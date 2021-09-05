/*
* spatialSound.c
*
*  Created on: Oct 28, 2012
*      Author: BLEE
*
*  Description: This program contains functions for floating-point spatial sound effect
*
*  For the book "Real Time Digital Signal Processing:
*                Fundamentals, Implementation and Application, 3rd Ed"
*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
*                Publisher: John Wiley and Sons, Ltd
*
*/

#include <stdio.h>
#include <math.h>
#include "tistdtypes.h"
#include "spatialSound.h"

// L -90,-60,-30,0,+30,+60,+90
// distant 20 meter
#define SCALE_FACTOR 0.4
static float IID[SAMPLEPOINTS][SIDES] =
{	
	{0.80/SCALE_FACTOR,0.20/SCALE_FACTOR},	//-75	Left, Right
	{0.74/SCALE_FACTOR,0.26/SCALE_FACTOR},	//-60	Left, Right
	{0.68/SCALE_FACTOR,0.32/SCALE_FACTOR},	//-45	Left, Right
	{0.62/SCALE_FACTOR,0.38/SCALE_FACTOR},	//-30	Left, Right
	{0.56/SCALE_FACTOR,0.44/SCALE_FACTOR},	//-15	Left, Right
	{0.50/SCALE_FACTOR,0.50/SCALE_FACTOR},	// 0	center
	{0.44/SCALE_FACTOR,0.56/SCALE_FACTOR},	//+15	Left, Right
	{0.38/SCALE_FACTOR,0.62/SCALE_FACTOR},	//+30	Left, Right
	{0.32/SCALE_FACTOR,0.68/SCALE_FACTOR},	//+45	Left, Right
	{0.26/SCALE_FACTOR,0.74/SCALE_FACTOR},	//+60	Left, Right
	{0.20/SCALE_FACTOR,0.80/SCALE_FACTOR},	//+75	Left, Right
};

// Relative to the center of the head in ms
#define MULT_FACTOR  (ONESECOND/1000.0)
static float ITD[SAMPLEPOINTS][SIDES] =
{	
	{0.0*MULT_FACTOR,1.0*MULT_FACTOR},	//Left, Right
	{0.1*MULT_FACTOR,0.9*MULT_FACTOR},	//Left, Right
	{0.2*MULT_FACTOR,0.8*MULT_FACTOR},	//Left, Right
	{0.3*MULT_FACTOR,0.7*MULT_FACTOR},	//Left, Right
	{0.4*MULT_FACTOR,0.6*MULT_FACTOR},	//Left, Right
	{0.5*MULT_FACTOR,0.5*MULT_FACTOR},  //Center
	{0.6*MULT_FACTOR,0.4*MULT_FACTOR},	//Left, Right
	{0.7*MULT_FACTOR,0.3*MULT_FACTOR},	//Left, Right
	{0.8*MULT_FACTOR,0.2*MULT_FACTOR},	//Left, Right
	{0.9*MULT_FACTOR,0.1*MULT_FACTOR},	//Left, Right
	{1.0*MULT_FACTOR,0.0*MULT_FACTOR},	//Left, Right
};
 
// This is the initialization function, to generate the gain table
#define W (3.1415926*15.0/180.0)
void spatialInit(spatial *t, Uint32 samples)
{
	float temp;
	Int16 i;
	t->Gain[SAMPLEPOINTS/2] = 1.0;
	t->segmentSamples = samples;
	for(i=1; i<=SAMPLEPOINTS/2; i++)
	{
		temp = cos(W*i);
		t->Gain[(SAMPLEPOINTS/2) + i] = temp;
		t->Gain[(SAMPLEPOINTS/2) - i] = temp;
		t->n = 0;
	}
 }

// Round to Int16
Int16 rounding16(float xd)
{
	Int16 y16;
	
	xd = xd +0.5;

	if(xd > 32767.0) y16 = 32767;
	else if (xd < -32768.0) y16 = -32768;
	else y16 = (Int16) xd;

	return y16;
 }

// Spatial sound processing function
void procSpatialSound(Int16 *out16, spatial *t)
{
	float yL,yR;
	Int16 i;

	yL = interpolate(t->mITD[LEFT]);
	yR = interpolate(t->mITD[RIGHT]);

	yL *= t->mIID[LEFT];
	yR *= t->mIID[RIGHT];

	out16[0] = rounding16(yL);
	out16[1] = rounding16(yR);

	/* Two points linear interpolation */
	/* Rotate buffer ready for next new sample in */
	for(i = MAX_BUF_SIZE-1; i> 0; i--)
	{
		d_buffer[i ] = d_buffer[i-1];
	}
}
 
void CalculateIID(spatial *t)
{
	Int32 segment = (Int32)(t->n/t->segmentSamples);
	t->mIID[LEFT] = t->Gain[segment] * IID[segment][LEFT];
	t->mIID[RIGHT] = t->Gain[segment] * IID[segment][RIGHT];
}

void CalculateITD(spatial *t)
{
	Int32 segment = (Int32)(t->n/t->segmentSamples);
	t->mITD[LEFT] = ITD[segment][LEFT];
	t->mITD[RIGHT] = ITD[segment][RIGHT];
}

// Linear interpolation 
float interpolate(float var_delay)
{
	Int32 iy0, iy1;
	float y0, y1;
	float fracY,yout;

	iy0 = (Int32)(var_delay);			// Latest
	iy1 = (Int32)(var_delay +1.0);		// History

	/* Two points linear interpolation */
	y0 = (float)d_buffer[iy0];
	y1 = (float)d_buffer[iy1];
	fracY = (float)(1.0 - (var_delay - (float)iy0));
	yout = fracY*y0 + (1.0-fracY)* y1;

	return yout;
}

