/*
 * fixedPoint_leaky_lms.h
 *
 *  Created on: June 5, 2012
 *      Author: BLEE
 *
 *  Description: This is the C headrer file for fixed-point leaky LMS experiment
 *
 *               The input is a 1kHz sine wave sampling rate 8kHz with noise
 *               The output is the sine wave
 *               The error is the noise
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#define L       128                    // LMS adaptive filter length
#define MU      (Int16)(0.003*32767)   // LMS adaptive filter step size
#define ROUND   0x4000                 // Rounding for fixed point arithmatic
#define LEAKY   (Int16)(0.999*32767)   // Leaky factor

typedef struct {
	Int16 in;                   // Input data
	Int16 des;                  // Desired data
	Int16 out;                  // Output data
	Int16 order;                // Filter length
	Int16 mu;                   // Step size
	Int16 err;                  // Error
	Int16 leaky;                // Leaky factor
	Int16 *w;                   // Pointer to coefficients
	Int16 *x;                   // Pointer to data delay line
} LMS;

void fixPoint_leaky_lms(LMS *lmsObj);
