/*
 *  imageMapping.c
 *
 *  Created on: Jul 21, 2012
 *      Author: BLEE
 *
 *  Description: This function maps image according to a given table
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include "tistdtypes.h"
#include "gammaContrast.h"

void imageMap(gcImg *img)
{
    Uint16  i,j,pixelUp,pixelLo,*pPtr,*table;
    
    pPtr = img->pixelPtr;
    table = img->tablePtr;
    for (j=0; j<img->height; j++)
    {
        for (i=0; i<img->width; i++)
        {
            pixelUp = *pPtr;
            pixelLo = pixelUp&0xff;
            pixelUp = (pixelUp>>8)&0xff;
            pixelUp = table[pixelUp];
            pixelLo = table[pixelLo];            
            *pPtr++ = pixelLo|(pixelUp<<8);
        }
    }
}
