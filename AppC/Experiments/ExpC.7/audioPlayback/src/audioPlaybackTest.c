/*
 * audioPlaybackTest.c
 *
 *  Created on: Apr 11, 2012
 *      Author: BLEE
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */


#include "stdio.h"
#include "usbstk5505.h"

extern void tone(Uint32, Int16, Int16, Uint16, Int16*);

#define SAMPLING	48000	// 48000Hz
#define GAIN		0		// 0dB
#define	TIME		10		// 10 sec

void main(void)
{
    /* Pre-generated sine wave data, 16-bit signed samples */
    Int16 table[48] = {
        0x0000, 0x10b4, 0x2120, 0x30fb, 0x3fff, 0x4dea, 0x5a81, 0x658b,
        0x6ed8, 0x763f, 0x7ba1, 0x7ee5, 0x7ffd, 0x7ee5, 0x7ba1, 0x76ef,
        0x6ed8, 0x658b, 0x5a81, 0x4dea, 0x3fff, 0x30fb, 0x2120, 0x10b4,
        0x0000, 0xef4c, 0xdee0, 0xcf06, 0xc002, 0xb216, 0xa57f, 0x9a75,
        0x9128, 0x89c1, 0x845f, 0x811b, 0x8002, 0x811b, 0x845f, 0x89c1,
        0x9128, 0x9a76, 0xa57f, 0xb216, 0xc002, 0xcf06, 0xdee0, 0xef4c
    };

	printf("Exp C.7 --- Audio play back\n");

    tone(SAMPLING, TIME, GAIN, 0, table);

    printf("\nExp --- completed\n");
}
