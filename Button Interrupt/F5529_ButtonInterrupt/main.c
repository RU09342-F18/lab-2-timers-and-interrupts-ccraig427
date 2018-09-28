#include <msp430.h> 

/**Date Created: 9/24/18
   Date Last Edited: 9/28/18
   Author: Colin Craig
   MSP430F5529 Button Interrupt
   */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer
	P1DIR = BIT0; //Sets the direction of P1.0 to output
	P4DIR = BIT7; //Sets the direction of P4.7 to output
	P1REN = BIT1; //Adds a pull-up resistor to P1.1
	P4REN = ~BIT1; //Adds a pull-down resistor to P4.1
	P1IE = BIT1; //Enables interrupts for 
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
