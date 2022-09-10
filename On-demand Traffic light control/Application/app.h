#ifndef APP_H_
#define APP_H_

#include <avr/io.h>
#include "avr/interrupt.h"
#include "../ECUAL/Button/button.h"
#include "../ECUAL/LED/led.h"

typedef enum{
	Normal, Pedestrian
}System_Mode;

typedef enum{
	Green, Yellow, Red
}LED_State;

System_Mode Current_Mode;
LED_State Car_State;

void APP_start(void);

#endif /* APP_H_ */