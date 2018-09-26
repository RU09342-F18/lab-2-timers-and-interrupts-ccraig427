#include <msp430.h> 

/**Date Created: 9/24/18 
   Date Last Edited: 
   Author: Colin Craig 
   MSP430F5529 Button Interrupt
   */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR = BIT0; //Set P1.0 to output direction
	P4DIR = BIT7; //Set P4.7 to output direction
	P1REN = BIT1; //Enable Pull Up on SW2 (P1.1)
	P1IE = BIT1; //P1.1 interrupt enabled
	__enable_interrupt();
	return 0;
}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
    __delay_cycles(500);
    P1OUT ^= BIT0; //Toggle LED1
    P4OUT ^= BIT7; //Toggle LED2
    P1IFG = ~BIT1; //P1.1 IFG cleared
}
