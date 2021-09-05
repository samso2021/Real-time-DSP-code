 /*
 * realtime_predictorTest.c
 *
 *  Created on: Oct 21, 2012
 *      Author: BLEE
 *
 *  Description: This is test program for the adaptive line predictor experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#include <stdio.h>
#include "tistdtypes.h"
#include "i2s.h"
#include "dma.h"
#include "dmaBuff.h"


extern void AIC3204_init(Uint32, Int16, Int16);
extern void predictor_init(void);
extern void predictor(void);

#define IER0        *(volatile unsigned *)0x0000

#define SF8KHz			8000
#define DAC_GAIN		6		// 6dB range: -6dB to 29dB
#define ADC_GAIN		3		// 3dB range: 0dB to 46dB

Int16 testCase;

void main(void)
{
	printf("Real-time adaptive predictor experiment\n");
	printf("Enter 1 for windband, using speech.wav as source audio\n");
	printf("Enter 2 for narrowband, using tone_1khz_8khz_noise.wav\n");
    scanf ("%d", &testCase);
    if (testCase != 1)
    	testCase = 2;

	setDMA_address();		// DMA address setup for each buffer

    asm(" BCLR ST1_INTM");	// Disable all interrupts
    IER0 = 0x0110;      	// Enable DMA interrupt

    set_i2s0_slave();		// Set I2S
    AIC3204_init(SF8KHz, DAC_GAIN, (Uint16)ADC_GAIN);  // Set AIC3204
	enable_i2s0();

	enable_dma_int();		// Set up and enable DMA
    set_dma0_ch0_i2s0_Lout(XMIT_BUFF_SIZE);
    set_dma0_ch1_i2s0_Rout(XMIT_BUFF_SIZE);
    set_dma0_ch2_i2s0_Lin(XMIT_BUFF_SIZE);
	set_dma0_ch3_i2s0_Rin(XMIT_BUFF_SIZE);

	printf("Exp --- Adaptive predictor experiment\n");
	predictor_init();		// Initialize adaptive predictor
	predictor();			// Adaptive predictor loop
}






