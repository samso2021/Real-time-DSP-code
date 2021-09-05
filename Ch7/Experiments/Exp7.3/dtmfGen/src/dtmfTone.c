/*
 * dtmfTone.c
 *
 *  Created on: Mar 11, 2012
 *      Author: BLEE
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */


#define AIC3204_I2C_ADDR 0x18
#include "usbstk5505.h"
#include "usbstk5505_gpio.h"
#include "usbstk5505_i2c.h"
#include "usbstk5505_i2S.h"
#include "stdio.h"
#include "dtmf.h"

extern void aic3204_tone_headphone( );
extern void Init_AIC3204(Uint32 sf, Int16 gDAC, Uint16 gADC);
extern Int16 AIC3204_rset( Uint16 regnum, Uint16 regval);

void tone_init(Uint32 sf, Int16 gDAC, Uint16 gADC)
{
    /* Initialize BSL */
    USBSTK5505_init( );

    /* Set A20_MODE for GPIO mode */
    CSL_FINST(CSL_SYSCTRL_REGS->EBSR, SYS_EBSR_A20_MODE, MODE1); 
    
    /* Use GPIO to enable AIC3204 chip */
    USBSTK5505_GPIO_init();
    USBSTK5505_GPIO_setDirection(GPIO26, GPIO_OUT);
    USBSTK5505_GPIO_setOutput( GPIO26, 1 );    // Take AIC3201 chip out of reset
    
    /* Initialize I2C */
    USBSTK5505_I2C_init( );

    /* Initialized AIC3204 */
    Init_AIC3204(sf, gDAC, gADC);

    /* Initialize I2S */
    USBSTK5505_I2S_init();
}

void tone_stop(void)
{
    USBSTK5505_I2S_close();  // Disable I2S
    AIC3204_rset( 1, 1 );    // Reset codec

    USBSTK5505_GPIO_setOutput( GPIO26, 0 );    // Disable AIC3204
}

void dtmfTone(Int16 *fl, Int16 *fh)
{
    Int16 sample;
    Int16 data;

    /* Play Tone */
    for ( sample = 0 ; sample < DTMF_TABLE_SIZE; sample++ )
    {
    	data = fl[sample] + fh[sample];

        /* Write 16-bit left channel Data */
        USBSTK5505_I2S_writeLeft(data);

        /* Write 16-bit right channel Data */
        USBSTK5505_I2S_writeRight(data);
    }

    data = 0;
	for (sample = 0; sample <600; sample++)
    {
        /* Send silence to the left channel */
		USBSTK5505_I2S_writeLeft(data);

        /* Send silence to the right channel */
		USBSTK5505_I2S_writeRight(data);
    }
}
