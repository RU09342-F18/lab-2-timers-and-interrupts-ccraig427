# Button Interrupt
## Colin Craig 
### Embedded Systems: Section 1
In this part of the lab, we were introduced to interrupts involving a simple task. The task was the same as last week's lab which is to toggle an LED based on  the press of a button. The only difference is that we are using interrupts to toggle the LED rather than polling. 
### F5529 
For this microcontroller, the button toggles flip flops between LED1 and LED2. It uses an interrupt to toggle the values of the LEDs. To do this, I changed the initial value of LED2 to be the opposite of LED1. In order to do this, a pull-up resistor must be enabled on the button which is P2.1. Also, the register IE (Interrupt Enabled) must be enabled by setting it equal to BIT1. I was able to get away with setting these register equal to certain bits because the rest of the bits in the register aren't being used for anything else. For the interrupt function, the reason I still put a delay was to account for debouncing of the button. This way, it would give the button plenty of time to reset to it's initial position without toggling the LEDs mistakenly. Once it toggles, the interrupt flag must be reset in order to to send out another interrupt to toggle again. 
### G2553
For this microcontroller, the button toggles just one LED using an interrupt. It works the same way as the F5529 except that the button is now P1.3. 
