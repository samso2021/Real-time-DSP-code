/*
 * fixedPoint_nlms.h
 *
 *  Created on: Aug 4, 2012
 *      Author: BLEE
 *
 *  Description: This is the header file for fixed-point AEC experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include "tistdtypes.h"

#define L       512                    // LMS adaptive filter length
#define MU      (Int16)(0.03*32768)    // LMS adaptive filter step size

#define ALPHA_SHIFT_SHORT		5		// Alpha = 1/window length
#define ALPHA_SHIFT_MEDIUM		7		// Alpha for medium window
#define ALPHA_SHIFT_LONG		14		// Alpha for long window

/**************************************************************************
*   Define variables for voice activity detection
**************************************************************************/
#define HANGOVER_TIME			1600	// Hangover time is 200 ms
#define SAFE_MARGIN			 9830400 	// Safety margin for speech detector
										// (150 shifted 16 bits)
#define VAD_POWER_THRESH       13573	// VAD power threshold. sqrt(2) - 1

typedef struct {
  Int16 in;                   // Input data of far end
  Int16 des;                  // Desired data of near end
  Int16 out;                  // Output data of fir
  Int16 order;                // Filter length
  Int16 mu;                   // Step size
  Int16 err;                  // AEC error output
  Int16 *w;                   // Pointer to coefficients
  Int16 *x;                   // Pointer to data delay line
  Int16 freez;                // 1 freeze, 0 not freeze
} LMS;


typedef struct {
  Int16 nearFlag;        // Flag of near-end speech detector
  Int16 farFlag;         // Flag of far-end speech detector
  Int16 nearHangCount;
  Int16 farHangCount;
  Int32  trainTime;

  Int32 nfNear;          // Near-end noise floor
  Int32 nfFar;           // Far-end noise floor
  Int32 saveMargin;		 // Safety margin for speech detector
  Int32 thresNear;       // Threshold for near-end speech detector
  Int32 thresFar;        // Threshold for far-end speech detector
  
  Int32 farInPowS;       // Power of farEndIn by short window
  Int32 farInPowM;       // Power of farEndIn by medium window
  Int32 micInPowS;       // Power of microphoneIn by short window
  Int32 micInPowM;       // Power of microphoneIn by medium window
  Int32 spkOutPowS;      // Power of speakerOut by short window
  Int32 spkOutPowM;      // Power of speakerOut by medium window
  Int32 errorAECpowS;    // Power of errorAEC by short window
  Int32 errorAECpowM;    // Power of errorAEC by medium window

} DTALK;

void fixPoint_nlms(DTALK *dtObj, LMS *lmsObj);
void fixPoint_double_talk(DTALK *dtObj, LMS *lmsObj);
long aec_power_estimate(Int32 pn, Int32 xn, Int16 n);
void aec_init(LMS *lms,DTALK *dt);
void fixPoint_nlp(DTALK *dtObj, LMS *lmsObj);
Int16 div_l( Int32  L_num, Int16 den );

