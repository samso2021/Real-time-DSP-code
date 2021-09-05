/*
 *  filter2DTest.c
 *
 *  Created on: Jul 22, 2012
 *      Author: BLEE
 *
 *  Description: This is the test program for 2D filter experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "tistdtypes.h"
#include "filter2D.h"

// Image filter
#define UNIT   1023.0
#define SCALE  1.0   
Int16 highpass[I*J] =  // Highpass filter coefficient
{ 
     (Int16)(-1*UNIT/SCALE), (Int16)(-1*UNIT/SCALE), (Int16)(-1*UNIT/SCALE),
     (Int16)(-1*UNIT/SCALE), (Int16)( 9*UNIT/SCALE), (Int16)(-1*UNIT/SCALE),
     (Int16)(-1*UNIT/SCALE), (Int16)(-1*UNIT/SCALE), (Int16)(-1*UNIT/SCALE)
}; 

Int16 lowpass[I*J] =  // Lowpass filter coefficient
{
     (Int16)(UNIT/SCALE/9.0), (Int16)(UNIT/SCALE/9.0), (Int16)(UNIT/SCALE/9.0),
     (Int16)(UNIT/SCALE/9.0), (Int16)(UNIT/SCALE/9.0), (Int16)(UNIT/SCALE/9.0),
     (Int16)(UNIT/SCALE/9.0), (Int16)(UNIT/SCALE/9.0), (Int16)(UNIT/SCALE/9.0)
};

Int16 laplacian[I*J] =  // Laplacian filter coefficient
{
     (Int16)(1*UNIT/SCALE), (Int16)(  4*UNIT/SCALE), (Int16)(1*UNIT/SCALE),
     (Int16)(4*UNIT/SCALE), (Int16)(-20*UNIT/SCALE), (Int16)(4*UNIT/SCALE),
     (Int16)(1*UNIT/SCALE), (Int16)(  4*UNIT/SCALE), (Int16)(1*UNIT/SCALE)
};

#define IMG_WIDTH	160	// Make sure the image width is equal or less than 160
#define OFFSET		54

Int16  bmpHeader[OFFSET];
Int16  temp[3*IMG_WIDTH];
Uint16 r3x3[IMG_WIDTH*3],g3x3[IMG_WIDTH*3],b3x3[IMG_WIDTH*3];
Uint16 newR[IMG_WIDTH],newG[IMG_WIDTH],newB[IMG_WIDTH];

void main(void) 
{ 
    IMFILTER imfilt;
    FILE   *fpIn,*fpOut;
    Int16  state,c,i,j,k,n;
    Uint32 M,N;
    Int16  *filter;

    printf("Enter:\t 1 or 2 or 3 for 2D filter experiment\n");
    printf("\t 1 - highpass filter using eagle160x160.bmp(sharp)\n");
    printf("\t 2 - laplacian filter using hallway160x120.bmp(edge)\n");
    printf("\t 3 - lowpass filter using kingProtea160x128.bmp(smooth)\n");
    scanf ("%d", &c);

    // Open input files
    if (c == 1)
    {
     	fpIn = fopen("..\\data\\eagle160x160.bmp", "rb");
     	fpOut = fopen("..\\data\\highpassFltImage.bmp", "wb");
     	filter = highpass;
    }
    else if (c == 2)
    {
     	fpIn = fopen("..\\data\\hallway160x120.bmp", "rb");
     	fpOut = fopen("..\\data\\edgeFltImage.bmp", "wb");
     	filter = laplacian;
    }
    else
    {
     	fpIn = fopen("..\\data\\kingProtea160x128.bmp", "rb");
     	fpOut = fopen("..\\data\\smoothFltImage.bmp", "wb");
     	filter = lowpass;
    }

    // Open input BMP file
    if (fpIn == NULL)
    {
        printf("Can't open input BMP file for reading\n");
        exit(0);
    }

    printf("Exp - 2D filter started\n");
    fread(bmpHeader,  sizeof(Int8),  OFFSET, fpIn);	// Get BMP file header
    fwrite(bmpHeader, sizeof(Int8), OFFSET, fpOut);	// Create BMP file header

    // Get BMP image width and height
    M = (Uint32)(((Uint32)bmpHeader[21]<<24)&0xff000000|((Uint32)bmpHeader[20]<<16)&0xff0000|
		(bmpHeader[19]<<8)&0xff00|bmpHeader[18]&0xff);
    N = (Uint32)(((Uint32)bmpHeader[25]<<24)&0xff000000|((Uint32)bmpHeader[24]<<16)&0xff0000|
		(bmpHeader[23]<<8)&0xff00|bmpHeader[22]&0xff);

    // Initialization
    imfilt.I2D = I;
    imfilt.J2D = J;
    imfilt.shift = SHIFT;
    imfilt.filter = filter;
    imfilt.imWidth = M;

    // Initialize filter RGB buffers
    for(k=0, j=0; j<(imfilt.imWidth*3); j++)
    {
        r3x3[j] = 0x80;
        g3x3[j] = 0x80;
        b3x3[j] = 0x80;
    }
    state = 2;

    // 2-D filtering start
    for(i=0; i<2; i++)
    {
        // Get a new row of pixels
        if (state == 0)
        {
            fread(temp, sizeof(Int8), imfilt.imWidth*3, fpIn);
            n = state*imfilt.imWidth;
            for(k=0, j=0; j<imfilt.imWidth; j++)
            {
                r3x3[n] = temp[k++];
                g3x3[n] = temp[k++];
                b3x3[n++] = temp[k++];
            }
            state = 1;
        }
        else if (state == 2)
        {
            fread(temp, sizeof(Int8), imfilt.imWidth*3, fpIn);
            n = state*imfilt.imWidth;
            for(k=0, j=0; j<imfilt.imWidth; j++)
            {
                r3x3[n] = temp[k++];
                g3x3[n] = temp[k++];
                b3x3[n++] = temp[k++];
            }
            state = 0;
        }

        imfilt.state = state;

        imfilt.outData = newR;       // Color of red
        imfilt.inData = r3x3;
        filter2D(&imfilt);

        imfilt.outData = newG;       // Color of green
        imfilt.inData = g3x3;
        filter2D(&imfilt);

        imfilt.outData = newB;       // Color of blue
        imfilt.inData = b3x3;
        filter2D(&imfilt);
    }

    // Get a new row of pixels
    for(i=0; i<N-2; i++)
    {
        if (state == 0)
        {
            fread(temp, sizeof(Int8), imfilt.imWidth*3, fpIn);
            n = state*imfilt.imWidth;
            for(k=0, j=0; j<imfilt.imWidth; j++)
            {
                r3x3[n] = temp[k++];
                g3x3[n] = temp[k++];
                b3x3[n++] = temp[k++];
            }
            state = 1;
        }
        else if (state == 1)
        {
            fread(temp, sizeof(Int8), imfilt.imWidth*3, fpIn);
            n = state*imfilt.imWidth;
            for(k=0, j=0; j<imfilt.imWidth; j++)
            {
                r3x3[n] = temp[k++];
                g3x3[n] = temp[k++];
                b3x3[n++] = temp[k++];
            }
            state = 2;
        }
        else if (state == 2)
        {
            fread(temp, sizeof(Int8), imfilt.imWidth*3, fpIn);
            n = state*imfilt.imWidth;
            for(k=0, j=0; j<imfilt.imWidth; j++)
            {
                r3x3[n] = temp[k++];
                g3x3[n] = temp[k++];
                b3x3[n++] = temp[k++];
            }
            state = 0;
        }

        // Start filtering
        imfilt.state = state;

        imfilt.outData = newR;       // Color of red
        imfilt.inData = r3x3;
        filter2D(&imfilt);

        imfilt.outData = newG;       // Color of green
        imfilt.inData = g3x3;
        filter2D(&imfilt);

        imfilt.outData = newB;       // Color of blue
        imfilt.inData = b3x3;
        filter2D(&imfilt);

        // Output the filtered results
        for(k=0, j=0; j<imfilt.imWidth; j++)
        {
            temp[k++] = newR[j];
            temp[k++] = newG[j];
            temp[k++] = newB[j];
        }
        fwrite(temp, sizeof(Int8), imfilt.imWidth*3, fpOut);
        printf("%d rows processed\n", i+3);
    }

    // Pad last two rows
    for(i=0; i<2; i++)
    {
        if (state == 0)
        {
            n = state*imfilt.imWidth;
            for(k=0, j=0; j<imfilt.imWidth; j++)
            {
                r3x3[n] = 0x80;
                g3x3[n] = 0x80;
                b3x3[n++] = 0x80;
            }
            state = 1;
        }
        else if (state == 1)
        {
            n = state*imfilt.imWidth;
            for(k=0, j=0; j<imfilt.imWidth; j++)
            {
                r3x3[n] = 0x80;
                g3x3[n] = 0x80;
                b3x3[n++] = 0x80;
            }
            state = 2;
        }
        else if (state == 2)
        {
            n = state*imfilt.imWidth;
            for(k=0, j=0; j<imfilt.imWidth; j++)
            {
                r3x3[n] = 0x80;
                g3x3[n] = 0x80;
                b3x3[n++] = 0x80;
            }
            state = 0;
        }

        imfilt.state = state;

        imfilt.outData = newR;       // Color of red
        imfilt.inData = r3x3;
        filter2D(&imfilt);

        imfilt.outData = newG;       // Color of green
        imfilt.inData = g3x3;
        filter2D(&imfilt);

        imfilt.outData = newB;       // Color of blue
        imfilt.inData = b3x3;
        filter2D(&imfilt);

        // Output the filtered results
        for(k=0, j=0; j<imfilt.imWidth; j++)
        {
            temp[k++] = newR[j];
            temp[k++] = newG[j];
            temp[k++] = newB[j];
        }
        fwrite(temp, sizeof(Int8), imfilt.imWidth*3, fpOut);
    }

    fclose(fpIn);
    fclose(fpOut);
    printf("Exp - completed\n");
}

