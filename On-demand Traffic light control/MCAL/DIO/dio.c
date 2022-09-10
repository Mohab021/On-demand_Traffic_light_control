#include "dio.h"

errorState_Dio DIO_init(uint8t Port, uint8t Pin, uint8t Direction) {
	if( !(Port == A || Port == B || Port == C || Port == D) ){
		return Dio_Wrong_Port;
	}
	if( !(Pin>=0 && Pin<8) ){
		return Dio_Wrong_Pin;
	}
	if( !(Direction == input || Direction == output) ){
		return Dio_Wrong_Direction;
	}
	
	if(Direction == output){
		*(volatile uint8t*)(Port + 1) |= (1<<Pin); // set 1 --> DDRX 
	}
	else {
		*(volatile uint8t*)(Port + 1) &= ~(1 << Pin); // clear 0 --> DDRX 
	}
	return Dio_OK;
}

errorState_Dio DIO_write(uint8t Port, uint8t Pin, uint8t Value) {
	if( !(Port == A || Port == B || Port == C || Port == D) ){
		return Dio_Wrong_Port;
	}
	if( !(Pin>=0 && Pin<8) ){
		return Dio_Wrong_Pin;
	}
	if( !(Value == low || Value == high) ){
		return Dio_Wrong_Value;
	}

	if (Value == high) {
		*(volatile uint8t*)(Port + 2) |= (1 << Pin); // write 1 --> PORTX 
	}
	else {
		*(volatile uint8t*)(Port + 2) &= ~(1 << Pin); // write 0 --> PORTX 
	}
	return Dio_OK;
}

errorState_Dio DIO_read(uint8t Port, uint8t Pin, uint8t* Value) {
	if( !(Port == A || Port == B || Port == C || Port == D) ){
		return Dio_Wrong_Port;
	}
	if( !(Pin>=0 && Pin<8) ){
		return Dio_Wrong_Pin;
	}
	
	*Value = ( *(volatile uint8t*)(Port) & (1 << Pin) ) >> Pin; // read from PINX
	return Dio_OK;
}

errorState_Dio DIO_toggle(uint8t Port, uint8t Pin) {
	if( !(Port == A || Port == B || Port == C || Port == D) ){
		return Dio_Wrong_Port;
	}
	if( !(Pin>=0 && Pin<8) ){
		return Dio_Wrong_Pin;
	}
	
	*(volatile uint8t*)(Port + 2) ^= (1 << Pin); // flip --> PORTX 
	return Dio_OK;
}