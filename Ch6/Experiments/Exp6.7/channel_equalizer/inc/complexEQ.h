/*
 * complexEQ.h
 *
 *  Created on: Oct 20, 2012
 *      Author: BLEE
 *
 *  Description: This is the C header file for adaptive channel equalizer experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

typedef struct {
    Int16 re;
    Int16 im;
} COMPLEX;

// ITU V.29 9600 bps training points
#define UNIT        0x1000
#define C_REAL      (Int16)0
#define C_IMAG      (Int16)(3*UNIT)
#define D_REAL      (Int16)(-3*UNIT)
#define D_IMAG      (Int16)(3*UNIT)

// Force training constants, reference: ITU V.29
#define INIT_X      0x2A						// 0101010b
#define NUM_SIMBOL  384
#define THRESHOLD   (Int32)(0x4000000)

#define EQ_ORDER    32							// Adaptive filter order

Int16   randGen(Int16 *);
void    signalGen(COMPLEX *);
void    equalizer(COMPLEX *, COMPLEX *, COMPLEX *);
void    channel(COMPLEX, COMPLEX *, COMPLEX *);

extern COMPLEX txSignal[NUM_SIMBOL];           // Transmitter force training signal
extern COMPLEX rxDesire[NUM_SIMBOL];           // Receiver local desired signal
extern COMPLEX x[EQ_ORDER+1],w[EQ_ORDER+1];    // NLMS delayline and coefficients
extern COMPLEX power,mu,error;                 // NLMS variables
extern COMPLEX ch_x[3],ch_y[3];                // Simulated channel delay line
extern Int16   txCnt;                          // Transmit symbol count
