;/*
; * arraySort.asm
; *
; *  Created on: Apr 12, 2012
; *      Author: BLEE
; *
; *  For the book "Real Time Digital Signal Processing:
; *                Fundamentals, Implementation and Application, 3rd Ed"
; *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
; *                Publisher: John Wiley and Sons, Ltd
; */

;
;   Function prototype:
;		void arraySort(short *p1, short *p2, short n);
;
;   Entry: AR0 is the pointer p1
;          AR1 is the pointer p2
;          T0 is length n
;   Exit:
;
  	.def _arraySort      ; Using "_" prefix for C-callable
  	.ref _sort
  	.ref _a, _b

	.text
_arraySort:
	amov #_a,XAR0		; AR0 is the pointer to a[]
	amov #_b,XAR1		; AR1 is the pointer to b[]
	mov  #8,T0			; T0 is the length
	call _sort			; Sort a[] and reorder in b[]
	ret
	.end
