/*
*  2DWaveletTest.c
*
*  Created on: Jul 28, 2012
*      Author: BLEE
*
*  Description: This is the test program for 2D wavelet experiment
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
* ------ note: this experiment requires:
*                       (1) to be linked in 32-bit pointer mode in project file
*                       (2) to set proejct (Basic Option)  -v 5505
*/
 
#include <stdio.h>
#include <stdlib.h>
#include "tistdtypes.h"
#include "wavelet.h"

#define IMG_WIIDTH 128		// Image width
#define IMG_HEIGHT 128		// Image height
#define OFFSET      54		// BMP header size
#define NUM_ROWS    1		// The row number to read data
#define THRESHOLD   15		// The data smaller than THRESHOLD, will be zeroed

#pragma DATA_SECTION(DATAY, "imgY");
#pragma DATA_ALIGN(DATAY, 2);
Int16   DATAY[IMG_WIIDTH][IMG_HEIGHT];

#pragma DATA_SECTION(DATACB, "imgCb");
#pragma DATA_ALIGN(DATACB, 2);
Int16   DATACB[IMG_WIIDTH][IMG_HEIGHT];

#pragma DATA_SECTION(DATACR, "imgCr");
#pragma DATA_ALIGN(DATACR, 2);
Int16   DATACR[IMG_WIIDTH][IMG_HEIGHT];

#pragma DATA_SECTION(temp_wksp, ".wksp_array");
#pragma DATA_ALIGN(temp_wksp, 2);
Int16 temp_wksp[IMG_WIIDTH];

#pragma DATA_SECTION(RGB, "tempvar");
#pragma DATA_ALIGN(RGB, 2);
Int16   RGB[IMG_WIIDTH*2*3];

Uint16  bmpHeader[OFFSET];

void zero_samll_data(Int16  **image, Int16 width, Int16 height);

