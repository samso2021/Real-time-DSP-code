;/*
; * findMax.asm
; *
; *  Created on: Apr 7, 2012
; *      Author: BLEE
; *
; *  For the book "Real Time Digital Signal Processing:
; *                Fundamentals, Implementation and Application, 3rd Ed"
; *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
; *                Publisher: John Wiley and Sons, Ltd
; */

;
;   Function prototype:
;		short findMax(short *p, short n);
;
;   Entry: AR0 is the pointer of p and T0 contains length n
;   Exit:  T0 contains the maximum data value found
;
  	.def   _findMax      ; Using "_" prefix for C-callable
	.text
_findMax:
	sub  #2,T0
	mov  T0,BRC0         ; Setup up loop counter
	mov  *AR0+,T0        ; Place the first data in T0
||	rptblocal loop-1     ; Loop through entire array
	mov  *AR0+,AR1       ; Place the next data in AR1
	cmp  T0<AR1,TC1      ; Check to see if new data is greater
||	nop                  ;   than the maximum?
	xccpart TC1          ; If find new maximum, place it in T0
||	mov  AR1,T0
loop
	ret                  ; Return with maximum data in T0
	.end
