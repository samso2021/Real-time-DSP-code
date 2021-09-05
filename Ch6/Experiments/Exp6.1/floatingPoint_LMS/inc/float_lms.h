/*
 * float_lms.h
 *
 *  Created on: June 5, 2012
 *      Author: BLEE
 *
 *  Description: This is the C header file for floating-point adaptive LMS program
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#define L       128     // LMS adaptive filter length
#define MU      0.003   // LMS adaptive filter step size

typedef struct {
    double in;          // Input data
    double des;         // Desired data
    double out;         // Output data
    Int16  order;       // Filter length
    double mu;          // Step size
    double err;         // Error
    double *w;          // Pointer to coefficients
    double *x;          // Pointer to data delay line
} LMS;

void float_lms(LMS *lmsObj);
