/*
 * floatPoint_nr.h
 *
 *  Created on: Sep 9, 2012
 *      Author: BLEE
 *
 *  Description: This is the C header file for spectrum subtraction noise reduction experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

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
    float   Ll;             // Length of long window
    float   Nf;             // Estimated noise floor
    float   *pwindow;       // Pointer for Hamming window

    float   HBV[LL/2];      // Input buffer for previous frame
    float   DV[LL/2];       // Buffer used for overlap
    float   window[LL/2];   // Window coefficients
    float   TB[LL/2+1];     // Signal spectrum of current frame
    float   NS[LL/2+1];     // Noise spectrum

    Complex D[LL];          // Buffer used to store complex data

    Int16   flag;           // Flag = 1,speech; flag = 0,silence
    Int16   vadFlag;        // VAD detection flag

    float   En;             // Current frame power
    float   Noise_scale;    // To scale noise bin
    float   Atten;          // Noise reduction attenuation factor
    float   tmp;            // Temporary memory used in power estimation
    float   h[LL/2+1];      // Signal spectrum of current frame

} NR_VAR;

extern NR_VAR    *pnr;

void  nr_hwindow(NR_VAR *pnr);
void  nr_init(NR_VAR *pnr);
Int16 nr_ss(NR_VAR *pnr);
Int16 nr_vad (NR_VAR *pnr);
void  nr_fft(Complex *x, Int16 n, Int16 fft_ifft);
void  nr_proc(NR_VAR *pnr);
