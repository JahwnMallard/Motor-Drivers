/*
 * Motor_Driver.h
 *
 *  Created on: Nov 20, 2013
 *      Author: C2C John Miller
 */

#ifndef MOTOR_DRIVER_H_
#define MOTOR_DRIVER_H_

//Sets up timer system and pins
void initRobot();

//moves corresponding motors forward at the duty cycle
void leftMotorForward(char dutyCycle);
void rightMotorForward(char dutyCycle);

//stops corresponding motors
void leftMotorStop();
void rightMotorStop();

//Moves robot in corresponding directions based on duty cycle
void moveRobotForward(char dutyCycle);
void moveRobotBackward(char dutyCycle);
void turnRobotLeft(char dutyCycle);
void turnRobotRight(char dutyCycle);

#endif /* MOTOR_DRIVER_H_ */
