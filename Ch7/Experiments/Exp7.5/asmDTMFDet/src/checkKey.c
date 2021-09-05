/*
 * checkKey.c
 *
 *  Created on: Jul 15, 2012
 *      Author: BLEE
 *
 *  Description: C program check DTMF detected keys
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include "dtmfDetect.h"

enum
{         //col|row
  KEY_1 =  0x10|0x01,
  KEY_2 =  0x20|0x01,
  KEY_3 =  0x40|0x01,
  KEY_A =  0x80|0x01,      
  KEY_4 =  0x10|0x02,
  KEY_5 =  0x20|0x02,
  KEY_6 =  0x40|0x02,
  KEY_B =  0x80|0x02,
  KEY_7 =  0x10|0x04,
  KEY_8 =  0x20|0x04,
  KEY_9 =  0x40|0x04,
  KEY_C =  0x80|0x04,
  KEY_STAR=0x10|0x08,
  KEY_0 =  0x20|0x08,
  KEY_POND=0x40|0x08,
  KEY_D =  0x80|0x08
};

void checkKey(Int8 *key, Int16 keyIndex)
{
	switch(keyIndex)
	{
      case KEY_1:
        key[0] = '1'; break;
      case KEY_2:
        key[0] = '2'; break;
      case KEY_3:
        key[0] = '3'; break;
      case KEY_4:
        key[0] = '4'; break;
      case KEY_5:
        key[0] = '5'; break;
      case KEY_6:
        key[0] = '6'; break;
      case KEY_7:
        key[0] = '7'; break;
      case KEY_8:
        key[0] = '8'; break;              
      case KEY_9:
        key[0] = '9'; break;
      case KEY_0:
        key[0] = '0'; break;
      case KEY_STAR:
        key[0] = '*'; break;
      case KEY_POND:
        key[0] = '#'; break;
      case KEY_A:
        key[0] = 'A'; break;
      case KEY_B:
        key[0] = 'B'; break;
      case KEY_C:
        key[0] = 'C'; break;
      case KEY_D:
        key[0] = 'D'; break;
      default:
        key[0] = 0;   break;
	}  
	key[1] = 0;
}
