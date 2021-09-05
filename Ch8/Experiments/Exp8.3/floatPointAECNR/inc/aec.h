/*
 * aec.h
 *
 *  Created on: Oct 26, 2012
 *      Author: BLEE
 *
 *  Description: This is the C header file for Leaky Normalized LMS based AEC with NR experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include <stdio.h>
#include <math.h>

#define MAX  512          // Maximum order of arrays
#define MuDefault (0.04)  // Step size for LMS update

typedef struct {

  short AECorder;        // Order of AEC filter
  short shortWindow;     // Length of short window, 4 ms
  short mediumWindow;    // Length of medium window, 16 ms
  short longWindow;      // Length of long window, 2 second
  short nearFlag;        // Flag of near-end speech detector
  short farFlag;         // Flag of far-end speech detector
  short ms5;             // 5 ms for ramp up
  short ms50;            // 50 ms for ramp down
  short hangoverTime;    // Hangover time is 200 ms
  short trainTime;       // Training time is 2 second

  short farHangCount;    // Hangover counter for far-end speech
  short nearHangCount;   // Hangover counter for near-end speech

  float nfNear;          // Near-end noise floor
  float nfFar;           // Far-end noise floor
  float saveMargin;      // Safety margin for speech detector
  float thresNear;       // Threshold for near-end speech detector
  float thresFar;        // Threshold for far-end speech detector
  
  float errorAEC;        // Error signal of AEC
  float comfortNoise;    // Comfort noise for transmission
  float clipThres;       // Clipping threshold for center clipper

  float farInPowS;       // Power of farEndIn by short window
  float farInPowM;       // Power of farEndIn by medium window
  float micInPowS;       // Power of microphoneIn by short window
  float micInPowM;       // Power of microphoneIn by medium window
  float spkOutPowS;      // Power of speakerOut by short window
  float spkOutPowM;      // Power of speakerOut by medium window
  float errorAECpowS;    // Power of errorAEC by short window
  float errorAECpowM;    // Power of errorAEC by medium window

  float alphaShort;      // 1/short window length
  float alphaMedium;     // 1/medium window length
  float alphaLong;       // 1/long window length
  float alpha1Short;     // 1 - alphaShort
  float alpha1Medium;    // 1 - alphaMedium
  float alpha1Long;      // 1 - alphaLong
  float rampUp;          // Ramp up step size
  float rampDown;        // Ramp down step size
  float txGain;          // Attenuator value for transmit signal

  float AECcoef[MAX];    // Coefficient vector of AEC filter
  float AECbuf[MAX];     // Signal buffer for AEC
 
  float leaky;           // Leaky factor is 1. - 2**-15
  float mu;
  float CniGain;         // Initial value of CNI gain
  float clipThres2;      // 2nd clipping threshold for center clipper
} AEC_STR;

void  shift(float *x, 
            short N, 
            float newSample); // Function to update signal vector
float fir(float *x, 
          float *w, 
          short ntap);        // Function to perform FIR filtering
float uran(void);             // Function to generate white noise
short aecCalc(float microphoneIn, 
              float farEndIn, 
              AEC_STR *aec);
void  aec_param_init(AEC_STR *aec);

