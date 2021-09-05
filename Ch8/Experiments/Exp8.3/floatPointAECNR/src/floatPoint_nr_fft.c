/*
 * floatPoint_nr_fft.c
 *
 *  Created on: Oct 26, 2012
 *      Author: BLEE
 *
 *  Description: This is the spectrum subtraction and fft code
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include <stdlib.h>
#include <math.h>
#include "tistdtypes.h"
#include "nr.h"

/***********************************************************************
*    FFT or IFFT routine                                               *
***********************************************************************/

void nr_fft(Complex *x, Int16 n, Int16 fft_ifft)
{ 
  Complex u, w, t, ctemp;
  Int16 nv2, nm1;
  Int16 i, j, jj, k, l;
  Int16 le, le1, ip, m;
  float fm;

  fm=(float)(log((double)n)/log((double)2));
  m=(Int16)(fm+0.1);                        // Fixed for rounding
  nv2=n/2;
  nm1=n-1;
  j=0;
  jj=1;
  for(i=0;i<nm1;i++)
  {
    if (i<j)
    {
      t.real=x[j].real;
      t.imag=x[j].imag;
      x[j].real=x[i].real;
      x[j].imag=x[i].imag;
      x[i].real=t.real;
      x[i].imag=t.imag;
    }
    k=nv2;
    while(k<jj)
    {
      j-=k;
      jj-=k;
      k=k/2;
    }
    j+=k;
    jj+=k;
  }

  /* Main FFT loop */

  for (l=0;l<m;l++)
  {
    le=(Int16)(pow(2.0,(double)(l+1)));
    le1=le/2;
    u.real=1.0;
    u.imag=0.0;
    if (fft_ifft == FFT)
    {
      w.real=(float)(cos(PI/le1));
      w.imag=(float)(-sin(PI/le1));
    }
    else //if (SWITCH==IFFT)
    {
      w.real=(float)(cos(PI/le1));
      w.imag=(float)(sin(PI/le1));
    }
    for (j=0;j<le1;j++)
    {
      for(i=j;i<n;i+=le)
      {
        ip=i+le1;
        t.real=x[ip].real*u.real-x[ip].imag*u.imag;
        t.imag=x[ip].imag*u.real+x[ip].real*u.imag;
        x[ip].real=x[i].real-t.real;
        x[ip].imag=x[i].imag-t.imag;
        x[i].real=x[i].real+t.real;
        x[i].imag=x[i].imag+t.imag;
      }
      ctemp.real=u.real*w.real-u.imag*w.imag;
      ctemp.imag=u.real*w.imag+u.imag*w.real;
      u.real=ctemp.real;
      u.imag=ctemp.imag;
    }
  }
}