void main()
{
    ycbcr2rgbImg img;
    Uint16 *r,*g,*b;
    Uint16 *y,*cb,*cr;
    Uint32 blockSize,blockSize_2,blockSizex3,position;
    FILE   *fRGB,*fy,*fcb,*fcr,*fBMP;
    Int16  i,j,k,c;
    Int16  *tmp,*tmpRGB;
    Int16  **image;

    printf("Enter:\t 0, 1, 2, 3, or 4 for wavelet experiment\n");
    printf("   0 - generate reference image(a BMP file without apply wavelet)\n");
    printf("   1 - generate decomposition level 1 image(pryamid decomposition)\n");
    printf("   2 - generate decomposition level 2 image(pryamid decomposition)\n");
    printf("   3 - generate perfect reconstructed image(level 1 decomposition+construct)\n");
    printf("   4 - generate reconstructed image with zero small values(level 2 decomposition+construct)\n");
    scanf ("%d", &c);

    // Open input YUV files
    if ( (fy = fopen("..\\data\\totem128x128Y8.dat", "rb") ) == NULL)
    {
        printf("Can't open input Y file for reading %s\n");
        exit(0);
    }
    if ( (fcb = fopen("..\\data\\totem128x128CB8.dat", "rb") ) == NULL)
    {
        printf("Can't open input Cb file for reading %s\n");
        exit(0);
    }
    if ( (fcr = fopen("..\\data\\totem128x128Cr8.dat", "rb") ) == NULL)
    {
        printf("Can't open input Cr file for reading %s\n");
        exit(0);
    }

    if (c == 1)
    {
     	fBMP = fopen("..\\data\\decompositLevel1.bmp", "wb");
    }
    else if (c == 2)
    {
     	fBMP = fopen("..\\data\\decompositLevel2.bmp", "wb");
    }
    else if (c == 3)
    {
    	fBMP = fopen("..\\data\\reconstructed.bmp", "wb");
    }
    else if (c == 4)
    {
     	fBMP = fopen("..\\data\\reconstructedZeroed.bmp", "wb");
    }
    else // (c == 0)
    {
     	fBMP = fopen("..\\data\\reference.bmp", "wb");
    }

    // Open working file, the order written is B,G,R,B,G,R,....
    fRGB = fopen("..\\data\\BGR.RGB", "wb");

    // Initialize the data buffer, set a block size
    img.width = IMG_WIIDTH;
    img.height = NUM_ROWS;
    blockSize = img.width * img.height;
    blockSizex3 = blockSize*3;
    blockSize_2 = blockSize>>1;

    // Allocate data buffer memory spaces
    if ( (y = (Uint16 *)malloc (blockSize_2)) == 0)
    {
        printf("Can't allocate enough memory for data Y\n");
        exit(0);
    }
    if ( (cb = (Uint16 *)malloc (blockSize_2)) == 0)
    {
        printf("Can't allocate enough memory for data Cb\n");
        exit(0);
    }
    if ( (cr = (Uint16 *)malloc (blockSize_2)) == 0)
    {
        printf("Can't allocate enough memory for data Cr\n");
        exit(0);
    }
    if ( (r = (Uint16 *)malloc (blockSize_2)) == 0)
    {
        printf("Can't allocate enough memory for data R\n");
        exit(0);
    }
    if ( (g = (Uint16 *)malloc (blockSize_2)) == 0)
    {
        printf("Can't allocate enough memory for data G\n");
        exit(0);
    }
    if ( (b = (Uint16 *)malloc (blockSize_2)) == 0)
    {
        printf("Can't allocate enough memory for data B\n");
        exit(0);
    }
    if ( (tmp = (Int16 *)malloc (blockSize)) == 0)
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

    printf("Exp --- 2D wavelet experiment\n");

    // Get YCbCr data one block a time and make the conversion
    printf("\treading YCbCr file\n");
    for (i=0; i<IMG_HEIGHT; i+=NUM_ROWS)
    {
        fread(tmp, sizeof(Int8), blockSize, fy);
        for (j=0; j<blockSize; j++)
        {
        	DATAY[i][j] = tmp[j];
        }
    }
    for (i=0; i<IMG_HEIGHT; i+=NUM_ROWS)
    {
        fread(tmp, sizeof(Int8), blockSize, fcb);
        for (j=0; j<blockSize; j++)
        {
        	DATACB[i][j] = tmp[j];
        }
    }
    for (i=0; i<IMG_HEIGHT; i+=NUM_ROWS)
    {
        fread(tmp, sizeof(Int8), blockSize, fcr);
        for (j=0; j<blockSize; j++)
        {
        	DATACR[i][j] = tmp[j];
        }
    }
    free(tmp);
    fclose(fy);
    fclose(fcb);
    fclose(fcr);

    // Do wavelet
    switch (c)
    {
		case 1:
		case 2:
			printf("\tapply wavelet to do decomposition level %d\n", c);
			image = (Int16 **)malloc((size_t)(IMG_WIIDTH*sizeof(Int16 *)));
			if(!image) printf("\tallocation failure 1 in matrix()");

			for( i = 0; i < IMG_HEIGHT; i++ )
			{
				image[i] = &DATAY[i][0];
			}
			IMG_wave_decom_two_dim( image, temp_wksp, IMG_WIIDTH, IMG_HEIGHT, db4, c );

			for( i = 0; i < IMG_HEIGHT; i++ )
			{
				image[i] = &DATACB[i][0];
			}
			IMG_wave_decom_two_dim( image, temp_wksp, IMG_WIIDTH, IMG_HEIGHT, db4, c );

			for( i = 0; i < IMG_HEIGHT; i++ )
			{
				image[i] = &DATACR[i][0];
			}
			IMG_wave_decom_two_dim( image, temp_wksp, IMG_WIIDTH, IMG_HEIGHT, db4, c );

			free(image);
			break;

		case 3:
			printf("\twavelet decomposition with level 1\n");
			image = (Int16 **)malloc((size_t)(IMG_WIIDTH*sizeof(Int16 *)));
			if(!image) printf("\tallocation failure 1 in matrix()");

			for( i = 0; i < IMG_HEIGHT; i++ )
			{
				image[i] = &DATAY[i][0];
			}
			IMG_wavep_decom_two_dim( image, temp_wksp, IMG_WIIDTH, IMG_HEIGHT, db4, 1 );
			IMG_wavep_recon_two_dim( image, temp_wksp, IMG_WIIDTH, IMG_HEIGHT, db4, 1 );

			for( i = 0; i < IMG_HEIGHT; i++ )
			{
				image[i] = &DATACB[i][0];
			}
			IMG_wavep_decom_two_dim( image, temp_wksp, IMG_WIIDTH, IMG_HEIGHT, db4, 1 );
			IMG_wavep_recon_two_dim( image, temp_wksp, IMG_WIIDTH, IMG_HEIGHT, db4, 1 );

			for( i = 0; i < IMG_HEIGHT; i++ )
			{
				image[i] = &DATACR[i][0];
			}
			IMG_wavep_decom_two_dim( image, temp_wksp, IMG_WIIDTH, IMG_HEIGHT, db4, 1 );
			IMG_wavep_recon_two_dim( image, temp_wksp, IMG_WIIDTH, IMG_HEIGHT, db4, 1 );

			printf("\twavelet reconstruction with level 1\n");
			free(image);
			break;

		case 4:
			printf("\twavelet decomposition with level 2 and zero small value data\n");
			image = (Int16 **)malloc((size_t)(IMG_WIIDTH*sizeof(Int16 *)));
			if(!image) printf("\tallocation failure 1 in matrix()");

			for( i = 0; i < IMG_HEIGHT; i++ )
			{
				image[i] = &DATAY[i][0];
			}
			IMG_wavep_decom_two_dim( image, temp_wksp, IMG_WIIDTH, IMG_HEIGHT, db4, 2 );
			zero_samll_data(image, IMG_WIIDTH, IMG_HEIGHT);
			IMG_wavep_recon_two_dim( image, temp_wksp, IMG_WIIDTH, IMG_HEIGHT, db4, 2 );

			for( i = 0; i < IMG_HEIGHT; i++ )
			{
				image[i] = &DATACB[i][0];
			}
			IMG_wavep_decom_two_dim( image, temp_wksp, IMG_WIIDTH, IMG_HEIGHT, db4, 2 );
			zero_samll_data(image, IMG_WIIDTH, IMG_HEIGHT);

			printf("\tsmall values are set to 0\n");

			IMG_wavep_recon_two_dim( image, temp_wksp, IMG_WIIDTH, IMG_HEIGHT, db4, 2 );

			for( i = 0; i < IMG_HEIGHT; i++ )
			{
				image[i] = &DATACR[i][0];
			}
			IMG_wavep_decom_two_dim( image, temp_wksp, IMG_WIIDTH, IMG_HEIGHT, db4, 2 );
			zero_samll_data(image, IMG_WIIDTH, IMG_HEIGHT);
			IMG_wavep_recon_two_dim( image, temp_wksp, IMG_WIIDTH, IMG_HEIGHT, db4, 2 );

			printf("\twavelet reconstruction with level 2\n");
			free(image);
			break;

		default:
			printf("\tgenerate reference image\n");
			break;
    }

    // Get YCbCr data one block a time and make the conversion
    printf("\tYCbCr to RBG conversion\n");
    for (i=0; i<IMG_HEIGHT; i+=NUM_ROWS)
    {
        y = img.y;
        for (k=0, j=0; j<blockSize_2; j++)
        {
            *y++ = DATAY[i][k]&0xff | DATAY[i][k+1]<<8;
            k += 2;
        }

        cb = img.cb;
        for (k=0, j=0; j<blockSize_2; j++)
        {
            *cb++ = DATACB[i][k]&0xff | DATACB[i][k+1]<<8;
            k += 2;
        }

        cr = img.cr;
        for (k=0, j=0; j<blockSize_2; j++)
        {
            *cr++ = DATACR[i][k]&0xff | DATACR[i][k+1]<<8;
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
    }

    free(img.y);									// Free memory spaces that are no longer needed
    free(img.cb);
    free(img.cr);
    free(img.r);
    free(img.g);
    free(img.b);

    fclose(fRGB);									// Close all open files

    // Allocate memory for a temp buffer
    if ( (tmp = (Int16 *)malloc (IMG_WIIDTH*3)) == 0)
    {
        printf("Can't allocate enough memory for data tmp\n");
        exit(0);
    }

    // Open RGB file for read
    fRGB = fopen("..\\data\\BGR.RGB", "rb");

    // Create the header for BMP file
    createBMPHeader(bmpHeader, IMG_WIIDTH, IMG_HEIGHT);
    fwrite(&bmpHeader, sizeof(Int8), OFFSET, fBMP);

    position = (Uint32)IMG_WIIDTH*(IMG_HEIGHT-1)*3;

    // Get RGB data one line a time and create the BMP file
    printf("\twriting BMP file\n");
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
    }

    free(tmp);									// Free memory spaces used that are no longer needed
    free(tmpRGB);
    
    fclose(fRGB);								// Close all open files
    fclose(fBMP);
    printf("Exp --- completed\n");
}

void zero_samll_data(Int16  **image, Int16 width, Int16 height)
{
	Int16 i,j,temp;

	for( i = 0; i < height; i++ )
	{
		for( j = 0; j < width; j++ )
		{
			temp = image[i][j];
			if (temp < 0)
			{
				temp = -temp;
			}
			if (temp <= THRESHOLD)		// Compare with predefined threshold
			{
				image[i][j] = 0;		// Zero out the data
			}
		}
	}

}
