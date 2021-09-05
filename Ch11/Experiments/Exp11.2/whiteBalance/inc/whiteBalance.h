/*
 *  whitebalance.h
 *
 *  Created on: Jul 21, 2012
 *      Author: BLEE
 *
 *  Description: This is the C header file for white balance experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

typedef struct {
	Uint32 rSum;              // Red pixel sum
	Uint32 gSum;              // Green pixel sum
	Uint32 bSum;              // Blue pixel sum
	Uint16 rGain;             // Red white balance gain
	Uint16 gGain;             // Green white balance gain
	Uint16 bGain;             // Blue white balance gain
	Uint16 width;             // Input: image width
	Uint16 height;            // Input: image height
	Uint16 *r;                // Input: pointer to R element buffer
	Uint16 *g;                // Input: pointer to G element buffer
	Uint16 *b;                // Input: pointer to B element buffer
	Uint16 status;            // WB status: 0 for sum calculation
	                          //            1 for WB correction
	                          //            2 for WB gain computation
} wbImg;

void whiteBalance(wbImg *img);

enum
{
	COMPUTE_SUM = 0,
	DO_WB,
	COMPUTE_GAIN
};
