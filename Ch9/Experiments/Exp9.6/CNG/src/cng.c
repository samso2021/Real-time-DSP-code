/*
 * cng.c
 *
 *  Created on: Sep 16, 2012
 *      Author: BLEE
 *
 *  Description: This program contains CNG functions
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include <stdlib.h>
#include "tistdtypes.h"
#include "cng.h"
Int16 pow10xTable[50]={
		0x0001,	0x0001,	0x0001,	0x0001,	0x0002,	0x0003,	0x0003,	0x0005,	0x0006,	0x0007,
		0x000A,	0x000C,	0x000F,	0x0013,	0x0019,	0x001F,	0x0027,	0x0032,	0x003F,	0x004F,
		0x0064,	0x007D,	0x009E,	0x00C7,	0x00FB,	0x013C,	0x018E,	0x01F5,	0x0276,	0x031A,
		0x03E7,	0x04EA,	0x0630,	0x07CB,	0x09CF,	0x0C5A,	0x0F8D,	0x1393,	0x18A5,	0x1F07,
		0x270F,	0x312D,	0x3DE8,	0x4DF0,	0x621E,	0x7B86,	0x7FFF,	0x7FFF,	0x7FFF,	0x7FFF};


Uint16 sid_dec(Uint8 noiseLevel)
{
	Int16 temp;

	temp = _ssub((Int16)LOG32767, noiseLevel);

	if (temp < 0)
	{
		temp = 0;
	}
	if (temp > 49 )
	{
		temp = 49;
	}
	temp = pow10xTable[temp];

	return temp;
}

void noise_gen(Int16 gain, Int16 *output, Int16 frameSize)
{
	Int16 i;

	for( i = 0; i < frameSize; i++ )
	{
		output[i] = _sshl(_smpy(gain, _ssub(rand(), 16384)), 1);
	}
}
