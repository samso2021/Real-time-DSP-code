/*
 * intrinsic_lpc_hamming.c
 *
 *  Created on: Dec 6, 2012
 *      Author: BLEE
 *
 *  Description: This is the Hamming window for LPC experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include <stdlib.h>
#include "tistdtypes.h"
#include "lpc.h"

void hmwindowing(Int16 N, Int16 *input1, Int16 *ws, Int16 *HammingWindow)
{
    Int16 i;
    Int32  acc0;
    
    for (i=0; i <N; i++)
    {
        acc0 = (Int32)input1[i]*HammingWindow[i];
        acc0 += 0x4000L;
        ws[i] = (Int16) (acc0 >>15);        // Simulate mult()
    }
}

