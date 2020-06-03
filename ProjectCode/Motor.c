/******************************************************************************
 * Name:    		Motor.h
 * Description: Implements the movement logic for the robot car, Consist of:
										Forward, Backward, Turn_Left, Turn_Right, Revearse,
										Stop_Right, Stop_Left, Stop_Both
										
 * Version: 		Version 1.00
 * Authors: 		Gunjeet Dhaliwal | Mckenzie Busenius
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 *
 *----------------------------------------------------------------------------
 * History:
 *          V1.00 Initial Version
 *          
 *****************************************************************************/

#include "stm32f10x.h"
#include "Motor.h"
#include "LCD.h"
#include "PWM.h"

void Forward(void){
		//Left Wheel
		updateLeft();
		GPIOB->ODR |= GPIO_ODR_ODR13;  // 12E
		GPIOC->ODR &= ~GPIO_ODR_ODR10; // 1A
		GPIOA->ODR |= GPIO_ODR_ODR8; //  2A
		
		//Right Wheel
		updateRight();
		GPIOB->ODR |= GPIO_ODR_ODR14; // 34E
		GPIOC->ODR &= ~GPIO_ODR_ODR11; // 4A
		GPIOB->ODR |= GPIO_ODR_ODR8; // 3A
	
}


void Turn_Right(void){
		//Left Wheel On, Right Wheel Stop
		GPIOB->ODR |= GPIO_ODR_ODR13;  // 12E
		GPIOC->ODR &= ~GPIO_ODR_ODR10; // 1A
		GPIOA->ODR |= GPIO_ODR_ODR8; //  2A
						
		Stop_Right();
					
}


void Turn_Left(void){
		//Right Wheel On, Left Wheel Stop
		GPIOB->ODR |= GPIO_ODR_ODR14; // 34E
		GPIOC->ODR &= ~GPIO_ODR_ODR11; // 4A
		GPIOB->ODR |= GPIO_ODR_ODR8; // 3A
						
		Stop_Left();
}


void Reverse(void){
		//Left Wheel On
		GPIOB->ODR |= GPIO_ODR_ODR13;  //  12E
		GPIOC->ODR |= GPIO_ODR_ODR10; //   1A
		GPIOA->ODR &= ~GPIO_ODR_ODR8; //  2A
	
		//Right Wheel On
		GPIOB->ODR |= GPIO_ODR_ODR14; // 34E
		GPIOC->ODR |= GPIO_ODR_ODR11; // 4A
		GPIOB->ODR &= ~GPIO_ODR_ODR8; // 3A
	
}


void Stop_Right(void){
	GPIOB->ODR &= ~GPIO_ODR_ODR14; //34D
}


void Stop_Left(void){
	GPIOB->ODR &= ~GPIO_ODR_ODR13; //12D
}


void Stop_Both(void){
	GPIOB->ODR &= ~GPIO_ODR_ODR13; //12D
	GPIOB->ODR &= ~GPIO_ODR_ODR14; //34D
}



