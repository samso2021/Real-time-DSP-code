;/*
; * adaptivePredictor.asm
; *
; *  Created on: June 6, 2012
; *      Author: BLEE
; *
; *  Description: This program is Self-tuned Adaptive linear predictor(Leaky LMS)
; *
; *               The input is a sine wave with white noise interference
; *               The adative line predictor will output both s(n) and v(n), sin wave and nosie
; *
; *   Prototype: unsigned short adaptivePredictor(ADAPTLE *ale)
; *
; *   Entry: in[]- input buffer contains wide & narrow band signals
; *          y[] - output of the filter narrow band signal
; *          e[] - output of the filter wide band signal
; *          x[] - adaptive filter delay-line buffer
; *          w[] - adaptive filter coefficient buffer
; *          Ns  - number of samples per block
; *          N   - order of the adaptive filter
; *          index - index to x[]
; *
; *   Return: T0 = Adaptive filter delay-line buffer index
; *   For the book "Real Time Digital Signal Processing:
; *                Fundamentals, Implementation and Application, 3rd Ed"
; *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
; *                Publisher: John Wiley and Sons, Ltd
; */


TWOMU    .set 0x80    ; 2*MU
ALPHA    .set 0x7ffe  ; Leaky factor

;
;    Declare local variables in SP address mode for C-callable
;
ARGS  .set  0                  ; Number of variables passed via stack

ALE_var     .struct            ; Define local variable structure  
d_ST1       .word              ; Used to save content of ST1
d_ST2       .word              ; Used to save content of ST2
d_ST3       .word              ; Used to save content of ST3 
return_addr .word              ; Return address
Size        .endstruct
ale         .set 0
ale         .tag ALE_var  

    .def    _adaptivePredictor
	
    .sect ".text:lms_code"  
	
_adaptivePredictor                       
    aadd #(ARGS-Size+1),SP          ; Adjust SP for local vars  

    mov  dbl(*AR0(#2)),XAR1         ; AR1 pointer to y[]
    mov  dbl(*AR0(#4)),XAR2         ; AR2 pointer to e[]
    mov  dbl(*AR0(#6)),XAR3         ; AR3 pointer to x[]
    mov  dbl(*AR0(#8)),XAR4         ; AR4 pointer to w[]        
    mov  *AR0(#10),T0               ; T0 = size of data block
    mov  *AR0(#11),T1               ; T1 = order

    mov  mmap(AR4),BSA45            ; Configure for circular buffers
    mov  mmap(T1),BK47   
    mov  mmap(AR3),BSA23
    mov  mmap(T1),BK03
    mov  *AR0(#12),AR3              ; AR3 -> x[] as circular buffer
    amov #0,XAR4			        ; AR4 -> w[] as circular buffer
	mov  dbl(*AR0),XAR0             ; AR0 point to in[]
				
    mov  mmap(ST1_55),AC0           ; Save ST1, ST2, and ST3
    mov  AC0,ale.d_ST1
    mov  mmap(ST2_55),AC0
    mov  AC0,ale.d_ST2
    mov  mmap(ST3_55),AC0
    mov  AC0,ale.d_ST3

    or   #0x340,mmap(ST1_55)        ; Set FRCT,SXMD,SATD
    or   #0x18,mmap(ST2_55)         ; Enable circular addressing mode
    bset SATA			            ; Set SATA
 	
    sub	 #1,T0
    mov  mmap(T0),BRC0              ; Set Sample block loop counter  
    sub  #2,T1
    mov  mmap(T1),BRC1              ; Counter for LMS update loop 
    mov  mmap(T1),CSR               ; Counter for FIR filter loop		

    mov  #ALPHA,T0                  ; T0=leaky alpha
||  rptblocal loop-1                ; for (n=0; n<Ns; n++)
    mpym *AR3+,*AR4+,AC0            ; temp = w[0]*x[0] 
||  rpt  CSR                        ; for (i=1; i<N; i++)
    macm *AR3+,*AR4+,AC0            ;   temp += w[i]*x[i]
    mov  rnd(hi(AC0)),*AR1          ; y[n] = temp;
    sub  *AR0,*AR1+,AC0             ; e[n]=in[n]-y[n]
    mov  rnd(hi(AC0)),*AR2+
    mpyk #TWOMU,AC0                 
    mov  rnd(hi(AC0)),mmap(T1)      ; T1=2*mu*e[n]
    mpym *AR4,T0,AC0
||  rptblocal lms_loop-1            ; for(j=0; i<N-2; i++)
    macm *AR3+,T1,AC0               ;   w[i]=alpha*w[i]+2*mu*e*x[i]     
    mov  rnd(hi(AC0)),*AR4+
    mpym *AR4,T0,AC0    
lms_loop 
    macm *AR3,T1,AC0                ; w[N-1]=alpha*w[N-1]+2*mu*e[n]*x[N-1]
    mov  rnd(hi(AC0)),*AR4+         ; Store the last w[i]
    mov  *AR0+,*AR3                 ; x[n]=in[n]
loop                              

    mov  ale.d_ST1,AR4              ; Restore ST1, ST2, and ST3
    mov  ar4,mmap(ST1_55)  
    mov  ale.d_ST2,AR4
    mov  ar4,mmap(ST2_55)
    mov  ale.d_ST3,AR4
    mov  AR4,mmap(ST3_55)
    aadd #(Size-ARGS-1),SP          ; Reset SP
    mov  AR3,T0                     ; Retrun T0=index
    ret
	
   .end
