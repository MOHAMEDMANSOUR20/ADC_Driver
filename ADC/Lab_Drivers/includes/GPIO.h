/*
 * GPIO.h
 *
 *  Created on: May 13, 2022
 *      Author: Mansour's Sons
 */

#ifndef INCLUDES_GPIO_H_
#define INCLUDES_GPIO_H_

#include "stm32f4xx.h"
void GPIO_Init (GPIO_TypeDef * GPIOx, char pin, char dir, char enable_bit);
char GPIO_WritePin(GPIO_TypeDef * GPIOx, char pin, char data);
uint32_t GPIO_ReadPin(GPIO_TypeDef * GPIOx, char pin);

#endif /* INCLUDES_GPIO_H_ */
