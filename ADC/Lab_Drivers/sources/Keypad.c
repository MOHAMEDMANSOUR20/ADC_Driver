#include "GPIO.h"
#include "Keypad.h"
#include "stm32f4xx.h"

#define col_start_ind 4
#define row_start_ind 7
#define seven_seg_start_ind 0

const char num_rows = 4;
const char num_cols = 3;
char rows[4] = {0,1,2,3};
char cols[3] = {0,1,2};
char look_up_table [4][3] = {{1,2,3},{4,5,6},{7,8,9},{'*',0,'#'}};
char current_key;

void Keypad_init(void) {

	GPIO_Init (GPIOB, 4, 1, 1);
	GPIO_Init (GPIOB, 5, 1, 1);
	GPIO_Init (GPIOB, 6, 1, 1);
	GPIO_Init (GPIOB, 7, 0, 1);
	GPIO_Init (GPIOB, 8, 0, 1);
	GPIO_Init (GPIOB, 9, 0, 1);
	GPIO_Init (GPIOB, 10, 0, 1);

}

void Keypad_manage(void) {

	uint32_t inp;
	for(int i=0; i<num_cols; i++){
		/* Iterating Over Column Pins and setting each one by 1 at a time: */
		GPIO_WritePin(GPIOB, col_start_ind + i, 1u);
		/* Iterating Over Row Pins: */
		for(int j=0; j<num_rows; j++){
			/* Skip if '#' or '*' are pressed: */
			if(j==3 && i!=1) continue;
			/* Reading Row Pin Value: */
			inp = GPIO_ReadPin(GPIOB, row_start_ind+j);
			/* If the pin is high wait until it goes low then modify the key value and print it on the seven segment: */
			while(inp) {
				inp = GPIO_ReadPin(GPIOB, row_start_ind+j);
				if(!inp){
					current_key = look_up_table[j][i];
					KeypadCallouts_KeyPressNotificaton();
					break;
				}
			}
		}
		/* Reset the column pin by 0: */
		GPIO_WritePin(GPIOB, col_start_ind + i, 0);
}

}

char Keypad_GetKey(void) {
	return current_key;
}

void KeypadCallouts_KeyPressNotificaton(void) {

	char outp = Keypad_GetKey();
	/* Setting each seven segment pin to print keypad Value: */
	for(int i=0; i<4; i++){
		GPIO_WritePin(GPIOB, seven_seg_start_ind + i, (outp & (1u<<i)));
}

}
