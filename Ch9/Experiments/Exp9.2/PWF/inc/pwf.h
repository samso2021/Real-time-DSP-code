/*
 * pwf.h
 *
 *  Created on: Dec 6, 2012
 *      Author: BLEE
 *
 *  Description: This is the C header file for PWF experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#define LPCORDER  10                    // Between 1 and 20 
#define FRAMESIZE 180

#define PI 3.1415926
#define GAMMA1 (Int16)(0.9*32767);      // Default gamma
#define GAMMA2 (Int16)(0.4*32767);


void calc_autoc(Int16 *ws, Int16 p_order, Int16 frame_size, Int16 *autoc);
void hmwindowing(Int16 N, Int16 *input1, Int16 *ws, Int16 *HammingWindow);
void hmwindowGen(Int16 N, Int16 *HammingWindow);
void calc_lpc(Int16 *autoc, Int16 *lpc, Int16 p);
void calc_wz (Int16 *lpc, Int16 gamma1, Int16 gamma2, Int16 p_order, Int16 *wf1, Int16 *wf2);
