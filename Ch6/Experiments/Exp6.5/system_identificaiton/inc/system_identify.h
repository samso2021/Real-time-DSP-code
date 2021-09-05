/*
 * system_identify.h
 *
 *  Created on: June 6, 2012
 *      Author: BLEE
 *
 *  Description: This is the C header file for system identification experiment
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

#define N0      48              // Adaptive filter order     
#define N1      48              // Unknown filter order 
#define Ns      128             // Number of input signal 

typedef struct {
    Int16 *in;                  // pointer to input data
    Int16 *des;                 // pointer to desired data
    Int16 *x;                   // pointer to data delay line
    Int16 *w;                   // pointer to coefficients
    Int16 size;                 // Data sample block size
    Int16 order;                // filter length
    Int16 index;                // Data delay line index for circular buffer
} ADAPTSYSID;

typedef struct {
    Int16 *in;                  // pointer to input data
    Int16 *out;                 // pointer to output data
    Int16 *x;                   // pointer to data delay line
    Int16 *w;                   // pointer to coefficients
    Int16 size;                 // Data sample block size
    Int16 order;                // filter length
    Int16 index;                // Data delay line index for circular buffer
} UNKNOWNSYS;


Uint16 unknowPlant(UNKNOWNSYS *unknown);
Uint16 sysIdentification(ADAPTSYSID *adaptSys);
