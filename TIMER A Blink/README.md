# TIMER A Blink
## Colin Craig 
### Embedded Systems: Section 1
This part of the lab uses timers to send interrupts. In this case, two timers were used to blink an LED at two different speeds. Timer A was used in both instances in this lab and used Up mode. This is done by setting a capture and control register value for the timer to increment every clock cycle. Once it hits that value, the timer sends an interrupt based on the falling edge to the pin that controls the LED. Once it does that, the interrupt flag is cleared and resets the capture and control register back to zero for the timer to increment once again. Doing this over and over again allows the timer to toggle the LED off and on. By setting the value of the two capture and control registers to different values, we can control the speeds of two different LEDS. 
### F5529
For the F5529, LED1 was controlled by P1.0 and LED2 was controlled by P4.7. Timer1 sent interrupts to P1.0 while Timer0 sent interrupts to P4.7. The ACLK instantiated with the following code: TA0CTL = TASSEL_1 + MC_1 + ID_3. This line of code also selected Up mode for the timer and set an divider value of 8. 
### G2553 
For the G2553, LED1 was controlled by P1.0 once again and LED2 was controlled by P1.6. The implementation of the task was very similiar. The only difference was the pin setup. 
