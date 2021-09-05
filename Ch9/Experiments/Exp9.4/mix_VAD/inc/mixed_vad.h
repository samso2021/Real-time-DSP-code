/*
 * mixed_vad.h
 *
 *  Created on: May 31, 2012
 *      Author: BLEE
 *
 *  Description: Header file for global variables and functions definition-point
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#define PI          3.1415926
#define EXP         8
#define LL          256           // Maximum FFT size
#define HOV         3             // Hangover time shorter
#define MAX16       32767         // Maximum of 16-bit data
#define FrameSize   256 
#define Fs          8000.0        // Sampling frequency
#define Fl          250.0         // End frequency
#define Fh          820.0         // High frequency
#define EE          (Int16)(Fh*(float)(1<<EXP)/Fs)
#define SS          (Int16)(Fl*(float)(1<<EXP)/Fs)


typedef struct {
  Int16 re;
  Int16 im;
} complex;

typedef struct {
  Int32 re;
  Int32 im;
} lcomplex;


enum Boolean
{
  FFT,IFFT
};

typedef struct
{
	Int32   thres;          // Threshold for power estimation
	Int32   En;             // Current frame power
	Int32   Em;             // Medium window power
	Int32   margin;         // Safety margin
	Int32   Nf;             // Estimated noise floor
    Int16   hov;            // Number of frames for hangover time
    Int16   ss;             // Starting freq. bin for VAD
    Int16   ee;             // Ending freq. bin for VAD
    Int16   Lm;             // Length of medium window
    Int16   Ll;             // Length of long window
    Int16   alphal;         // Constant for updating long window power
    Int16   al1;            // 1. - alphal
    Int16   alpham;         // Constant for updating medium window power
    Int16   am1;            // 1. - alpham
    Int16   *pwindow;       // Pointer for Hamming window
} MIXVAD;

extern MIXVAD  mixVad;
extern Int16   HBV[LL/2];      // Input buffer for previous frame
extern Int16   DV[LL/2];       // Buffer used for overlap
extern Int16   window[LL/2];   // Window coefficients
extern complex D[LL];          // Buffer used to store complex data
extern complex U[LL];          // Twiddle e^(-j2pi/N) table
extern Int16   inputbuf[LL/2]; // Input buffer


Int16 vad_pre(Int16 *, Int16, Int16, Int16 *);
Int16 vad(void);
void  vad_init(Int16);
void  hmwindow(Int16);
Int32 L_mls(Int32, Int16);
Int16 s_sqrt(Int32);

void  fft(complex *, Uint16, complex *, Uint16, Uint16);
void  bit_rev(complex *, Uint16);
void  w_table(complex *);


