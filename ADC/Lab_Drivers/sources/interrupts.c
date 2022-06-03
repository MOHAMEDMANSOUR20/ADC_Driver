#include "stm32f4xx.h"
#include "interrupts.h"

void EXTI_Init(unsigned char line, unsigned char edge){

	RCC -> APB2ENR |= (1U<<14);
	EXTI -> IMR |= (1U<<line);
	if(edge){
		EXTI ->RTSR |= (1u<<line);
		EXTI ->FTSR &= ~(1u<<line);
	}
	else{
		EXTI ->FTSR |= (1u<<line);
		EXTI ->RTSR &= ~(1u<<line);
	}

}

void NIVC_Init(unsigned char inter_no){

	unsigned char no = inter_no / 32;
	unsigned char pin = inter_no % 32;
	NVIC ->  ISER[no] |= (1u<<pin);

}

void Select_line(unsigned char EXTI_no, uint32_t port_no){

	unsigned char no = EXTI_no / 4;
	unsigned char pin = EXTI_no % 4;
	SYSCFG -> EXTICR[no] |= (port_no<<(pin*4));

}
