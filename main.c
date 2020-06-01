/******************************************************************************
 * Name:    		Main.c
 * Description: The main program file
 * Version: 		Version 1.00
 * Authors: 		Gunjeet Dhaliwal | Mckenzie Busenius
 *
 * This software is supplied "AS IS" without warranties of any kind
 *
 *----------------------------------------------------------------------------
 * History:
 *          V1.00 Initial Version
 *
 *****************************************************************************/

#include "stm32f10x.h"
#include "clocks.h"
#include "ultrasonic.h"
#include "IR.h"
#include "LCD.h"
#include "Motor.h"
#include "TempSensor.h"
#include "PWM.h"
#include "Display_LCD.h"
#include "Display_LEDs.h"

int main(void){
			
		// Clock and sub clock initilization
		clockInit();
		subclocks();
		LCD_IO_INIT();
	
		
		//PWM Function call, Reduces the duty cycle by 50%
		PWM_Left();
		PWM_Right();
		
		//Variable for Ultrasonic
		uint32_t UltraSensor, distance = 3;
		
		//Infinate Loop, to provide a go signal, Car wont move untill reset button is pressed
		while((GPIOA->IDR & GPIO_IDR_IDR0) == 0){}
		
		while(1){	
			/*
			Purpose: Go right, Send to display
			*/
			commandToLCD(LCD_CLR);
			while(IR_Detect_Front() == 1){
				GPIOA->ODR = 0x1E00;
				Forward();
				Display_Forward();
				Forward_LED_Pattern();
			}
			
			/*
			Purpose: Go right, Send to display
			*/
			commandToLCD(LCD_CLR);
			while((IR_Detect_Front() == 0) && (IR_Detect_Left() == 0) && (IR_Detect_Right() == 1)){
				Display_Right();
				Right_LED_Pattern();
				Turn_Right();
			}
			
		
			/*
			Purpose: Go Left both left and right are not Low(Active Low)
			*/
			commandToLCD(LCD_CLR);
			while((IR_Detect_Front() == 0) && (IR_Detect_Right() == 1) && (IR_Detect_Left() == 1)){
				Display_Left();
				Left_LED_Pattern();
				Turn_Left();
			}
			
			
			/*
			Purpose: Go Left, Send left to display
			*/
			commandToLCD(LCD_CLR);
			while((IR_Detect_Front() == 0) && (IR_Detect_Right() == 0) && (IR_Detect_Left() == 1)){
				Display_Left();
				Left_LED_Pattern();
				Turn_Left();
			}		
			
			
			/*
			Purpose: Backup, for a specific time, Follow with a left turn, send to display
			*/
			commandToLCD(LCD_CLR);
			while(distance > 2){
				UltraSensor =start_ultra();
				distance = (UltraSensor/58);
				dataToLCD(distance);
				while((IR_Detect_Front() == 0) && (IR_Detect_Right() == 0) && (IR_Detect_Left() == 0)){
					Display_Backward();
					Backward_LED_Pattern();
					Reverse();
					Turn_Left();
				}
			}	
		}//End While
}//End Main
 
