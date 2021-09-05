;/*
; * Experiment implementation of symmetric FIR filter - Chapter 3
; * symFir.asm
; *
; * Description: This is the implementation of symmetric block FIR filter
; *
; *  Created on: May 13, 2012
; *      Author: BLEE
; *
; * 		For the book "Real Time Digital Signal Processing:
; *                       Fundamentals, Implementation and Application, 3rd Ed"
; * 		              By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
; * 		              Publisher: John Wiley and Sons, Ltd
; */

	.mmregs 
	
	.sect	".text:fir"
	.align 4

	.def	_symFir

;----------------------------------------------------------------------
;   void symFir(Int16 *x,            => AR0
;               Int16 blkSize,       => T0
;               Int16 *h,            => AR1
;               Int16 order,         => T1
;               Int16 *y,            => AR2
;               Int16 *w,            => AR3
;               Int16 *index)        => AR4
;----------------------------------------------------------------------

_symFir:
    pshm  ST1_55                ; Save ST1, ST2, and ST3
    pshm  ST2_55
    pshm  ST3_55
    
    mov	  mmap(T1),BK03         ; Set signal buffer size = order	
    or    #0x340,mmap(ST1_55)   ; Set FRCT,SXMD,SATD   
    bset  SMUL                  ; Set SMUL
    mov   XAR1,XCDP             ; CDP as coefficient pointer
    mov   mmap(AR1),BSAC        ; Set up base address for CDP
    sfts  T1,#-1                ; T1 = order/2
||  mov   #0,CDP                ; Start from the 1st coefficient 
    mov   mmap(T1),BKC          ; Set the coefficient array size
    mov   XAR3,XAR1             ; AR1 & AR3 are signal buffer pointers
    mov   mmap(AR3),BSA01       ; Set base address of AR1 for signal buffer
    mov   mmap(AR3),BSA23       ; Set base address of AR3 for signal buffer    
    or    #0x10A,mmap(ST2_55)   ; CDP, AR1, AR3 are circular pointers
    mov   *AR4,AR3              ; AR3 is the Head of signal buffer 
    mov   *AR4,AR1              ; AR1 is the Tail of signal buffer  
||  sub   #1,T0
    amar  *AR1-                 ; Adjust tail starting point
||  mov   T0,BRC0               ; Outer loop counter blkSize-1 
    sub   #3,T1,T0              ; Inner loop for (order/2-2) iteration
    mov   T0,CSR
    mov   T1,T0                 ; Set up update offset for AR1
    sub   #2,T1                 ; Set up update offset for AR3
    mov   *AR0+,AC1             ; Get the first sample
||  rptblocal sample_loop-1     ; To prevent overflow in addition
    mov   #0,AC0                ;   input is scaled to Q14 format
||  mov   AC1<<#-1,*AR3         ; Put input to signal buffer in Q14
    add   *AR3+,*AR1-,AC1       ; AC1=[x(n)+x(n-L+1)]<<16
||  rpt   CSR                   ; Do order/2-2 iterations
    firsadd *AR3+,*AR1-,*CDP+,AC1,AC0    
    firsadd *(AR3-T0),*(AR1+T1),*CDP+,AC1,AC0 
    macm  *CDP+,AC1,AC0         ; Finish the last macm instruction  
    mov	  rnd(hi(AC0<<#1)),*AR2+; Store the rounded & scaled result
||  mov   *AR0+,AC1             ; Get next sample
sample_loop

    popm  ST3_55                ; Restore ST1, ST2, and ST3   
    popm  ST2_55
    popm  ST1_55
    mov   AR3,*AR4              ; Return signal buffer index
    ret
    .end             
