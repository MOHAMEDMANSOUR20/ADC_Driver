/*
 * GPIO.c
 *
 *  Created on: May 13, 2022
 *      Author: Mansour's Sons
 */
#include "stm32f4xx.h"
# include "GPIO.h"

void GPIO_Init (GPIO_TypeDef * GPIOx, char pin, char dir, char enable_bit){

	RCC -> AHB1ENR |= (1u << enable_bit);
	if (dir){

		GPIOx -> MODER |= (1u << (2*pin));
		GPIOx -> MODER &= ~(1u << (2*pin +1));

	}
	else{

		GPIOx -> MODER &= ~(1u << (2*pin));
		GPIOx -> MODER &= ~(1u << (2*pin +1));
		GPIOx -> PUPDR &= ~(1u << (2*pin+1));
		GPIOx -> PUPDR |= (1u << (2*pin));

	}
}

char GPIO_WritePin(GPIO_TypeDef * GPIOx, char pin, char data){

	uint32_t is_outp_pin = (GPIOx -> MODER) & (1u << (2*pin));
	if(is_outp_pin){

		if (data)
		GPIOx -> ODR |= (1u << pin);
		else
			GPIOx -> ODR &= ~(1u << pin);
		return 1;

	}
	else{
		return 0;
	}

}

uint32_t GPIO_ReadPin(GPIO_TypeDef * GPIOx, char pin){

	uint32_t is_inp_pin = !((GPIOx -> MODER) & (1u << (2*pin)));
	if(is_inp_pin){
		uint32_t inp_value = GPIOx -> IDR & (1u << pin);
		return inp_value;
	}
	else
		return 1;

	}
