/*
 *  filter2D.h
 *
 *  Created on: Jul 22, 2012
 *      Author: BLEE
 *
 *  Description: This is the C header file for 2D filter experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#define I         3
#define J         3
#define SHIFT    10

typedef struct {
	Int16  I2D;
	Int16  J2D;
	Int16  state;
	Int16  shift;
	Int16  *filter;
    Uint16 *inData;
    Uint16 *outData;
	Int16  imWidth;
} IMFILTER;

void filter2D(IMFILTER *imfilt);
