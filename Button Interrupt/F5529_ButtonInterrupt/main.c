/**Date Created: 9/24/18
   Date Last Edited: 9/28/18
   Author: Colin Craig
   MSP430F5529 Button Interrupt
   */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    P1DIR = BIT0; //Sets the direction of P1.0 to output
    P4DIR = BIT7; //Sets the direction of P4.7 to output
    P1OUT = BIT0; //Sets the initial value of P1.0 On
    P4OUT = ~BIT7; //Sets the initial value of P4.7 Off
    P2REN = BIT1; //Adds a pull-up resistor to P2.1
    P2IE = BIT1; //Enables interrupts to P2.1
    __enable_interrupt();
    return 0;
}

#pragma vector=PORT2_VECTOR
__interrupt void Port_2(void)
{
    __delay_cycles(500); //Delays 500 cycles to help with debouncing
    P1OUT ^= BIT0; //Toggles LED1
    P4OUT ^= BIT7; //Toggles LED2
    P2IFG &= ~BIT1; //Clears P2.1 interrupt flag
}
