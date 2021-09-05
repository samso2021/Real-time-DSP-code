;/*
; * asm_dlms.asm
; *
; *  Created on: Oct 20, 2012
; *      Author: BLEE
; *
; *  Description: This is the delayed LMS algorithm in assembly language implementation
; *
; *               The input is a 1kHz sine wave sampling rate 8kHz with noise
; *               The output is the sine wave
; *               The error is the noise
; *
; *  For the book "Real Time Digital Signal Processing:
; *                Fundamentals, Implementation and Application, 3rd Ed"
; *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
; *                Publisher: John Wiley and Sons, Ltd
; */

	.mmregs

	.sect	".text:dlms"
	.align 4
	.global	_asm_dlms

;----------------------------------------------------------------------
; unsigned short asm_dlms (LMS *lmsObj)                                           
;----------------------------------------------------------------------
_asm_dlms:
    pshboth XAR5                    ; AR5 will be used as index into x[]	
    pshboth XAR7                    ; AR7 will be used pointer to e[]	    
    psh   T3                        ; T3 is needed for LMS instruction
;
; Set up DSP processor for the Q15 processing mode with overflow
;
    mov   #0,mmap(ST0_55)           ; Clear all fields (OVx, C, TCx)
    or    #4140h,mmap(ST1_55)       ; Set CPL, FRCT, SXMD
    and   #07940h,mmap(ST1_55)      ; Clear BRAF, M40, SATD, C16, 54CM, ASM
    or    #0022h,mmap(ST2_55)       ; Set AR1 and AR5 in circular mode
    bclr  ARMS                      ; Disable ARMS bit in ST2
    bclr  SST                       ; Saturate-on-Store is disabled

;
; Set up paramters and pointers for the LMS algorithm
; 
    mov   dbl(*AR0(#2)),XAR3        ; AR3 pointer to des[], large memory model
    mov   dbl(*AR0(#4)),XAR2        ; AR2 pointer to out[], large memory model
    mov   dbl(*AR0(#6)),XAR1        ; AR1 pointer to w[],   large memory model
    mov   dbl(*AR0(#8)),XAR4        ; AR4 pointer to x[],   large memory model        
    mov   dbl(*AR0(#10)),XAR7       ; AR7 pointer to err[], large memory model
    mov   *AR0(#12),T0              ; T0 = step        
    mov   *AR0(#13),T1              ; T1 = order
    mov   *AR0(#14),AC0             ; AC0 = size of data block
    mov   *AR0(#15),AR5             ; AR5 is index in data array 
    mov   dbl(*AR0),XAR0            ; AR0 point to in[], large memory model                   
        
    mov   mmap(AR4),BSA45           ; BSA45 as start of circular data buffer
    mov   mmap(AR1),BSA01           ; BSA01 as start of coeffs buffer
    mov   #0,AR1                    ; AR0 to the 1st coefficient in buffer
    sub   #1,AC0                    ; Set block repeat counter
    mov   mmap(AC0L),BRC0 
    mov   mmap(T1),BK03             ; BK03 with order used with AR2    
    aadd  #1,T1
    mov   mmap(T1),BK47             ; BK47 = number of data samples (order+1)
    asub  #3,T1
    mov   mmap(T1),BRC1             ; Inner loop to number of coefficients-2
;
; Process block data using adaptive filter 
;
    mov   #0,AC1                    ; Clear AC1 for initial error term
||  rptblocal outer_loop-1
    mov   hi(AC1),T3                ; Put error in T3
    mov   *AR0+,*AR5+               ; Get input 
    mpym  *AR5+,T3,AC0              ; Put the 1st update term in AC0
||  mov   #0,AC1                    ; Clearing FIR value
    lms   *AR1,*AR5,AC0,AC1         ; AC0 has the update coefficient w[0]
                                    ; AC1 is the 1st FIR output out[0]
||  rptblocal inner_loop-1
    mov   hi(AC0),*AR1+             ; Save the updated coefficient
||  mpym  *AR5+,T3,AC0              ; Computing the next update coefficient
    lms   *AR1,*AR5,AC0,AC1         ; AC0 has the update coefficient w[i]
inner_loop:                         ; AC1 is update of FIR output out[i]
					            
    mov   hi(AC0),*AR1+             ; Save the updated coefficient
||  mov   rnd(hi(AC1)),*AR2+        ; Save the FIR output
    sub   AC1,*AR3+<<#16,AC2        ; AC2 is error amount
||  amar  *AR5+                     ; Point to oldest data sample
    mpyr  T0,AC2,AC1                ; Update mu_error term and place in AC1
||  mov   hi(AC2),*AR7+             ; Save error term
outer_loop:

;
; Restore registers and DSP processor modes 
;
    mov   AR5,T0                    ; Return data x[] index of oldest data
    pop   T3
    popboth XAR7                    ; Restore AR7 
||  bclr  FRCT                      ; Clear FRCT bit in ST1 return to C-caller
    popboth XAR5                    ; Restore AR5	
||  bset  ARMS                      ; Set ARMS bit for C-caller
    and   #0F800h,mmap(ST2_55)      ; Reset pointers in linear mode

    ret

 
