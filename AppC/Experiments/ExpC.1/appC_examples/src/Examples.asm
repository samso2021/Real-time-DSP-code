;/*
; * Examples.asm
; *
; *  Created on: Sept 7, 2012
; *      Author: BLEE
; *
; *  For the book "Real Time Digital Signal Processing:
; *                Fundamentals, Implementation and Application, 3rd Ed"
; *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
; *                Publisher: John Wiley and Sons, Ltd
; */

	.def	_Example_C1
	.def	_Example_C2
	.def	_Example_C3
	.def	_Example_C4
	.def	_Example_C5
	.def	_Example_C6
	.def	_Example_C7
	.def	_Example_C8
	.def	_Example_C9
	.def	_Example_C10
	.def	_Example_C11
	.def	_Example_C12

	.def	_Example_init

_Example_C1:
	mov #0x3,DPH
	mov #0x0100,DP
	ret

_Example_C2:
	mov *AR0,AC0
	ret

_Example_C3:
	mov *AR2+,*AR3-,AC0
	ret

_Example_C4:
	mov *+CDP(#2),AC3
	ret

_Example_C5:
	mov *(#0x11234),T2
	ret

_Example_C6:
	mov mmap(@AC0L), T2
	ret

_Example_C7:
	bclr #13,ST0_55				; Clear TC1 before testing
	bclr #12,ST0_55				; Clear TC2 before testing
	btstp @28,AC0
	ret

_Example_C8:
	mpym *AR0+,*CDP-,AC0
	ret

_Example_C9:
	amov #0x200,AR1
	amov #0x300,AR2
	mov #0xfff0,T3
	sub AC3,AC3
	mov #0x1234,AC3
	bset FRCT

	macmr40 T3=*AR1+,*AR2+,AC3	; Example C.19

	bclr FRCT
	ret

_Example_C10:
	bclr #11,ST0_55
	ret

_Example_C11:
	bset #13,ST0_55
	mov #0x100,AR1
	sub	AC0,AC0
	xcc _test2,TC1				; This test is true, will execute instruction
	mov	*AR1+,AC0
_test2

	bclr #13,ST0_55
	mov #0x100,AR1
	sub	AC0,AC0
	xcc _test3,TC1				; This test is false, will not execute instruction
	mov	*AR1+,AC0
_test3
	nop
	ret

_Example_C12:
	bset #13,ST0_55
	mov #0x100,AR1
	sub	AC0,AC0
	xccpart _test4,TC1			; This test is true, will execute instruction
	mov	*AR1+,AC0
_test4

	bclr #13,ST0_55
	mov #0x100,AR1
	sub	AC0,AC0
	xccpart _finish_test,TC1	; This test is false, will partial execute instruction
	mov	*AR1+,AC0
_finish_test
	nop
	ret


_Example_init:
	mov #0,DPH					; Init for example C.1
	mov #0,DP

	sub AC0,AC0					; Init for exmaple C.2
	mov #0x0fab,*(AC0H)
	mov #0x8678,*(AC0L)
	amov #0x100,XAR0
	mov #0x12ab,*AR0

	amov #0x200,XAR2			; Init for example C.3
	amov #0x300,XAR3
	mov #0x5555,*AR2
	mov #0x3333,*AR3

	sub AC3,AC3					; Init for exmaple C.4
	mov #0x0fab,*(AC3H)
	mov #0xef45,*(AC3L)
	amov #0x400,XCDP
	mov #0x5631,*CDP(#2)

	mov #0xffff,*(#0x11234)		; Init for example C.5

	ret

	.end
