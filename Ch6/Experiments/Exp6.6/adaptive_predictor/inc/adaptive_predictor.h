/*
 *  adaptive_predictor.h
 *
 *  Created on: June 6, 2012
 *      Author: BLEE
 *
 *  Description: This is the C header file for adaptive line predictor experiment
 *
 *               The input is a sine wave with white noise interference
 *               The adaptive line predictor will output both s(n) and v(n)
 *
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#define L   128                 // Adaptive FIR filter order 
#define Ns	256                 // Number of input signal per block 

typedef struct {
    Int16 *in;                  // Pointer to input data
    Int16 *y;                   // Pointer to output data
    Int16 *e;                   // Pointer to error
    Int16 *x;                   // Pointer to data delay line
    Int16 *w;                   // Pointer to coefficients
    Int16 size;                 // Data sample block size
    Int16 order;                // Filter length
    Int16 index;                // Data delay line index for circular buffer
} ADAPTLP;

Uint16 adaptivePredictor(ADAPTLP *alp);
