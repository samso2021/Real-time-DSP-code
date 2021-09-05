;/*
; * gFilter.asm
; *
; *  Created on: Jul 15, 2012
; *      Author: BLEE
; *
; *  Description: C program of the Goertzel algorithm filter
; *
; *  Prototyp: void gFilter (short *d, short in, short coef)
; *
; *  For the book "Real Time Digital Signal Processing:
; *                Fundamentals, Implementation and Application, 3rd Ed"
; *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
; *                Publisher: John Wiley and Sons, Ltd
; *
; */

	.mmregs

	.sect	".text:gFilter"

	.global	_gFilter

_gFilter:
    mov  T0, AC0  
    sfts AC0, #-7        ; d[0]  = in >> 7 
    mov  AC0, *AR0+  
    mov  *AR0+, AR1 
    mov  AR1, HI(AC1) 
    mpy  T1, AC1, AC1    ; AC0   = (long) d[1] * coef
    sfts AC1, #-14, AC1  ; AC0 >>= 14 
    sub  *AR0-, AC1, AR2 ; AC0  -= d[2]
    amar *AR0-
    add  AC0, AR2        
    mov  AR2, *AR0+      ; d[0] += (short)AC0 
    mov  AR2, *AR0+      ; d[1] = d[0] 
    mov  AR1, *AR0       ; d[2] = d[1] 
    ret

    .end
