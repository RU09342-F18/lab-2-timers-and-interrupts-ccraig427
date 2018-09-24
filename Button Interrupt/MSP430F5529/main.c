#include <msp430.h> 

/**Date Created: 9/24/18 
   Date Last Edited: 
   Author: Colin Craig 
   MSP430F5529 Button Interrupt
   */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR = BIT0;
	P4DIR = BIT7;
	P1REN = BIT1;
	P4REN = ~BIT1;
	P1OUT = BIT1;
	P4OUT = ~BIT1;
	P1IE = BIT1;
	__enable_interrupt();
	return 0;
}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
    __delay_cycles(500);
    P1OUT ^= BIT0;
    P4OUT ^= BIT7;
    P1IFG = ~BIT1;
}
