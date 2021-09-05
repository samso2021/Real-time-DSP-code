;/*
;*  col2rowmn.asm
;*
;*  Created on: July 29, 2012
;*      Author: BLEE, this program is from Texas Instrument's example
;*
;*  Description: This program copies a column of an image to a buffer
;*
;*  For the book "Real Time Digital Signal Processing:
;*                Fundamentals, Implementation and Application, 3rd Ed"
;*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
;*                Publisher: John Wiley and Sons, Ltd
;*
;*/

;****************************************************************
; Function:    	col2row
; Version:     	1.00
; Processor:   	C55xx
; Description: 	copy a column of an image to a buffer
;              
; Usage:  	   	col2row(int *col, int *row, 
;						int IMAGE_WIDTH, int HEIGHT );
;                                     
; Note:		    The row buffer size should be the same as HEIGHT	
; Arguments:
;       col:    the starting address of the column
;		row:    the address of the buffer
;IMAGE_WIDTH:    the width of the image
;	 HEIGHT:    the size of the column need to be processed
;
; Copyright Texas instruments Inc, 2000
;****************************************************************

      .ARMS_off                     ;enable assembler for ARMS=0
      .cpl_on                       ;enable assembler for CPL=1
      .mmregs                       ;enable mem mapped register names

      .global _col2row
                           
      .text
_col2row:

	SUB		#1, T1
	MOV		T1, CSR
	
	RPT     CSR
	MOV	    *(AR0+T0), *AR1+

;
; Return to calling function
;----------------------------------------------------------------
	RET							;return to calling function

;----------------------------------------------------------------
;End of file
