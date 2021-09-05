/*
 * Experiment sample rate conversion - Chapter 3
 * interpolation.h
 *
 * Description: This is the header file for interpolation FIR filter
 *
 *  Created on: May 13, 2012
 *      Author: BLEE
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#define  TAPS48to96         196

#define  INT_NUM_DATA_IN    (DATA_SIZE*3)  // DATA_SIZE is defined in decimation.h
#define  INT_NUM_DATA_OUT   (INT_NUM_DATA_IN*2)

void  interpolate(Int16 *x, Int16 blkSize,
                  Int16 *h, Int16 order,
                  Int16 *y,
                  Int16 *w, Int16 *index,
                  Int16 interp);
