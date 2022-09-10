#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/Timer/timer.h"

typedef enum{
	LED_OK, LED_Wrong_Port, LED_Wrong_Pin, LED_Wrong_Value
}errorState_LED;

errorState_LED LED_init(uint8t Port, uint8t Pin);
errorState_LED LED_on(uint8t Port, uint8t Pin);
errorState_LED LED_off(uint8t Port, uint8t Pin);
errorState_LED LED_toggle(uint8t Port, uint8t Pin);
errorState_LED LED_on_time(uint8t Port, uint8t Pin, uint8t Value);
errorState_LED LED_blink_time(uint8t Port, uint8t Pin, uint8t Value);
errorState_LED LED_double_blink_time(uint8t Port1, uint8t Pin1, uint8t Port2, uint8t Pin2, uint8t Value);

#endif /* LED_H_ */