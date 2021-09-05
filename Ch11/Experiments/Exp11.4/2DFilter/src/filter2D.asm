;/*
; *  filter2D.asm
; *
; *  Created on: Jul 21, 2012
; *      Author: BLEE
; *
; *  Description: This is the assembly version of the 2D filter
; *
; *  For the book "Real Time Digital Signal Processing:
; *                Fundamentals, Implementation and Application, 3rd Ed"
; *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
; *                Publisher: John Wiley and Sons, Ltd
; *
; */
	
	.mmregs

	.sect	".text:filter2D"

	.global	_filter2D

_filter2D:
    psh   T3, T2
;----------------------------------------------------------------------
;  initialization        
;----------------------------------------------------------------------
    mov   *AR0+, T0       		 ; mn = imfilt->m2D * imfilt->n2D
    mpym  *AR0+, T0, AC0  
    sub   #1, AC0
    mov   mmap(AC0L), BRC1

    mov   *AR0+, T3             ; row = imfilt->state
    mov   *AR0+, T0             ; state
    neg   T0, T2      
||  mov   dbl(*AR0+), XAR4      ; filter
    mov   dbl(*AR0+), XAR3      ; pixel  = imfilt->inData
    mov   dbl(*AR0+), XAR1
    mov   *AR0, T1              ; w imfilt->imWidth         
    mov   XAR1,XAR0 
    sub   #1, T1, AR1
    mov   AR1, BRC0

;----------------------------------------------------------------------
; process one row of data            
;----------------------------------------------------------------------
    mov   #0, AC2
||  rptblocal row_loop-1        ; for(x=0; x<imfilt->imWidth; x++)
    amar  *AR4, XAR2            ; filter = imfilt->filter
    mov   #0, AC0  
||  rptblocal filter_loop-1     ; for(temp32=0, i=0; i<mn; i++)
    macm  *(T3), T1, AC2, AC1   ; temp32 += (long)pixel[(row*w)+x] * *filter++; 
    mov   AC1, T0  
    mov   *AR3(T0) << #16, AC1
    macm  *AR2+, AC1, AC0 
    add   #1, T3                ; row++
    cmp   *(T3) == #3, TC1      ; if (row == 3) 
    xcc   TC1                   ; row = 0
||  mov   #0, T3            
filter_loop:

;----------------------------------------------------------------------
;  shift to compensate integer coefficient then limit to 8-bit          
;----------------------------------------------------------------------
    sfts  AC0, T2, AC0          ; temp32 >>= imfilt->shift 
||  mov   #256, AC1 
    cmp   AC0 >= AC1, TC1       ; if (temp32 > 255) temp32 = 255 
    xcc   AC0 < #0              ; if (temp32 < 0) temp32 = 0
    mov   #0, AC0
    xcc   TC1
    mov   #255, AC0
    mov   AC0, *AR0+            ; *imfilt->outData++ = (char)(temp32)
    add   #1, AC2 
row_loop:    

    pop   T3,T2
    ret


