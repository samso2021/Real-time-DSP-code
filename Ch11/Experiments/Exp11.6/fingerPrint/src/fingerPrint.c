/*
 * fingerPrint.c
 *
 *  Created on: Jul 20, 2012
 *      Author: BLEE, modified
 *
 *  Description: This file has the fingerprint algorithms
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


/*  ============================================================================
 *   Copyright (c) TooAn 2010
 *
 *  ============================================================================
 */
#include <string.h>
#include <math.h>
#include "tistdtypes.h"
#include "fingerPrint.h"

#if USE_FDK_DEMO_CODE
/** segment mark    								*/
Uint16 segment_mark[TA_BLK_NUM];
/** Block direction    								*/
Int16 Angle[TA_BLK_NUM];
/** gabor filter table 								*/
Int16 data_f[GABOR_ORITATION_NUM][GABOR_SIZE][GABOR_SIZE];
#endif

/** ============================================================================
 * Function:  		 Binarization
 *
 * Description:
 *            		 Binarization gray fingerprint image
 *					
 * parameter 
 * 					 image		enhanced image data
 *
 * return			 void
 *
 * TOOAN_version:	 1.0
 *  ============================================================================
 */
void TA_BinImage (Uint16 *image)
{
#if USE_FDK_DEMO_CODE
	 This program is part of Texas Instruments TMS320C5515 Fingerprint Development Kit
	 (http://processors.wiki.ti.com/index.php/C5000_Fingerprint_Kit).
#endif
}

/** ============================================================================
 * Function:		Segement
 *
 * Description:
 *             		Segement gray fingerprint image
 *					
 * parameter 
 * 					pImg		src image data
 *
 * return	  		void
 *
 * TOOAN_version: 	1.0
 *  ============================================================================
 */
void TA_Segement(Uint16 *pImg)
{
#if USE_FDK_DEMO_CODE
	 This program is part of Texas Instruments TMS320C5515 Fingerprint Development Kit
	 (http://processors.wiki.ti.com/index.php/C5000_Fingerprint_Kit).
#endif
}

/** ============================================================================
 * Function:	    Graystretch
 *
 * Description:
 *					stretch gray  &  enhancement image
 *					
 * parameter 
 *					pImg		src image data
 *
 * return			void
 *
 * TOOAN_version:	1.0
 *  ============================================================================
 */
void TA_Graystretch(Uint16 *pImg)
{
#if USE_FDK_DEMO_CODE
	 This program is part of Texas Instruments TMS320C5515 Fingerprint Development Kit
	 (http://processors.wiki.ti.com/index.php/C5000_Fingerprint_Kit).
#endif
}

/** ============================================================================
 * Function:		thinning image
 *
 * Description:
 *					thinning the binaray fingerprint image
 *					
 * parameter 
 *					Img			binaray image data			
 *					Temp        image buffer		
 *					T_mark		thinning mark
 *
 * return			void
 *
 * TOOAN_version:	1.0
 *  ============================================================================
 */
void TA_Thin_image(Uint16 *Img,Uint16 *Temp,Uint16 *T_mark)
{
#if USE_FDK_DEMO_CODE
	 This program is part of Texas Instruments TMS320C5515 Fingerprint Development Kit
	 (http://processors.wiki.ti.com/index.php/C5000_Fingerprint_Kit).
#endif
}

/** ============================================================================
 * Function		Get Block Direction 
 *					Block Size = 8*8
 *	
 * Description:
 *					Get block direction by gradient method   
 *				
 * parameter 
 *					Img			Image data
 *					Gx			Horizontal gradient
 *					Gy			Vertical gradient
 *
 * return			void
 *
 * TOOAN_version:	1.0
 *  ============================================================================
 */ 
void TA_GetBlockDirection(Uint16* Img,Int16* Gx,Int16* Gy)
{
#if USE_FDK_DEMO_CODE
	 This program is part of Texas Instruments TMS320C5515 Fingerprint Development Kit
	 (http://processors.wiki.ti.com/index.php/C5000_Fingerprint_Kit).
#endif
} 

/** ============================================================================
 * Function		gabor table
 *					Block Size = 8*8
 *	
 * Description:
 *					generation gabor filter table --- data_f
 *				
 * parameter 
 *					void
 *
 * return			void
 *
 * TOOAN_version:	1.0
 *  ============================================================================
 */ 
void TA_gabor_filter_table();
void TA_gabor_filter_table()
{
#if USE_FDK_DEMO_CODE
	 This program is part of Texas Instruments TMS320C5515 Fingerprint Development Kit
	 (http://processors.wiki.ti.com/index.php/C5000_Fingerprint_Kit).
#endif
}

/** ============================================================================
 * Function		Enhancement gray fingerprint image
 *					
 *	
 * Description:
 *					gabor filter
 *				
 * parameter 
 *					Img				src gray fingerprint image
 *					enhance_image	enhanced image	
 *
 * return			void
 *
 * TOOAN_version:	1.0
 *  ============================================================================
 */
void TA_gabor_filter(Uint16 *Img, Int16 *enhance_image)
{
#if USE_FDK_DEMO_CODE
	 This program is part of Texas Instruments TMS320C5515 Fingerprint Development Kit
	 (http://processors.wiki.ti.com/index.php/C5000_Fingerprint_Kit).
#endif
}
