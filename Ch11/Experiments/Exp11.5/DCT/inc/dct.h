/*
* dct.h
*
*  Created on: Jul 27, 2012
*      Author: BLEE
*
*  Description: This is the C header file for DCT experiment
*
*  For the book "Real Time Digital Signal Processing:
*                Fundamentals, Implementation and Application, 3rd Ed"
*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
*                Publisher: John Wiley and Sons, Ltd
*
*/

// -------- structure and prototype for function - YCbCr2RGB -----------

typedef struct {
    Uint16 *y;                // Input: pointer to Y element buffer
    Uint16 *cb;               // Input: pointer to Cb element buffer
    Uint16 *cr;               // Input: pointer to Cr element buffer
    Uint16 *r;                // Output: pointer to R element buffer
    Uint16 *g;                // Output: pointer to G element buffer
    Uint16 *b;                // Output: pointer to B element buffer
    Uint16 width;             // Input: image width
    Uint16 height;            // Input: image height
} ycbcr2rgbImg;

void ycbcr2rgb(ycbcr2rgbImg img);
void createBMPHeader(Uint16 *bmpHeader, Uint16 width, Uint16 height);

void dct8x8(Int16 *block, Int16 (*dctCoef)[8]);
void idct8x8(Int16 *block, short (*idctCoef)[8]);
void DCTcoefGen(Int16 (*dctCoef)[8], Int16 dctidct);

