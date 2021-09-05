/*
 * fAecCalc.c
 *
 *  Created on: Aug 4, 2012
 *      Author: BLEE
 *
 *  Description: This program performs Leaky Normalized LMS algorithms for floating-point AEC experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

/**************************************************************************
*           C program simulation of acoustic echo canceler using          *
*         1. mode detector (with near-end & far-end speech detectors)     *
*         2. on-line adaptation using leaky normalized LMS algorithm      *                                               *
*         3. residual error of AEC is used for near-end speech detector   *
*            The first 2 seconds of receive signal is considered in the   *
*            receive mode with additional 12 dB residual echo reduction   *
*         4. residual echo suppressor using center clipper when echo      *
*            return loss enhancement (ERLE) > 18 dB                       *
*         5. comfort noise is injected when center clipper is enabled     *
*         6. Attenuator on transmit is used for receive mode when         *
*            ERLE < 18 dB and for double-talk mode                        *
*                                                                         *
***************************************************************************
*--------------------------------------------------------------------------
*  Functions called by this program
*
*    fir, shift, uran
*
**************************************************************************/

#include <stdlib.h>
#include <math.h>
#include "tistdtypes.h"
#include "fAec.h"

Int16 aecCalc(float microphoneIn, float farEndIn, AEC_STR *aec)
{
  Int16 tempbin;
  float AECout,farEndOut;              // Output from AEC filter
  float speakerOut;                    // Signal send to loudspeaker
  float temp;                          // Temporary storage
  Int16 k;


  speakerOut = (float)farEndIn;        // Insert RX_processing here later
  temp = (float)fabs(speakerOut);      // temp = |speakerOut|
  aec->spkOutPowS = (float)(aec->alpha1Short*aec->spkOutPowS + aec->alphaShort*temp);
  aec->spkOutPowM = (float)(aec->alpha1Medium*aec->spkOutPowM + aec->alphaMedium*temp);
	
/**************************************************************************
*    Real-time speakerphone simulation:
*
*              _______________
*    farEndIn  |             |      speakerOut     to loudspeaker
*    --------->|RX_processing|-----|----------|-----------------> 
*              |_____________|     |          |
*                                __|__      __|__
*        ---------------------  |     |    |     |
*        | Other processing  |  |NLLMS|--->| AEC |
*        ---------------------  |_____|    |_____|
*                                  |          |
*               _____________      |          |AECout
*              |             |     |         -|  + 
*    <---------|TX_processing|<----|--------(sum)<--------------
*    farEndOut |_____________|   errorAEC           micropjoneIn
*
*
*    AEC FIR filter is updated by leaky normalized LMS (LNLMS) algorithm
*    TX_processing:
*      (1) residual echo suppressor using center clipper and inject
*          comfort noise if there is 18 dB ERLE in receive mode
*      (2) attenuator with -12 dB if ERLE < 18 dB in receive mode
*      (3) attenuator with -6 dB in double-talk mode
*    Other processing: none at this program, in the future, they are:
*      (1) analog loudspeaker volume control and detection
*      (2) performance monitoring to detect environment changes
*      (3) noise reduction
*      (4) automatic gain control
*
*************************************************************************/

  // Update far-end noise floor estimate of receiving far-end signal      
 
  temp = (float)fabs((float)farEndIn);    // temp = |farEndIn|
  aec->farInPowS = (float)(aec->alpha1Short*aec->farInPowS + aec->alphaShort*temp);
  aec->farInPowM = (float)(aec->alpha1Medium*aec->farInPowM + aec->alphaMedium*temp);

  if (aec->nfFar < aec->farInPowS)
  {
    aec->nfFar = (float)(aec->alpha1Long*aec->nfFar + aec->alphaLong*temp);
  }                 
  else
  {
    aec->nfFar = (float)(aec->alpha1Medium*aec->nfFar + aec->alphaMedium*temp);
  }                 

  // Update near-end noise floor estimate of signal pickup by microphone
  
  temp = (float)fabs((float)microphoneIn);        // temp = |microphoneIn|
  aec->micInPowS = (float)(aec->alpha1Short*aec->micInPowS + aec->alphaShort*temp);
                       // Estimate microphone signal power by short window
  aec->micInPowM = (float)(aec->alpha1Medium*aec->micInPowM + aec->alphaMedium*temp);

  if (aec->nfNear < aec->micInPowS)
  {
    aec->nfNear = (float)(aec->alpha1Long*aec->nfNear + aec->alphaLong*temp);
  }                
  else
  {
    aec->nfNear = (float)(aec->alpha1Medium*aec->nfNear + aec->alphaMedium*temp);
  }              

  //  AEC filtering to obtain echo mimic and error of AEC                 

  shift(aec->AECbuf,aec->AECorder,speakerOut);     
  AECout = fir(aec->AECbuf,aec->AECcoef,aec->AECorder); 
  aec->errorAEC = (float) microphoneIn - AECout;     

  aec->errorAECpowS = (float)(aec->alpha1Short*aec->errorAECpowS 
                    + aec->alphaShort*fabs(aec->errorAEC));
                        // Estimate power of AEC error by short window
  aec->errorAECpowM = (float)(aec->alpha1Medium*aec->errorAECpowM 
                    + aec->alphaMedium*fabs(aec->errorAEC));
                        // Estimate power of AEC error by medium window

/************************************************************************
*  Speech detection algorithm:
*
*    Far-end speech detector:
*      if (farInPowS > thresFar)
*         there is far-end speech
*
*    Near-end speech detector:
*      if (micInPowS > acousticLoss*spkOutPowS || erroAECpowS > thresNear)
*         there is near-end speech
*
************************************************************************/

  aec->thresFar = (float)(1.414*aec->nfFar + aec->saveMargin);                   
  aec->thresNear = (float)((1.414*aec->nfNear + aec->saveMargin)*4.0);
    
  if (aec->farInPowS>aec->thresFar)
  {
    aec->farFlag = 1;                 // Declare far-end speech
    aec->farHangCount = aec->hangoverTime; // Set hangover time counter
  }
  else
  {
    if (aec->farHangCount > 0)        // Counter no expire yet
    {
      aec->farHangCount--;            // Decrement hangover counter
    }
    else
    {
        aec->farFlag = 0;             // Hangover counter expired
    }
  }
	
  if ((aec->micInPowS>aec->thresNear) && (aec->errorAECpowS>aec->thresNear))
  {
    aec->nearFlag = 1;                // Declare near-end speech
    aec->nearHangCount = aec->hangoverTime;// Set hangover time counter
  }
  else
  {
    if (aec->nearHangCount > 0)       // Counter no expire yet
    {
      aec->nearHangCount--;           // Decrement hangover counter
    }
    else
    {
        aec->nearFlag = 0;            // Hangover counter expired
    }
  }

/************************************************************************
*  Mode detector:
*    Transmit    - near-end speech only, nearFlag = 1, farFlag = 0
*    Receive     - far-end speech only,  farFlag = 1, nearFalg = 0
*    Double-talk - both near-end and far-end speeches are present,
*                                        nearFlag = farFlag = 1
*    Idle        - no activity,          nearFlag = farFlag = 0
*
*
*
*  Operations at different Mode:
*
*    Mode        | TX_processing
*    ------------|-----------------------------------------------------
*    Idle        | farEndOut = microphoneIn
*                |
*    Transmit    | farEndOut = microphoneIn 
*                |  
*    Receive     | farEndOut = comfortNoise if ERLE > 18 dB
*                | farEndOut = 0.25*errorAEC if ERLE < 18 dB (-12 dB)
*                | update AEC coefficients
*                | 
*    double-talk | farEndOut = 0.5*errorAEC (-6 dB loss) 
*
***********************************************************************/

  aec->clipThres = (float)(aec->micInPowM/(1.414*4.0));  // Clipping threshold is 15 dB ERLE
  aec->clipThres2= (float)(aec->farInPowM/8.);           // Clipping threshold is 18 dB ERL

  if (aec->farFlag == 1)                                 // There is far-end speech
  {
    if ((aec->nearFlag == 0) || (aec->trainTime > 0))    // Receive mode
    {

      //  Receive mode operations 
      if (aec->trainTime > 0)                            // Counter is no expire yet
      {
        aec->trainTime--;                                // Decrement the counter
        if (aec->txGain > 0.25)
        {      
          aec->txGain -= aec->rampDown;                  // Ramp down
        }
        farEndOut = (float)(aec->txGain*aec->errorAEC);  // Attenuate by 12 dB
      }

      if ((aec->errorAECpowM<aec->clipThres)||(aec->errorAECpowM<aec->clipThres2))
      {                                        
        // Generate comfort noise to match background noise
        aec->comfortNoise = (float)((uran()-0.5));  
   
        // CniGain adjustment in case the captured Gain is not real
        if ( aec->CniGain > (1.414*aec->errorAECpowM) ) // 3dB margin
        {
          aec->CniGain = aec->errorAECpowM;             // Update CniGain with latest seeorAECPowM
        }		
        
        farEndOut = aec->CniGain*aec->comfortNoise;     // Inject comfort noise
        farEndOut *= aec->txGain;                       // Smoothed using current txGain further
      }
      else											
      {
        if (aec->txGain > 0.25)
        {
          aec->txGain -= aec->rampDown;                 // Ramp down
        }

        farEndOut =  (float)(aec->txGain*aec->errorAEC); // Disable center clipper
      } // Attenuated by 12 dB

      if (aec->farInPowM < 16000.) // Signal farEndIn is in reasonable
      { 
        // nfFar dependent
        // Experiment data: nfFar = around 5.0  for -64dBm0 input
        temp = (float) (aec->nfFar/5.0);                // Normalized to -64dBm0
        if (temp > 8.0 )
        {
          temp = 8.0;                                   // Boundary checking 
        }
        else if (temp < 1.0) 
        {
          temp = 1.0;
        }
        temp = (float)((aec->mu*aec->errorAEC)/
               ((aec->spkOutPowM+aec->saveMargin)*temp)); // Normalized step size

        for (k=0; k<aec->AECorder; ++k)                // Update 100% AEC coefficients
        {
          aec->AECcoef[k] = (float)(aec->leaky*aec->AECcoef[k] + temp*aec->AECbuf[k]);
        } // Leaky normalized LMS update
      }
    }
    else                                               // Double-talk mode operation
    {
      if (aec->txGain > 0.5)
      {
        aec->txGain -= aec->rampDown;                  // Ramp down
      }
      if (aec->txGain < 0.5)
      {
        aec->txGain += aec->rampUp;                    // Ramp up
      }
       
      farEndOut = (float)(aec->txGain*aec->errorAEC);  // Attenuate 6 dB
    }
  }
  else                                                 // There is no far-end speech
  {
    if (aec->nearFlag == 1)                            // Transmit mode operation
    {
      if (aec->txGain < 1)
      {
        aec->txGain += aec->rampUp;
      }
      
      farEndOut = aec->txGain* (float)microphoneIn;    // Full gain at transmit path
    }
    else                                               // Idle mode operation
    {
      if (aec->txGain > 0.5)
      {
        aec->txGain -= aec->rampDown;                  // Ramp down
      }
      if (aec->txGain < 0.5)
      {
        aec->txGain += aec->rampUp;                    // Ramp up
      }

      farEndOut = (float)(aec->txGain*(float)microphoneIn); // Attenuate 6 dB
      aec->CniGain = aec->errorAECpowM;                // Record background noise amplitude
    }
  }

  tempbin = (short)(farEndOut+0.5); 
  return tempbin;
}
