/*
 * GPIO_avr.h
 *
 * Created: 13/06/2022 13:08:45
 *  Author: abelh
 */ 


#ifndef GPIO_AVR_H_
#define GPIO_AVR_H_

#define F_CPU	16000000UL
#include <avr/io.h>

//DDR , PORT , PIN
#define PIN_OUTPUT(P,b)	 DDR ## P |= 1U<<DD ## P ## b      //COMO SALIDA (DDRB |= 1<<DDB5)
#define PIN_INPUT(P,b)	{DDR ## P &=~ (1U<<DD ## P ## b),\
						 PORT ## P |= 1U<<PORT ## P ## b;}    //COMO ENTRADA (PULL UP ACTIVADO)
#define PIN_SET(P,b)	 PORT ## P |= 1U<< PORT ## P ## b;	  //1
#define PIN_RESET(P,b)	 PORT ## P &=~ (1U<< PORT ## P ## b); //0
#define PIN_READ(P,b)	 (PIN ## P)>>PIN ## P ## b			  //LECTURA
#define PIN_TOGGLE(P,b)  PIN ## P |= 1U<<PIN ## P ## b		  //XOR

//DISPOSITIVOS DE SALIDA
#define LED1 B,1
#define PIN_SET_(a)		 PIN_SET(a)
#define PIN_RESET_(a)	 PIN_RESET(a)
#define PIN_TOGGLE_(a)	 PIN_TOGGLE(a)

//ENCIENDE LED 1
void GPIO_Init(void);

#endif /* GPIO_AVR_H_ */