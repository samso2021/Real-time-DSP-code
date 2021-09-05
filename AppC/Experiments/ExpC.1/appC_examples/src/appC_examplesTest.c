/*
 * appC_examplesTest.c
 *
 *  Created on: Sep 7, 2012
 *      Author: BLEE
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */
#include <stdio.h>

extern void Example_C1();		// Appendix C example C.1
extern void Example_C2();		// Appendix C example C.2
extern void Example_C3();		// Appendix C example C.3
extern void Example_C4();		// Appendix C example C.4
extern void Example_C5();		// Appendix C example C.5
extern void Example_C6();		// Appendix C example C.6
extern void Example_C7();		// Appendix C example C.7
extern void Example_C8();		// Appendix C example C.8
extern void Example_C9();		// Appendix C example C.9
extern void Example_C10();		// Appendix C example C.10
extern void Example_C11();		// Appendix C example C.11
extern void Example_C12();		// Appendix C example C.12
extern void Example_C13();		// Appendix C example C.13
extern void Example_C14();		// Appendix C example C.14
extern void Example_C15();		// Appendix C example C.15
extern void Example_C16();		// Appendix C example C.16


extern	void Example_init();	// Initialize the system for examples

void main(void)
{
	printf("Exp C.1 --- Examples in Appendix C\n");
	Example_init();	// Initialize for the examples

	Example_C1();	// Show example C.1
	Example_C2();	// Show example C.2
	Example_C3();	// Show example C.3
	Example_C4();	// Show example C.4
	Example_C5();	// Show example C.5
	Example_C6();	// Show example C.6
	Example_C7();	// Show example C.7
	Example_C8();	// Show example C.8
	Example_C9();	// Show example C.9
	Example_C10();	// Show example C.10
	Example_C11();	// Show example C.11
	Example_C12();	// Show example C.12

	printf("\nExp --- completed\n");
}

