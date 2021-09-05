/*
 * fingerPrint.h
 *
 *  Created on: Jul 20, 2012
 *      Author: BLEE, modified
 *
 *  Description: This is the C header file for fingerprint experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 *  This program shows the functions flow for the Texas Instruments
 *  TMS320C5515 Fingerprint Development Kit
 *  (http://processors.wiki.ti.com/index.php/C5000_Fingerprint_Kit).
 *  The TMS320C5515 Fingerprint Development Kit is available from TI website.
 *
 */

/******************************************************************************/
/** Src image width					*/
#define TA_IMG_WIDTH				64
/** Src image hight					*/
#define TA_IMG_HEIGHT				64
/** Src image size					*/
#define M_NPIXEL              		4096
/** Image block width for direction & segment				    */
#define TA_BLK_WIDTH				4
/** Image block hight for direction & segment				    */
#define TA_BLK_HEIGHT				4
/** Get (x-y) absolute value   				                    */
#define ABSXY(x,y) 					((x)>(y)?((x)-(y)):((y)-(x)))
/** Vertical block num      				                    */
#define TA_BLK_NUMY					(TA_IMG_HEIGHT/TA_BLK_HEIGHT)
/** Horizontal block num      				                    */
#define TA_BLK_NUMX					(TA_IMG_WIDTH/TA_BLK_WIDTH)
/** All block num      				                            */
#define TA_BLK_NUM					(TA_BLK_NUMX*TA_BLK_NUMY)
/** Block size      				                            */
#define TA_BLOCK_PIXEL				(TA_BLK_WIDTH*TA_BLK_HEIGHT)

/* Gabor filter */
/** Gabor filter direction num   	                            */
#define GABOR_ORITATION_NUM			16
/** Gabor filter frequent  			                            */
#define GABOR_FREQUENT				5	
/** Gabor filter size      			                            */
#define GABOR_SIZE					7
/** Gabor filter radius size   		                            */
#define GABOR_RADIUS				(GABOR_SIZE/2)

/** Mathematical constant pi                                    */
#define PI 							3.1415926

void TA_BinImage (Uint16 *);
void TA_Graystretch(Uint16 *);
void TA_Segement(Uint16 *);
void TA_gabor_filter(Uint16 *, Int16 *);
void TA_Thin_image(Uint16 *,Uint16 *, Uint16 *);
void TA_GetBlockDirection(Uint16 *, Int16 *, Int16 *);

#define USE_FDK_DEMO_CODE  0 // Set to 1 if the FDK Demo software is available.
                             // (http://processors.wiki.ti.com/index.php/C5000_Fingerprint_Kit)
                             // Set to 0, for this demonstration for the experiment.



