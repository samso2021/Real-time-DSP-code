;/*
;* AIC3204_init.asm  AIC3204_init(Uint32, Int16, Uint16)
;*
;*  Created on: Mar 14, 2012
;*      Author: BLEE, modified
;*
;*  For the book "Real Time Digital Signal Processing:
;*                Fundamentals, Implementation and Application, 3rd Ed"
;*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
;*                Publisher: John Wiley and Sons, Ltd
;*/

;//////////////////////////////////////////////////////////////////////////////
;// * File name: aic_test_i2c.asm
;// *
;// * Description:  Code for playback using I2S2 and DMA1 to AIC3204.
;// *
;// * Copyright (C) 2009 Texas Instruments Incorporated - http://www.ti.com/
;// *
;// *
;// *  Redistribution and use in source and binary forms, with or without
;// *  modification, are permitted provided that the following conditions
;// *  are met:
;// *
;// *    Redistributions of source code must retain the above copyright
;// *    notice, this list of conditions and the following disclaimer.
;// *
;// *    Redistributions in binary form must reproduce the above copyright
;// *    notice, this list of conditions and the following disclaimer in the
;// *    documentation and/or other materials provided with the
;// *    distribution.
;// *
;// *    Neither the name of Texas Instruments Incorporated nor the names of
;// *    its contributors may be used to endorse or promote products derived
;// *    from this software without specific prior written permission.
;// *
;// *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
;// *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
;// *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
;// *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
;// *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
;// *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
;// *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
;// *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
;// *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
;// *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
;// *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;// *
;//////////////////////////////////////////////////////////////////////////////


        .mmregs

        .global  _AIC3204_init		; AIC3204_init(Uint32, Int16, Uint16)

        .include "lpva200.inc"

        .text

        .C54CM_off
        .CPL_off
        .ARMS_off
 
;****************************************************************************************
;   Define constants
;****************************************************************************************
I2C_CLKDIV_VAL   .set     35
AIC3204_I2C_ADDR .set    0x18

		.bss DAC_gain, 1
		.bss ADC_gain, 1
		.bss pReg5, 1

;****************************************************************************************
        .text 
;****************************************************************************************
;****************************************************************************************
;   Configure AIC3204
;****************************************************************************************
_AIC3204_init:
        and #0x3f, T0
		mov T0, DAC_gain		; Save DAC gain (one dB step)
		and #0x7f, T1
		add T1, T1
		mov T1, ADC_gain		; Save ADC gain (make 0.5dB to 1 dB step)
		mov #((8|1)<<4)|1,pReg5	; Default P=1 (48KHz), enable PLL on (0x80), R=1

check_24000:
		mov #24000, AC1			; Check 24000Hz
		cmpu AC0 != AC1, TC1
		bcc check_16000,TC1
		mov #((8|2)<<4)|1,pReg5

check_16000:					; Check 16000Hz
		mov #16000,AC1
		cmpu AC0 != AC1, TC1
		bcc check_12000,TC1
		mov #((8|3)<<4)|1,pReg5

check_12000:					; Check 12000Hz
		mov #12000,AC1
		cmpu AC0 != AC1, TC1
		bcc check_8000,TC1
		mov #((8|4)<<4)|1,pReg5

check_8000:						; Check 8000Hz
		mov #8000,AC1
		cmpu AC0 != AC1, TC1
		bcc config_AIC,TC1
		mov #((8|6)<<4)|1,pReg5

