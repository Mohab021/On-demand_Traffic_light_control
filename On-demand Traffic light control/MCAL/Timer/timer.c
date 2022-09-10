#define F_CPU 1000000UL
#include <avr/io.h>
#include "timer.h"

errorState_Timer _delay_250m(void){
	/*  Step1: Choosing Normal mode */
	/*  Step2: F_CPU = 1MHz,
		Prescaler of 1024, F_osc = 976.5625Hz, T_tick = 1.024ms
		Number of ticks to get 250ms delay, is 244 ticks
		Start counting from value 12 */
	/*  Step3: Setting the prescaler to 1024, Timer will star counting here */
	/*  Step4: Check overflow flag */
	/*  Step5: Stop counting by selecting No clock source */
	/*  Step6: Clear overflow flag */

	TCCR0 = 0x00; //Step1
	TCNT0 = 0x0C; //Step2
	TCCR0 |= (1<<0) | (1<<2); //Step3
	while( (TIFR & (1<<TOV0)) == 0 ) ; //Step4
	TCCR0 = 0x00; //Step5
	TIFR |= (1<<TOV0); //Step6
	
	return Timer_OK;
}