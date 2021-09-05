/*
 * system_identificaitonTest.c
 *
 *  Created on: Oct 20, 2012
 *      Author: BLEE
 *
 *  Description: This is the test program for system identification experiment
 *
 *               The input is a 1kHz sine wave sampling rate 8kHz with noise
 *               The output is the sine wave
 *               The error is the noise
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#include <stdio.h>
#include <stdlib.h>
#include "tistdtypes.h"
#include "system_identify.h"


// Unknown system (filter coefficients)
#include "unknow_plant.dat"


UNKNOWNSYS unknownSys;    // Unknown system object
UNKNOWNSYS *unknown = &unknownSys;

ADAPTSYSID adaptSysId;    // Adaptive system identification object
ADAPTSYSID *adaptSys = &adaptSysId;

#pragma DATA_ALIGN(w,2);	
#pragma DATA_ALIGN(d_sys,2);
#pragma DATA_ALIGN(d_fir,2);
#pragma DATA_ALIGN(in,2);
#pragma DATA_ALIGN(d,2);

Int16 w[N0],              // Adaptive filter coefficients
      d_sys[N0],          // Adaptive filter delayed sample buffer 
      d_fir[N1],          // Unknown system delayed sample buffer 
      in[Ns],             // Input sample buffer 
      d[Ns];              // Unknown system output buffer 
    
Int8 temp[2*Ns];          // Temp array for reading data from a file

void main()
{
    FILE   *fp;
	Int16  i,j;
    Uint32 cnt;

    // Open input file for read input data
    if ((fp = fopen("..\\data\\x.pcm", "rb"))== NULL)
	{
        printf("Can't open input data file\n");
		exit(0);
	}

    for (i=0; i<N0; i++)
    {
        w[i] = 0;          // Initialize adaptive filter coefficients  
        d_sys[i] = 0;      // Initialize adaptive filter delay-line  
    }
    
    for (i=0; i<N1; i++)
    {
        d_fir[i] = 0;      // Initialize unknown filter delay-line  
    }
    
    // Initialize unknown system object
    unknown->in = in;
    unknown->out = d;
    unknown->x = d_fir;
    unknown->w = plant;
    unknown->size = Ns;
    unknown->order = N1;
    unknown->index = 0;                        

    // Initialize adaptive system identification object
    adaptSys->in = in;
    adaptSys->des = d;
    adaptSys->x = d_sys;
    adaptSys->w = w;
    adaptSys->size = Ns;
    adaptSys->order = N0;
    adaptSys->index = 0;     
        
    printf("Exp --- started\n");
    cnt = 0;
    while (fread(temp, sizeof(Int8), (2*Ns), fp)  == (2*Ns))
    {                                                             
        for (j=0, i=0; i<Ns; i++) // Get input data
        {
            in[i]   = (temp[j]&0xFF)|(temp[j+1]<<8);   
            j += 2;            
        }
        
        // Run unknown system
        unknown->index = unknowPlant(unknown);   
        
        // Run adaptive system identification
        adaptSys->index = sysIdentification(adaptSys);
        printf("%ld data samples are processed\n", cnt+= Ns*2);
    }
    
    // Close input file and open new file for writing result out
	fclose(fp);
	fp = fopen("..\\data\\result.txt", "wt");
	
	// Display the system identification result
	fprintf(fp, "Unknown plant\t\t System identification\t\t Differences\n");
	printf("\n\n Unknown plant\t\t System identification\t\t Differences\n");
	for (i=0; i<N0; i++)
	{      
        fprintf(fp, "unknown[%i]=%8d\t sysid[%i]=%8d\t error[%i]=%4d\n",
                i, plant[i], i, w[i], i, plant[i]-w[i]);        		
        printf("unknown[%i]=%8d\t sysid[%i]=%8d\t error[%i]=%4d\n",
                i, plant[i], i, w[i], i, plant[i]-w[i]);
	}
	fclose(fp);
    printf("Exp --- completed\n");
}
