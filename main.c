//Question 1
/*
#include <msp430.h> 

#define RedLED BIT0
#define GreenLED BIT6
#define ToggleLeds (P1OUT ^= RedLED|GreenLED)

int main(void)
{
	BCSCTL2 |= DIVS_3;
	WDTCTL = WDT_MDLY_32;
	IE1 |= WDTIE;

	P1DIR = RedLED|GreenLED;
	P1OUT = RedLED;

	_enable_interrupts();

	LPM1;
	
}

#pragma vector = WDT_VECTOR
__interrupt void WDT(void){
    ToggleLeds;
}
*/

//Question 2
/*
#include "msp430G2553.h" // 5.2

void main(void)
{
 WDTCTL = WDTPW + WDTHOLD;  // Stop WDT
 P1DIR |= BIT6;             // P1.6 to output
TA0CTL = TASSEL_2 + MC_1+ID_3;//+TACLR;
 TA0CCR0 = 62499; // Set maximum count value (PWM Period
 TA0CCR1 = 6249; // initialize counter compare value
 TA0CCTL0 |= CCIE;
 TA0CCTL1 |= CCIE;
 TA0CCTL0 &=~CCIFG;
 TA0CCTL1 &=~CCIFG;
 _enable_interrupts(); // Enter LPM0
}
#pragma vector = TIMER0_A0_VECTOR       //define the interrupt service vector
__interrupt void TA0_ISR (void)    // interrupt service routine
    {
    P1OUT |=BIT6;
    TA0CCTL0 &=~CCIFG;
    }
#pragma vector = TIMER0_A1_VECTOR
__interrupt void TA1_ISR (void) {
    P1OUT &=~BIT6;
    TA0CCTL1 &=~CCIFG;
    }
*/
//Question 3
/*
#include <msp430.h>

void main(void)
{
    WDTCTL = WDTPW|WDTHOLD;

    P1DIR |= BIT6;      //Setting up LED pins
    P1SEL |= BIT6;

    TACCR0 = 31249;     //Setting period based on total cycles
    TACCR1 = 6249;      //Setting duty cycle
    TACCTL1 = OUTMOD_7;             //PWM set to Reset/Set
    TACTL = TASSEL_2|ID_3|MC_1;     //setting up clock

    LPM1;
}
*/
