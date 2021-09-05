/*
 * sineGenTest.c
 *
 *  Created on: Jul 14, 2012
 *      Author: BLEE
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */


#include "stdio.h"
#include "usbstk5505.h"

extern void tone(Uint32, Int16, Int16, Uint16, Int16*);

#define SAMPLING	8000	// 8000Hz
#define GAIN		0		// 0dB
#define	TIME		10		// 10 seconds

void main( void )
{
    /* Pre-generated sine wave data, 16-bit signed samples */
    Int16 table[8] = {0x0000,0x5a81,0x7ffd,0x5a81,0x0000,0xa57f,0x8002,0xa57f};
    
    printf("Exp7.1 --- 1kHz sinewave, sampling at 8kHz\n");

    tone(SAMPLING, TIME, GAIN, 0, table);

    printf("\nExp --- completed\n");
}
