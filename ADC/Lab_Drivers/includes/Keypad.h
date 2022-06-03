#ifndef INCLUDES_KEYPAD_H_
#define INCLUDES_KEYPAD_H_

#include "stm32f4xx.h"


void Keypad_init();
void Keypad_manage(void);
char Keypad_GetKey(void);
void KeypadCallouts_KeyPressNotificaton(void);

#endif /* INCLUDES_GPIO_H_ */
