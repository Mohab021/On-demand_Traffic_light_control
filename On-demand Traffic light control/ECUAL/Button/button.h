#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/Interrupt/interrupt.h"

typedef enum{
	Button_OK, Button_Wrong_Port, Button_Wrong_Pin
}errorState_Button;

errorState_Button BUTTON_init(uint8t Port, uint8t Pin);
errorState_Button BUTTON_read(uint8t Port, uint8t Pin, uint8t * Value);
errorState_Button BUTTON_interrupt(uint8t Port, uint8t Pin);

#endif /* BUTTON_H_ */