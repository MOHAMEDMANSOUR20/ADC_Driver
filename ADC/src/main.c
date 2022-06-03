/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/
#include "GPIO.h"
#include "ADC.h"

#include "stm32f4xx.h"
			

int main(void)
{

unsigned short int data;
unsigned short int *data_ptr = &data;

GPIO_Init(GPIOB,0,1,1);
GPIO_Init(GPIOB,1,1,1);
GPIO_Init(GPIOB,2,1,1);
GPIO_Init(GPIOB,3,1,1);

ADCConfigType x;
x.res = very_low;
x.conv = single;
x.v_ref = 2;

ADCConfigType * y = &x;

ADC_Init(y);


ADC_StartConv(0u);
		unsigned char read = ADC_ReadData(data_ptr);
		if(read){
			for(int i=0; i<4; i++){
				GPIO_WritePin(GPIOB,i,(ADC1->DR&(1<<i)));
			}}
			else{
				for(int i=0; i<4; i++){
				GPIO_WritePin(GPIOB,i,(12&(1<<i)));
			}
		}

	for(;;){

		for(int i=0; i<1000;i++);
	}
}
