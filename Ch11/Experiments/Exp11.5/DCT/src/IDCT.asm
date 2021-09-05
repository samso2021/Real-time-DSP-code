;/*
;*  IDCT.asm
;*
;*  Created on: Jul 27, 2012
;*      Author: BLEE
;*
;*  Description: This is the inverse 8x8 DCT algorithm in assembly implemenation
;*
;*  Prototype: void idct8x8(short *block, short (*idctCoef)[8])
;*
;*  For the book "Real Time Digital Signal Processing:
;*                Fundamentals, Implementation and Application, 3rd Ed"
;*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
;*                Publisher: John Wiley and Sons, Ltd
;*
;* ------ note: only 8-bit data mode is supported --------------------------
;*/

	.mmregs
	
	.sect	".text:idct8x8"

	.global	_idct8x8

BLOCK_SIZE .set 64

_idct8x8:
    pshboth XAR5
    aadd #-BLOCK_SIZE, SP      ; Adjust for temp16[64] buffer
;
;  First apply 1-D IDCT on the columns of 8x8 data block
;
    mov  #7, BRC0
    mov  #7, BRC1
    mov  #8, T0
||  amar *AR0, XAR5    
    mov  #0, T1
||  rptblocal columnLoop-1     ; for(i=0; i<8; i++)           
    mov  XSP, XAR4
    amar *AR1, XAR2            ; tmpCoef = &idctCoef[0][0]
    aadd T1, AR4
||  rptblocal dataLoop1-1      ; for(h=0; h<8; h++)
    amar *AR5, XAR3            ; tmpDat = curData
    mpym *(AR3+T0), *AR2+, AC0 ; AC0  = *tmpCoef++ * (long)(*tmpDat); tmpDat += 8 
||  rpt  #6                    ; for(j=0; j<7; j++)
    macm *(AR3+T0), *AR2+, AC0 ; AC0 += *tmpCoef++ * (long)(*tmpDat); tmpDat += 8
    sfts AC0, #-12             ; temp16[i+(h<<3)] = (short)(AC0>>12) 
    mov  AC0, *(AR4+T0)
dataLoop1
    add  #1, T1  
||  amar *AR5+
columnLoop

;
;  Apply 1-D IDCT on the resulting rows
;
    mov  #7, BRC0
    mov  #7, BRC1
    mov  XSP, XAR5
    rptblocal rowLoop-1    ; for(i=0; i<64; i+=8)
    amar *AR0, XAR4
    amar *AR1, XAR2        ; tmpCoef = &idctCoef[0][0]
||  rptblocal dataLoop2-1  ; for(h=0; h<8; h++) 
    amar *AR5, XAR3        ; tmpDat = curData
    mpym *AR3+, *AR2+, AC0 ; AC0  = *tmpCoef++ * (long)(*tmpDat++)
||  rpt  #6                ; for(j=0; j<7; j++)  
    macm *AR3+, *AR2+, AC0 ; AC0 += *tmpCoef++ * (long)(*tmpDat++)
    sfts AC0, #-15         ; block[i+h] = (short)(AC0>>15) 
    mov  AC0, *AR4+ 
dataLoop2  
    amar *(AR0+T0)
    amar *(AR5+T0)  
rowLoop

    aadd #BLOCK_SIZE, SP
    popboth XAR5
    ret

