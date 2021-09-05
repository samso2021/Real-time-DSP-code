;/*
;*  recInplcemn.asm
;*
;*  Created on: July 29, 2012
;*      Author: BLEE, this program is from Texas Instrument's example
;*
;*  Description: This program performs reconstruction wavelet-decompsed signal
;*
;*  For the book "Real Time Digital Signal Processing:
;*                Fundamentals, Implementation and Application, 3rd Ed"
;*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
;*                Publisher: John Wiley and Sons, Ltd
;*
;*/

;****************************************************************
; Function:    	reconInplace
; Version:     	1.00
; Processor:   	C55xx
; Description: 	reconstruction wavelet-decompsed signal
;
; Usage:  		reconInplace( int *input, int *output,
;			   			 	   int length, int *wavename )
;                                     
; Arguments:
;     input:	the wavelet decomposed signal buffer
;    output:    the reconstructed signal buffer
;    length:    length of the signal buffers
;  wavename:    the wavelet filter coefficients
;
; Copyright Texas instruments Inc, 2000
;****************************************************************

      .ARMS_off                     ;enable assembler for ARMS=0
      .CPL_on                       ;enable assembler for CPL=1
      .mmregs                       ;enable mem mapped register names

; Stack frame
; -----------
RET_ADDR_SZ       .set 1            ;return address
REG_SAVE_SZ       .set 0            ;save-on-entry registers saved
FRAME_SZ          .set 0            ;local variables
ARG_BLK_SZ        .set 0            ;argument block

PARAM_OFFSET      .set ARG_BLK_SZ + FRAME_SZ + REG_SAVE_SZ + RET_ADDR_SZ

; Register usage                                  
; --------------                                  
	  .asg    AR0, signal			;linear buffer     
	  .asg    AR1, wksp_add			;wksp address
	  .asg    AR2, filter_add		;filter address
      .asg    AR3, low          	;circular buffer
      .asg    AR4, high         	;circular buffer
      .asg    CDP, wksp       		;circular buffer   
      .asg    XAR0, xsignal
      .asg    XAR3, xlow
      .asg    XAR4, xhigh
  	  ;For reconstruction  
  	  ;---------------------------------------
      .asg    AR1, low_fl           ;circular
      .asg    AR2, high_fl			;circular
      .asg    AR4, low_sg           ;circular
      .asg    AR7, high_sg                    
      ;---------------------------------------
      
      .asg    BSA23, low_base   	;base addr for high
      .asg    BSA45, high_base  	;base addr for low
      .asg    BSAC, wksp_base                     
      
      ;For reconstruction
      ;---------------------------------------
      .asg 	  BSA01, low_fl_base
      .asg    BSA23, high_fl_base
      .asg    BSA45, low_sg_base
      .asg    BSA67, high_sg_base
      ;----------------------------------------
            
      .asg    BK03, low_sz      	;circ buffer size for filter_sz
      .asg    BK47, high_sz     	;circ buffer size for filter_sz 
      .asg    BKC, wksp_sz
      
      ;For reconstruction  
      .asg   BK03, fl_sz
      .asg   BK47, hf_sg_sz               
      
      .asg   CSR, inner_cnt
      .asg   BRC0, outer_cnt
    
ST2mask1  .set  0000000100011000b   ;circular/linear pointers       
ST2mask2  .set  0000000110010110b

      .global _reconInplace

      .text
_reconInplace:

;
; Configure the status registers as needed.
;----------------------------------------------------------------

	AND	#001FFh, mmap(ST0_55)		;clear all ACOVx,TC1, TC2, C
 
	OR	#04140h, mmap(ST1_55)		;set CPL, SXMD, FRCT

	AND	#0F9DFh, mmap(ST1_55)		;clear M40, SATD, 54CM    
    
	AND	#07A00h, mmap(ST2_55)		;clear ARMS, RDM, CDPLC, AR[0-7]LC

	AND	#0FFDDh, mmap(ST3_55)		;clear SATA, SMUL

;
; Setup loop counts
;----------------------------------------------------------------   
	MOV		mmap(T0), wksp_sz
	SFTL	T0, #-1         		;T0 = T0/2, input_length/2  
	MOV		mmap(T0), low_sz        ;lower part size
	MOV		mmap(T0), high_sz       ;higher part size   

	MOV		xsignal, xlow
	MOV		xlow, xhigh
	AMAR	*(high+T0)
	
	MOV     mmap(low), low_base    	;lower part address
	MOV		mmap(high), high_base	;higher part address
	MOV		mmap(wksp_add), wksp_base
 

; Set circular/linear ARx behavior
	MOV		#ST2mask1, mmap(ST2_55)	;configure circular/linear pointers
	
	MOV		*filter_add, T1
	SFTL    T1, #-1   				;Set the offset into T1
	SUB     #1, T1
    SUB	    T0, T1
    NEG     T1, T1
	MOV		T1, low
	MOV		T1, high	       
	MOV		#0, wksp
	
	SUB		#1, T0
	MOV		T0, BRC0            	;outer loop executes nr times   

;
; Start of outer loop
;----------------------------------------------------------------
	RPTBLOCAL	loop1-1     		;start the outer loop
    
    MOV    *low+, *wksp+
    MOV    *high+, *wksp+
 	
loop1:					    		;end of outer loop


;
;Reconstruction
;-------------------------
	MOV		*filter_add+, T1
	AMAR	*(filter_add+T1)
	AMAR	*(filter_add+T1)
	MOV		mmap(filter_add), low_fl_base
	AMAR	*(filter_add+T1)
	MOV		mmap(filter_add), high_fl_base     
	
	MOV		#0, low_fl
	MOV		#0, high_fl
	MOV		#0, wksp
	
	MOV		T0, outer_cnt  

	MOV		mmap(T1), fl_sz
	ADD		#1, T0
	MOV		mmap(T0), hf_sg_sz
	SUB		#3, T1
	MOV		T1, inner_cnt
	NEG		T1, T0

; Set circular/linear ARx behavior
	MOV		#ST2mask2, mmap(ST2_55)	;configure circular/linear pointers
	                                                 
	RPTBLOCAL 	loop2-1
	
	MPY *low_fl+, *wksp+, AC0
	::MPY *high_fl+, *wksp+, AC1   
	
	||RPT inner_cnt
	MAC *low_fl+, *wksp+, AC0
	::MAC *high_fl+, *wksp+, AC1
	
	MAC *low_fl+, *(wksp+T0), AC0
	::MAC *high_fl+, *(wksp+T0), AC1
	
	MOV HI(AC0), *signal+
	MOV HI(AC1), *signal+
	
loop2:	
	
;
; Restore status regs to expected C-convention values as needed
;----------------------------------------------------------------
	BCLR	FRCT					;clear FRCT

	AND	#0FE00h, mmap(ST2_55)		;clear CDPLC and AR[7-0]LC

	BSET	ARMS					;set ARMS

;
; Return to calling function
;----------------------------------------------------------------
	||RET							;return to calling function

;----------------------------------------------------------------
;End of file
