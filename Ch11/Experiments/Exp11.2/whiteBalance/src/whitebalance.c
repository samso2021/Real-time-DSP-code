/*
 *  whitebalance.c
 *
 *  Created on: Jul 21, 2012
 *      Author: BLEE
 *
 *  Description: This is C program performs white balance operations
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include "tistdtypes.h"
#include "whiteBalance.h"

void whiteBalance(wbImg *img)
{
    Int32  AC0,AC1,AC2;
    Uint16 i,j,len;
    Uint16 *r,*g,*b;
    Uint16 rGain,gGain,bGain;

    len = img->width;
    r = img->r;
    g = img->g;
    b = img->b;
    
    if (img->status == COMPUTE_SUM)
    {
        AC0 = 0;
        AC1 = 0;
        AC2 = 0;
        for (j=0; j<img->height;j++)
        {
            for (i=0;i<len;i++)
            {
                AC0 += (*r>>8)&0xff;
                AC0 += (*r++)&0xff;
                AC1 += (*g>>8)&0xff;
                AC1 += (*g++)&0xff;
                AC2 += (*b>>8)&0xff;
                AC2 += (*b++)&0xff;
            }
        }

        // Write sum result before return;
        img->rSum += AC0;
        img->gSum += AC1;
        img->bSum += AC2;
    }
	
    if (img->status == COMPUTE_GAIN)
    {
        img->rGain = 255;
        img->gGain = 255;
        img->bGain = 255;
        if ( (img->gSum <= img->rSum)&&(img->gSum <= img->bSum) )
        {
            img->rGain = (Uint16)((img->gSum*255) / img->rSum);
            img->bGain = (Uint16)((img->gSum*255) / img->bSum);
        }
        else if ( (img->rSum <= img->gSum)&&(img->rSum <= img->bSum) )
        {
            img->gGain = (Uint16)((img->rSum*255) / img->gSum);
            img->bGain = (Uint16)((img->rSum*255) / img->bSum);
        }
        else if ( (img->bSum <= img->gSum)&&(img->bSum <= img->rSum) )
        {
            img->gGain = (Uint16)((img->bSum*255) / img->gSum);
            img->rGain = (Uint16)((img->bSum*255) / img->rSum);
        }
    }

	
    if (img->status == DO_WB)
    {
        rGain = img->rGain;
        gGain = img->gGain;
        bGain = img->bGain;
        for (j=0; j<img->height;j++)
        {
            for (i=0;i<len;i++)
            {
                if (rGain < 255)
                {
                    AC0 = (*r>>8)&0xff;
                    AC0 *= rGain;
                    if (AC0 > 0xff00)
                        AC0 = 0xff00;
                    AC0 &= 0xff00;
                    AC1 = (*r)&0xff;
                    AC1 *= rGain;
                    AC1 >>= 8;
                    if (AC1 > 0xff)
                        AC1 = 0xff;
                    *r++ = (Uint16)(AC0|AC1);
                }
                
                if (gGain < 255)
                {
                    AC0 = (*g>>8)&0xff;
                    AC0 *= gGain;
                    if (AC0 > 0xff00)
                        AC0 = 0xff00;
                    AC0 &= 0xff00;
                    AC1 = (*g)&0xff;
                    AC1 *= gGain;
                    AC1 >>= 8;
                    if (AC1 > 0xff)
                        AC1 = 0xff;
                    *g++ = (Uint16)(AC0|AC1);
                }
                
                if (bGain < 255)
                {
                    AC0 = (*b>>8)&0xff;
                    AC0 *= bGain;
                    if (AC0 > 0xff00)
                        AC0 = 0xff00;
                    AC0 &= 0xff00;
                    AC1 = (*b)&0xff;
                    AC1 *= bGain;
                    AC1 >>= 8;
                    if (AC1 > 0xff)
                        AC1 = 0xff;
                    *b++ = (Uint16)(AC0|AC1);
                }
            }
        }
    }
}
