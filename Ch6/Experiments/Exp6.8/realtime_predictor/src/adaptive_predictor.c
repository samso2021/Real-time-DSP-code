/*
 * adaptive_predictor.c
 *
 *  Created on: June 8, 2012
 *      Author: BLEE
 *
 *  Description: This program controls the adaptive line predictor experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#include <stdio.h>
#include "tistdtypes.h"
#include "dma.h"
#include "dmaBuff.h"

extern void predictor_init(void);
extern void predictor(void);

/* Define DSP system memory map */
#pragma DATA_SECTION(eL, ".bss:error");
#pragma DATA_SECTION(wL, ".bss:filter");
#pragma DATA_SECTION(xL, ".bss:filter");
#pragma DATA_SECTION(yL, ".bss:output");
#pragma DATA_SECTION(eR, ".bss:error");
#pragma DATA_SECTION(wR, ".bss:filter");
#pragma DATA_SECTION(xR, ".bss:filter");
#pragma DATA_SECTION(yR, ".bss:output");
#pragma DATA_ALIGN(XmitL1,2);
#pragma DATA_ALIGN(XmitL2,2);
#pragma DATA_ALIGN(XmitR1,2);
#pragma DATA_ALIGN(XmitR2,2);

Int16 XmitL1[XMIT_BUFF_SIZE];
Int16 XmitR1[XMIT_BUFF_SIZE];
Int16 XmitL2[XMIT_BUFF_SIZE];
Int16 XmitR2[XMIT_BUFF_SIZE];

Int16 RcvL1[XMIT_BUFF_SIZE];
Int16 RcvR1[XMIT_BUFF_SIZE];
Int16 RcvL2[XMIT_BUFF_SIZE];
Int16 RcvR2[XMIT_BUFF_SIZE];

// Adaptive line predictor related variables
#include "adaptive_predictor.h"

ADAPTLP linePredictorL1,      // Adaptive line predictor object
		linePredictorL2,
		linePredictorR1,
		linePredictorR2;
ADAPTLP *alpL1 = &linePredictorL1,
		*alpL2 = &linePredictorL2,
		*alpR1 = &linePredictorR1,
		*alpR2 = &linePredictorR2;

Int16   eL[Ns],eR[Ns],      // Error signal buffer
		yL[Ns],yR[Ns],		// Filter output buffer
        wL[L],wR[L],        // Adaptive filter coefficients
        xL[L],xR[L];        // Filter delay-line buffer

extern Int16 testCase;

void predictor_init(void)
{
	Int16 i, indexL, indexR;

    // Initialize adaptive system identification object
	indexL = 0;
    alpL1->in = RcvL1;
    alpL1->y = yL;
    alpL1->e = eL;
    alpL1->x = xL;
    alpL1->w = wL;
    alpL1->size = Ns;
    alpL1->order = L;
    alpL1->index = indexL;

    alpL2->in = RcvL2;
    alpL2->y = yL;
    alpL2->e = eL;
    alpL2->x = xL;
    alpL2->w = wL;
    alpL2->size = Ns;
    alpL2->order = L;
    alpL2->index = indexL;

	indexR = 0;
    alpR1->in = RcvR1;
    alpR1->y = yR;
    alpR1->e = eR;
    alpR1->x = xR;
    alpR1->w = wR;
    alpR1->size = Ns;
    alpR1->order = L;
    alpR1->index = indexR;

    alpR2->in = RcvR2;
    alpR2->y = yR;
    alpR2->e = eR;
    alpR2->x = xR;
    alpR2->w = wR;
    alpR2->size = Ns;
    alpR2->order = L;
    alpR2->index = indexR;

   for (i=0; i<L; i++)
   {
       wL[i] = wR[i] = 0;          // Initialize adaptive filter coefficients
       xL[i] = xR[i] = 0;          // Initialize adaptive filter delay-line
   }
}
void predictor(void)
{
	Int32 n=0;
	Int16 i,j=0;

	printf("Adaptive predictor status:\n");
	printf("off\n");
    while (1)					// Forever loop for the demo
    {
    	if (n++ == (0x2000000))
    	{
    		n = 0;
    		j++;
    		if (j &= 1)
    			printf("on (signal enhanced)\n");
    		else
    			printf("off \n");
    	}

        if((leftChannel == 1)&&(rightChannel == 1))
        {
        	leftChannel = rightChannel= 0;
            if ((CurrentRxL_DMAChannel == 2)&&(CurrentRxR_DMAChannel == 2))
            {
            	if (j) // Apply adaptive predictor to the input data and write out result to output
            	{
            		alpL1->index = adaptivePredictor(alpL1);
            		alpR1->index = adaptivePredictor(alpR1);
               		if (testCase&1)
               		{
               			for(i=0; i<XMIT_BUFF_SIZE; i++)
               			{
               				XmitL1[i] = eL[i]<<1;
               				XmitR1[i] = eR[i]<<1;
               			}
            		}
               		else
               		{
               			for(i=0; i<XMIT_BUFF_SIZE; i++)
               			{
               				XmitL1[i] = yL[i]<<1;
               				XmitR1[i] = yR[i]<<1;
               			}
            		}
            	}
            	else  // Without adaptive predictor, pass through the audio
            	{
            		for(i=0; i<XMIT_BUFF_SIZE; i++)
            		{
            			XmitL1[i] = RcvL1[i];
            			XmitR1[i] = RcvR1[i];
            		}
            	}
            }
            else
            {
            	if (j) // Apply adaptive predictor to the input
            	{
            		alpL2->index = adaptivePredictor(alpL2);
            		alpR2->index = adaptivePredictor(alpR2);
               		if (testCase&1)
               		{
               			for(i=0; i<XMIT_BUFF_SIZE; i++)
               			{
               				XmitL2[i] = eL[i]<<1;
               				XmitR2[i] = eR[i]<<1;
               			}
            		}
               		else
               		{
               			for(i=0; i<XMIT_BUFF_SIZE; i++)
               			{
               				XmitL2[i] = yL[i]<<1;
               				XmitR2[i] = yR[i]<<1;
               			}
            		}                                	}
            	else  // Without adaptive predictor, pass through the audio
            	{
            		for(i=0; i<XMIT_BUFF_SIZE; i++)
            		{
            			XmitL2[i] = RcvL2[i];
            			XmitR2[i] = RcvR2[i];
            		}
            	}
             }
        }
    }
}
