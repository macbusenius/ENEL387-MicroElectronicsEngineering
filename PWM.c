/******************************************************************************
 * Name:    		PWM.h
 * Description: Provides a Duty cycle of 50% to both wheels
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
#include "PWM.h"
#include "LCD.h"

void PWM_Left(void){
		TIM1->CR1 |= TIM_CR1_CEN; // Enable Timer1
		TIM1->CR2 |= TIM_CR2_OIS1; // Output Idle State for Channel 1 OC1=1 when MOE=0
		TIM1->EGR |= TIM_EGR_UG; // Reinitialize the counter
		TIM1->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE | TIM_CCMR1_OC1FE; //PWM mode 1, Preload Enable, Fast Enable
		
		//TIM1->CCMR2 not used for this application
		TIM1->CCER |= TIM_CCER_CC1E; //Enable CH1 output on PA8
		TIM1->PSC = 0x095F; //Divide 24 MHz by 2400 , PSC_CLK = 10000 Hz, 1 count = 0.1 ms
		TIM1->ARR = 100; // 100 counts = 10 ms
		TIM1->CCR1 = 50; // 10 counts = 1 ms = 10% duty cycle  50 counts = 5 ms = 50%duty cycle
		TIM1->BDTR |= TIM_BDTR_MOE | TIM_BDTR_OSSI; //Main Output Enable, Force Idle Level First
		TIM1->CR1 |= TIM_CR1_ARPE | TIM_CR1_CEN; // Enable Timer1
}


void PWM_Right(void){
		TIM16->CR1 |= TIM_CR1_CEN; // Enable Timer1
		TIM16->CR2 |= TIM_CR2_OIS1; // Output Idle State for Channel 1 OC1=1 when MOE=0
		TIM16->EGR |= TIM_EGR_UG; // Reinitialize the counter
		TIM16->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE | TIM_CCMR1_OC1FE; //PWM mode 1, Preload Enable, Fast Enable
		
		//TIM1->CCMR2 not used for this application
		TIM16->CCER |= TIM_CCER_CC1E; //Enable CH1 output on PB8
		TIM16->PSC = 0x095F; //Divide 24 MHz by 2400 , PSC_CLK = 10000 Hz, 1 count = 0.1 ms
		TIM16->ARR = 100; // 100 counts = 10 ms
		TIM16->CCR1 = 50; // 10 counts = 1 ms = 10% duty cycle  50 counts = 5 ms = 50%duty cycle
		TIM16->BDTR |= TIM_BDTR_MOE | TIM_BDTR_OSSI; //Main Output Enable, Force Idle Level First
		TIM16->CR1 |= TIM_CR1_ARPE | TIM_CR1_CEN; // Enable Timer1
}


void updateLeft(void){
		TIM1->CCR1 = 50;
		TIM1->EGR |= TIM_EGR_UG; // Reinitialize the counter • 
		delay(10);//000);
}	


void updateRight(void){
		TIM16->CCR1 = 50;
		TIM16->EGR |= TIM_EGR_UG; // Reinitialize the counter • 
		delay(10);//000000);
}	

