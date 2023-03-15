/*
 * USART_avr.c
 *
 * Created: 4/06/2022 12:13:28
 *  Author: abelh
 */ 

#include "USART_avr.h"

void UART_Config(uint8_t speed, uint32_t baudios){
	uint16_t   baud;
	URBB_VALUE(9600,speed,baud);
	
	//1.ESTABLECER LA TAZA DE BAUDIOS
	UBRR0H = (uint8_t)(baud>>8);
	UBRR0L = (uint8_t)(baud & 0xFF) ;
	
	//2.CONFIGURAR EL FORMATO DEL FRAME
	//BIT DE TX/RX   ;  8 BITS
	UCSR0C &= ~(1U<<UCSZ02);
	UCSR0C |= (1U<<UCSZ01) | (1U<<UCSZ01);
	//PARIEDAD ; SIN PARIEDAD
	UCSR0C &= ~(1U<<UPM01 | 1U<<UPM00);
	//BIT STOP ; 1 BIT DE STOP
	UCSR0C &= ~(1U<<USBS0);
	
	//3.HABILITAR LA TX Y RX DEPENDIENDO DEL USO
	UCSR0B |= (1<<RXEN0) | (1<<TXEN0); //HABILITA TX/RX
	
	//4.CONFIGURACION DE INTERRUPCIONES 
	UCSR0B |= (1<<RXCIE0); //HABILITA INTERRUPCION PARA Rx	
		
	return;
}

void UART_Transmit(uint8_t data){
	/* Wait for data to be received */
	while (!(UCSR0A & (1<<UDRE0)));
	/* Get and return received data from buffer */
	UDR0 = data;
}

uint8_t UART_Receive(void){
	while (!(UCSR0A & (1<<RXC0)));
	return UDR0;
}

void UART_SendData(uint8_t *pData, uint16_t Size){
	while(Size-->0){
		UART_Transmit(*pData);
		pData++;
	}
	return;
}