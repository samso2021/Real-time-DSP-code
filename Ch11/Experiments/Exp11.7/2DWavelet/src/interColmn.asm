;/*
;*  interColmn.asm
;*
;*  Created on: July 29, 2012
;*      Author: BLEE, this program is from Texas Instrument's example
;*
;*  Description: This program interlaces the low-pass output and high-pass output
;*               to a buffer for reconstruction
;*
;*  For the book "Real Time Digital Signal Processing:
;*                Fundamentals, Implementation and Application, 3rd Ed"
;*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
;*                Publisher: John Wiley and Sons, Ltd
;*
;*/

;****************************************************************
; Function:    	interlaceCol
; Version:    	1.00
; Processor:   	C55xx
; Description: 	interlace the low-pass output and high-pass output
;				to a buffer for reconstruction
;
; Usage:  		interlaceCol( int *low, int *high, int *output, 
;						       int IMAGE_WIDTH, int HEIGHT, 
;				               int filter_length)
;                                     
;   Arguments:
;         low:	The low-pass output from the deomposition
;        high:  The high-pass output from the decompositon
;      output:	The interlaced signal buffer
; IMAGE_WIDTH:	widht of the image
;      HEIGHT:  height of the column, it may be different from 
; 				the height of the image
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
      .asg    AR0, low          	;linear buffer
      .asg    AR1, high         	;linear buffer
      .asg    AR2, output       	;circular buffer
      
      .asg    XAR2, xoutput         ;extended output    
      .asg    BSA23, out_base  	    ;base addr for output
      .asg    BK03, out_sz      	;circ buffer size for filter_sz
    
ST2mask  .set  0000000000000100b   	;circular/linear pointers

      .global _interlaceCol

      .text
_interlaceCol:

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
	MOV		mmap(T1), out_sz		;output circular buffer size
	MOV		mmap(AR2), out_base
	SUB		#2, AR3					;filter_length - 2
	MOV		XAR3, xoutput
	
	SFTL	T1, #-1         		
	SUB		#1, T1
	MOV		T1, BRC0				;outer loop executes nr times    


; Set circular/linear ARx behavior

	MOV		#ST2mask, mmap(ST2_55)	;configure circular/linear pointers

;
; Start of outer loop
;----------------------------------------------------------------
	RPTBLOCAL	loop1-1     		;start the outer loop
    
    MOV    *(low+T0), *output+
    MOV    *(high+T0), *output+
 	
loop1:					    		;end of outer loop

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
