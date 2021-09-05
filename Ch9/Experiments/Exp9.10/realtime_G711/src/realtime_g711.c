/*
 * realtime_g711.c
 *
 *  Created on: Oct 28, 2012
 *      Author: BLEE
 *
 *      Description: This program contains functions for real-time G711 experiment
 *
 *      For the book "Real Time Digital Signal Processing:
 *                    Fundamentals, Implementation and Application, 3rd Ed"
 *                    By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                    Publisher: John Wiley and Sons, Ltd
 */

#include <stdio.h>
#include <math.h>
#include "tistdtypes.h"
#include "dma.h"
#include "dmaBuff.h"
#include "g711.h"

/* Define DSP system memory map */
#pragma DATA_SECTION(XmitL1, "XmitL1");
#pragma DATA_SECTION(XmitL2, "XmitL2");
#pragma DATA_SECTION(XmitR1, "XmitR1");
#pragma DATA_SECTION(XmitR2, "XmitR2");
#pragma DATA_ALIGN(XmitL1,2);
#pragma DATA_ALIGN(XmitL2,2);
#pragma DATA_ALIGN(XmitR1,2);
#pragma DATA_ALIGN(XmitR2,2);

Int16 XmitL1[XMIT_BUFF_SIZE];
Int16 XmitR1[XMIT_BUFF_SIZE];
Int16 XmitL2[XMIT_BUFF_SIZE];
Int16 XmitR2[XMIT_BUFF_SIZE];

#pragma DATA_SECTION(RcvL1, "RcvL1");
#pragma DATA_SECTION(RcvR1, "RcvR1");
#pragma DATA_SECTION(RcvL2, "RcvL2");
#pragma DATA_SECTION(RcvR2, "RcvR2");
#pragma DATA_ALIGN(RcvL1,2);
#pragma DATA_ALIGN(RcvR1,2);
#pragma DATA_ALIGN(RcvL2,2);
#pragma DATA_ALIGN(RcvR2,2);

Int16 RcvL1[XMIT_BUFF_SIZE];
Int16 RcvR1[XMIT_BUFF_SIZE];
Int16 RcvL2[XMIT_BUFF_SIZE];
Int16 RcvR2[XMIT_BUFF_SIZE];

void g711(void);
void g711_init(void);
void process(Int16 *, Int16 *, Int16 *, Int16 *, Int16);

enum
{
   BOTH_CHANNEL = 0,
   PASS_THROUGH_ONLY,
   G711_CODEC_ONLY
};

void g711_init(void)
{
	Int16 i;
	for (i=0; i<XMIT_BUFF_SIZE; i++)
	{
		XmitL1[i]=0;
		XmitL2[i]=0;
		XmitR1[i]=0;
		XmitR2[i]=0;
	}
}

void g711(void)
{
	Uint32 n;
	Int16  state;

	printf(" - G.711 compressed / expanded audio: (left channel)\n");
	printf(" - Original audio sent pass-through: (right channel)\n");

	n = 0;
	state = BOTH_CHANNEL;
	while (1)			// Forever loop for the demo if status is set
    {
    	if (n++ == 0x4000000)
    	{
    		n = 0;
    		state++;
    		if (state > G711_CODEC_ONLY)
    		{
    			state =BOTH_CHANNEL;
    		}

    		if (state == G711_CODEC_ONLY)
    		{
    			printf("left channel G711\n");
    		}
    		if (state == PASS_THROUGH_ONLY)
    		{
    			printf("right channel pass through\n");
    		}
    		if (state == BOTH_CHANNEL)
    		{
    			printf("both channels\n");
    		}
    	}
        if((leftChannel == 1)&&(rightChannel == 1))
        {
        	leftChannel = 0;
        	rightChannel= 0;
            if((CurrentRxL_DMAChannel == 2)&&(CurrentRxR_DMAChannel == 2))
            {
           		process(RcvL1, XmitL1, RcvR1, XmitR1, state);
            }
            else
            {
           		process(RcvL2, XmitL2, RcvR2, XmitR2, state);
            }
        }
    }
}

// Experiment related variables
Int16 buffer[XMIT_BUFF_SIZE];
Int8  coded[XMIT_BUFF_SIZE];

void process(Int16 *inDataPtrL, Int16 *outDataPtrL, Int16 *inDataPtrR, Int16 *outDataPtrR, Int16 state)
{
    Uint16 i;

    // G.711 compress and expand to one channel
   	ulaw_compress(XMIT_BUFF_SIZE, inDataPtrL, coded);	// This channel to be compressed
   	ulaw_expand(XMIT_BUFF_SIZE, coded, buffer);			// Expanded from compressed data to buffer

   	switch(state)
   	{
   		case G711_CODEC_ONLY:
		for(i=0; i<XMIT_BUFF_SIZE; i++)
		{
			*(outDataPtrR+i) = 0;				// Pass through input data
			*(outDataPtrL+i) = *(buffer+i); 	// Play G711 compressed-expanded data
		}
   		break;
   		case PASS_THROUGH_ONLY:
		for(i=0; i<XMIT_BUFF_SIZE; i++)
		{
			*(outDataPtrR+i) = *(inDataPtrR+i);	// Pass through input data
			*(outDataPtrL+i) = 0; 				// Play G711 compressed-expanded data
		}
   		break;
   		default:								// Both channels
		for(i=0; i<XMIT_BUFF_SIZE; i++)
		{
			*(outDataPtrR+i) = *(inDataPtrR+i);	// Pass through input data
			*(outDataPtrL+i) = *(buffer+i); 	// Play G711 compressed-expanded data
		}
		break;
   	}
}

