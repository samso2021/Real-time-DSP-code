/*
 * asm_dft128.h
 *
 *  Created on: May 29, 2012
 *      Author: BLEE
 *
 *  Description: This is the C header file for the assembly DFT experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#define  N 128
void dft_128(Int16 *, Int16 *);
void mag_128(Int16 *, Int16 *);
