/*
 * sirenGenTest.c
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
#include "siren.h"

#define SAMPLING	8000    // 8000Hz
#define GAIN		0       // 0dB
#define	TIME		10      // 10 seconds

/* Pre-generated siren data, 16-bit signed samples */
#pragma DATA_SECTION (sirentable, ".usect")
#include "wailSiren.h"

static Uint16 index=0;

void main( void )
{
    printf("Exp7.2 --- siren generator at 8kHz\n");

    siren(SAMPLING, TIME, GAIN, 0, sirentable, index);

    printf("\nExp --- completed\n");
}
