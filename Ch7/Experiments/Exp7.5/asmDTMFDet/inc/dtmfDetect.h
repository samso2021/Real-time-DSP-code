/*
 * dtmfDetec.h
 *
 *  Created on: Jul 15, 2012
 *      Author: BLEE
 *
 *  Description: C header file for DTMF detection experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#ifndef DTMFDETECT_H_
#define DTMFDETECT_H_
#include "tistdtypes.h"

void  gFilter(Int16 *d, Int16 in, Int16 coef);
Int16 computeOutput(Int16 *d, Int16 coef);
void  dtmfFreq(Int16 *data, Int16 *d, Int16 *c, Int16 frameSize);
void  gFreqDetect(Int16 *keyIndex, Int16 *d, Int16 *c, Int16 threshold);
void  checkKey(Int8 *key, Int16 keyIndex);
void  init(Int16 *d, Int16 *c);

#endif /* DTMFDETECT_H_ */
