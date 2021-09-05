 /*
 * audioLoopbackTest.c
 *
 *  Created on: Apr 11, 2012
 *      Author: BLEE
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

#define IER0        *(volatile unsigned *)0x0000

#define SF48KHz			48000
#define DAC_GAIN		2		// 0dB range: -6dB to 29dB
#define ADC_GAIN		0		// 0dB range: 0dB to 46dB

extern void audio(void);


void main(void)
{
	Int16 i;

	for(i=0; i<XMIT_BUFF_SIZE; i++)// Clean the audio output buffers
	{
		XmitL1[i] = 0;
		XmitL2[i] = 0;
		XmitR1[i] = 0;
		XmitR2[i] = 0;
	}

	setDMA_address();		// DMA address setup for each buffer

    asm(" BCLR ST1_INTM");	// Disable all interrupts
    IER0 = 0x0110;      	// Enable DMA interrupt

    set_i2s0_slave();		// Set I2S
    AIC3204_init(SF48KHz, DAC_GAIN, (Uint16)ADC_GAIN);  // Set AIC3204
	enable_i2s0();

	enable_dma_int();		// Set up and enable DMA
    set_dma0_ch0_i2s0_Lout(XMIT_BUFF_SIZE);
    set_dma0_ch1_i2s0_Rout(XMIT_BUFF_SIZE);
    set_dma0_ch2_i2s0_Lin(XMIT_BUFF_SIZE);
	set_dma0_ch3_i2s0_Rin(XMIT_BUFF_SIZE);

	printf("Exp C.8 --- Audio experiment (loop input to output)\n");

	audio();
}






