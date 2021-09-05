/*
* RGB2BMPHeader.c
*
*  Created on: Jul 27, 2012
*      Author: BLEE
*
*  Description: This C file generates BMP file header for RGB conversion experiment
*
*  For the book "Real Time Digital Signal Processing:
*                Fundamentals, Implementation and Application, 3rd Ed"
*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
*                Publisher: John Wiley and Sons, Ltd
*
*/

#include "tistdtypes.h"

typedef struct {
    Uint16 bfType;         // Where BMP image file starts
    Uint32 bfSize;         // BMP file size
    Uint16 bfReserved1;
    Uint16 bfReserved2;
    Uint32 bfOffBits;      // BMP data starts offset from beginning
    Uint32 biSize;         // BMP file header info block size
    Uint32 biWidth;        // BMP image width
    Uint32 biHeight;       // BMP image height
    Uint16 biPlanes;       // BMP number of planes (must be zero)
    Uint16 biBitCount;     // BMP number of bits per pixel
    Uint32 biCompression;  // BMP compression type, 0=no compression
    Uint32 biSizeImage;    // BMP image data length
    Uint32 biXPelsPerMeter;// BMP X-direction number of pixels/meter
    Uint32 biYPelsPerMeter;// BMP Y-direction number of pixels/meter
    Uint32 biClrUsed;      // BMP number of color used
    Uint32 biClrImportant; // BMP number of color important
} BMPHEADER;

void createBMPHeader(Uint16 *bmpHeader, Uint16 width, Uint16 height)
{
   BMPHEADER bmp;

   // Prepare the BMP file header
   bmp.bfType          = 0x4D42;   // Microsoft BMP file
   bmp.bfSize          = (width*height*3)+54;
   bmp.bfReserved1     = 0;
   bmp.bfReserved2     = 0;
   bmp.bfOffBits       = 54;       // Total bytes of file header
   bmp.biSize          = 40;       // The size of information block
   bmp.biWidth         = width; 
   bmp.biHeight        = height;
   bmp.biPlanes        = 1;
   bmp.biBitCount      = 24;      // 8-bit RGB color data
   bmp.biCompression   = 0;       // No compression
   bmp.biSizeImage     = (width*height*3); 
   bmp.biXPelsPerMeter = 0;
   bmp.biYPelsPerMeter = 0;
   bmp.biClrUsed       = 0; 
   bmp.biClrImportant  = 0;

   bmpHeader[0]  = (Uint8)(bmp.bfType & 0xff);
   bmpHeader[1]  = (Uint8)(bmp.bfType >> 8);
   bmpHeader[2]  = (Uint8)(bmp.bfSize & 0xff);
   bmpHeader[3]  = (Uint8)((bmp.bfSize >> 8) & 0xff);
   bmpHeader[4]  = (Uint8)((bmp.bfSize >> 16) & 0xff);
   bmpHeader[5]  = (Uint8)((bmp.bfSize >> 24) & 0xff);
   bmpHeader[6]  = (Uint8)(bmp.bfReserved1 & 0xff);
   bmpHeader[7]  = (Uint8)((bmp.bfReserved1>>8) & 0xff);
   bmpHeader[8]  = (Uint8)(bmp.bfReserved2 & 0xff);
   bmpHeader[9]  = (Uint8)((bmp.bfReserved2>>8) & 0xff);
   bmpHeader[10] = (Uint8)(bmp.bfOffBits & 0xff);
   bmpHeader[11] = (Uint8)((bmp.bfOffBits >> 8) & 0xff);
   bmpHeader[12] = (Uint8)((bmp.bfOffBits >> 16) & 0xff);
   bmpHeader[13] = (Uint8)((bmp.bfOffBits >> 24) & 0xff);
   bmpHeader[14] = (Uint8)(bmp.biSize & 0xff);
   bmpHeader[15] = (Uint8)((bmp.biSize >> 8) & 0xff);
   bmpHeader[16] = (Uint8)((bmp.biSize >> 16) & 0xff);
   bmpHeader[17] = (Uint8)((bmp.biSize >> 24) & 0xff);
   bmpHeader[18] = (Uint8)(bmp.biWidth & 0xff);
   bmpHeader[19] = (Uint8)((bmp.biWidth >> 8) & 0xff);
   bmpHeader[20] = (Uint8)((bmp.biWidth >> 16) & 0xff);
   bmpHeader[21] = (Uint8)((bmp.biWidth >> 24) & 0xff);
   bmpHeader[22] = (Uint8)(bmp.biHeight & 0xff);
   bmpHeader[23] = (Uint8)((bmp.biHeight >> 8) & 0xff);
   bmpHeader[24] = (Uint8)((bmp.biHeight >> 16) & 0xff);
   bmpHeader[25] = (Uint8)((bmp.biHeight >> 24) & 0xff);
   bmpHeader[26] = (Uint8)(bmp.biPlanes & 0xff);
   bmpHeader[27] = (Uint8)(bmp.biPlanes >> 8);
   bmpHeader[28] = (Uint8)(bmp.biBitCount & 0xff);
   bmpHeader[29] = (Uint8)(bmp.biBitCount >> 8);
   bmpHeader[30] = (Uint8)(bmp.biCompression & 0xff);
   bmpHeader[31] = (Uint8)((bmp.biCompression >> 8) & 0xff);
   bmpHeader[32] = (Uint8)((bmp.biCompression >> 16) & 0xff);
   bmpHeader[33] = (Uint8)((bmp.biCompression >> 24) & 0xff);
   bmpHeader[34] = (Uint8)(bmp.biSizeImage & 0xff);
   bmpHeader[35] = (Uint8)((bmp.biSizeImage >> 8) & 0xff);
   bmpHeader[36] = (Uint8)((bmp.biSizeImage >> 16) & 0xff);
   bmpHeader[37] = (Uint8)((bmp.biSizeImage >> 24) & 0xff);
   bmpHeader[38] = (Uint8)(bmp.biXPelsPerMeter & 0xff);
   bmpHeader[39] = (Uint8)((bmp.biXPelsPerMeter >> 8) & 0xff);
   bmpHeader[40] = (Uint8)((bmp.biXPelsPerMeter >> 16) & 0xff);
   bmpHeader[41] = (Uint8)((bmp.biXPelsPerMeter >> 24) & 0xff);
   bmpHeader[42] = (Uint8)(bmp.biYPelsPerMeter & 0xff);
   bmpHeader[43] = (Uint8)((bmp.biYPelsPerMeter >> 8) & 0xff);
   bmpHeader[44] = (Uint8)((bmp.biYPelsPerMeter >> 16) & 0xff);
   bmpHeader[45] = (Uint8)((bmp.biYPelsPerMeter >> 24) & 0xff);
   bmpHeader[46] = (Uint8)(bmp.biClrUsed & 0xff);
   bmpHeader[47] = (Uint8)((bmp.biClrUsed >> 8) & 0xff);
   bmpHeader[48] = (Uint8)((bmp.biClrUsed >> 16) & 0xff);
   bmpHeader[49] = (Uint8)((bmp.biClrUsed >> 24) & 0xff);
   bmpHeader[50] = (Uint8)(bmp.biClrImportant & 0xff);
   bmpHeader[51] = (Uint8)((bmp.biClrImportant >> 8) & 0xff);
   bmpHeader[52] = (Uint8)((bmp.biClrImportant >> 16) & 0xff);
   bmpHeader[53] = (Uint8)((bmp.biClrImportant >> 24) & 0xff);
}

