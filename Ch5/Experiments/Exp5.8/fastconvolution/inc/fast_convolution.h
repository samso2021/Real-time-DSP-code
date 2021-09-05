/*
* fast_convolution.h
*
*  Created on: Oct 14, 2012
*      Author: BLEE
*
*  Description: This C header file defines the data types used
*
*  For the book "Real Time Digital Signal Processing:
*                Fundamentals, Implementation and Application, 3rd Ed"
*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
*                Publisher: John Wiley and Sons, Ltd
*
*/

#define FLT_LEN   511                 // Filter length
#define FFT_PTS   1024                // FFT size
#define DATA_LEN  (FFT_PTS+1-FLT_LEN) // Data segment length
#define EXP 10               	      // EXP = log2(FFT_PTS)

#define FFT_FLAG     0
#define IFFT_FLAG    1
#define SCALE_FLAG   0
#define NOSCALE_FLAG 1

extern void fft(complex *, Uint16, complex *, Uint16, Uint16);
extern void bit_rev(complex *, Uint16);
extern void w_table(complex *, Uint16);
extern void olap_add(complex *, Int16 *, Uint16, Uint16);
extern void freqflt(complex *, complex *, Uint16);
