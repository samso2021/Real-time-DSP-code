;/*
;*  decomColmn.asm
;*
;*  Created on: July 29, 2012
;*      Author: BLEE, this program is from Texas Instrument's example
;*
;*  Description: This program performs wavelet decomposition of a column of an image
;*
;*  For the book "Real Time Digital Signal Processing:
;*                Fundamentals, Implementation and Application, 3rd Ed"
;*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
;*                Publisher: John Wiley and Sons, Ltd
;*
;*/

;****************************************************************
; Function:    	decomCol
; Version:     	1.00
; Processor:   	C55xx
; Description: 	wavelet decomposition of a column of an image
;              
; Usage:		decomCol( int *signal, int *low_out, 
;						   int *high_out, int IMAGE_WIDTH, 
;						   int HEIGHT, int *wavename );
;                                     
; Note:			Before using this function, we should copy the 
;				column we want to process to a buffer. Then use
;				this function the decompsed signal will be saved
;				in the same column.
;   Arguments:	
;      signal:	A buffer saved the elements of the column
;     low_out: 	should be the starting address of the column
;    high_out:	should be the middle point address of the column
; IMAGE_WIDTH:  The width of the image
;      HEIGHT:  The length of the column we want to process, it 
;				may be different from the height of the image
;	 wavename:  wavelet filter coefficients
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
      .asg     CDP, input           ;input data, circular pointer
      .asg     AR1, low_out         ;low output, linear pointer
      .asg     AR2, high_out        ;high output, linear pointer
      .asg     AR3, low_filter	    ;low_pass filter, circular pointer
      .asg     AR4, high_filter     ;high_pass filter, circular pointer
     
      .asg     BSAC, input_base     ;base addr for input_ptr
      .asg     BSA45, high_fl_base  ;base addr for low_filter
      .asg     BSA23, low_fl_base   ;base addr for high_filter
      
      .asg     BK03, low_fl_sz      ;circ buffer size for filter_sz
      .asg     BK47, high_fl_sz     ;circ buffer size for filter_sz 
      .asg     BKC,  input_sz       ;input circular buffer size
    

      .asg     CSR, inner_cnt       ;inner loop count
      .asg     BRC0, outer_cnt      ;outer loop count

ST2mask  .set  0000000100011000b   	;circular/linear pointers

      .global _decomCol

      .text
_decomCol:

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
;
; Setup loop counts
;----------------------------------------------------------------     
	MOV 	mmap(T1), input_sz      ;input circular buffer size = HEIGHT
	SFTL	T1, #-1
	SUB		#1, T1         
	MOV		T1, outer_cnt           ;outer loop executes times      
	
	MOV		T0, T1                  ;WIDTH is in T1
	
	MOV		mmap(AR0), input_base	;base address of input 
	MOV		*AR3+, T0				;length of filter         
	MOV		mmap(AR3), low_fl_base	;base address of low_pass filter
    AMAR 	*(AR3+T0)              	;point to high_pass filter
	MOV		mmap(AR3), high_fl_base	;base address of high_pass filter
	
	MOV		#0,	input               ;reset input buffer index
	MOV		#0, low_filter          ;reset low_pass filter index
	MOV		#0, high_filter         ;reset high_pass filter index
	
	MOV		mmap(T0), low_fl_sz	    ;low_pass filter circular buffer size
    MOV		mmap(T0), high_fl_sz    ;high_pass filter circular buffer size
       
 
        
; Set circular/linear ARx behavior

	MOV		#ST2mask, mmap(ST2_55)	;configure circular/linear pointers
 	
	SUB		#3, T0
	MOV		T0, inner_cnt       	;inner loop executes times
	NEG		T0, T0              	;T0 is used to reset input pointer                                   

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
	
	MOV	HI(AC0), *(low_out+T1)	    ;store short result to low_out buffer
	::MOV	HI(AC1), *(high_out+T1) ;store short result to high_out buffer
	
loop1:					            ;end of outer loop

;
; Restore status regs to expected C-convention values as needed
;----------------------------------------------------------------
	BCLR	FRCT			        ;clear FRCT

	AND	#0FE00h, mmap(ST2_55)	    ;clear CDPLC and AR[7-0]LC

	BSET	ARMS			        ;set ARMS

;
; Return to calling function
;----------------------------------------------------------------
	||RET							;return to calling function

;----------------------------------------------------------------
;End of file
