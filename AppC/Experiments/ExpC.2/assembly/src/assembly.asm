;/*
; * assembly.asm
; *
; *  Created on: Apr 1, 2012
; *      Author: BLEE
; *
; *  For the book "Real Time Digital Signal Processing:
; *                Fundamentals, Implementation and Application, 3rd Ed"
; *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
; *                Publisher: John Wiley and Sons, Ltd
; */

;
;	Assembly program example
;

N           .set	128
stk_size    .set	0x100

_Xin        .usect ".in_data",(2*N)    ; Input data array
_Xout       .usect ".out_data",(2*N)   ; Output data array
_Spectrum   .usect ".out_data",N       ; Data spectrum array

            .sect .data
input       .copy input.inc            ; Copy input.inc into program

            .def  _start               ; Define this program’s entry point
            .def  _Xin,_Xout,_Spectrum ; Make these data global data
            .ref  _dft_128,_mag_128    ; Reference external functions

            .sect .text

_start
    bset  SATD                  ; Set up saturation for D unit
    bset  SATA                  ; Set up saturation for A unit
    bset  SXMD                  ; Set up sign extension mode

    mov   #N-1,BRC0             ; Init counter for loop N times
    amov  #input,XAR0           ; Input data array pointer
    amov  #_Xin,XAR1            ; Xin array pointer

    rptblocal complex_data_loop-1 ; Form complex data
    mov  *AR0+,*AR1+
    mov  #0,*AR1+
complex_data_loop

    amov  #_Xin,XAR0            ; Xin array pointer
    amov  #_Xout,XAR1           ; Xout array pointer
    call  _dft_128              ; Perform 128-point DFT
    amov  #_Xout,XAR0           ; Xout pointer
    amov  #_Spectrum,XAR1       ; Spectrum array pointer
    call  _mag_128              ; Compute squared-magnitude response
    ret

    .end
