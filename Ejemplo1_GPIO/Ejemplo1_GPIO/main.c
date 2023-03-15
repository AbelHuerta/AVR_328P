/*
 * Ejemplo1_GPIO.c
 *
 * Created: 1/05/2022 15:10:45
 * Author : abelh
 */ 


#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>	
#include <math.h>
#include "GPIO.h"

void ejemplo1(void);
void ejemplo2(void);
void ejemplo3(void);

int main(void)
{
   GPIO_INIT();
   for(;;){
		GPIO_TOGGLE();
		_delay_ms(200);
   }
   
}

void ejemplo1(void){
	//DEFINO COMO SALIDAS PB7 Y PB0
	DDRB |= (1<<7) | (1<<0);
	
	for(;;){
		PORTB |= (1<<7);
		PORTB &= ~(1<<0);
		_delay_ms(300);
		PORTB &= ~(1<<7);
		PORTB |= (1<<0);
		_delay_ms(300);
	}
}
void ejemplo2(void){
	//TODO EL PUERTO COMO SALIDA
	DDRB = 0xFF;
	
	for(;;){
		PORTB = 0x0F;
		_delay_ms(200);
		PORTB = 0xF0;
		_delay_ms(200);
	}
}
void ejemplo3(void){
	 DDRB |= (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7);
	 for(;;){
		 
		 //PORTB = pow(i,1)-1;
		 for(int i=0;i<=8;i++){ // 128 = 1000 0000 = 2^7
			 PORTB= pow(2,i);
			 _delay_ms(200);
		 }
		 for(int i=8;i>=0;i--){
			 PORTB= pow(2,i);
			 _delay_ms(200);
		 } 
	 }
}