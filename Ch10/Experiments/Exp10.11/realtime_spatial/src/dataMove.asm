;/*
; * dataMove.asm
; *
; *  Created on: Oct 28, 2012
; *      Author: BLEE
; *
; *      Description: This assembly routine shifts the data buffer
; *
; *      prototype: void datamove(Int16 *ptr, Int16 n)
; *
; *  For the book "Real Time Digital Signal Processing:
; *                Fundamentals, Implementation and Application, 3rd Ed"
; *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
; *                Publisher: John Wiley and Sons, Ltd
; */

	.text

	.global  _dataMove
XMIT_BUFF_SIZE	.set 1024	; This number must be the same as d_buffer[]

_dataMove
	add  #XMIT_BUFF_SIZE-1,AR0
	amov XAR0,XAR1
	sub  #1,AR1
	rpt  #XMIT_BUFF_SIZE-2
	mov  *AR1-,*AR0-
	ret

	.end

