/*
 * interrup_PCINT.c
 *
 * Created: 28/05/2022 19:49:12
 * Author : abelh
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include "Interrupciones_AVR.h"
#include <avr/interrupt.h>

volatile bool Flag_PCINT = false;
uint8_t i;

int main(void)
{
	cli();
	PCINTX_Init();
	//SALIDAS
	DDRB |= (1<<5);
	//INICIALMENTE APAGADO
	PORTB &= ~(1<<5);
	sei();
	for (;;)
	{
		if (Flag_PCINT)
		{
			for (i=0;i<=9;i++)
			{
				PORTB ^= (1<<5);
				_delay_ms(200);
			}
			Flag_PCINT = false;
		}
		
	}
}
