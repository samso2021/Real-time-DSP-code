/*
 * fAecInit.c
 *
 *  Created on: Aug 4, 2012
 *      Author: BLEE
 *
 *  Description: This program performs initialization for floating-point AEC experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "tistdtypes.h"
#include "fAec.h"

void aec_param_init(AEC_STR *aec)
{
  memset(aec,0,sizeof(AEC_STR));// Signal buffer for AEC

  aec->AECorder = 512;         // Order of AEC filter
  aec->shortWindow = 32;       // Length of short window, 4 ms
  aec->mediumWindow = 128;     // Length of medium window, 16 ms
  aec->longWindow = 16000;     // Length of long window, 2 second
  aec->ms5 = 80;               // 10 ms for ramp up
  aec->ms50 = 800;             // 100 ms for ramp down
  aec->hangoverTime = 1600;    // Hangover time is 200 ms
  aec->trainTime = 16000;      // Training time is 2 second

  aec->farHangCount = 1600;    // Hangover counter for far-end speech
  aec->nearHangCount = 1600;   // Hangover counter for near-end speech

  aec->saveMargin = 150.;      // Safety margin for speech detector

  aec->txGain = 1.;            // Attenuator value for transmit signal

 
  aec->leaky = (float)0.999969482;					// Leaky factor is 1. - 2**-15
  aec->mu = (float)(MuDefault/32767.);
  aec->CniGain = (float)50.;						// Initial value of CNI gain

/* Calculate parameters for power estimation using different window length */

  aec->alphaShort = (float)(1./aec->shortWindow);    // Alpha = 1/window length
  aec->alphaMedium = (float)(1./aec->mediumWindow);  // Alpha for medium window
  aec->alphaLong = (float)(1./aec->longWindow);      // Alpha for long window
  aec->alpha1Short = (float)(1. - aec->alphaShort);  // Alpha1 = 1 - alpha
  aec->alpha1Medium = (float)(1. - aec->alphaMedium);// For medium window
  aec->alpha1Long = (float)(1. - aec->alphaLong);    // For long window
  aec->rampUp = (float)(1./aec->ms5);                // Ramp up take 10 ms
  aec->rampDown = (float)(1./aec->ms50);             // Ramp down take 100 ms
} 

