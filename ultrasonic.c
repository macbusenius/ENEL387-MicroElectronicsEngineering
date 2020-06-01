/******************************************************************************
 * Name:    		Unltrasonic.c
 * Description: Implementatin of the ultrasonic sensor, Checking the distance
 *							and keeping it away from the wall while running the backup function.
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
#include "ultrasonic.h"
#include "LCD.h"

uint32_t start_ultra(void){
		uint32_t counter =0;
		low();
		delay1(30);		
		high();
		delay1(60); //10 us
		low();
		while((GPIOB->IDR & GPIO_IDR_IDR11)==0) {}
		
		while((GPIOB->IDR & GPIO_IDR_IDR11)!=0) {
			delay1(600);
			counter++;
		}
		return counter;		
}


void high(void){
		GPIOB->ODR |= GPIO_ODR_ODR12;
}


void low(void){
		GPIOB->ODR &= ~GPIO_ODR_ODR12;
}


int delay1(int time){
		for(int i=0; i<=time; i++){
			if(i == time)
				return 0;
		}
		return 0;
}
