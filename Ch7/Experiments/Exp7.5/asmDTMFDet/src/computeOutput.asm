;/*
; * computeOutput.asm
; *
; *  Created on: Jul 15, 2012
; *      Author: BLEE
; *
; *  Description: C program to compute DTMF decode output
; *
; *  Prototype: short computeOutput(short *d, short coef)
; *
; *  For the book "Real Time Digital Signal Processing:
; *                Fundamentals, Implementation and Application, 3rd Ed"
; *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
; *                Publisher: John Wiley and Sons, Ltd
; *
; */

	.mmregs
	.sect	".text:computeOutput"

	.global	_computeOutput

_computeOutput:
    amar  *AR0+
    mpym  *AR0+, T0, AC1 ; AC1  = (long) d[1] * coef 
    sfts  AC1, #-14      ; AC1 >>= 14; 
    mov   AC1, T0
    mpym  *AR0-, T0, AC0 ; AC1  = AC1 * d[2] 
    sqrm  *AR0+, AC1     ; AC0  = (long) d[1] * d[1];  
    sqam  *AR0-, AC1     ; AC0 += (long) d[2] * d[2];  
    sub   AC0, AC1       ; AC0 -= AC1 
||  mov   #0, *AR0+      ; d[1] = 0
    sfts  AC1, #-14, AC0  
||  mov   #0, *AR0       ; d[2] = 0 
    mov   AC0, T0        ; Out  = (short)(AC0 >> 14);
    ret   

	.end

