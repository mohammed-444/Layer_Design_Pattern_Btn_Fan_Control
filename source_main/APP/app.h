
#ifndef _APP_H
#define _APP_H


#include "../ECUAL/dc_motor/dc_motor.h"
#include "../ECUAL/lcd/lcd.h"
#include "../ECUAL/button/button.h"
#include <util/delay.h>




void app_init(void);

void app_start(void);

void read_press(uint8* pressed_flag_ptr,uint8* press_num_ptr);

void rotate_press(uint8* press_num_ptr);





#endif
