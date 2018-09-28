#include <msp430.h>

/**Date Created: 9/24/18
   Date Last Edited: 9/28/18
   Author: Colin Craig
   MSP430G2553 Button Interrupt
   */

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;   //Disables watchdog timer
    P1DIR = BIT0; //Sets direction of P1.0 as an output
    P1OUT = ~BIT0; //Sets initial value of P1.0 to ground
    P1REN = BIT3; //Adds a pull-up resistor to P1.3
    P1IE = BIT3; //Enable button as an interrupt
    P1IFG &= ~BIT3; //Clears P1.3 Interrupt flags
    __enable_interrupt(); //Enables interrupt

}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)   //Interrupt function
{
    __delay_cycles(500);
    P1OUT ^= BIT0; //Toggles LED
    P1IFG &= ~BIT3; //Clears P1.3 Interrupt Flags
}
