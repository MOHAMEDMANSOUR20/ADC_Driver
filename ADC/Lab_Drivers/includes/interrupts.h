#ifndef INCLUDES_INTERRUPTS_H_
#define INCLUDES_INTERRUPTS_H_

#include "stm32f4xx.h"
void EXTI_Init(unsigned char line, unsigned char edge);
void NIVC_Init(unsigned char inter_no);
void Select_line(unsigned char EXTI_no, uint32_t port_no);

#endif
