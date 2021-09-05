;/*
; * asmLoop.asm
; *
; *  Created on: Apr 7, 2012
; *      Author: BLEE
; *
; *  For the book "Real Time Digital Signal Processing:
; *                Fundamentals, Implementation and Application, 3rd Ed"
; *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
; *                Publisher: John Wiley and Sons, Ltd
; */

	.global _asmLoop

	.text

_asmLoop:
	rpt	#(2*300)-1
	mov #0x5555,*AR0+
	ret
	.end
