#include <msp430.h> 

/**Date Created: 9/26/18
   Date Last Edited:
   Author: Colin Craig
   MSP430F5529 Timer A Blink
   */

#include <msp430.h>
#define LED1 BIT0;
#define LED2 BIT7; 

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;        //stop watchdog timer
//Configures LEDs
    P1DIR |= LED1;                   //sets P1.0 as an output
    P1OUT &= ~LED1;                  //sets initial value of LED off
    P4DIR |= LED2;                   //sets P1.6 as an output
    P4OUT &= ~LED2;                  //sets initial value of LED off
//Set up Timer1_A0 CCSFR and interrupts
    TA0CCR0 = 10000;                 //Capture and Compare register counter value
    TA0CCTL0 = 0x10;                 //Enables Timer A0 interrupts
    TA0CTL = TASSEL_1 + MC_1;        //TASSEL == 1 selects ACLK | MC_1 selects Up Mode
//Set up Timer0_A0 CCSFR and interrupts for LED1
    TA1CCR0 = 20000;                 //Capture and Compare register counter value
    TA1CCTL0 = 0x10;                 //Enables Timer A1 interrupts
    TA1CTL = TASSEL_1 + MC_1;        //TASSEL == 1 selects ACLK | MC_1 selects Up Mode

    _BIS_SR(LPM0_bits + GIE);        //Enables Low Power interrupts
}

#pragma vector=TIMER1_A0_VECTOR    //Timer1 A0 interrupt
__interrupt void Timer1_A0 (void)
{
    P1OUT ^= LED1;               //Toggles LED1
}
#pragma vector=TIMER0_A0_VECTOR    //Timer0 A0 interrupt
__interrupt void Timer0_A0 (void)
{
    P4OUT ^= LED2;                  //Toggles LED2
}
