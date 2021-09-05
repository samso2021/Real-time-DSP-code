/*
 * siren.c
 *
 *  Created on: Jul 14, 2012
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
#include "siren.h"

extern void aic3204_tone_headphone( );
extern void Init_AIC3204(Uint32 sf, Int16 gDAC, Uint16 gADC);
extern Int16 AIC3204_rset( Uint16 regnum, Uint16 regval);

void siren(Uint32 sf, Int16 playtime, Int16 gDAC, Uint16 gADC, Int16 *data, Uint16 index)
{
    Int16 sec, msec;

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

    /* Play Tone */
    for ( sec = 0 ; sec < playtime ; sec++ )
    {
        for ( msec = 0 ; msec < 8000 ; msec++ ) // 8 sample per second
        {
            /* Write 16-bit left channel Data */
            USBSTK5505_I2S_writeLeft(data[index]);

            /* Write 16-bit right channel Data */
            USBSTK5505_I2S_writeRight(data[index]);

            if (index++ == SIREN_TABLE_SIZE)
            	index = 0;

        }
    }

    USBSTK5505_I2S_close();  // Disable I2S
    AIC3204_rset( 1, 1 );    // Reset codec

    USBSTK5505_GPIO_setOutput( GPIO26, 0 );    // Disable AIC3204
}
