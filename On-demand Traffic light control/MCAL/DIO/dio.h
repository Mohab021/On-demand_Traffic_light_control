#ifndef DIO_H_
#define DIO_H_

#define input 0x00
#define output 0xFF

#define low 0
#define high 1

#define A 0x39
#define B 0x36
#define C 0x33
#define D 0x30

typedef unsigned char uint8t;
typedef unsigned short uint16t;
typedef unsigned int uint32t;

typedef enum{
	Dio_OK, Dio_Wrong_Port, Dio_Wrong_Pin, Dio_Wrong_Direction, Dio_Wrong_Value
}errorState_Dio;

errorState_Dio DIO_init(uint8t Port, uint8t Pin, uint8t Direction);
errorState_Dio DIO_write(uint8t Port, uint8t Pin, uint8t Value);
errorState_Dio DIO_read(uint8t Port, uint8t Pin, uint8t * Value);
errorState_Dio DIO_toggle(uint8t Port, uint8t Pin);

/*
//PORTA Registers
#define PIN_A *(volatile uint8t*)(A)
#define DDR_A *(volatile uint8t*)(A+1)
#define PORT_A *(volatile uint8t*)(A+2)
//PORTB Registers
#define PIN_B *(volatile uint8t*)(B)
#define DDR_B *(volatile uint8t*)(B+1)
#define PORT_B *(volatile uint8t*)(B+2)
//PORTC Registers
#define PIN_C *(volatile uint8t*)(C)
#define DDR_C *(volatile uint8t*)(C+1)
#define PORT_C *(volatile uint8t*)(C+2)
//PORTD Registers
#define PIN_D *(volatile uint8t*)(D)
#define DDR_D *(volatile uint8t*)(D+1)
#define PORT_D *(volatile uint8t*)(D+2)
*/

#endif /* DIO_H_ */