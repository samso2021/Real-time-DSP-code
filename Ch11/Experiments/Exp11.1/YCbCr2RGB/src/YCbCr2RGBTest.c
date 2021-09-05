/*
*  YCbCr2RGBTest.c
*
*  Created on: Jul 27, 2012
*      Author: BLEE
*
*  Description: This is the test program for YCbCr color space conversion to RGB color space
*
*  For the book "Real Time Digital Signal Processing:
*                Fundamentals, Implementation and Application, 3rd Ed"
*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
*                Publisher: John Wiley and Sons, Ltd
*
* input files are binary formatted Y, Cb, Cr files
* output file a BMP file
*
* ------ note: only 8-bit data mode is supported --------------------------
* ------ note: minimum processing unit is two pixels in the same row ------
*/
 
#include <stdio.h>
#include <stdlib.h>
#include "tistdtypes.h"
#include "ycbcr2rgb.h"

#define IMG_WIIDTH 160
#define IMG_HEIGHT 120
#define OFFSET      54
#define NUM_ROWS   (IMG_HEIGHT/15)

#pragma DATA_SECTION(RGB, ".Imgbuf1");
#pragma DATA_ALIGN(RGB, 2);
Int16   RGB[IMG_WIIDTH*2*3];

Uint16  bmpHeader[OFFSET];

