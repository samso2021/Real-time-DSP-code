/* 
//  Example 3.17: fixed-point implementation of FIR filter 
//  File name: firCoef.h   
//
//  Description: This is the filter coefficient file for fixed-point FIR filter
//
//  For the book "Real Time Digital Signal Processing: 
//                Fundamentals, Implementation and Application, 3rd Ed"
//                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
//                Publisher: John Wiley and Sons, Ltd
*/

short firCoefFixedPoint[NUM_TAPS]={
(short)(-0.0011606*32767.0),(short)(0.005235*32767.0),  (short)(0.0019751*32767.0), (short)(-0.0010696*32767.0),  
(short)(0.00070486*32767.0),(short)(-0.0023019*32767.0),(short)(-0.0085149*32767.0),(short)(0.0032251*32767.0),
(short)(0.019339*32767.0),  (short)(0.0019924*32767.0), (short)(-0.024454*32767.0), (short)(-0.00927*32767.0),    
(short)(0.015833*32767.0),  (short)(0.0056414*32767.0), (short)(0.0040532*32767.0), (short)(0.022213*32767.0),
(short)(-0.018912*32767.0), (short)(-0.074497*32767.0), (short)(0.0079832*32767.0), (short)(0.13193*32767.0),    
(short)(0.03699*32767.0),   (short)(-0.16479*32767.0),  (short)(-0.10113*32767.0),  (short)(0.15292*32767.0),
(short)(0.15292*32767.0),   (short)(-0.10113*32767.0),  (short)(-0.16479*32767.0),  (short)(0.03699*32767.0),    
(short)(0.13193*32767.0),   (short)(0.0079832*32767.0), (short)(-0.074497*32767.0), (short)(-0.018912*32767.0),
(short)(0.022213*32767.0),  (short)(0.0040532*32767.0), (short)(0.0056414*32767.0), (short)(0.015833*32767.0),  
(short)(-0.00927*32767.0),  (short)(-0.024454*32767.0), (short)(0.0019924*32767.0), (short)(0.019339*32767.0),
(short)(0.0032251*32767.0), (short)(-0.0085149*32767.0),(short)(-0.0023019*32767.0),(short)(0.00070486*32767.0),
(short)(-0.0010696*32767.0),(short)(0.0019751*32767.0), (short)(0.005235*32767.0),  (short)(-0.0011606*32767.0)
};
