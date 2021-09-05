/*
 * cng.h
 *
 *  Created on: Sep 16, 2012
 *      Author: BLEE
 *
 *  Description: This is the C header file for CNG functions
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

enum {
	VOICE,
	SID,
	UNTX,
	REPT
};

#define BLOCKSIZE 512
#define LOG32767 90.3087
void noise_gen(Int16 gain, Int16 *output, Int16 frameSize);
Uint16 sid_dec(Uint8 noiseLevel);
