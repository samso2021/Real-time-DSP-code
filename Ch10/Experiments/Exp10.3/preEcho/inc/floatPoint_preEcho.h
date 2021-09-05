/*
 * floatPoint_preEcho.h
 *
 *  Created on: Oct 26, 2012
 *      Author: BLEE
 *
 *  Description: This is the C header for floating-point MDCT/IMDCT/pre-echo experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#ifndef MDCT_INCLUDE
#define MDCT_INCLUDE

#define FRAME 512        /* 64 or 512 */
#define NUM_QNT 64
#define PI 3.1415926

void mdct(Int16 *in, Int16 *out, Int16 N);
void inv_mdct(Int16 *in, Int16 *out, Int16 N);
void mdct_init(Int16 N);
void mdct_qnt( Int16 *mdct_enc16, Int16 M, float QuantStep);

extern float win[FRAME];
extern float cos_dec[4*FRAME];
extern float QuantStep;
#endif
