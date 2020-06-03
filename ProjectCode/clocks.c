/******************************************************************************
 * Name:    		Clocks.c
 * Description: Set up the clock and sub clocks
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

void clockInit(void) {
	uint32_t temp = 0x00;     
	
	//R1    // Output PLL/2 as MCO,
	RCC->CFGR = 0x07050002;

  //R2 // Turn on PLL, HSE, HSI
	RCC->CR =  0x01010081;     

  // Wait for the PLL to stabilize
	while (temp != 0x02000000){
		//Check to see if the PLL lock bit is set
		temp = RCC->CR & 0x02000000; 
  }   
}


void subclocks(void){
	RCC->APB2ENR |=  RCC_APB2ENR_TIM1EN | RCC_APB2ENR_TIM16EN | RCC_APB2ENR_TIM1EN | RCC_APB2ENR_ADC1EN | RCC_APB2ENR_AFIOEN | RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN;

	GPIOA->CRL &= ~GPIO_CRL_MODE1 & ~GPIO_CRL_MODE2;
	GPIOA->CRL &= ~GPIO_CRL_CNF1 & ~GPIO_CRL_CNF2;
	ADC1->CR2 = 0x00000001;
	
	GPIOA->CRH |= GPIO_CRH_CNF8_1 | GPIO_CRH_MODE8_1 | GPIO_CRH_MODE8_0 ;
  GPIOA->CRH &= ~GPIO_CRH_CNF8_0 ;
	
	
	GPIOA->CRH |=  GPIO_CRH_MODE9 | GPIO_CRH_MODE10 | GPIO_CRH_MODE11 | GPIO_CRH_MODE12 | GPIO_CRH_MODE15 ;
	GPIOA->CRH &=  ~GPIO_CRH_CNF9 & ~GPIO_CRH_CNF10 & ~GPIO_CRH_CNF11 & ~GPIO_CRH_CNF12 & ~GPIO_CRH_CNF15;
	
	GPIOB->CRH |= GPIO_CRH_MODE8;
	GPIOB->CRH &= ~GPIO_CRH_CNF8;
	
	GPIOB->CRL |= GPIO_CRL_MODE5 | GPIO_CRL_MODE1 | GPIO_CRL_MODE0;
	GPIOB->CRL &= ~GPIO_CRL_CNF5 & ~GPIO_CRL_CNF1 & ~GPIO_CRL_CNF0;
	
	GPIOB->CRL |= GPIO_CRL_MODE3 | GPIO_CRL_CNF4_0 | GPIO_CRL_CNF6_0 | GPIO_CRL_CNF7_0;
	GPIOB->CRL &= ~GPIO_CRL_CNF3 & ~GPIO_CRL_CNF4_1 & ~GPIO_CRL_MODE4 & ~GPIO_CRL_CNF6_1 & ~GPIO_CRL_MODE6 & ~GPIO_CRL_CNF7_1 & ~GPIO_CRL_MODE7;
	
	GPIOB->CRH |= GPIO_CRH_CNF8_1 | GPIO_CRH_MODE8_1 | GPIO_CRH_MODE8_0 | GPIO_CRH_CNF10_0;
	GPIOB->CRH &= ~GPIO_CRH_CNF8_0 & ~GPIO_CRH_CNF10_1 & ~GPIO_CRH_MODE10;
		
	GPIOB->CRH |= GPIO_CRH_MODE12 | GPIO_CRH_MODE11;
	GPIOB->CRH &= ~GPIO_CRH_CNF12 & ~GPIO_CRH_CNF11;
	
	GPIOB->CRH |= GPIO_CRH_MODE13 | GPIO_CRH_MODE14;
	GPIOB->CRH &= ~GPIO_CRH_CNF13 & ~GPIO_CRH_CNF14;
	
	GPIOC->CRL |= GPIO_CRL_MODE0 | GPIO_CRL_MODE1 | GPIO_CRL_MODE2 | GPIO_CRL_MODE3 | GPIO_CRL_MODE4 | GPIO_CRL_MODE5 | GPIO_CRL_MODE6 | GPIO_CRL_MODE7;
	GPIOC->CRL &= ~GPIO_CRL_CNF0 & ~GPIO_CRL_CNF1 & ~GPIO_CRL_CNF2 & ~GPIO_CRL_CNF3 & ~GPIO_CRL_CNF4 & ~GPIO_CRL_CNF5 & ~GPIO_CRL_CNF6 & ~GPIO_CRL_CNF7;
		
	GPIOC->CRH |= GPIO_CRH_MODE10 | GPIO_CRH_MODE11;
	GPIOC->CRH &= ~GPIO_CRH_CNF10 & ~GPIO_CRH_CNF11;
}
		

