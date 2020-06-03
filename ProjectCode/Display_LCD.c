/******************************************************************************
 * Name:    		Display_LCD.c
 * Description: To display actions to the LCD screen in our custom format.
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
#include "LCD.h"
#include "TempSensor.h"
#include "Display_LCD.h"

void Display_Forward(void){
		uint32_t TempSensor;
		dataToLCD('T');
		dataToLCD('E');
		dataToLCD('M');
		dataToLCD('P');
		dataToLCD(':');
		TempSensor = ADCreadT();
		reg_out(TempSensor);
		delay(10000);
		commandToLCD(LCD_LN2);	
		dataToLCD('G');
		dataToLCD('O');
		dataToLCD('I');
		dataToLCD('N');
		dataToLCD('G');
		dataToLCD(' ');
		dataToLCD('F');
		dataToLCD('O');
		dataToLCD('R');
		dataToLCD('W');
		dataToLCD('A');
		dataToLCD('R');
		dataToLCD('D');
		commandToLCD(LCD_LN1);
}


void Display_Right(void){
		uint32_t TempSensor;
		dataToLCD('T');
		dataToLCD('E');
		dataToLCD('M');
		dataToLCD('P');
		dataToLCD(':');
		TempSensor = ADCreadT();
		reg_out(TempSensor);
		delay(10000);
		commandToLCD(LCD_LN2);	
		dataToLCD('T');
		dataToLCD('U');
		dataToLCD('R');
		dataToLCD('N');
		dataToLCD('I');
		dataToLCD('N');
		dataToLCD('G');
		dataToLCD(' ');
		dataToLCD('R');
		dataToLCD('I');
		dataToLCD('G');
		dataToLCD('H');
		dataToLCD('T');
	
}


void Display_Left(void){
		uint32_t TempSensor;
		dataToLCD('T');
		dataToLCD('E');
		dataToLCD('M');
		dataToLCD('P');
		dataToLCD(':');
		TempSensor = ADCreadT();
		reg_out(TempSensor);
		delay(10000);
		commandToLCD(LCD_LN2);	
		dataToLCD('T');
		dataToLCD('U');
		dataToLCD('R');
		dataToLCD('N');
		dataToLCD('I');
		dataToLCD('N');
		dataToLCD('G');
		dataToLCD(' ');
		dataToLCD('L');
		dataToLCD('E');
		dataToLCD('F');
		dataToLCD('T');
		commandToLCD(LCD_LN1);
	
}


void Display_Backward(void){
		uint32_t TempSensor;
		dataToLCD('T');
		dataToLCD('E');
		dataToLCD('M');
		dataToLCD('P');
		dataToLCD(':');
		TempSensor = ADCreadT();
		reg_out(TempSensor);
		delay(10000);
		commandToLCD(LCD_LN2);	
		dataToLCD('B');
		dataToLCD('A');
		dataToLCD('C');
		dataToLCD('K');
		dataToLCD('I');
		dataToLCD('N');
		dataToLCD('G');
		dataToLCD(' ');
		dataToLCD('U');
		dataToLCD('P');
		commandToLCD(LCD_LN1);
}
