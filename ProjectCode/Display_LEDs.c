/******************************************************************************
 * Name:    		Display_LEDs.c
 * Description: To display actions to the LEDs in our custom format.
 * Version: 		Version 1.00
 * Authors: 		Gunjeet Dhaliwal | Mckenzie Busenius
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 *----------------------------------------------------------------------------
 * History:
 *          V1.00 Initial Version
 *
 *****************************************************************************/

#include "stm32f10x.h"
#include "clocks.h"
#include "Display_LEDs.h"
#include "LCD.h"

/*
Output Pattern: The LEDs light up in a left to right pattern
*/
void Forward_LED_Pattern(){
		GPIOA->ODR &= ~GPIO_ODR_ODR9;
		delay(900000);
		GPIOA->ODR = 0x1E00;
		GPIOA->ODR &= ~GPIO_ODR_ODR10;
		delay(100000);
		GPIOA->ODR = 0x1E00;
		GPIOA->ODR &= ~GPIO_ODR_ODR11;
		delay(100000);
		GPIOA->ODR = 0x1E00;
		GPIOA->ODR &= ~GPIO_ODR_ODR12;
		delay(900000);
		GPIOA->ODR = 0x1E00;
}


/*
Output Pattern: The LEDs on the left go High and they go Low
*/
void Left_LED_Pattern(){
		GPIOA->ODR = 0x1E00;
		GPIOA->ODR &= ~GPIO_ODR_ODR9 & ~GPIO_ODR_ODR10;
		delay(900000);
		GPIOA->ODR = 0x1E00;
}


/*
Output Pattern: The LEDs on the right go High and they go Low
*/
void Right_LED_Pattern(){
		GPIOA->ODR = 0x1E00;
		GPIOA->ODR &= ~GPIO_ODR_ODR11 & ~GPIO_ODR_ODR12;
		delay(900000);
		GPIOA->ODR = 0x1E00;		
}


/*
Output Pattern: The LEDs go High and they go Low
*/
void Backward_LED_Pattern(){
		GPIOA->ODR = 0x1E00;
		GPIOA->ODR &= 0x00;
		delay(900000);
		GPIOA->ODR = 0x1E00;
}