void main()
{
    ycbcr2rgbImg img;
    Uint16  *r,*g,*b;
    Uint16  *y,*cb,*cr;
    Uint32 blockSize,blockSize_2,blockSizex2,blockSizex3,position;
    FILE   *fRGB,*fy,*fcb,*fcr,*fBMP;
    Int16  i,j,k;
    Int16  *tmp,*tmpRGB;

    // Open input YCbCr data files
    if ( (fy = fopen("..\\data\\butterfly160x120Y8.dat", "rb") ) == NULL)
    {
        printf("Can't open input Y file for reading %s\n");
        exit(0);
    }
    if ( (fcb = fopen("..\\data\\butterfly160x120Cb8.dat", "rb") ) == NULL)
    {
        printf("Can't open input Cb file for reading %s\n");
        exit(0);
    }
    if ( (fcr = fopen("..\\data\\butterfly160x120Cr8.dat", "rb") ) == NULL)
    {
        printf("Can't open input Cr file for reading %s\n");
        exit(0);
    }

    // Open working file, the order written is B,G,R,B,G,R,....
    fRGB = fopen("..\\data\\BGR.RGB", "wb");

    // Initialize the data buffer, set a block size
    img.width = IMG_WIIDTH;
    img.height = NUM_ROWS;
    blockSize = img.width * img.height;
    blockSizex3 = blockSize*3;
    blockSizex2 = blockSize*2;
    blockSize_2 = blockSize>>1;

    // Allocate data buffer memory spaces
    if ( (y = (Uint16 *)malloc (blockSize)) == 0)
    {
        printf("Can't allocate enough memory for data Y\n");
        exit(0);
    }
    if ( (cb = (Uint16 *)malloc (blockSize)) == 0)
    {
        printf("Can't allocate enough memory for data Cb\n");
        exit(0);
    }
    if ( (cr = (Uint16 *)malloc (blockSize)) == 0)
    {
        printf("Can't allocate enough memory for data Cr\n");
        exit(0);
    }
    if ( (r = (Uint16 *)malloc (blockSize)) == 0)
    {
        printf("Can't allocate enough memory for data R\n");
        exit(0);
    }
    if ( (g = (Uint16 *)malloc (blockSize)) == 0)
    {
        printf("Can't allocate enough memory for data G\n");
        exit(0);
    }
    if ( (b = (Uint16 *)malloc (blockSize)) == 0)
    {
        printf("Can't allocate enough memory for data B\n");
        exit(0);
    }
    if ( (tmp = (Int16 *)malloc (blockSizex2)) == 0)
    {
        printf("Can't allocate enough memory for data tmp\n");
        exit(0);
    }

    tmpRGB = &RGB[0];	// Set up working buffer

    // Setup parameters, choose block size equals 1 row of data
    img.y = y;
    img.cb = cb;
    img.cr = cr;
    img.r = r;
    img.g = g;
    img.b = b;

    printf("Exp --- YCbCr to RGB conversion\n");

    // Get YCbCr data one block a time and make the conversion
    for (i=0; i<IMG_HEIGHT; i+=NUM_ROWS)
    {
        fread(tmp, sizeof(Int16), blockSize, fy); // Get one block of Y data in
        y = img.y;
        for (k=0,j=0; j<blockSize_2; j++)
        {
            *y++ = tmp[k]&0xff | tmp[k+1]<<8;
            k += 2;
        }

        fread(tmp, sizeof(Int16), blockSize, fcb); // Get one block of Cb data in
        cb = img.cb;
        for (k=0,j=0; j<blockSize_2; j++)
        {
            *cb++ = tmp[k]&0xff | tmp[k+1]<<8;
            k += 2;
        }

        fread(tmp, sizeof(Int16), blockSize, fcr); // Get one block of Cr data in
        cr = img.cr;
        for (k=0,j=0; j<blockSize_2; j++)
        {
            *cr++ = tmp[k]&0xff | tmp[k+1]<<8;
            k += 2;
        }

        ycbcr2rgb(img);								// Perform YCbCr to RGB conversion

        r = img.r;
        g = img.g;
        b = img.b;
        for (k=0,j=0; j<blockSize_2; j++)
        {
            tmpRGB[k++] = (*b)&0xff;
            tmpRGB[k++] = (*g)&0xff;
            tmpRGB[k++] = (*r)&0xff;

            tmpRGB[k++] = (*b++)>>8;
            tmpRGB[k++] = (*g++)>>8;
            tmpRGB[k++] = (*r++)>>8;
        }
        fwrite(tmpRGB,  sizeof(Int16), blockSizex3, fRGB); // Write one block of RGB data out
        printf("completed row #%d\n", i+NUM_ROWS);
    }

    free(img.y);									// Free memory spaces that are no longer needed
    free(img.cb);
    free(img.cr);
    free(img.r);
    free(img.g);
    free(img.b);
    free(tmp);

    fclose(fRGB);									// Close all open files
    fclose(fy);
    fclose(fcb);
    fclose(fcr);

    // Allocate memory for a temp buffer
    if ( (tmp = (Int16 *)malloc (IMG_WIIDTH*3)) == 0)
    {
        printf("Can't allocate enough memory for data tmp\n");
        exit(0);
    }

    // Open RGB file for read
    fRGB = fopen("..\\data\\BGR.RGB", "rb");

    // Open BMP file for write
    fBMP = fopen("..\\data\\butterfly160x120.bmp", "wb");

    // Create the header for BMP file
    createBMPHeader(bmpHeader, IMG_WIIDTH, IMG_HEIGHT);
    fwrite(&bmpHeader, sizeof(Int8), OFFSET, fBMP);

    position = (Uint32)IMG_WIIDTH*(IMG_HEIGHT-1)*3;

    // Get RGB data one line a time and create the BMP file
    for (i=0; i<IMG_HEIGHT; i++)
    {
        fseek(fRGB, position, 0);				// Set up file pointer and read data
        fread(tmpRGB, sizeof(Int8), IMG_WIIDTH*3, fRGB);

        for (k=0,j=0; j<IMG_WIIDTH; j++)
        {
            tmp[k++] = *tmpRGB++;
            tmp[k++] = *tmpRGB++;
            tmp[k++] = *tmpRGB++;
        }
        tmpRGB -= (IMG_WIIDTH*3);
        position -= (IMG_WIIDTH*3);
        fwrite(tmp, sizeof(Int8), IMG_WIIDTH*3, fBMP);
        printf("writing BMP file row #%d\n", i+1);
    }

    free(tmp);									// Free memory spaces used that are no longer needed
    free(tmpRGB);
    
    fclose(fRGB);								// Close all open files
    fclose(fBMP);
    printf("Exp --- completed\n");
}
