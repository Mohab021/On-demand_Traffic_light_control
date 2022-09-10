#include <avr/io.h>
#include "avr/interrupt.h"
#include "interrupt.h"

errorState_Interrupt Interrupt_init(void) {
	//Step1: Enable External Interrupt 0 - INT0
	//Step2: Choose External Interrupt sense (on rising edge of INT0) - when press is complete
	//Step3: Enable Global Interrupt - Set 7th bit in status register

	GICR |= (1 << INT0); //Step1
	MCUCR |= (1 << ISC00) | (1 << ISC01); //Step2
	sei(); //Step3
	
	return Interrupt_OK;
}