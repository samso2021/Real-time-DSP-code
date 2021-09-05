/*
 * intrinsic_nlms.h
 *
 *  Created on: June 5, 2012
 *      Author: BLEE
 *
 *  Description: This is the intrinsic normalize LMS experiment header file
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
#define ALPHA   (1.0*32767)            // LMS adaptive filter step size
#define ROUND   0x4000                 // Rounding for fixed point arithmetic
#define C       0x20                   // Safety factor
#define BETA    (short)(0.99*32767)    // Beta for integrating
#define ONE_MINUS_BETA (32767-BETA)

typedef struct {
    long alpha;                 // Alpha
    short in;                   // Input data
    short des;                  // Desired data
    short out;                  // Output data
    short order;                // Filter length
    short err;                  // Error
    short c;                    // Safety factor
    short power;                // Power
    short *w;                   // Pointer to coefficients
    short *x;                   // Pointer to data delay line
} LMS;

void intrinsic_nlms(LMS *lmsObj);
