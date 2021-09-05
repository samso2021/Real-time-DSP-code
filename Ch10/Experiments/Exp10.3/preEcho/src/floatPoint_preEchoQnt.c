/*
 * floatPoint_preEchoQnt.c
 *
 *  Created on: Oct 26, 2012
 *      Author: BLEE
 *
 *  Description: This is program simulates Log Quantization
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include <math.h>
#include "tistdtypes.h"
#include "floatPoint_preEcho.h"

void mdct_qnt(Int16 *mdct_enc16, Int16 M, float QuantStep)
{
    float temp,sign;
    Int16 index,j;

    for (j = 0; j < M; j++)
    {
        if (mdct_enc16[j]<0) 
        {
            sign = -1.0;
        }
        else
        {
            sign=1;
        }
	
        if (mdct_enc16[j]==0) 
        {
            continue;
        }
        temp = (float)log10(fabs((float)mdct_enc16[j]));

        temp = (float)(temp/(float)QuantStep);

        index = (int)temp;	// Quantized index
        temp = ((float)index)*QuantStep;

        temp = (float)(sign*pow(10.,temp));
        mdct_enc16[j] = (Int16) temp;
    }
}

