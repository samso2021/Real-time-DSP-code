;/*
; * dtmfFreq.asm
; *
; *  Created on: Jul 15, 2012
; *      Author: BLEE
; *
; *  Description: C program to find DTMF frequencies using Goertzel algorithm
; *
; *  Protype: void dtmfFreq(short *data, short *d, short *c, short frameSize)
;*
; *  For the book "Real Time Digital Signal Processing:
; *                Fundamentals, Implementation and Application, 3rd Ed"
; *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
; *                Publisher: John Wiley and Sons, Ltd
; *
; */

	.mmregs

	.sect	".text:dtmfFreq"

	.global	_dtmfFreq

	.global	_gFilter

ptrC      .set 0
ptrD      .set 2
stockSize .set 4
	
_dtmfFreq:
    psh  T3, T2
    pshboth XAR5
    pshboth XAR6
    pshboth XAR7
    aadd #-stockSize, SP

    mov  T0, T2                ; Save frameSize
    amar *AR0, XAR6            ; Save *data
    mov  XAR1, dbl(*SP(#ptrD)) ; Save *d
    mov  XAR2, dbl(*SP(#ptrC)) ; Save *c
    
frameLoop:                     ; for (j=0; j<frameSize; j++) {
    mov  *AR6+, T3             ;   x = *data++
    mov  dbl(*SP(#ptrD)), XAR5 ;   AR5 = *c
    mov  dbl(*SP(#ptrC)), XAR7 ;   AR7 = *dd
   
    amar *AR5, XAR0
    mov  T3, T0 
||  mov  *AR7+, T1 
    call _gFilter              ;   gFilter(dd, x, c[0]) 
    aadd #3, AR5               ;   dd += 3

    amar *AR5, XAR0
    mov  T3, T0 
||  mov  *AR7+, T1 
    call _gFilter              ;   gFilter(dd, x, c[1]) 
    aadd #3, AR5               ;   dd += 3

    amar *AR5, XAR0
    mov  T3, T0 
||  mov  *AR7+, T1 
    call _gFilter              ;   gFilter(dd, x, c[2]) 
    aadd #3, AR5               ;   dd += 3

    amar *AR5, XAR0
    mov  T3, T0 
||  mov  *AR7+, T1 
    call _gFilter              ;   gFilter(dd, x, c[3]) 
    aadd #3, AR5               ;   dd += 3

    amar *AR5, XAR0
    mov  T3, T0 
||  mov  *AR7+, T1 
    call _gFilter              ;   gFilter(dd, x, c[4]) 
    aadd #3, AR5               ;   dd += 3

    amar *AR5, XAR0
    mov  T3, T0 
||  mov  *AR7+, T1 
    call _gFilter              ;   gFilter(dd, x, c[5]) 
    aadd #3, AR5               ;   dd += 3

    amar *AR5, XAR0
    mov  T3, T0 
||  mov  *AR7+, T1 
    call _gFilter              ;   gFilter(dd, x, c[6]) 
    aadd #3, AR5               ;   dd += 3

    amar *AR5, XAR0
    mov  T3, T0 
||  mov  *AR7+, T1 
    call _gFilter              ;   gFilter(dd, x, c[7]) 

    sub  #1, T2 
    aadd #3, AR5               ;   dd += 3
||  bcc  frameLoop,T2 != #0    ; }

    aadd #stockSize, SP
    popboth XAR7
    popboth XAR6
    popboth XAR5
    pop  T3,T2
    ret

    .end
