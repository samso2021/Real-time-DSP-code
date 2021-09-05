/*
 *  gammaContrastTest.c
 *
 *  Created on: Jul 21, 2012
 *      Author: BLEE
 *
 *  Description: This is the test program for gamma and contrast experiment
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
#include "gammaContrast.h"

#define IMG_WIDTH	160
#define IMG_HEIGHT	120
#define OFFSET		54

Int16  bmpHeader[OFFSET];
Int16  temp[3*IMG_WIDTH];
Uint16 r[IMG_WIDTH],g[IMG_WIDTH],b[IMG_WIDTH];

Uint16 lines;
Uint16 gammaTable[TABLESIZE];
Uint16 hiContrastTable[TABLESIZE];
Uint16 loContrastTable[TABLESIZE];

void main()
{
    gcImg  img;
    gcTbl  tbl;
    FILE   *fpIn, *fpOut;
    Uint16 i,j,k,c;
    Int16  testMode;

    printf("Enter: 1 for gamma2.20\n");
    printf("       2 for low contrast\n");
    printf("       3 for high contrast\n");
    scanf ("%d", &c);

    // Open input files
    if (c == 1)
    {
     	fpIn = fopen("..\\data\\boat.bmp", "rb");
     	fpOut = fopen("..\\data\\gamma220.bmp", "wb");
     	testMode = GAMMA;
    }
    else if (c == 2)
    {
     	fpIn = fopen("..\\data\\temple.bmp", "rb");
     	fpOut = fopen("..\\data\\lowContrast.bmp", "wb");
     	testMode = LOWCONTRAST;
    }
    else
    {
     	fpIn = fopen("..\\data\\temple.bmp", "rb");
     	fpOut = fopen("..\\data\\highContrast.bmp", "wb");
     	testMode = HIGHCONTRAST;
    }

    // Open input BMP file
    if (fpIn == NULL)
    {
        printf("Can't open input BMP file for reading\n");
        exit(0);
    }

    printf("Exp - Gamma and contrast started\n");
    fread(bmpHeader,  sizeof(Int8),  OFFSET, fpIn);	// Get BMP file header
    fwrite(bmpHeader, sizeof(Int8), OFFSET, fpOut);	// Create BMP file header


    // Initialize the data buffer, set a block equals 1 row of data
    img.width = IMG_WIDTH;
    img.height = 1;

    // Initialize for gnerating tables and set table pointer
    if (testMode == GAMMA)
    {
        tbl.gamma = 2.20;
        tbl.tablePtr = gammaTable;
        tbl.tblSelect = GAMMA;
        tbl.len = TABLESIZE;
        img.tablePtr = gammaTable;
    }
    else if (testMode == LOWCONTRAST)
    {
        tbl.lowContrast = 0.00005;
        tbl.tablePtr = loContrastTable;
        tbl.tblSelect = LOWCONTRAST;
        tbl.len = TABLESIZE;    
        img.tablePtr = loContrastTable;
    }    
    else if (testMode == HIGHCONTRAST)
    {
        tbl.highContrast = -0.00004;
        tbl.tablePtr = hiContrastTable;
        tbl.tblSelect = HIGHCONTRAST;
        tbl.len = TABLESIZE;    
        img.tablePtr = hiContrastTable;
    }  
    tableGen(&tbl);
    
    // Initialize API structure
    img.r = r;
    img.g = g;
    img.b = b;
    lines = 0;

    // Get RGB data one block a time and process it
    for(i=0; i<IMG_HEIGHT; i++)
    {
       	fread(temp, sizeof(Int8), IMG_WIDTH*3, fpIn);
       	for(k=0, j=0; j<IMG_WIDTH; j++)
       	{
            r[j] = temp[k++];
            g[j] = temp[k++];
            b[j] = temp[k++];
       	}

        img.pixelPtr = r;			// Process R data
        imageMap(&img);

        img.pixelPtr = g;			// Process G data
        imageMap(&img);

        img.pixelPtr = b;			// Process B data
        imageMap(&img);

       	for(k=0, j=0; j<IMG_WIDTH; j++)
       	{
            temp[k++] = r[j];
            temp[k++] = g[j];
            temp[k++] = b[j];
       	}
        fwrite(temp, sizeof(Int8),IMG_WIDTH*3,fpOut);
        printf("row #%d processed\n",i+1);
    }

    fclose(fpIn);
    fclose(fpOut);
    printf("Exp - completed\n");
}
