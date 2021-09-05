 /*
 * realtime_g711Test.c
 *
 *  Created on: Nov 4, 2012
 *      Author: BLEE
 *
 *  Description: Test program for real-time ITU-T G.711 experiment
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
extern void g711_init(void);
extern void g711(void);

#define IER0        *(volatile unsigned *)0x0000

#define SF8KHz			8000
#define DAC_GAIN		6		// 6dB range: -6dB to 29dB
#define ADC_GAIN		3		// 3dB range: 0dB to 46dB



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
    AIC3204_init(SF8KHz, DAC_GAIN, (Uint16)ADC_GAIN);  //set AIC3204
    enable_i2s0();

    enable_dma_int();		// Set up and enable DMA
    set_dma0_ch0_i2s0_Lout(XMIT_BUFF_SIZE);
    set_dma0_ch1_i2s0_Rout(XMIT_BUFF_SIZE);
    set_dma0_ch2_i2s0_Lin(XMIT_BUFF_SIZE);
    set_dma0_ch3_i2s0_Rin(XMIT_BUFF_SIZE);

    printf("Exp --- real-time G.711 experiment\n");
    g711_init();			// Initialize for experiment
    g711();					// Real-time loop
}






