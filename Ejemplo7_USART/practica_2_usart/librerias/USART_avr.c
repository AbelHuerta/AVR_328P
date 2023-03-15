/*
 * USART_avr.c
 *
 * Created: 15/05/2022 18:42:50
 *  Author: abelh
 */ 

#include "USART_avr.h"

void UART0_Avr_Init(uint32_t BaudRate){
	//CONFIGURACION DE BAUDIOS
	UBRR0 = (uint16_t) ((F_CPU/8UL/BaudRate) -1UL);
	
	//CONFIGURACION DE UART0 DOBLE VELOCIDAD
	UCSR0A |= (1<<U2X0);
	
	//CONFIGURAMOS EL TIPO DE DATO A ENVIAR 8BITS
	UCSR0B &= ~(1<<UCSZ02);
	UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00) ;
	
	//CONFIGURAR AL MODO ASINCRONO
	UCSR0C &= ~(1<<UMSEL00) & ~(1<<UMSEL01);
	
	//CONFIGURAMOS LA PARIDAD
	UCSR0C &= ~(1<<UPM01) & ~(1<<UPM00);
	
	//CONFIGURAR EL BIT DE STOP
	UCSR0C &= ~(1<<USBS0);
	
	//HABILITAMOS LA TX
	UCSR0B |= (1<<TXEN0);
	
	//HABILITAMOS RX
	UCSR0B |= (1<<RXEN0);
}

void UART0_Avr_Print_Char(char C){
	while((UCSR0A & (1<<UDRE0)) == 0);
	UDR0 = C;
}

void UART0_Avr_Print_String(char *C){
	char *ptr;
	ptr = C;
	
	while(*ptr);
	
}