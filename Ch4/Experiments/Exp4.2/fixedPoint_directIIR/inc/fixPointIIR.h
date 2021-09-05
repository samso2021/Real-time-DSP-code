/*
* fixPointIIR.h
*
*  Created on: May 25, 2012
*      Author: BLEE
*
*  Description: This is the header file for the fixed-point IIR filter in direct form-I
*
*  For the book "Real Time Digital Signal Processing:
*                Fundamentals, Implementation and Application, 3rd Ed"
*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
*                Publisher: John Wiley and Sons, Ltd
*
*/

void fixPoint_IIR(Int16 in, Int16 *x, Int16 *y,
                  Int16 *b, Int16 nb, Int16 *a, Int16 na);
