
#include "ADC.h"
#if USE_POLLING == 1
	unsigned char eoc = 0;
# else
	unsigned char int_flag = 0;
#endif
void ADC_Init(ADCConfigType* ConfigParamPtr){


/* Enabling ADC and its Clock: */
RCC -> APB2ENR |= (1u<<8);
ADC1 -> CR2 |= (1U<<0);

/* Setting Resolution: */
ADC1 -> CR1 |= ( (ConfigParamPtr -> res) <<24);

/* Setting Conversion Mode: */
if(ConfigParamPtr -> conv)
	ADC1 -> CR2 |= (1u<<1);
else
	ADC1 -> CR2 &= ~(1u<<1);

ADC1 -> SQR1 &= ~(15u<<20);

}

void ADC_StartConv(unsigned char ChannelNum){

	/* Setting port A pin 1 to analog mode ( channel 1 in ADC ): */
	if (ChannelNum<8){
		RCC -> AHB1ENR |= (1u<<0);
		GPIOA -> MODER |= (1u << (2*ChannelNum));
		GPIOA -> MODER |= (1u << (2*ChannelNum +1));
		GPIOA -> PUPDR &= ~(1u << (2*ChannelNum));
		GPIOA -> PUPDR &= ~(1u << (2*ChannelNum+1));
	}
	else if (ChannelNum<10){
		RCC -> AHB1ENR |= (1u<<1);
		GPIOB -> MODER |= (1u << (2*(ChannelNum-8)));
		GPIOB -> MODER |= (1u << (2*(ChannelNum-8) +1));
		GPIOB -> PUPDR &= ~(1u << (2*(ChannelNum-8)));
		GPIOB -> PUPDR &= ~(1u << (2*(ChannelNum-8)+1));
	}
	else{
		RCC -> AHB1ENR |= (1u<<2);
		GPIOB -> MODER |= (1u << (2*(ChannelNum-10)));
		GPIOB -> MODER |= (1u << (2*(ChannelNum-10) +1));
		GPIOB -> PUPDR &= ~(1u << (2*(ChannelNum-10)));
		GPIOB -> PUPDR &= ~(1u << (2*(ChannelNum-10)+1));
	}

	/* Setting channel as the only channel in regular sequence: */

	ADC1 -> SQR3 |= (ChannelNum<<0);

	/* Starting Conversion: */
	ADC1 -> CR2 |= (1u<<30);

#if USE_POLLING == 0
	/* Enabling ADC Interrupt: */
	ADC1 ->CR1 |= (1u<<5);
#endif

	}

# if USE_POLLING == 1

	void ADC_GetConversionState(unsigned char* ConversionStatePtr){
		unsigned char end_conv = ADC1 -> SR & (1u<<1);
		if (end_conv) * ConversionStatePtr = 1;
		else  * ConversionStatePtr = 0;
	}

# else

	void ADC_IRQHandler(void){
		int_flag = 1;
	}

# endif

unsigned char ADC_ReadData(unsigned short int* DataPtr){
# if USE_POLLING == 1
	unsigned char *ptr = &eoc;
	ADC_GetConversionState(ptr);
	if(eoc){
		*DataPtr = ADC1 -> DR;
		return 1;
	}
	else return 0;

# else
	if (int_flag){
		*DataPtr = ADC1 ->DR;
		int_flag = 0;
		return 1;
	}
	else return 0;

#endif
}


