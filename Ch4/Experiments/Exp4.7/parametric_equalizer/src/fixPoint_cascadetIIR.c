/*
 
//  Project: Experiment: implementation of fixed-point IIR filter in direct form II 
//  File name: fixPoint_cascadeIIR.c   
//
//  Description: This is the header file for the fixed-point IIR filter in direct form II
//
//  For the book "Real Time Digital Signal Processing: 
//                Fundamentals, Implementation and Application, 2nd Ed"
//                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
//                Publisher: John Wiley and Sons, Ltd

    fixPoint_cascadeIIR.c - IIR direct form II biquads implementation
    prototype: void cascadeIIR(short *, short, short *, float *, short, float *);

    Entry: arg0: pointer to the input sample buffer
           arg1: size of the input sample buffer
           arg2: pointer to the output sample buffer
           arg3: pointer to the coefficients array
           arg4: number of second-order IIR sections
           arg5: pointer to the filter delay-line buffer

    Return: None
*/

void cascadeIIR(short *x, short Nx, short *y, short *coef, short Ns, short *w)
{      
    short i,j,n,m,k,l;
    short temp16;
	long  w_0, temp32;
        
    m=Ns*5;                            // Setup for circular buffer coef[]  
    k=Ns*2;                            // Setup for circular buffer w[]  

    for (j=0,l=0,n=0; n<Nx; n++)       // IIR filter begin 
    {
        w_0 = (long)x[n]<<12;          // Scale input to prevent overflow  
        for (i=0; i<Ns; i++)
        {
            temp32 = (long)(*(w+l)) * *(coef+j); j++; l=(l+Ns)%k;
			w_0   -= temp32<<1;
            temp32 = (long)(*(w+l)) * *(coef+j); j++; 
            w_0   -= temp32<<1;

			temp16 = *(w+l);
			*(w+l) = (short)(w_0>>15); // Save in Q15  
 
			w_0    = (long)temp16 * *(coef+j); j++;
			w_0  <<= 1;
            temp32 = (long)*(w+l) * *(coef+j); j++; l=(l+Ns)%k;
			w_0   += temp32<<1;
            temp32 = (long)*(w+l) * *(coef+j); j=(j+1)%m; l=(l+1)%k; 
			w_0   += temp32<<1;
		}
        y[n] = (short)(w_0>>12);       // Q15 format output 
    }
}
