#include <msp430.h> 

/**Date Created: 9/24/18
   Date Last Edited:
   Author: Colin Craig
   MSP430F5529 Button Interrupt
   */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR = BIT0; //Sets the direction of P1.0 to output
	P4DIR = BIT7; //Sets the direction of P4.7 to output
	P1REN = BIT1; //Adds a pull-up resistor to P1.1
	P1IE = BIT1; //Enables interrupts to P1.1
	__enable_interrupt();
	return 0;
}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
    __delay_cycles(500); //Delays 500 cycles to help with debouncing
    P1OUT ^= BIT0; //Toggles LED1
    P4OUT ^= BIT7; //Toggles LED2
    P1IFG = ~BIT1; //Clears P1.1 interrupt flag
}
