;/*
;*  reconColmn.asm
;*
;*  Created on: July 29, 2012
;*      Author: BLEE, this program is from Texas Instrument's example
;*
;*  Description: This program performs reconstruction a column of an image
;*
;*  For the book "Real Time Digital Signal Processing:
;*                Fundamentals, Implementation and Application, 3rd Ed"
;*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
;*                Publisher: John Wiley and Sons, Ltd
;*
;*/

;****************************************************************
; Function:    	reconCol
; Version:     	1.00
; Processor:   	C55xx
; Description: 	reconstruction a column of an image
;
; Usage:  		reconCol( int *input, int *col, int IMAGE_WIDTH, 
;						   int HEIGHT, int *wavename)
;     
; Note:			Before calling this function, interlace_col() 
;				should be called first to interlace the decomposed
;				signal into buffer input                                
;   Arguments:
;	    input:	the interlaced decompsed signal buffer
;         col:  the starting address of the column
; IMAGE_WIDTH:	width of the image
;      HEIGHT:  column size
;    wavename:  wavelet filter coefficients buffer
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
      .asg     CDP, input           ;circular pointer
      .asg     AR1, output         	;linear pointer
      .asg     AR3, low_filter	    ;circular pointer
      .asg     AR4, high_filter     ;circular pointer
                   
      .asg	   BSAC, input_base		;base addr for input
      .asg     BSA23, low_fl_base   ;base addr for low_filter
      .asg     BSA45, high_fl_base	;bass addr for high_filter
                                                              
      .asg     BKC, input_sz		;input circular buffer size
      .asg     BK03, low_fl_sz      ;circ buffer size for filter_sz
      .asg     BK47, high_fl_sz     ;circ buffer size for filter_sz 

      .asg     CSR, inner_cnt       ;inner loop count
      .asg     BRC0, outer_cnt      ;outer loop count

ST2mask  .set  0000000100011000b  	;circular/linear pointers

      .global _reconCol

      .text
_reconCol:

;
; Configure the status registers as needed.
;----------------------------------------------------------------

	AND	#001FFh, mmap(ST0_55)		;clear all ACOVx,TC1, TC2, C
 
	OR	#04140h, mmap(ST1_55)		;set CPL, SXMD, FRCT

	AND	#0F9DFh, mmap(ST1_55)		;clear M40, SATD, 54CM    
    
	AND	#07A00h, mmap(ST2_55)		;clear ARMS, RDM, CDPLC, AR[0-7]LC

	AND	#0FFDDh, mmap(ST3_55)		;clear SATA, SMUL       
	
;
; Setup passed parameters in their destination registers
; Setup circular/linear CDP/ARx behavior
;----------------------------------------------------------------   
 	MOV 	mmap(T1), input_sz
 	SFTL	T1, #-1
 	SUB		#1, T1
 	MOV		T1, outer_cnt;           
 	
 	MOV		T0, T1					;T1 = WIDTH
 	
   	MOV	 	*AR2+, T0				;length of filter
    AMAR 	*(AR2+T0)				
    AMAR 	*(AR2+T0)               ;AR2 point to lower rec filter
    MOV		mmap(AR2), low_fl_base	;get the low_pass filter address
    
    AMAR 	*(AR2+T0)               ;AR2 point to higher rec filter
	MOV		mmap(AR2), high_fl_base	;get the high_pass filter address

; Set circular/linear ARx behavior

	MOV	#ST2mask, mmap(ST2_55)		
	
	MOV		#0, low_filter		    	
	MOV		#0, high_filter		    	   
	
	MOV		mmap(T0), low_fl_sz		    
    MOV		mmap(T0), high_fl_sz		    
   		
 
;
; Setup loop counts
;----------------------------------------------------------------
	
	SUB		#3, T0      
	MOV		T0, inner_cnt   		;inner loop executes times
	NEG		T0, T0          		;T0 is used to reset input pointer   
	
	MOV		#0,	input					
	MOV		mmap(AR0), input_base	;base address of input             
	
;
; Start of outer loop
;----------------------------------------------------------------
	RPTBLOCAL	loop1-1				;start the outer loop
    
;1st iteration                                          
	
  	MPY	*low_filter+, *input+, AC0
	::MPY	*high_filter+, *input+, AC1
   
;inner loop
	||RPT	inner_cnt
	MAC	*low_filter+, *input+, AC0
	::MAC	*high_filter+, *input+, AC1

;last iteration
	MAC	*low_filter+, *(input+T0), AC0
	::MAC	*high_filter+, *(input+T0), AC1
	
  
;store result to memory
	MOV	HI(AC0), *(output+T1)		;store short result to memory
	MOV	HI(AC1), *(output+T1)		;store short result to memory
	
loop1:								;end of outer loop

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
