;/*
; * unknowFirFilter.asm
; *
; *  Created on: June 6, 2012
; *      Author: BLEE
; *
; *  Description: This is the unknown plant (generic FIR filter) used for system identification experiment
; *
; *               The input is a white noise
; *               The adative filter coefficients after converge should match the unknown system
; *
; *
; *  Prototype: unsigned short unknowPlant(ADAPTSYSID *adaptSys)
; *
; *   Entry: arg0: AR0 - filter input sample buffer pointer
; *          arg1: T0  - number of samples in input buffer
; *          arg2: AR1 - FIR coefficients array pointer
; *          arg3: T1  - FIR filter order
; *          arg4: AR2 - output sample buffer pointer
; *          arg5: AR3 - delayline buffer pointer
; *          arg6: AR4 - delayline buffer index
; *
; *   Return: T0 = Delayline buffer index
; *
; *  For the book "Real Time Digital Signal Processing:
; *                Fundamentals, Implementation and Application, 3rd Ed"
; *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
; *                Publisher: John Wiley and Sons, Ltd
; */

     .def  _unknowPlant 
     .sect ".text:fir_code"
	
_unknowPlant              
    pshm  ST1_55              ; Save ST1 and ST2
    pshm  ST2_55

    or    #0x340,mmap(ST1_55) ; Set FRCT,SXMD,SATD

    mov   dbl(*AR0(#2)),XAR2  ; AR2 is the filter output pointer     
    mov   dbl(*AR0(#4)),XAR3  ; AR3 is the filter delay line pointer     
    mov   dbl(*AR0(#6)),XAR1  ; AR1 is the filter coefficient pointer     
    mov   *AR0(#8),T0         ; T0 number of samples in input buffer     
    mov   *AR0(#9),T1         ; T1 FIR filter order     
                            
    mov   mmap(AR1),BSA01     ; AR1=base address for coeff 
    mov   mmap(T1),BK03       ; Set coefficient array size 
    mov   mmap(AR3),BSA23     ; AR3=base address for delayline
    or    #0xA,mmap(ST2_55)   ; AR1 & AR3 as circular pointers
    amov  #0,XAR1             ; Start from zero offset
    mov   *AR0(#10),AR3       ; Start with offset=index
    mov   dbl(*AR0),XAR0      ; AR0 is input pointer         
    sub   #1,T0               ; T0=Ns-1
    mov   T0,BRC0             ; Init outer loop for Ns times
    sub   #3,T1,T0            ; T0=N1-3
    mov   T0,CSR              ; Init inner loop N1-2 times
||  rptblocal sample_loop-1   ; Start the outer loop
    mov   *AR0+,*AR3          ; Put the sample to delayline
    mpym  *AR3+,*AR1+,AC0     ; Do the 1st iteration
||  rpt   CSR                 ; Start the inner loop
    macm  *AR3+,*AR1+,AC0
    macmr *AR3,*AR1+,AC0      ; Do the last iteration 	
    mov   hi(AC0),*AR2+       ; Save Q15 filtered value 
sample_loop

    popm  ST2_55              ; Restore ST1 and ST2	
    popm  ST1_55
    mov   AR3,T0              ; Return delayline index
||  ret
    .end

