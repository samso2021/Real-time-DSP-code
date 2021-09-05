/*
 * floatPoint_mdct.h
 *
 *  Created on: Oct 26, 2012
 *      Author: BLEE
 *
 *  Description: This is the C header file for direct MDCT and inverse MDCT experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#ifndef MDCT_INCLUDE
#define MDCT_INCLUDE

#define FRAME 36
#define PI 3.1415926

void mdct(Int16 *in, Int16 *out, Int16 N);
void inv_mdct(Int16 *in, Int16 *out, Int16 N);
void mdct_init(Int16 N);

extern float win[FRAME];
extern float cos_enc[FRAME>>1][FRAME];
extern float cos_dec[4*FRAME];

#endif
