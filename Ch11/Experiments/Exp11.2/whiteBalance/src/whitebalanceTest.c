/*
 *  whitebalanceTest.c
 *
 *  Created on: Jul 21, 2012
 *      Author: BLEE
 *
 *  Description: This is the test program for white balance experiment
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
#include "whiteBalance.h"

#define IMG_WIDTH	160
#define IMG_HEIGHT	120
#define OFFSET		54

Int16  bmpHeader[OFFSET];
Int16  temp[3*IMG_WIDTH];
Uint16 r[IMG_WIDTH],g[IMG_WIDTH],b[IMG_WIDTH];

void main()
{
    wbImg img;
    Uint16 i,j,k,c;
    FILE *fpIn, *fpOut;

    printf("Enter: 1 for 2850k in-file\n");
    printf("Enter: 2 for 4150k in-file\n");
    printf("Enter: 3 for 6500k in-file\n");
    scanf ("%d", &c);

    if (c == 1)
    {
        fpIn = fopen("..\\data\\tory_2850k.bmp", "rb");
     	fpOut = fopen("..\\data\\wb2850k.bmp", "wb");
    }
    else if (c == 2)
    {
        fpIn = fopen("..\\data\\tory_4150k.bmp", "rb");
     	fpOut = fopen("..\\data\\wb4150k.bmp", "wb");
    }
    else
    {
        fpIn = fopen("..\\data\\tory_6500k.bmp", "rb");
     	fpOut = fopen("..\\data\\wb6500k.bmp", "wb");
    }
    
    // Open input BMP file
    if (fpIn == NULL)
    {
        printf("Can't open input BMP file for reading\n");
        exit(0);
    }

    printf("Exp - WB started\n");
    fread(bmpHeader, sizeof(Int8),  OFFSET, fpIn);	// Get BMP file header
    fwrite(bmpHeader, sizeof(Int8), OFFSET, fpOut);	// Create BMP file header

    // Initialize the data buffer, set a block equals 1 row of data
    img.width = IMG_WIDTH;
    img.height = 1;

    // Initialize API structure
    img.r = r;
    img.g = g;
    img.b = b;
    img.rSum = 0;
    img.gSum = 0;
    img.bSum = 0;

    for(i=0; i<IMG_HEIGHT; i++)
    {
    	fread(temp, sizeof(Int8), IMG_WIDTH*3, fpIn);
    	for(k=0, j=0; j<IMG_WIDTH; j++)
    	{
            r[j] = temp[k++];
            g[j] = temp[k++];
            b[j] = temp[k++];
    	}

        img.status = COMPUTE_SUM;				// White balance gain computation
        whiteBalance(&img);
    }

    img.status = COMPUTE_GAIN;					// White balance gain computation
    whiteBalance(&img);

    fseek(fpIn, OFFSET, SEEK_SET);				// Back to read data again

    for(i=0; i<IMG_HEIGHT; i++)
    {
    	fread(temp, sizeof(Int8), IMG_WIDTH*3, fpIn);
    	for(k=0, j=0; j<IMG_WIDTH; j++)
    	{
            r[j] = temp[k++];
            g[j] = temp[k++];
            b[j] = temp[k++];
    	}

        img.status = DO_WB;						// Do white balance
        whiteBalance(&img);

    	for(k=0, j=0; j<IMG_WIDTH; j++)
    	{
            temp[k++] = r[j];
            temp[k++] = g[j];
            temp[k++] = b[j];
    	}
        fwrite(temp, sizeof(Int8),IMG_WIDTH*3,fpOut);
        printf("%d rows processed\n", i+1);
    }

    fclose(fpIn);
    fclose(fpOut);
    printf("Exp - completed\n");
}

