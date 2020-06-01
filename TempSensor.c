/******************************************************************************
 * Name:    		Temp Sensor.c
 * Description: Read the temp sensor and send the data to the LCD screen
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
#include "TempSensor.h"
#include "LCD.h"

uint32_t ADCreadT(void){
		ADC1->SQR3 = 0x00000002;
		ADC1->CR2 = 0x00000001;
		while(ADC1->SR &= 0x02){
				return(ADC1->DR); 
		}
}

void reg_out( uint32_t reg_data){
		int i;
		uint32_t shifted_val;
		uint8_t print_val;
		dataToLCD (0x30);
		dataToLCD (0x78);
		for ( i=28; i >= 0 ; i = (i-4)){
				shifted_val = (reg_data >> i) & 0xf;
				print_val = (to_ascii(shifted_val));
		}
		dataToLCD(0x20);
}


