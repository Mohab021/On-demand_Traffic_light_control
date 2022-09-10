#include "button.h"

errorState_Button BUTTON_init(uint8t Port, uint8t Pin){
	if( !(Port == A || Port == B || Port == C || Port == D) ){
		return Button_Wrong_Port;
	}
	if( !(Pin>=0 && Pin<8) ){
		return Button_Wrong_Pin;
	}
	
	DIO_init(Port, Pin, input);
	return Button_OK;
}

errorState_Button BUTTON_read(uint8t Port, uint8t Pin, uint8t * Value){
	if( !(Port == A || Port == B || Port == C || Port == D) ){
		return Button_Wrong_Port;
	}
	if( !(Pin>=0 && Pin<8) ){
		return Button_Wrong_Pin;
	}
	
	DIO_read(Port, Pin, Value);
	return Button_OK;
}

errorState_Button BUTTON_interrupt(uint8t Port, uint8t Pin){
	if( !(Port == A || Port == B || Port == C || Port == D) ){
		return Button_Wrong_Port;
	}
	if( !(Pin>=0 && Pin<8) ){
		return Button_Wrong_Pin;
	}
	
	Interrupt_init();
	return Button_OK;
}