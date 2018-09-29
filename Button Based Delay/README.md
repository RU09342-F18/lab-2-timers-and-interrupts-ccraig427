# Button Based Delay
## Colin Craig 
### Embedded Systems: Section 1 
In this part of the lab, we were tasked with using a button to change the frequency of the LED. In other words, however long we hold the button in would be the new period for the flashing LED. To do this, two timers, global interrupt, if statement, and a capture and control register is needed. This works by pressing the button down for however long you want. Once it is released, LED1 will start toggling at the time the button was pressed down for. This works by the capture and control register value incrementing for however long it is held down. Once it is let go, the LED starts to toggle using a timer in Up mode up to that value. By pressing the button again, the process is repeated. 
### F5529 
The MSP430F5529 used TimerB to send the interrupts to the designated ports. For the LEDs, P1.0 was the initial toggling LED while P4.7 was the one that toggled on when the button was pressed. 
### G2553 
The MSP430G2553 used TimerA to send the interrupts to the designated ports. For the LEDS, P1.0 was the initial toggling LED while P1.6 was the one that toggled on when the button was pressed. Other than those difference, the code for both the G2553 and F5529 were very similiar. 
