/*
 *  tableGen.c
 *
 *  Created on: Jul 21, 2012
 *      Author: BLEE
 *
 *  Description: This function generates lookup tables for the experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include <math.h>
#include "tistdtypes.h"
#include "gammaContrast.h"

void tableGen(gcTbl *tbl)
{
    Uint16 i,range;
    float invgamma,gain,a,b,c,d;
    
    range = tbl->len-1;
    switch (tbl->tblSelect)
    {
        case GAMMA:
            invgamma = (float)1.0/tbl->gamma;
            gain = (float) range / pow((float)range, invgamma);
            for(i=0; i<=range; i++)
            {
                *tbl->tablePtr++ = gain * pow(i, invgamma);
            }
        break;
        
        case LOWCONTRAST:
            a = tbl->lowContrast;
            b = (-383.0) * a;
            c = 1.0 + 32640.0 * a;
            for(i=0; i<=range; i++)
            {
                d = a * (float)i + b;
                d = d * (float)i + c;
                d *= (float)i; 
                *tbl->tablePtr++ = (Uint16)(d);
            }
        break;
        
        case HIGHCONTRAST:
            a = tbl->highContrast;
            b = (-383.0) * a;
            c = 1.0 + 32640.0 * a;
            for(i=0; i<=range; i++)
            {
                d = a * (float)i + b;
                d = d * (float)i + c;
                d *= (float)i; 
                if (d > range)
                {
                   d = range;
                }
                if (d < 0)
                {
                    d = 0;
                }
                *tbl->tablePtr++ = (Uint16)(d);
            }        
        break;

        default:
        break;
    }
}
