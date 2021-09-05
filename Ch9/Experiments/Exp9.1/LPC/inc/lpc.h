/*
 * lpc.h
 *
 *  Created on: Dec 6, 2012
 *      Author: BLEE
 *
 *  Description: This is the C header file for LPC experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#define LPCORDER  10                       /* Between 1 and 20 */
#define FRAMESIZE 180
#define PI 3.1415926

void  calc_autoc(Int16 *ws, Int16 p_order, Int16 frame_size, Int16 *autoc);
void  calc_lpc(Int16 *autoc, Int16 *lpc, Int16 p);
void  hmwindowGen(Int16 N, Int16 *HammingWindow);
void  hmwindowing(Int16 N, Int16 *input1, Int16 *ws, Int16 *HammingWindow);
