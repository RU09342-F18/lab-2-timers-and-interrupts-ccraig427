#include <msp430.h>

/**Date Created: 9/24/18
   Date Last Edited: 9/28/18
   Author: Colin Craig
   MSP430F5529 Button-Based Delay
   */

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;   //Disables watchdog timer
    P1DIR |= BIT0; //Sets direction of P1.0 as an output
    P1DIR &= ~BIT1; //Sets direction of P1.1 (Button) as an input
    P4DIR |= BIT7; //Sets direction of P4.7 as an output
    P1OUT |= ~BIT0; //Sets initial value of P1.0 to ground
    P1REN |= BIT3; //Adds a pull-up resistor to P1.3
    P1IE |= BIT3; //Enable button as an interrupt
    P1IES |= BIT1; //Falling edge will create an interrupt
    P1IFG &= ~BIT3; //Clears P1.3 Interrupt flags

    TB0CTL = TASSEL_1 + ID_3 + MC_1; //Selects ACLK, Divides by 8, and in Up Mode
    TB0CCR0 = 500; //Capture and Compare Register value
    TB0CCTL0 = CCIE; //Selects Capture and Compare Interrupt Enable request
    __BIS_SR(LPM0_bits + GIE); //Enables Global Interrupt

    return 0;
}

#pragma vector =TIMER0_B0_VECTOR //Interrupt enabled from TimerB
__interrupt void TIMER0_A1(void)
{

    P1OUT ^= BIT0; //toggle P1.0 LED

}

#pragma vector =PORT1_VECTOR
__interrupt void Button_down(void)
{
    if (P1IES & BIT1) //if falling edge
    {
        P1IES &=~BIT1; //change to rising edge
        TBCTL=TBCLR; //clear timer
        TB0CTL = TASSEL_1 + ID_3 + MC_2; //change to continuous
        P4OUT |= BIT7; //checks to see if we're in the if statement
    }

    else
    {
        P4OUT &= ~BIT7; // turn off LED on P4.7
        TB0CTL = MC_0; //turn off timer
        TB0CCR0 = TB0R; //set CCR to current timer value
        TBCTL |= TBCLR; //clear timer
        TB0CTL = TASSEL_1 + ID_3 + MC_1; //change to up mode
        P1IES |= BIT1; //change to detect falling edge
    }

    P1IFG &= ~BIT1; //clear flag
}
