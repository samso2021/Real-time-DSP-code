/*
 * wavelet.h
 *
 *  Created on: July 29, 2012
 *      Author: BLEE
 *
 *  Description: This C header file with wavelet experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

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
void IMG_wave_decom_two_dim(Int16 **image, Int16 * wksp, Int16 width, Int16 height, Int16 *wavename, Int16 level);
void IMG_wave_recon_two_dim(Int16 **image, Int16 * wksp, Int16 width, Int16 height, Int16 *wavename, Int16 level);
void IMG_wavep_decom_two_dim(Int16 **image, Int16 * wksp, Int16 width, Int16 height, Int16 *wavename, Int16 level);
void IMG_wavep_recon_two_dim(Int16 **image, Int16 * wksp, Int16 width, Int16 height, Int16 *wavename, Int16 level);
void col2row(Int16 *col, Int16 *row, Int16 IMAGE_WIDTH, Int16 HEIGHT);
void decomInplace(Int16 *singal, Int16 *wksp, Int16 LENGTH, Int16 *wavename);
void decomCol(Int16 *signal, Int16 *low_out, Int16 *high_out, Int16 IMAGE_WIDTH, Int16 HEIGHT, Int16 *wavename);
void interlaceCol(Int16 *low, Int16 *high, Int16 *output, Int16 IMAGE_WIDTH, Int16 HEIGHT, Int16 filter_length);
void reconInplace(Int16 *input, Int16 *output, Int16 length, Int16 *wavename );
void reconCol(Int16 *input, Int16 *col, Int16 IMAGE_WIDTH, Int16 HEIGHT, Int16 *wavename);

extern Int16 db2[17];
extern Int16 db3[25];
extern Int16 db4[33];
extern Int16 db5[41];
extern Int16 db6[49];
extern Int16 db7[57];
extern Int16 db8[65];
extern Int16 db9[73];
extern Int16 db10[81];

