#include "led.h"

errorState_LED LED_init(uint8t Port, uint8t Pin){
	if( !(Port == A || Port == B || Port == C || Port == D) ){
		return LED_Wrong_Port;
	}
	if( !(Pin>=0 && Pin<8) ){
		return LED_Wrong_Pin;
	}

	DIO_init(Port, Pin, output);
	return LED_OK;
}

errorState_LED LED_on(uint8t Port, uint8t Pin){
	if( !(Port == A || Port == B || Port == C || Port == D) ){
		return LED_Wrong_Port;
	}
	if( !(Pin>=0 && Pin<8) ){
		return LED_Wrong_Pin;
	}
	
	DIO_write(Port, Pin, high);
	return LED_OK;
}

errorState_LED LED_off(uint8t Port, uint8t Pin){
	if( !(Port == A || Port == B || Port == C || Port == D) ){
		return LED_Wrong_Port;
	}
	if( !(Pin>=0 && Pin<8) ){
		return LED_Wrong_Pin;
	}
	
	DIO_write(Port, Pin, low);
	return LED_OK;
}

errorState_LED LED_toggle(uint8t Port, uint8t Pin){
	if( !(Port == A || Port == B || Port == C || Port == D) ){
		return LED_Wrong_Port;
	}
	if( !(Pin>=0 && Pin<8) ){
		return LED_Wrong_Pin;
	}
	
	DIO_toggle(Port, Pin);
	return LED_OK;
}

errorState_LED LED_on_time(uint8t Port, uint8t Pin, uint8t Value){
	if( !(Port == A || Port == B || Port == C || Port == D) ){
		return LED_Wrong_Port;
	}
	if( !(Pin>=0 && Pin<8) ){
		return LED_Wrong_Pin;
	}
	if( Value<0 ){
		return LED_Wrong_Value;
	}
	
	/* Step1: Turn On LED */
	/* Step2: Still High for Number of seconds */
	/* Step1: Turn Off LED */
	
	DIO_write(Port, Pin, high); //Step1
	for(char i=0 ; i<Value*4 ; i++){
		_delay_250m(); //Step2
	}
	DIO_write(Port, Pin, low); //Step3
	return LED_OK;
}

errorState_LED LED_blink_time(uint8t Port, uint8t Pin, uint8t Value){
	if( !(Port == A || Port == B || Port == C || Port == D) ){
		return LED_Wrong_Port;
	}
	if( !(Pin>=0 && Pin<8) ){
		return LED_Wrong_Pin;
	}
	if( Value<0 ){
		return LED_Wrong_Value;
	}
	
	/* Step1: Turn On LED */
	/* Step2: Blinking for Number of seconds */
	/* Step1: Turn Off LED */
	
	DIO_write(Port, Pin, high); //Step1
	for(char i=0 ; i<Value*4 ; i++){
		DIO_toggle(Port, Pin); //Step2
		_delay_250m();
	}
	DIO_write(Port, Pin, low); //Step3
	return LED_OK;
}

errorState_LED LED_double_blink_time(uint8t Port1, uint8t Pin1, uint8t Port2, uint8t Pin2, uint8t Value){
	if( !(Port1 == A || Port1 == B || Port1 == C || Port1 == D) ){
		return LED_Wrong_Port;
	}
	if( !(Pin1>=0 && Pin1<8) ){
		return LED_Wrong_Pin;
	}
	if( !(Port2 == A || Port2 == B || Port2 == C || Port2 == D) ){
		return LED_Wrong_Port;
	}
	if( !(Pin2>=0 && Pin2<8) ){
		return LED_Wrong_Pin;
	}
	if( Value<0 ){
		return LED_Wrong_Value;
	}

	/* Step1: Turn On LED1 and LED2 */
	/* Step2: Blinking for Number of seconds */
	/* Step1: Turn Off LED1 and LED2 */
	
	DIO_write(Port1, Pin1, high); //Step1
	DIO_write(Port2, Pin2, high);
	for(char i=0 ; i<Value*4 ; i++){
		DIO_toggle(Port1, Pin1); //Step2
		DIO_toggle(Port2, Pin2);
		_delay_250m();
	}
	DIO_write(Port1, Pin1, low); //Step3
	DIO_write(Port2, Pin2, low);
	return LED_OK;
}