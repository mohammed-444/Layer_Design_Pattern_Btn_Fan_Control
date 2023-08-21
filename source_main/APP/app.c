#include "app.h"


void app_init(void){
	LCD_init();
	DcMotor_Init();
	button_init(PWM_BUTTON_PORT, PWM_BUTTON_PIN, PULL_UP);

}




void app_start(void){
	uint8 pressed_flag=0;
	uint8 press_num=0;

	LCD_displayStringRowColumn((uint8)0,(uint8)2,"FAN IS ");

	while(1){

		read_press(& pressed_flag,&press_num);
		rotate_press(&press_num);
	}

}


void read_press(uint8* pressed_flag_ptr,uint8* press_num_ptr){
	uint8 button_value = 1;
	button_value = read_button(PWM_BUTTON_PORT, PWM_BUTTON_PIN);

		if((button_value == LOGIC_LOW)  && (*pressed_flag_ptr == LOGIC_LOW)){

			_delay_ms((double)50);

			button_value = read_button(PWM_BUTTON_PORT, PWM_BUTTON_PIN);

			if((button_value == LOGIC_LOW)  && (*pressed_flag_ptr == LOGIC_LOW)){

				*pressed_flag_ptr = LOGIC_HIGH;

				(*press_num_ptr)++;

			}
		}
		if((button_value == LOGIC_HIGH)){
			*pressed_flag_ptr = LOGIC_LOW;
		}


}

void rotate_press(uint8* press_num_ptr){
	if(((*press_num_ptr)<=(uint8)0) || ((*press_num_ptr)>(uint8)10)){

		(*press_num_ptr) = (uint8)0;
	}

	if ((*press_num_ptr) == (uint8)0) {
			LCD_displayStringRowColumn((uint8)0,(uint8)9,"OFF   ");
			DcMotor_Rotate(stop,(uint8)0);
	}
	else{
		uint8 temp=(*press_num_ptr)*(uint8)10;
		LCD_moveCursor((uint8)0,(uint8)9);
		LCD_intgerToString((sint32)temp);
		LCD_displayCharacter('%');
		DcMotor_Rotate(clockwise,temp);
	}
}




