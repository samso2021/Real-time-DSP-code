/*
 * siren.h
 *
 *  Created on: Jul 14, 2012
 *      Author: BLEE
  *
 *  Description: This is the data file for siren signal generation
 *               800 - 1700 Hz sweep at 8kHz sampling rate
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#ifndef SIREN_H_
#define SIREN_H_

#define SIREN_TABLE_SIZE     19680

void siren(Uint32, Int16, Int16, Uint16, Int16*, Uint16);

#endif /* SIREN_H_ */
