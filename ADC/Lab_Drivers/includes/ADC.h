#ifndef INCLUDES_ADC_H_
#define INCLUDES_ADC_H_

	#include "stm32f4xx.h"
	# define USE_POLLING 1

	enum resolution{very_low = 3, low = 2, high = 1, very_high = 0};
	enum conv_mode{single = 0, continues = 1};

	#if USE_POLLING == 1
		void ADC_GetConversionState(unsigned char* ConversionStatePtr);
	#endif
	typedef struct {
		enum resolution res;
		enum conv_mode conv;
		float v_ref;
	} ADCConfigType;

	void ADC_Init(ADCConfigType* ConfigParamPtr);
	void ADC_StartConv(unsigned char ChannelNum);
	unsigned char ADC_ReadData(unsigned short int* DataPtr);


#endif
