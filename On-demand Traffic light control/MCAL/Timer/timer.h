#ifndef TIMER_H_
#define TIMER_H_

typedef enum{
	Timer_OK, Timer_WRONG
}errorState_Timer;

errorState_Timer _delay_250m(void);

#endif /* TIMER_H_ */