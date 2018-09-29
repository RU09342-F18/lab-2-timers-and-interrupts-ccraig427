#include <msp430.h>

/**Date Created: 9/24/18
   Date Last Edited: 9/28/18
   Author: Colin Craig
   MSP430G2553 Button-Based Delay
   Credit to Jack Pedicone for Button_Down Interrupt
   */
int main(void)
{
    WDTCTL = WDTPW + WDTHOLD;   //Disables watchdog timer
    P1DIR |= BIT0; //Sets direction of P1.0 as an output
    P1DIR &= ~BIT3; //Sets direction of P1.3 (Button) as an input
    P1DIR |= BIT6; //Sets direction of P1.6 as an output
    P1OUT |= ~BIT0; //Sets initial value of P1.0 to ground
    P1REN |= BIT3; //Adds a pull-up resistor to P1.3
    P1IE |= BIT3; //Enable button as an interrupt
    P1IES |= BIT3; //Falling edge will create an interrupt
    P1IFG &= ~BIT3; //Clears P1.1 Interrupt flags
    BCSCTL3 = LFXT1S_2; //Enables Crystal Timer

    TA0CTL = TASSEL_1 + ID_1 + MC_1; //Selects ACLK, Divides by 8, and in Up Mode
    CCTL0 = CCIE; //Selects Capture and Compare Interrupt Enable request
    CCR0 = 1000; //Capture and Compare Register value
    _BIS_SR(LPM0_bits + GIE); //Enable Global Interrupt
    return 0;
}
//Interrupt for initial LED1 button blink
#pragma vector =TIMER0_A0_VECTOR
__interrupt void TIMER0_A1(void)
{

    P1OUT ^= BIT0; //Toggles LED1

}
//Interrupt for when the button is pressed
#pragma vector =PORT1_VECTOR
__interrupt void Button_press(void)
{
    if (P1IES & BIT3) //If falling edge and button Pressed
    {
        P1IES &=~BIT3; //Rising Edge
        TACTL=TACLR; //Clears timer
        TA0CTL = TASSEL_1 + ID_1 + MC_2; //ACLK, Divides by 3, Continuous Mode
        P1OUT |= BIT6;
    }

    else //When button is let go
    {
        P1OUT &= ~BIT6; //LED2 Turned Off
        TA0CTL = MC_0; //Turns off Timer
        TA0CCR0 = TA0R; //Set Capture and Compare Register to counter value
        TACTL |= TACLR; //Clears timer
        TA0CTL = TASSEL_1 + ID_1 + MC_1; //ACLK, Divides by 3, Up Mode
        P1IES |= BIT3; //Detects Falling Edge
    }

    P1IFG &= ~BIT3; //Clears Interrupt Flag
}
