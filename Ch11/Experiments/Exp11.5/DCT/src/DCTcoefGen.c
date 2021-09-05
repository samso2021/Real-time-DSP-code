/*
*  DCTcoefGen.c
*
*  Created on: Jul 27, 2012
*      Author: BLEE
*
*  Description: his function generates the 8x8 forward DCT/IDCT coefficients
*
*  For the book "Real Time Digital Signal Processing:
*                Fundamentals, Implementation and Application, 3rd Ed"
*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
*                Publisher: John Wiley and Sons, Ltd
*
* ------ note: only 8-bit data mode is supported --------------------------
*/

#include <math.h>
#include <stdlib.h>
#include "tistdtypes.h"
#include "dct.h"

#define PI          3.1415926
#define UNITS       (Int32)(4095*1.414*2.0)


void DCTcoefGen(Int16 (*dctCoef)[8], Int16 dctidct)
{
  Int32  u,x;
  double cu;

  for (u=0;u<8;u++)
  {
    for(x=0;x<8;x++)
    {
      if (u==0)
      {
        cu = 0.70710678/2.0;
      }
      else
      {
        cu = 1.0/2.0;
      }
      if (dctidct == 1)  // Generated iDCT coefficients
      {
        dctCoef[x][u] = (Int32)(cu*cos(((2.0*x+1.0)*PI*u)/16.0)*UNITS + 0.5);
      }
      else               // Generates DCT coefficients
      {
        dctCoef[u][x] = (Int32)(cu*cos(((2.0*x+1.0)*PI*u)/16.0)*UNITS + 0.5);
      }
    }
  }
}
