/*
 * Motor_Driver.c
 *
 *  Created on: Nov 20, 2013
 *      Author: Administrator
 */

#include <msp430.h>
#include "Motor_Driver.h"
void initRobot() {

	P1DIR |= BIT2;                // TA0CCR1 on P1.2
	P1SEL |= BIT2;                // TA0CCR1 on P1.2

	P2DIR |= BIT1;                // TA1CCR1 on P2.1
	P2SEL |= BIT1;                // TA1CCR1 on P2.1

	P2DIR |= BIT5;                // TA2CCR1 on P2.5
	P2SEL |= BIT5;               // TA2CCR1 on P2.5

	P2DIR |= BIT4;                // TA2CCR1 on P2.4
	P2SEL |= BIT4;                // TA2CCR1 on P2.4

	WDTCTL = WDTPW | WDTHOLD;          // stop the watchdog timer

	TA0CTL &= ~MC1 | MC0;
	TA1CTL &= ~MC1 | MC0;

	TA0CTL |= TACLR;                // clear timer A0
	TA1CTL |= TACLR;                // clear timer A0

	TA0CTL |= TASSEL1;           // configure for SMCLK
	TA1CTL |= TASSEL1;           // configure for SMCLK

	TA0CCR0 = 100;  // set signal period to 100 clock cycles (~100 microseconds)
	TA1CCR0 = 100;
	TA0CCR1 = 0;   //Left wheel duty cycle
	TA1CCR1 = 0;   //Right wheel duty cycle
	TA1CCR2 = 0;  //Reverse duty cycle

	TA0CCTL1 |= OUTMOD_7;
	TA1CCTL1 |= OUTMOD_7;        // set TA0CCTL1, TA1CCTL1, TA1CCTL2 to Reset / Set mode
	TA1CCTL2 |= OUTMOD_7;

	TA0CTL |= MC0;
	TA1CTL |= MC0;               // count up

}


void leftMotorForward(dutyCycle) {
	TA0CCR1 = dutyCycle;
	TA1CCR2 = 0;
}

void leftMotorStop() {
	TA0CCR1 = 0;
	TA1CCR2 = 0;
}

void rightMotorStop() {
	TA1CCR1 = 0;
	TA1CCR2 = 0;
}

void rightMotorForward(char dutyCycle) {
	TA1CCR2 = 0;
	TA1CCR1 = dutyCycle;

}

void moveRobotBackward(char dutyCycle) {
	rightMotorStop();
	leftMotorStop();
	_delay_cycles(100000);  //short pause so that the motors are smoother
	TA1CCR2 = dutyCycle;
}

void moveRobotForward(char dutyCycle) {

	rightMotorForward(dutyCycle);
	leftMotorForward(dutyCycle);

}

void turnRobotLeft(char dutyCycle) {
	leftMotorStop();
	rightMotorForward(dutyCycle);

}
void turnRobotRight(char dutyCycle) {

	rightMotorStop();
	leftMotorForward(dutyCycle);

}

