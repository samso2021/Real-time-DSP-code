/*
*  YCbCr2RGB.c
*
*  Created on: Jul 27, 2012
*      Author: BLEE
*
*  Description: This C file converts YCbCr color space to RGB color space
*
*  For the book "Real Time Digital Signal Processing:
*                Fundamentals, Implementation and Application, 3rd Ed"
*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
*                Publisher: John Wiley and Sons, Ltd
*
* input: - data is assumed to be packed in 8-bit and stored separated in Y, Cb, and Cr
* output: - data is assumed to be packed in 8-bit and stored separated in R, G, and B
*
* data structure:
* typedef struct {
*    unsigned short *y;                // Input: pointer to Y element buffer
*             short *cb;               // Input: pointer to Cb element buffer
*             short *cr;               // Input: pointer to Cr element buffer
*    unsigned short *r;                // Output: pointer to R element buffer
*    unsigned short *g;                // Output: pointer to G element buffer
*    unsigned short *b;                // Output: pointer to B element buffer
*    unsigned short width;             // Input: image width
*    unsigned short height;            // Input: image height
*} ycbcr2rgbImg;
*
* ------ note: only 8-bit data mode is supported --------------------------
* ------ note: minimum processing unit is two pixels in the same row ------
*
*/

#include "tistdtypes.h"
#include "ycbcr2rgb.h"

#define  SHIFT 12
#define  UINT  (0x100000-1)


static Int16 COEF_YCbCr2RGB[7] = {
    (Int16)( 0.00456621*UINT+0.5), (Int16)( 0.00625893*UINT+0.5),
	(Int16)( 0.00456621*UINT+0.5), (Int16)(-0.00153632*UINT-0.5),(Int16)(-0.00318811*UINT-0.5),
	(Int16)( 0.00456621*UINT+0.5), (Int16)( 0.00791071*UINT+0.5) };

void ycbcr2rgb(ycbcr2rgbImg img)
{
    Int32  AC0, AC1;
    Int16  *cPtrB;
    Uint16 *r,*g,*b,*y,*cb,*cr;
    Uint16 i,j,len;
    Int16  yhi,ylo,cbhi,cblo,crhi,crlo;

    len = img.width>>1;
    y = img.y;
    cb = img.cb;
    cr = img.cr;
    r = img.r;
    g = img.g;
    b = img.b;


	//  These equations transform YCBCR in [0, 255] to RGB in [0,1].
    //  in(:,:,1) = in(:,:,1)-16;
    //  in(:,:,2) = in(:,:,2)-128;
    //  in(:,:,3) = in(:,:,3)-128;
    //  rgb(:,:,1) = .00456621 * in(:,:,1) + .00625893 * in(:,:,3);
    //  rgb(:,:,2) = .00456621 * in(:,:,1) - .00153632 * in(:,:,2) - .00318811 * in(:,:,3);
    //  rgb(:,:,3) = .00456621 * in(:,:,1) + .00791071 * in(:,:,2);


    // This implementation is very sensitive to overflow and underflow
    // R,G,B must be limited to the range of [0, 255]

    for (j=0; j<img.height;j++)
    {
        for (i=0;i<len;i++)
        {
            cPtrB = COEF_YCbCr2RGB;
            ylo  = ((*y>>8)&0xff) - 16;
            yhi  = ((*y)&0xff) - 16;
            cblo = ((*cb>>8)&0xff) - 128;
            cbhi = ((*cb)&0xff) - 128;
            crlo = ((*cr>>8)&0xff) - 128;
            crhi = ((*cr)&0xff) - 128;
            y++;
            cb++;
            cr++;

            AC0   = (Int32)yhi  * *cPtrB;
            AC1   = (Int32)ylo  * *cPtrB++;
            AC0  += (Int32)crhi * *cPtrB;
            AC1  += (Int32)crlo * *cPtrB++;
            AC0  >>= SHIFT;
            AC1  >>= SHIFT;
            if (AC0 < 0) AC0 = 0;
            if (AC1 < 0) AC1 = 0;
            if (AC0 > 255) AC0 = 255;
            if (AC1 > 255) AC1 = 255;
            *r++  = (Int16)( AC0 | (AC1<<8) );

            AC0   = (Int32)yhi  * *cPtrB;
            AC1   = (Int32)ylo  * *cPtrB++;
            AC0  += (Int32)cbhi * *cPtrB;
            AC1  += (Int32)cblo * *cPtrB++;
            AC0  += (Int32)crhi * *cPtrB;
            AC1  += (Int32)crlo * *cPtrB++;
            AC0  >>= SHIFT;
            AC1  >>= SHIFT;
            if (AC0 < 0) AC0 = 0;
            if (AC1 < 0) AC1 = 0;
            if (AC0 > 255) AC0 = 255;
            if (AC1 > 255) AC1 = 255;
            *g++  = (Int16)( AC0 | (AC1<<8) );

            AC0   = (Int32)yhi  * *cPtrB;
            AC1   = (Int32)ylo  * *cPtrB++;
            AC0  += (Int32)cbhi * *cPtrB;
            AC1  += (Int32)cblo * *cPtrB++;
            AC0  >>= SHIFT;
            AC1  >>= SHIFT;
            if (AC0 < 0) AC0 = 0;
            if (AC1 < 0) AC1 = 0;
            if (AC0 > 255) AC0 = 255;
            if (AC1 > 255) AC1 = 255;
            *b++  = (Int16)( AC0 | (AC1<<8) );
        }
    }
    return;
}