;****************************************************************************************
; Configure I2C
;****************************************************************************************
config_AIC:
        ; Set GPIO26 as output
		mov port(#0x1C00), T0
        or #0x003F, T0
        mov T0, port(#0x1C00)
        rpt #9
        NOP

        mov port(#0x1C07), T0
        or #0x0400, T0
        mov T0, port(#0x1C07)
        rpt #9
        NOP

        ; Set GPIO26 = 0
        mov port(#0x1C0B), T0
        and #0xFBFF, T0
        mov T0, port(#0x1C0B)
        rpt #99
        NOP

        ; Set GPIO26 = 1
        mov port(#0x1C0B), T0
        or #0x0400, T0
        mov T0, port(#0x1C0B)
        rpt #9
        NOP
	

        ; Initialize IIC
        mov #0x0004, port(#I2C_PSC)            ; Set prescaler to divide by 4+1=5
                                               ; I2C CLK = 49.156 MHZ / 5 = 9.8312 MHz
        mov #(I2C_CLKDIV_VAL), port(#I2C_CLKL) ; CPU clock divided by 35+5 for low period 
        mov #(I2C_CLKDIV_VAL), port(#I2C_CLKH) ; CPU clock divided by 35+5 for high period
                                               ;   SCL_High_Period = (1/9.8312M) *(35+5) = 4.07us
                                               ;   SCL_Low_Period = (1/9.8312) *(35+5) = 4.07us
											   ;   1/(4.07u+4.07u) = 122.9 KHz
        mov #0x002F, port(#I2C_OAR)            ; I2C Address - 5505 is set to 01011xx
        mov #0x0400, port(#I2C_MDR)            ; Place I2C module in reset
        rpt #8999
        NOP

        mov #0x0420, port(#I2C_MDR)            ; master, transmitter,out of reset, 7-bit address
        mov #0x0000, port(#I2C_EMDR)           ; Backward compatibility mode free data mode disabled

        mov #AIC3204_I2C_ADDR, port(#I2C_SAR)  ; I2C Address for AIC3204
        
;****************************************************************************************
; Configure AIC3204
;****************************************************************************************
	    ; Point to page 0
        mov #0, AC1
        mov #0x0, AR1
        call i2c_WriteData8
        
        ;reset codec
        mov #1, AC1
        mov #0x1, AR1
        call i2c_WriteData8
        
	    ; Point to page 1
        mov #0, AC1
        mov #0x1, AR1
        call i2c_WriteData8

        ;Disable crude AVDD generation from DVDD
        mov #1, AC1
        mov #0x08, AR1
        call i2c_WriteData8

        ;Enable Analog Blocks and LDO
        mov #2, AC1
        mov #0x01, AR1
        call i2c_WriteData8
        
		;***********************************************************************
        ;* PLL and Clocks config and Power Up                                  
		;***********************************************************************
	    ; Point to page 0
        mov #0, AC1
        mov #0x0, AR1
        call i2c_WriteData8        

 		;AIC is master running off of 12 MHz crystal
        ;BCLK and WCLK is set as op to AIC3204(Master)
        mov #27, AC1 
        mov #0x0D, AR1 
        call i2c_WriteData8
        
        ;PLL setting: PLLCLK <- MCLK and CODEC_CLKIN <-PLL CLK
        mov #4, AC1
        mov #0x03, AR1
        call i2c_WriteData8
        
        ;PLL setting: J=8
        mov #6, AC1
        mov #0x08, AR1 
        call i2c_WriteData8
        
        ;PLL setting: HI_BYTE(D) for D=0x0780 (or 1920 decimal)
        mov #7, AC1
        mov #0x07, AR1 
        call i2c_WriteData8
        
        ;PLL setting: LO_BYTE(D) for D=0x0780
        mov #8, AC1
        mov #0x80, AR1
        call i2c_WriteData8
        
        ;For 32 bit clocks per frame in Master mode ONLY
        ;BCLK=DAC_CLK/N =(12288000/8) = 1.536MHz = 32*fs
	    mov #30, AC1
	    mov #0x88, AR1
	    call i2c_WriteData8
        
		;PLL setting: Power up PLL, P=1 and R=1
        mov #5, AC1
		mov pReg5, AR1  ; set up P,R and enable PLL
        call i2c_WriteData8
        
        ;for 48 KHz sampling
	    ;Hi_Byte(DOSR) for DOSR = 128 decimal or 0x0080 DAC oversamppling
	    mov #13, AC1 
	    mov #0x00, AR1 
	    call i2c_WriteData8
	    
		;Lo_Byte(DOSR) for DOSR = 128 decimal or 0x0080
	    mov #14, AC1 
	    mov #0x80, AR1 
	    call i2c_WriteData8	    
	    
		;AOSR for AOSR = 128 decimal or 0x0080 for decimation filters 1 to 6
	    mov #20, AC1 
	    mov #0x80, AR1
	    call i2c_WriteData8
	    
		;Power up NDAC and set NDAC value to 8
	    mov #11, AC1 
	    mov #0x88, AR1
	    call i2c_WriteData8
	    
		;Power up MDAC and set MDAC value to 2
	    mov #12, AC1 
	    mov #0x82, AR1
	    call i2c_WriteData8
	    
		;Power up NADC and set NADC value to 8
	    mov #18, AC1 
	    mov #0x88, AR1 
	    call i2c_WriteData8
	    
        ;for 48 KHz sampling
		;Power up MADC and set MADC value to 2
	    mov #19, AC1 
	    mov #0x82, AR1 
	    call i2c_WriteData8	    

		;***********************************************************************
        ;* DAC ROUTING and Power Up                                            
		;***********************************************************************
        ;Select page 1
        mov #0x00, AC1
        mov #0x01, AR1 
        call i2c_WriteData8
        
        ;LDAC AFIR routed to HPL
        mov #0x0C, AC1 
        mov #0x08, AR1 
        call i2c_WriteData8

        ;RDAC AFIR routed to HPR
        mov #0x0D, AC1 
        mov #0x08, AR1 
        call i2c_WriteData8
        
        ;Select page 0
        mov #0x00, AC1
        mov #0x00, AR1 
        call i2c_WriteData8

        ;Left vol=right vol
        mov #64, AC1 
        mov #0x02, AR1 
        call i2c_WriteData8
        
        ;Left DAC gain to 0dB VOL; Right tracks Left
        mov #65, AC1 
        mov #0x00, AR1 
        call i2c_WriteData8
        
        ;Power up left,right data paths and set channel
        mov #63, AC1 
        mov #0xD4, AR1 
        call i2c_WriteData8

        ;Select page 1
        mov #0x00, AC1
        mov #0x01, AR1 
        call i2c_WriteData8

        ;Unmute HPL , 0dB gain
        mov #0x10, AC1
        mov DAC_gain, AR1
        call i2c_WriteData8
        
        ;Unmute HPR , 0dB gain
        mov #0x11, AC1 
        mov DAC_gain, AR1
        call i2c_WriteData8
        
        ;Power up HPL,HPR
        mov #0x09, AC1
        mov #0x30, AR1
        call i2c_WriteData8

		;Select page 0
        mov #0x00, AC1
        mov #0x00, AR1 
        call i2c_WriteData8

		mov #0x02FF, mmap(@BRC0)
		rptblocal rptbloop-1
			rpt #0xFFFF
			NOP
rptbloop
		NOP
				
		;***********************************************************************
        ;* ADC ROUTING and Power Up                                            
		;***********************************************************************
		;Select page 1
	    mov #0, AC1
	    mov #0x01, AR1
	    call i2c_WriteData8

		;STEREO 1 Jack
		;IN2_L to LADC_P through 40 kohm
	    mov #0x34, AC1 
	    mov #0x30, AR1
	    call i2c_WriteData8

		;IN2_R to RADC_P through 40 kohmm
	    mov #0x37, AC1 
	    mov #0x30, AR1 
	    call i2c_WriteData8
	    
		;CM_1 (common mode) to LADC_M through 40 kohm
	    mov #0x36, AC1
	    mov #0x03, AR1
	    call i2c_WriteData8

		;CM_1 (common mode) to RADC_M through 40 kohm
	    mov #0x39, AC1 
	    mov #0xC0, AR1 
	    call i2c_WriteData8

		;MIC_PGA_L unmute, with gain set
	    mov #0x3b, AC1
	    mov ADC_gain, AR1
	    call i2c_WriteData8

		;MIC_PGA_R unmute, with gain set
	    mov #0x3c, AC1
	    mov ADC_gain, AR1
	    call i2c_WriteData8

		;MIC_PGA_L unmute
	    mov #0x3B, AC1 
	    mov #0x00, AR1 
	    call i2c_WriteData8

		;MIC_PGA_R unmute
	    mov #0x3C, AC1 
	    mov #0x00, AR1 
	    call i2c_WriteData8

        ;Select page 0
        mov #0, AC1
        mov #0, AR1
        call i2c_WriteData8

        ;Powerup Left and Right ADC
        mov #0x51, AC1 
        mov #0xC0, AR1 
        call i2c_WriteData8

        ;Unmute Left and Right ADC
        mov #0x52, AC1 
        mov #0x00, AR1 
        call i2c_WriteData8

        ;Dummy read
        mov #9, AC1 
        mov #0xABAB, AR1  

i2c_WriteData8:
	    
		; Data count register = 2 for 1)address + 2)data
		mov  #0x0002, port(#I2C_CNT)
		
		; Disable interrupts
		mov #0000, port(#I2C_IMR)

        rpt #99
		NOP

	    ; Place I2C as transmitter
	    mov #0010011000100000b, port(#I2C_MDR)        ; Master transit with Start
		                  ;0~~~~~~~~~~~~~~~ NACK MOD - Master Receiver Mode: 
	                      ;                 1 -> the I2C sends NACK to transmitter during acknowledge cycle.
	                      ;                 0 -> the I2C sends ACK to transmitter during acknowledge cycle.
	                      ;~0~~~~~~~~~~~~~~ FREE: 0-> Disable free-run 1 -> I2C runs free during debugger breakpoint.
	                      ;~~1~~~~~~~~~~~~~ STT - Start Condition Bit: 1 -> (master mode) generates start condition (STP = 0).
	                      ;~~~0~~~~~~~~~~~~ Reserved (?)
	                      ;~~~~1~~~~~~~~~~~ STP: Set to 1 to generate STOP condition.
	                      ;~~~~~1~~~~~~~~~~ MST: 1 -> I2C is in master mode.
	                      ;~~~~~~1~~~~~~~~~ TRX - Transmitter: 0 -> I2C is in receiver mode 
	                                        ; MST|TRX = 10 -> master receiver mode.
	                                        ; MST|TRX = 11 -> master transmitter mode.
	                      ;~~~~~~~0~~~~~~~~ XA - Expanded Address: 0 -> 7-bit address mode, 1 -> 10-bit address mode.
	                      ;~~~~~~~~0~~~~~~~ RM - Repeat Mode
	                                        ; RM|STT|STP = 110 -> (Re) Start: S-A-D-D-D-D... continuous
	                      ;~~~~~~~~~0~~~~~~ DLB - Digital Loopback Mode: 1 -> I2C in digital loopback mode.
	                      ;~~~~~~~~~~1~~~~~ nIRS: 1 -> I2C not in reset, 0 -> I2C in reset.
	                      ;~~~~~~~~~~~0~~~~ START byte mode: 0 -> I2C in not in START byte mode.
	                      ;~~~~~~~~~~~~0~~~ 1 -> I2C is in free data format (Figure 6d).
	                      ;~~~~~~~~~~~~~000 BC - Bit Count, number of bits which are yet to be received/tranmsitted. 
        rpt #99
		NOP
	    call i2c_wait_for_slave_ack 
		call i2c_wait_for_tx

	    ; Place Register Address in TX data register
	    and #0x00FF, AC1, AC1
	    mov AC1,port(#I2C_DXR)	            ; place address
        rpt #99
		NOP
	    call i2c_wait_for_slave_ack 
	    call i2c_wait_for_tx
	        
	    and #0x00FF, AR1, AC2
	    mov AC2, port(#I2C_DXR)				; write data
        rpt #99
		NOP
	    call i2c_wait_for_slave_ack 

        rpt #99
		NOP

        ret

;****************************************************************************************
;	i2c_ReadData8 - Reads 8-bits
;****************************************************************************************
i2c_ReadData8:

		; Data count register = 2 for 1)address + 2)data
		mov #0x0000, port(#I2C_CNT)

	    ; Place I2C as transmitter
        mov #0010001010100000b, port(#I2C_MDR)        ; Master transit with Start
		                  ;0~~~~~~~~~~~~~~~ NACK MOD - Master Receiver Mode: 
	                      ;                 1 -> the I2C sends NACK to transmitter during acknowledge cycle.
	                      ;                 0 -> the I2C sends ACK to transmitter during acknowledge cycle.
	                      ;~0~~~~~~~~~~~~~~ FREE: 0-> Disable free-run 1 -> I2C runs free during debugger breakpoint.
	                      ;~~1~~~~~~~~~~~~~ STT - Start Condition Bit: 1 -> (master mode) generates start condition (STP = 0).
	                      ;~~~0~~~~~~~~~~~~ Reserved (?)
	                      ;~~~~0~~~~~~~~~~~ STP: Set to 1 to generate STOP condition.
	                      ;~~~~~1~~~~~~~~~~ MST: 1 -> I2C is in master mode.
	                      ;~~~~~~1~~~~~~~~~ TRX - Transmitter: 0 -> I2C is in receiver mode 
	                                        ; MST|TRX = 10 -> master receiver mode.
	                                        ; MST|TRX = 11 -> master transmitter mode.
	                      ;~~~~~~~0~~~~~~~~ XA - Expanded Address: 0 -> 7-bit address mode, 1 -> 10-bit address mode.
	                      ;~~~~~~~~1~~~~~~~ RM - Repeat Mode
	                                        ; RM|STT|STP = 110 -> (Re) Start: S-A-D-D-D-D... continuous
	                      ;~~~~~~~~~0~~~~~~ DLB - Digital Loopback Mode: 1 -> I2C in digital loopback mode.
	                      ;~~~~~~~~~~1~~~~~ nIRS: 1 -> I2C not in reset, 0 -> I2C in reset.
	                      ;~~~~~~~~~~~0~~~~ START byte mode: 0 -> I2C in not in START byte mode.
	                      ;~~~~~~~~~~~~0~~~ 1 -> I2C is in free data format (Figure 6d).
	                      ;~~~~~~~~~~~~~000 BC - Bit Count, number of bits which are yet to be received/tranmsitted. 
        rpt #99
		NOP
	    call i2c_wait_for_slave_ack 
		call i2c_wait_for_tx

	    ; Place Register Address in TX data register
	    and #0x00FF, AC1, AC1
	    mov AC1, port(#I2C_DXR)	            ; place address
        rpt #99
		NOP
	    call i2c_wait_for_slave_ack 
	    call i2c_wait_for_tx
	    	        
        ; Place I2C in receive mode
	    mov #0000010010100000b, port(#I2C_MDR)        ; Master transit with Start
		                  ;0~~~~~~~~~~~~~~~ NACK MOD - Master Receiver Mode: 
	                      ;                 1 -> the I2C sends NACK to transmitter during acknowledge cycle.
	                      ;                 0 -> the I2C sends ACK to transmitter during acknowledge cycle.
	                      ;~0~~~~~~~~~~~~~~ FREE: 0-> Disable free-run 1 -> I2C runs free during debugger breakpoint.
	                      ;~~0~~~~~~~~~~~~~ STT - Start Condition Bit: 1 -> (master mode) generates start condition (STP = 0).
	                      ;~~~0~~~~~~~~~~~~ Reserved (?)
	                      ;~~~~0~~~~~~~~~~~ STP: Set to 1 to generate STOP condition.
	                      ;~~~~~1~~~~~~~~~~ MST: 1 -> I2C is in master mode.
	                      ;~~~~~~0~~~~~~~~~ TRX - Transmitter: 0 -> I2C is in receiver mode 
	                                        ; MST|TRX = 10 -> master receiver mode.
	                                        ; MST|TRX = 11 -> master transmitter mode.
	                      ;~~~~~~~0~~~~~~~~ XA - Expanded Address: 0 -> 7-bit address mode, 1 -> 10-bit address mode.
	                      ;~~~~~~~~1~~~~~~~ RM - Repeat Mode
	                                        ; RM|STT|STP = 110 -> (Re) Start: S-A-D-D-D-D... continuous
	                      ;~~~~~~~~~0~~~~~~ DLB - Digital Loopback Mode: 1 -> I2C in digital loopback mode.
	                      ;~~~~~~~~~~1~~~~~ nIRS: 1 -> I2C not in reset, 0 -> I2C in reset.
	                      ;~~~~~~~~~~~0~~~~ START byte mode: 0 -> I2C in not in START byte mode.
	                      ;~~~~~~~~~~~~0~~~ 1 -> I2C is in free data format (Figure 6d).
	                      ;~~~~~~~~~~~~~000 BC - Bit Count, number of bits which are yet to be received/tranmsitted. 

        ; Set NACK to finish read cycle
;;	    mov #1000010010100000b, port(#I2C_MDR)         ; Master transit with Start
		                  ;1~~~~~~~~~~~~~~~ NACK MOD - Master Receiver Mode: 
	                      ;                 1 -> the I2C sends NACK to transmitter during acknowledge cycle.
	                      ;                 0 -> the I2C sends ACK to transmitter during acknowledge cycle.
	                      ;~0~~~~~~~~~~~~~~ FREE: 0-> Disable free-run 1 -> I2C runs free during debugger breakpoint.
	                      ;~~0~~~~~~~~~~~~~ STT - Start Condition Bit: 1 -> (master mode) generates start condition (STP = 0).
	                      ;~~~0~~~~~~~~~~~~ Reserved (?)
	                      ;~~~~0~~~~~~~~~~~ STP: Set to 1 to generate STOP condition.
	                      ;~~~~~1~~~~~~~~~~ MST: 1 -> I2C is in master mode.
	                      ;~~~~~~0~~~~~~~~~ TRX - Transmitter: 0 -> I2C is in receiver mode 
	                                        ; MST|TRX = 10 -> master receiver mode.
	                                        ; MST|TRX = 11 -> master transmitter mode.
	                      ;~~~~~~~0~~~~~~~~ XA - Expanded Address: 0 -> 7-bit address mode, 1 -> 10-bit address mode.
	                      ;~~~~~~~~1~~~~~~~ RM - Repeat Mode
	                                        ; RM|STT|STP = 110 -> (Re) Start: S-A-D-D-D-D... continuous
	                      ;~~~~~~~~~0~~~~~~ DLB - Digital Loopback Mode: 1 -> I2C in digital loopback mode.
	                      ;~~~~~~~~~~1~~~~~ nIRS: 1 -> I2C not in reset, 0 -> I2C in reset.
	                      ;~~~~~~~~~~~0~~~~ START byte mode: 0 -> I2C in not in START byte mode.
	                      ;~~~~~~~~~~~~0~~~ 1 -> I2C is in free data format (Figure 6d).
	                      ;~~~~~~~~~~~~~000 BC - Bit Count, number of bits which are yet to be received/tranmsitted. 

        rpt #99
		NOP
        ; Generate start condition
	    mov #1010010010100000b, port(#I2C_MDR)        ; Master transit with Start
		                  ;0~~~~~~~~~~~~~~~ NACK MOD - Master Receiver Mode: 
	                      ;                 1 -> the I2C sends NACK to transmitter during acknowledge cycle.
	                      ;                 0 -> the I2C sends ACK to transmitter during acknowledge cycle.
	                      ;~0~~~~~~~~~~~~~~ FREE: 0-> Disable free-run 1 -> I2C runs free during debugger breakpoint.
	                      ;~~1~~~~~~~~~~~~~ STT - Start Condition Bit: 1 -> (master mode) generates start condition (STP = 0).
	                      ;~~~0~~~~~~~~~~~~ Reserved (?)
	                      ;~~~~0~~~~~~~~~~~ STP: Set to 1 to generate STOP condition.
	                      ;~~~~~1~~~~~~~~~~ MST: 1 -> I2C is in master mode.
	                      ;~~~~~~0~~~~~~~~~ TRX - Transmitter: 0 -> I2C is in receiver mode 
	                                        ; MST|TRX = 10 -> master receiver mode.
	                                        ; MST|TRX = 11 -> master transmitter mode.
	                      ;~~~~~~~0~~~~~~~~ XA - Expanded Address: 0 -> 7-bit address mode, 1 -> 10-bit address mode.
	                      ;~~~~~~~~1~~~~~~~ RM - Repeat Mode
	                                        ; RM|STT|STP = 110 -> (Re) Start: S-A-D-D-D-D... continuous
	                      ;~~~~~~~~~0~~~~~~ DLB - Digital Loopback Mode: 1 -> I2C in digital loopback mode.
	                      ;~~~~~~~~~~1~~~~~ nIRS: 1 -> I2C not in reset, 0 -> I2C in reset.
	                      ;~~~~~~~~~~~0~~~~ START byte mode: 0 -> I2C in not in START byte mode.
	                      ;~~~~~~~~~~~~0~~~ 1 -> I2C is in free data format (Figure 6d).
	                      ;~~~~~~~~~~~~~000 BC - Bit Count, number of bits which are yet to be received/tranmsitted. 

        rpt #99
		NOP
	    call i2c_wait_for_slave_ack 
        call i2c_wait_for_data

	    mov port(#I2C_DRR), AC2				; read data
	    and #0x00FF, AC2, AR1

	    ; Place I2C as transmitter
	    mov #1010011010100000b, port(#I2C_MDR)     ; Master transit with Start
		                  ;0~~~~~~~~~~~~~~~ NACK MOD - Master Receiver Mode: 
	                      ;                 1 -> the I2C sends NACK to transmitter during acknowledge cycle.
	                      ;                 0 -> the I2C sends ACK to transmitter during acknowledge cycle.
	                      ;~0~~~~~~~~~~~~~~ FREE: 0-> Disable free-run 1 -> I2C runs free during debugger breakpoint.
	                      ;~~1~~~~~~~~~~~~~ STT - Start Condition Bit: 1 -> (master mode) generates start condition (STP = 0).
	                      ;~~~0~~~~~~~~~~~~ Reserved (?)
	                      ;~~~~0~~~~~~~~~~~ STP: Set to 1 to generate STOP condition.
	                      ;~~~~~1~~~~~~~~~~ MST: 1 -> I2C is in master mode.
	                      ;~~~~~~1~~~~~~~~~ TRX - Transmitter: 0 -> I2C is in receiver mode 
	                                        ; MST|TRX = 10 -> master receiver mode.
	                                        ; MST|TRX = 11 -> master transmitter mode.
	                      ;~~~~~~~0~~~~~~~~ XA - Expanded Address: 0 -> 7-bit address mode, 1 -> 10-bit address mode.
	                      ;~~~~~~~~1~~~~~~~ RM - Repeat Mode
	                                        ; RM|STT|STP = 110 -> (Re) Start: S-A-D-D-D-D... continuous
	                      ;~~~~~~~~~0~~~~~~ DLB - Digital Loopback Mode: 1 -> I2C in digital loopback mode.
	                      ;~~~~~~~~~~1~~~~~ nIRS: 1 -> I2C not in reset, 0 -> I2C in reset.
	                      ;~~~~~~~~~~~0~~~~ START byte mode: 0 -> I2C in not in START byte mode.
	                      ;~~~~~~~~~~~~0~~~ 1 -> I2C is in free data format (Figure 6d).
	                      ;~~~~~~~~~~~~~000 BC - Bit Count, number of bits which are yet to be received/tranmsitted. 


	    ; I2C Set back ACK_enable
	    mov #1010011010100000b, port(#I2C_MDR)     ; Master transit with Start
	    
		                  ;1~~~~~~~~~~~~~~~ NACK MOD - Master Receiver Mode: 
	                      ;                 1 -> the I2C sends NACK to transmitter during acknowledge cycle.
	                      ;                 0 -> the I2C sends ACK to transmitter during acknowledge cycle.
	                      ;~0~~~~~~~~~~~~~~ FREE: 0-> Disable free-run 1 -> I2C runs free during debugger breakpoint.
	                      ;~~1~~~~~~~~~~~~~ STT - Start Condition Bit: 1 -> (master mode) generates start condition (STP = 0).
	                      ;~~~0~~~~~~~~~~~~ Reserved (?)
	                      ;~~~~0~~~~~~~~~~~ STP: Set to 1 to generate STOP condition.
	                      ;~~~~~1~~~~~~~~~~ MST: 1 -> I2C is in master mode.
	                      ;~~~~~~1~~~~~~~~~ TRX - Transmitter: 0 -> I2C is in receiver mode 
	                                        ; MST|TRX = 10 -> master receiver mode.
	                                        ; MST|TRX = 11 -> master transmitter mode.
	                      ;~~~~~~~0~~~~~~~~ XA - Expanded Address: 0 -> 7-bit address mode, 1 -> 10-bit address mode.
	                      ;~~~~~~~~1~~~~~~~ RM - Repeat Mode
	                                        ; RM|STT|STP = 110 -> (Re) Start: S-A-D-D-D-D... continuous
	                      ;~~~~~~~~~0~~~~~~ DLB - Digital Loopback Mode: 1 -> I2C in digital loopback mode.
	                      ;~~~~~~~~~~1~~~~~ nIRS: 1 -> I2C not in reset, 0 -> I2C in reset.
	                      ;~~~~~~~~~~~0~~~~ START byte mode: 0 -> I2C in not in START byte mode.
	                      ;~~~~~~~~~~~~0~~~ 1 -> I2C is in free data format (Figure 6d).
	                      ;~~~~~~~~~~~~~000 BC - Bit Count, number of bits which are yet to be received/tranmsitted. 


	    mov #0010111010100000b, port(#I2C_MDR) ; Stop I2S transmission
        rpt #1999
		NOP

        ret
        
;****************************************************************************************
;   i2c_wait_for_bus_busy - Waits for bus to be unused
;****************************************************************************************
i2c_wait_for_bus_busy:
	    mov port(#I2C_STR), T1             ; wait for bus busy flag set (BB)
	    and #ICBB_FLAG, T1, T0
	    bcc i2c_wait_for_bus_busy, T0 != #0 ; bus is being used
	    ret
	    
;****************************************************************************************
;   i2c_wait_for_slave_ack - Waits for Slave ACK
;****************************************************************************************
i2c_wait_for_slave_ack:
	    mov port(#I2C_STR), T1              ; wait for ack flag cleared (NACK)
	    and #ICNACK_FLAG, T1, T0
	    bcc i2c_wait_for_slave_ack, T0 != #0 ; still no ack
	    mov #ICNACK_FLAG, port(#I2C_STR)    ; clear NACK
	    ret
	    
;****************************************************************************************
;   i2c_wait_for_tx - Waits for Data Transmit
;****************************************************************************************
i2c_wait_for_tx:
	    mov port(#I2C_STR), T1            ; wait for transmit flag set (ICXRDY)
	    and #ICXRDY_FLAG, T1, T0
	    bcc i2c_wait_for_tx, T0 == #0      ; still in transmission
	    mov #ICXRDY_FLAG, port(#I2C_STR)  ; clear ICXRDY
	    ret
	    
;****************************************************************************************
;   i2c_wait_for_data - Waits for Data receive
;****************************************************************************************
i2c_wait_for_data:
	    mov port(#I2C_STR), T1             ; wait for transmit flag set (ICRRDY)
	    and #ICRRDY_FLAG, T1, T0
	    bcc i2c_wait_for_data, T0 == #0     ; still in transmission
	    mov #ICRRDY_FLAG, port(#I2C_STR)   ; clear ICRRDY
	    ret
	    
;****************************************************************************************
;   i2c_wait_for_register_access - Waits for register access ready
;****************************************************************************************
i2c_wait_for_register_access:
	    mov port(#I2C_STR), T1             ; wait for register access ready (ARDY)
	    and #ICBB_FLAG, T1, T0
	    bcc i2c_wait_for_register_access, T0==#0 ; registers are being used
	    ret
	    
;****************************************************************************************
;   i2c_wait_for_stop - Waits for stop condition
;****************************************************************************************
i2c_wait_for_stop:
	    mov port(#I2C_STR), T1             ; wait for stop condition (SCD)
	    and #ICSCD_FLAG, T1, T0
        bcc i2c_wait_for_stop, T0==#0       ; no stop yet
	    mov #ICSCD_FLAG, port(#I2C_STR)    ; clear SCD
	    ret
	    
;****************************************************************************************
	.end
