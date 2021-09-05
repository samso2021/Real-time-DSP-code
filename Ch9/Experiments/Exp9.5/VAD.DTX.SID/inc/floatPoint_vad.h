/*
 * floatPoint_vad.h
 *
 *  Created on: Sep 11, 2012
 *      Author: BLEE
 *
 *  Description: This is the C header file for VAD functions and variables
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#ifndef VADHEADER_H
#define VADHEADER_H
typedef struct 
{
  float real;
  float imag;
} Complex;

enum 
{
  FFT,IFFT
};

#define PI          3.1415926
#define LL          512             // Maximum FFT size
#define Fs          8000            // Sampling frequency
#define Fl          250             // Low frequency
#define Fh          820             // Up frequency
#define HOV         2               // Hangover time shorter 
#define MAX16       32767.0         // Maximum of 16-bit data
#define ALPHALATER  0.0125          // Constant used in updating noise spectrum
#define ALPHALATER1 1.0-0.0125      // Constant used in updating noise spectrum
#define FrameSize   256             // Better integer of 256

typedef struct {
    Int16   hov;            // Number of frames for hangover time
    Int16   ss;             // Starting freq. bin for VAD
    Int16   ee;             // Ending freq. bin for VAD
    Int16   L;              // Length of FFT and IFFT
    Int16   N;              // Length of overlap window
    Int16   *pIn;           // Input data buffer pointer

    float   thres;          // Threshold for power estimation
    float   alpha;          // Constant used in updating noise spectrum at start
    float   alpha1;         // Constant used in updating noise spectrum
    float   Em;             // Medium window power
    float   margin;         // Safety margin
    float   alphal;         // Constant for updating long window power
    float   al1;            // 1. - alphal
    float   alpham;         // Constant for updating medium window power
    float   am1;            // 1. - alpham
    float   Lm;             // Length of medium window
    float   Ll;             // length of long window
    float   Nf;             // Estiamted noise floor
    float   *pwindow;       // Pointer for Hamming window

    float   HBV[LL/2];      // Input buffer for previous frame
    float   DV[LL/2];       // Buffer used for overlap
    float   window[LL/2];   // Window coefficients
    float   TB[LL/2+1];     // Signal spectrum of current frame
    float   NS[LL/2+1];     // Noise spectrum

    Complex D[LL];          // Buffer used to store complex data
} VAD_VAR;

extern VAD_VAR    *pvad;

void  vad_hwindow(VAD_VAR *pvad);
void  vad_init(VAD_VAR *pvad);
Int16 vad_ss(VAD_VAR *pvad);
Int16 vad_vad (VAD_VAR *pvad);
void  vad_fft(Complex *x, Int16 n, Int16 fft_ifft);

#endif 
