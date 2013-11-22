#MotorDriver library
##API

C2C John Miller, ECE 382
Motor Drivers for the MSP430, designed for the ECE382 robot. 
Hardware diagram below:

			                _________________
	Left Motor Red input	|P1.2		P2.4|--- Left Motor Black input			
							|				|
							|				|
							|	MSP430		|
							|				|
	Right Motor Red Input	|P2.1		P2.5|--- right Motor Black input
							|_______________|

-void `initRobot()`
	- initializes the pins and timer of the robot. Left motor forward is on P1.2, Right motor forward is on 2.1, Both motors reverse are on 2.4 and 2.5

-void `leftMotorForward(char dutyCycle)`
	- Moves the left motor forward at the dutycycle (TA0CCR1 is set to duty cycle)
	
-void `rightMotorForward(char dutyCycle)`
	- Moves the right motor forward at the dutycycle (TA1CCR1 is set to duty cycle)
	
-void `leftMotorStop()`
	-Stops the left motor (TA1CCR2 and TA0CCR1 set to 0)
	
-void `rightMotorStop()`
	-Stops the right motor (TA1CCR2 and TA1CCR1 set to 0)
	
-void `moveRobotForward(char dutyCycle)`
	-Moves both motors forward (TA1CCR1 and TA0CCR1 set to duty cycle)
	
-void `moveRobotBackward(char dutyCycle)`
	-Moves both motors backward (TA1CCR2 set to duty cycle)
	
-void `turnRobotLeft(char dutyCycle)`
	-Move right motor forward (TA1CCR1 set to duty cycle) and stops the left motor (TA0CCR1 set to 0)
	
-void `turnRobotRight(char dutyCycle)`
	-Moves left motor forward (TA0CCR1 set to duty cycle) and stops the right motor (TA1CCR1 set to 0)
	
##Example Code

- This code will move the robot forward, backward, then do a short turn left, a short turn right, a large turn left, and a large turn right
`  
		initRobot();	
	      moveRobotForward(100);
	        __delay_cycles(700000);
	        moveRobotBackward(100);
	        __delay_cycles(700000);
	        turnRobotLeft(100);
	        __delay_cycles(700000);
	        turnRobotRight(100);
	        __delay_cycles(700000);
	        turnRobotLeft(100);
	        __delay_cycles(1500000);
	        turnRobotRight(100);
	        __delay_cycles(1500000);

	  `

	