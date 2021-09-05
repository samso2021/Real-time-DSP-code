/*
 * float_fft.h
 *
 *  Created on: May 29, 2012
 *      Author: BLEE
 *
 *  Description: This is the C header file for FFT experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

extern void fft(complex *, Uint16, complex *, Uint16, Uint16);
extern void bit_rev(complex *, Int16);

#define N 128           /* Number of FFT points */
#define EXP 7           /* EXP=log2(N) */
#define pi 3.1415926535897  
#define K 3             /* Index of Xk (0<K< N/2) */ 
 
