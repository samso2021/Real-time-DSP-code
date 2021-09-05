/*
 * floatPoint_sid.c
 *
 *  Created on: Sep 11, 2012
 *      Author: BLEE
 *
 *  Description: This is the SID (silence insertion description) function
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include <math.h>
#include "tistdtypes.h"
#include "floatPoint_dtx.h"

#define LOG32767	90.3087

unsigned char sid_enc(float sidEng,Int16 frameSize)
{

    Int16 temp;
	float tempf = ((float)sidEng);

	if(tempf < 1) tempf =1;


	tempf = -10.*log10(tempf)+ LOG32767;
	tempf = tempf + 0.5;			// Rounding
	temp = (Int16) tempf;


	if (temp < 0) temp = 0;
	if (temp > 90 ) temp = 90; 	

    return (unsigned char)(temp);

}
