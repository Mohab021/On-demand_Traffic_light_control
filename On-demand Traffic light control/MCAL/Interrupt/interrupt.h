#ifndef INTERRUPT_H_
#define INTERRUPT_H_

typedef enum{
	Interrupt_OK, Interrupt_WRONG
}errorState_Interrupt;

errorState_Interrupt Interrupt_init(void);

#endif /* INTERRUPT_H_ */