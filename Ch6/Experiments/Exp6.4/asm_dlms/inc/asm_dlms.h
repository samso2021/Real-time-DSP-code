/*
 * asm_dlms.h
 *
 *  Created on: June 6, 2012
 *      Author: BLEE
 *
 *  Description: This is the C header file for LMS experiment
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

#define N  100                  // Number of data to process each time
#define L  128                  // LMS adaptive filter length
#define STEP 655                // Step size

typedef struct {
    Int16 *in;                  // pointer to input data
    Int16 *des;                 // pointer to desired data
    Int16 *out;                 // pointer to output data
    Int16 *w;                   // pointer to coefficients
    Int16 *x;                   // pointer to data delay line
    Int16 *e  ;                 // pointer to error
    Int16 step;                 // step size
    Int16 order;                // filter length
    Int16 size;                 // Data sample block size
    Int16 index;                // Data delay line index for circular buffer
} LMS;

Uint16 asm_dlms(LMS *lmsObj);


