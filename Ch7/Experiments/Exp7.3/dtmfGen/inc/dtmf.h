/*
 * dtmf.h
 *
 *  Created on: Jul 14, 2012
 *      Author: BLEE
 *
*  Description: This C header file defines the functions used
*
*  For the book "Real Time Digital Signal Processing:
*                Fundamentals, Implementation and Application, 3rd Ed"
*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
*                Publisher: John Wiley and Sons, Ltd
*
*/


#ifndef STMF_H_
#define STMF_H_

#define DTMF_TABLE_SIZE     800

void tone_stop(void);
void tone_init(Uint32 sf, Int16 gDAC, Uint16 gADC);
void dtmfTone(Int16 *f1, Int16 *fh);

#endif /* STMF_H_ */
