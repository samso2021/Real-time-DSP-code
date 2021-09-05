/*
 * floatPoint_nr_proc.c
 *
 *  Created on: Oct 26, 2012
 *      Author: BLEE
 *
 *  Description: This is the spectrum subtraction speech detection process
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

/***************************************************************
*      Spectral Subtraction
*
*         |---------|    |-----|
*  x(n)-->|windowing|-|->| FFT |-----|-------|----------|
*         |---------| |  |-----|     |       |          |
*                     |              |    |-----| speech|
*                    (a)..................| VAD |.......\
*                     |   noise      |    |-----|       |
*                     |              |                  |
*                     |          |-------|        |-----------|
*                     |          | Phase |        | spectral  |
*                     |          |-------|        |subtraction|
*                     |              |            |-----------|
*         |--------|  |   |------|   |                  |
*  x(n)<--| overlap|<-|---| IFFT |<----------------------
*         |--------|      |------|
*
*    a. Using modified algorithm for speech detection
*    b. Noise spectrum is estimated during the silence frame
*    c. Attenuate noise frame in time domain
*    d. There is no signal spectral averaging
*
***************************************************************/

#include <math.h>
#include "tistdtypes.h"
#include "nr.h"

void  nr_proc(NR_VAR *pnr)
{
    Int16 k,L,N,*inputbuf;
    Int32 Acc0;
    NR_VAR *p = (NR_VAR *)pnr;

	L = p->L;
	N = p->N;
    inputbuf = p->pIn;

    if (p->vadFlag)                         // Speech is detected since En >= threshold
    { 
        p->flag = 1;

        for (k=0;k<=N;k++)
        {
            if ((p->TB[k]/p->NS[k])>= 16.0) // Compute channel gain
			{
                p->tmp = (float)(p->TB[k] - (127./128.)*p->NS[k]);
			}
            else if ((p->TB[k]-p->NS[k]) >= 0.025*p->NS[k])
			{
                p->tmp = (float)(p->TB[k] - (p->Noise_scale)*p->NS[k]);
			}
            else 
			{
				p->tmp = (float)((1.0-p->Noise_scale)*p->TB[k]/2.0);
			}
            p->h[k] = p->tmp / p->TB[k];
        }
    }
    else                                   // Silence is detected since En < threshold
    { 
        { 
            p->flag = 0;
            for (k=0;k<=N;k++)             // Update the noise spectrum
            {
                p->NS[k] = p->alpha1*p->NS[k] + p->alpha*p->TB[k];
            }
            p->margin = (float)((1.0-1./128.)
				      *p->margin + (1./128.)*p->En); // New average of margin
        }
    }

    if (p->flag == 1)                      //  Speech frame, spectral subtraction
    { 
        p->D[0].real = p->D[0].real*p->h[0];
        p->D[0].imag = p->D[0].imag*p->h[0];

        for (k=1;k<=N;k++)
        {
            p->D[k].real = p->D[k].real*p->h[k];
            p->D[k].imag = p->D[k].imag*p->h[k];

            p->D[L-k].real = p->D[k].real;
            p->D[L-k].imag = -p->D[k].imag;
        }

        nr_fft(p->D,p->L,IFFT);
       
    }
    else                                  //  Noise frame, attenuate time domain
    {                                     //  Input signal
        for (k=0;k<N;k++)
        {  
            p->D[k].real = p->Atten*p->HBV[k];   
            p->D[k+N].real = p->Atten*(float)inputbuf[k];
        }
    }

    for (k=0;k<N;k++)                           // 50% data overlapping
    {   
        p->HBV[k] = (float) inputbuf[k];        // Update the data buffer
            
        Acc0 = (Int32)(p->D[k].real + p->DV[k]); // Doing 50% overlap
            
        if (Acc0 >=32767) 
		{
			Acc0 = 32767;  
		}
        else if (Acc0 <= -32768) 
		{
			Acc0 = -32768;
		}
        inputbuf[k] = (Int16) Acc0;
    }

    for (k=0;k<N;k++)                           // Delay the buffer for next frame
    {
        p->DV[k] = p->D[k+N].real;
    }
}


