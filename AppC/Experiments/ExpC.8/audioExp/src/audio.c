/*
 * audio.c
 *
 *  Created on: Apr 11, 2012
 *      Author: BLEE
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#include "tistdtypes.h"
#include "dma.h"
#include "dmaBuff.h"

Int16 XmitL1[XMIT_BUFF_SIZE];
Int16 XmitR1[XMIT_BUFF_SIZE];
Int16 XmitL2[XMIT_BUFF_SIZE];
Int16 XmitR2[XMIT_BUFF_SIZE];

Int16 RcvL1[XMIT_BUFF_SIZE];
Int16 RcvR1[XMIT_BUFF_SIZE];
Int16 RcvL2[XMIT_BUFF_SIZE];
Int16 RcvR2[XMIT_BUFF_SIZE];

extern void audio(void);


void audio(void)
{
    Int16 i;

    while (1)			// Forever loop for the demo if status is set
    {
        if(leftChannel == 1)
        {
        	leftChannel = 0;
            if (CurrentRxL_DMAChannel == 2)
            {
            	for(i=0; i<XMIT_BUFF_SIZE; i++)
            	{
            		XmitL1[i] = RcvL1[i];
            	}
            }
            else
            {
            	for(i=0; i<XMIT_BUFF_SIZE; i++)
            	{
            		XmitL2[i] = RcvL2[i];
            	}
             }
        }
        if(rightChannel == 1)
        {
        	rightChannel= 0;
            if (CurrentRxR_DMAChannel == 2)
            {
            	for(i=0; i<XMIT_BUFF_SIZE; i++)
            	{
            		XmitR1[i] = RcvR1[i];
            	}
            }
            else
            {
             	for(i=0; i<XMIT_BUFF_SIZE; i++)
             	{
             		XmitR2[i] = RcvR2[i];
             	}
            }
        }
    }
}
