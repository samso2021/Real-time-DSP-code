/*
 * Experiment decimation using FIR filter - Chapter 3
 * coef48to24.h
 *
 * Description: This is the filter coefficient file for a 2:1 decimation FIR filter
 *
 *  Created on: May 13, 2012
 *      Author: BLEE
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#define Q15 32767

Int16 deciFilt48to24[TAPS48to24]={
(Int16)(0.001471*Q15),
(Int16)(-0.007929*Q15),
(Int16)(-0.027013*Q15),
(Int16)(-0.031867*Q15),
(Int16)(0.017209*Q15),
(Int16)(0.130256*Q15),
(Int16)(0.255831*Q15),
(Int16)(0.311233*Q15),
(Int16)(0.255831*Q15),
(Int16)(0.130256*Q15),
(Int16)(0.017209*Q15),
(Int16)(-0.031867*Q15),
(Int16)(-0.027013*Q15),
(Int16)(-0.007929*Q15),
(Int16)(0.001471*Q15)
};
