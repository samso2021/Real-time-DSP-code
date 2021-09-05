;/*
; * dspFunc55.asm
; *
; *  Created on: Dec 5, 2012
; *      Author: BLEE
; *
; *  Description: This is program contains s_sqrt and L_msl
; *
; *  For the book "Real Time Digital Signal Processing:
; *                Fundamentals, Implementation and Application, 3rd Ed"
; *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
; *                Publisher: John Wiley and Sons, Ltd
; *
; */

     .global  _s_sqrt

;
; Function:        s_sqrt()
;
; Description:     Square root computation
;

	.sect	".text"

_s_sqrt
      BSET	ST1_FRCT
      mov   ac0,ac2
||    mov   #13,ac0
      mov   mmap(AC0L),brc0        ;   BRC0=LE1-1
      mov   #0,t0
      mov   #0x4000<<#16,ac1
||    rptblocal sqrtloop-1
      add   mmap(t0)<<#16,ac1,ac0
      sqr   ac0,ac0
      CMP   ac2 >= ac0, TC1
      add   mmap(t0)<<#16,ac1,ac0
      xcc   move111,tc1 
      mov   mmap(AC0H),t0
move111
      sfts   ac1,#-1
sqrtloop
      BCLR  ST1_FRCT
      ret           

;******************************************************************************
;* FUNCTION NAME: L_mls                                                       *
;*                                                                            *
;*   Function Uses Regs : AC0,T0,AR0,CARRY,M40,SATD,FRCT,SMUL                 *
;*   Stack Frame        : Compact (No Frame Pointer, w/ debug)                *
;*   Total Frame Size   : 1 word                                              *
;*                        (1 return address/alignment)                        *
;******************************************************************************
	.global	_L_mls

	.sect	".text"

_L_mls:  
    OR 		#0x0340, mmap(ST1_55)	; Set FRCT, STAD, and SXMD
	AND 	#0xFFFF, AC0, AC1
    BSET 	ST3_SMUL
||	SFTL	AC1, #-1
	MPYM    mmap(AC0H), T0, AC0 	
	MPYM    mmap(AC1L), T0, AC1
	MOV     HI(AC1), T0
	MACK	T0, #1, AC0 			
;	MOV		AC0, dbl(*AR0)
    BCLR 	ST3_SMUL
    BCLR 	ST1_FRCT
    
    ret

	.end
	
   	    


       
