/*
 * dtmfGenTest.c
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
#include "dtmf.h"

#define SAMPLING	8000	// 8000Hz
#define GAIN		0		// 0dB
#define	TIME		10		// 10 seconds

/* Length of siren data table */
#define DTMF_TABLE_SIZE     800

// Tone tables
#include "tone697.h"
#include "tone770.h"
#include "tone852.h"
#include "tone941.h"
#include "tone1209.h"
#include "tone1336.h"
#include "tone1477.h"
#include "tone1633.h"



#define NUM_DIGITS  16
char  digits[NUM_DIGITS]={'1','2','3','A','4','5','6','B','7','8','9','C','*','0','#','D'};

void main( void )
{
	Int16 i;
    const Int16 *ptrFl,*ptrFh;

    /* Pre-generated sine wave data, 16-bit signed samples */

	printf("Exp7.3 --- DTMF tone at 8kHz\n");

	tone_init(SAMPLING, GAIN, 0);

	for (i=0; i<NUM_DIGITS; i++)
	{
        switch(digits[i])
        {
	      case '1':
	        ptrFl = tone697;
	        ptrFh = tone1209;
	        break;
	      case '2':
	        ptrFl = tone697;
	        ptrFh = tone1336;
	        break;
	      case '3':
	        ptrFl = tone697;
	        ptrFh = tone1477;
	        break;
	      case 'a':
          case 'A':
	        ptrFl = tone697;
	        ptrFh = tone1633;
	        break;
	      case '4':
	        ptrFl = tone770;
	        ptrFh = tone1209;
	        break;
	      case '5':
	        ptrFl = tone770;
	        ptrFh = tone1336;
	        break;
	      case '6':
	        ptrFl = tone770;
	        ptrFh = tone1477;
	        break;
	      case 'b':
          case 'B':
	        ptrFl = tone770;
	        ptrFh = tone1633;
	        break;
	      case '7':
	        ptrFl = tone852;
	        ptrFh = tone1209;
	        break;
	      case '8':
	        ptrFl = tone852;
	        ptrFh = tone1336;
	        break;
	      case '9':
	        ptrFl = tone852;
	        ptrFh = tone1477;
	        break;
	      case 'c':
          case 'C':
	        ptrFl = tone852;
	        ptrFh = tone1633;
	        break;
	      case '*':
	        ptrFl = tone941;
	        ptrFh = tone1209;
	        break;
	      case '0':
	        ptrFl = tone941;
	        ptrFh = tone1336;
	        break;
	      case '#':
	        ptrFl = tone941;
	        ptrFh = tone1477;
	        break;
	      case 'd':
          case 'D':
	        ptrFl = tone941;
	        ptrFh = tone1633;
	        break;
	      default:
	        ptrFl = NULL;
	        ptrFh = NULL;
	        break;
	    }

        dtmfTone((Int16 *)ptrFl, (Int16 *)ptrFh);
	}

	tone_stop();

	printf("DTMF digits played: ");
	for (i=0; i<NUM_DIGITS; i++)
	{
		printf("%c ", digits[i]);
	}

    printf("\nExp --- completed\n");
}
