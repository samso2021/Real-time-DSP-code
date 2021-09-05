/*
 * fingerPrintTest.c
 *
 *  Created on: Jul 20, 2012
 *      Author: BLEE
 *
 *  Description: This is the test program for fingerprint experiment
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
#include "fingerPrint.h"

#define OFFSET 14
Int8 bmpHeader[TA_IMG_WIDTH];
Int8 temp[TA_IMG_WIDTH*3];

#pragma DATA_SECTION(image, ".Imgbuf1");
#pragma DATA_SECTION(vbin,  ".Imgbuf2");
#pragma DATA_SECTION(work,  ".Imgbuf3");
Uint16 image[TA_IMG_HEIGHT][TA_IMG_WIDTH];
Uint16 vbin[TA_IMG_HEIGHT][TA_IMG_WIDTH];
Uint16 work[TA_IMG_HEIGHT][TA_IMG_WIDTH];

void writeFile(FILE *fp, Int8 *t, Uint16 *b, Int8 *, Uint32, Int16);

void main()
{
	FILE *fpIn,*fpOut;
	Uint32 offset;
	Int16 i,j,k;
	Uint16 *pImg, *pVbin,*pTemp;

	if ((fpIn = fopen("..\\data\\fingerprint64x64.bmp", "rb"))==NULL)
	{
		printf("Can't open input BMP file\n");
		exit(0);
	}

	printf("Exp --- finger print experiment\n");
	pImg = (Uint16 *)&image[0];
	pVbin= (Uint16 *)&vbin[0];
	pTemp= (Uint16 *)&work[0];

	// Check image is BMP file format
	fread(bmpHeader, sizeof(Int8), OFFSET, fpIn);
	if ((bmpHeader[0] != 'B')||(bmpHeader[1] != 'M'))
	{
		printf("Input is not a BMP file\n");
		exit(0);
	}

	// Get BMP data starting point (offset)
	offset = (Uint32)(((Uint32)bmpHeader[13]<<24)&0xff000000|((Uint32)bmpHeader[12]<<16)&0xff0000|
			(bmpHeader[11]<<8)&0xff00|bmpHeader[10]&0xff);

	// Create BMP file header for late use
	fread(&bmpHeader[OFFSET], sizeof(Int8), offset-OFFSET, fpIn);
	bmpHeader[offset]='\0';

	// Convert RGB image matrix to G matrix
	for(i=0; i<TA_IMG_HEIGHT; i++)								// Read 64x64 BMP image in
	{
		fread(temp, sizeof(Int8), TA_IMG_WIDTH*3, fpIn);
		for(k=0, j=2; j<TA_IMG_WIDTH*3; j+=3)
		{
			image[i][k] = temp[j];								// Form G image matrix
			k++;
		}
	}
	fclose(fpIn);												// Close input image file

	// Segement
	printf("\t1. generate Segement BMP image\n");
	TA_Segement(pImg);											// Segement
	fpOut = fopen("..\\data\\1_Segement.bmp", "wb");			// Open Segement file for write
	writeFile(fpOut, temp, pImg, bmpHeader, offset, 1);
	fclose(fpOut);

	// Gray Stretch
	printf("\t2. generate Gray Stretch BMP image\n");
	TA_Graystretch(pImg);										// Gray Stretch
	fpOut = fopen("..\\data\\2_Graystretch.bmp", "wb");			// Open Gray Stretch file for write
	writeFile(fpOut, temp, pImg, bmpHeader, offset, 2);
	fclose(fpOut);

	// Block Direction
	printf("\t3. generate Block Direction BMP image\n");
	TA_GetBlockDirection(pImg, (Int16 *)pVbin, (Int16 *)pTemp);	// Get Block Direction

	fpOut = fopen("..\\data\\3_BlockDirection.bmp", "wb");		// Open Block Direction file for write
	writeFile(fpOut, temp, pVbin, bmpHeader, offset, 3);
	fclose(fpOut);

	// Gabor Filter
	printf("\t4. generate Gabor Filter BMP image\n");
	TA_gabor_filter(pImg,(short *)pVbin); 						// Gabor Filtering
	fpOut = fopen("..\\data\\4_GaborFilter.bmp", "wb");			// Open Gabor Filter file for write
	writeFile(fpOut, temp, pVbin, bmpHeader, offset, 4);
	fclose(fpOut);

	// Binarization
	printf("\t5. generate Binarization BMP image\n");
	TA_BinImage(pVbin); 										// Binarization Gray Image
	fpOut = fopen("..\\data\\5_Binarization.bmp", "wb");		// Open Binarization file for write
	writeFile(fpOut, temp, pVbin, bmpHeader, offset, 5);
	fclose(fpOut);

	// Thinning
	printf("\t6. generate Thinning BMP image\n");
	TA_Thin_image(pVbin,pImg,pTemp); 							// Thinning Binary Image
	fpOut = fopen("..\\data\\6_Thinning.bmp", "wb");			// Open Thinning file for write
	writeFile(fpOut, temp, pVbin, bmpHeader, offset, 6);
	fclose(fpOut);

	printf("Exp --- completed\n");
}

void writeFile(FILE *fp, Int8 *t, Uint16 *b, Int8 *h, Uint32 o, Int16 action)
{
#if USE_FDK_DEMO_CODE                                           // This code runs the real fingerprint using the FDK Demo software

	Int16 i,j,k;

	fwrite(h, sizeof(Int8), o, fp);							    // Create output file header

	for(i=0; i<TA_IMG_HEIGHT; i++)
	{
		for(k=0, j=0; j<TA_IMG_WIDTH; j++)
		{
			t[k] = *(b+(i*TA_IMG_WIDTH)+j);
			t[k+1] = t[k];
			t[k+2] = t[k];
			k += 3;
		}
		fwrite(t, sizeof(Int8), TA_IMG_WIDTH*3, fp);		    // Write data out
	}

#else	// This section is for a demo to show the fingerprint images without actually processing the data.
	FILE *fpIn1;

	if (action == 1)
		fpIn1 = fopen("..\\data\\reference_Segement.bmp", "rb");
	if (action == 2)
		fpIn1 = fopen("..\\data\\reference_Graystretch.bmp", "rb");
	if (action == 3)
		fpIn1 = fopen("..\\data\\reference_BlockDirection.bmp", "rb");
	if (action == 4)
		fpIn1 = fopen("..\\data\\reference_GaborFilter.bmp", "rb");
	if (action == 5)
		fpIn1 = fopen("..\\data\\reference_Binarization.bmp", "rb");
	if (action == 6)
		fpIn1 = fopen("..\\data\\reference_Thinning.bmp", "rb");


	if (fpIn1 == NULL)
	{
		if (action == 1)
			printf("Can't open reference_Segement.bmp\n");
		if (action == 2)
			printf("Can't open reference_Graystretch.bmp\n");
		if (action == 3)
			printf("Can't open reference_BlockDirection.bmp\n");
		if (action == 4)
			printf("Can't open reference_GaborFilter.bmp\n");
		if (action == 5)
			printf("Can't open reference_Binarization.bmp\n");
		if (action == 6)
			printf("Can't open reference_Thinning.bmp\n");
		exit(0);
	}

	fread(bmpHeader, sizeof(Int8), o, fpIn1);
	fwrite(bmpHeader, sizeof(Int8), o, fp);

	while (fread(temp, sizeof(Int8), TA_IMG_WIDTH*3, fpIn1) == (TA_IMG_WIDTH*3))
	{
		fwrite(temp, sizeof(Int8), TA_IMG_WIDTH*3, fp);
	}
	fclose(fpIn1);
#endif
}
