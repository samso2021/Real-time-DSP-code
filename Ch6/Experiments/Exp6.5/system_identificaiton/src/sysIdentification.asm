;/*
; * sysIdentification.asm
; *
; *  Created on: June 6, 2012
; *      Author: BLEE
; *
; *  Description: This is the adaptive filter for system identification
; *
; *               The input is a white noise
; *               The adative filter coefficients after converge should match the unknown system
; *
; *
; *  Prototype: unsigned short adaptive(ADAPTSYSID *adaptSys)
; *
; *   Entry: in[] - input signals
; *          d[] - reference signal
; *          x[] - adaptive filter delay-line buffer
; *          w[] - adaptive filter coefficient array
; *          Ns  - number of samples per block
; *          N   - order of the adaptive filter
; *          index - index to x[]
; *
; *  Return: T0 = Adaptive filter delay-line buffer index
; *
; *  For the book "Real Time Digital Signal Processing:
; *                Fundamentals, Implementation and Application, 3rd Ed"
; *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
; *                Publisher: John Wiley and Sons, Ltd
; */


TWOMU .set 0x1800      ; 2*MU

    .def  _sysIdentification
    .sect ".text:lms_code"
	
_sysIdentification:                       
    pshm ST1_55               ; Save ST1, ST2, and ST3
    pshm ST2_55
    pshm ST3_55

    mov   dbl(*AR0(#2)),XAR1  ; AR1 is the desired signal pointer     
    mov   dbl(*AR0(#4)),XAR2  ; AR2 is the adaptive filter delay line pointer     
    mov   dbl(*AR0(#6)),XAR3  ; AR3 is the adaptive filter coefficient pointer     
    mov   *AR0(#8),T0         ; T0 number of samples in input buffer     
    mov   *AR0(#9),T1         ; T1 adaptive filter order     
	
    mov  mmap(AR3),BSA45
    mov  mmap(T1),BK47  
    mov  mmap(AR2),BSA23
    mov  mmap(T1),BK03
    mov  *AR0(#10),AR3        ; AR3 -> x[] as circular buffer
    amov #0,XAR4              ; AR4 -> w[] as circular buffer
    mov  dbl(*AR0),XAR0       ; AR0 is input pointer
    			
    or   #0x340,mmap(ST1_55)  ; Set FRCT,SXMD,SATD
    or   #0x18,mmap(ST2_55)   ; Enable circular addressing mode
    bset SATA                 ; Set SATA

    sub  #1,T0
    mov  mmap(T0),BRC0        ; Set Sample block loop counter  
    sub  #2,T1
    mov  mmap(T1),BRC1        ; Counter for LMS update loop 
    mov  mmap(T1),CSR         ; Counter for FIR filter loop		
    rptblocal loop-1          ; for (n=0; n<Ns; n++)
    mov  *AR0+,*AR3           ; x[n]=in[n]
    mpym *AR3+,*AR4+,AC0      ; temp = w[0]*d[0] 
||  rpt  CSR                  ; for (i=0; i<N-1; i++)
    macm *AR3+,*AR4+,AC0      ;   y += w[i]*x[i]
    sub  *AR1+ <<#16,AC0      ; AC0=-e=y-d[n], AR1 points to d[n]
    mpyk #-TWOMU,AC0
    mov  rnd(hi(AC0)),mmap(T1); T1=2*mu*e[n]
    rptblocal lms_loop-1      ; for(j=0; i<N-2; i++)
    mpym *AR3+,T1,AC0         ;   AC0=2*mu*e*x[i]     
    add  *AR4<<#16,AC0        ;   w[i]+=2*mu*e*x[i]     
    mov  rnd(hi(AC0)),*AR4+
lms_loop 
    mpym *AR3,T1,AC0          ; w[N-1]+=2*mu*e*x[N-1]
    add  *AR4<<#16,AC0    
    mov  rnd(hi(AC0)),*AR4+   ; Store the last w[N-1]  
loop                              

    popm ST3_55               ; Restore ST1, ST2, and ST2
    popm ST2_55
    popm ST1_55	
    mov  AR3,T0               ; Return T0=index
    ret
	
    .end
