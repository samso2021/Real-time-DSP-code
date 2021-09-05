/*
 * channel_equalizerTest.c
 *
 *  Created on: Oct 20, 2012
 *      Author: BLEE
 *
 *  Description: This is the test program for adaptive channel equalizer experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#include <stdio.h>
#include <stdlib.h>
#include "tistdtypes.h"
#include "complexEQ.h"
#include <gsm.h>

COMPLEX txSignal[NUM_SIMBOL];           // Transmitter force training signal
COMPLEX rxDesire[NUM_SIMBOL];           // Receiver local desired signal
COMPLEX x[EQ_ORDER+1],w[EQ_ORDER+1];    // NLMS delayline and coefficients
COMPLEX power,mu,error;                 // NLMS variables
COMPLEX ch_x[3],ch_y[3];                // Simulated channel delay line
Int16   e[NUM_SIMBOL];
Int16   txCnt;


void main()
{
    COMPLEX rxSimbol,txSimbol,out;
    Int32   rxEnergy,temp32;
    Int16   eqTest,energy,i,j;
    FILE    *fpErr;

    fpErr = fopen("..\\data\\error.xls", "wt");

    // Initialize transmitter
    signalGen(txSignal);

    // Initialize receiver
    signalGen(rxDesire);

	// Initialize system
	eqTest      = 0;
	energy      = 0;
	rxSimbol.re = 0;
	rxSimbol.im = 0;
	txCnt       = 0;
    rxEnergy    = 0;
	j           = 0;

	for(i=0; i<=EQ_ORDER; i++)
	{
        x[i].re = 0;
        x[i].im = 0;
		w[i].re = 0;
		w[i].im = 0;
	}
	power.re = 0x7fff;
	power.im = 0x7fff;

	// Initialize the channel model
	for(i=0; i<3; i++)
    {
	   ch_x[i].re = 0;
	   ch_x[i].im = 0;
	   ch_y[i].re = 0;
	   ch_y[i].im = 0;
    }

	// Initialize step size
	mu.re = mu.im = 7;


	// Begin channel equalizer test
    printf("Exp --- started\n");
	while (eqTest>= 0)
	{
		if (energy == 0)
		{
            rxEnergy = _smac(rxEnergy, rxSimbol.re, rxSimbol.re);
            rxEnergy = _smac(rxEnergy, rxSimbol.im, rxSimbol.im);
        }

        if (rxEnergy > (Int32)THRESHOLD)            // Detected energy
		{
            energy = 1;                            // Can start EQ training
		}

		if ( (energy == 1) || (eqTest > 0) )
		{
			 equalizer(&rxSimbol, &out, &error);   // Force training in progress
             
			 temp32 = _lsmpy(error.re, error.re);
			 temp32 = _smac(temp32, error.im, error.im);
             e[j++] = (Int16)(temp32>>15);

             if (eqTest++ >= NUM_SIMBOL-1)
			 {
                 eqTest = -1;                      // EQ training is completed
			 }
		}

	    // Start transmitter
		if (txCnt < NUM_SIMBOL)
		{
            txSimbol = txSignal[txCnt];
		}
		else
		{
            txSimbol.re = 0;
		    txSimbol.im = 0;
		}

		// Channel
		channel(txSimbol, ch_x, ch_y);
		rxSimbol = ch_y[0];
    }

	// Write the error to a file
	fprintf(fpErr, "Equalizer Error Plot\n");
	for (i = 0; i < NUM_SIMBOL; i++)
	{
		fprintf(fpErr, "%d\n",(Int16)e[i]);
	}

    fclose(fpErr);
    printf("Exp --- completed\n");
}





