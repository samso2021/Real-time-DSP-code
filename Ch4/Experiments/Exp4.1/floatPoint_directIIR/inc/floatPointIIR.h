/*
* floatPointIIR.h
*
*  Created on: May 25, 2012
*      Author: BLEE
*
*  Description: This is the header file for the floating-point IIR filter in direct form-I
*
*  For the book "Real Time Digital Signal Processing:
*                Fundamentals, Implementation and Application, 3rd Ed"
*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
*                Publisher: John Wiley and Sons, Ltd
*
*/

void floatPoint_IIR(double in, double *x, double *y, 
                    double *b, short nb, double *a, Int16 na);
