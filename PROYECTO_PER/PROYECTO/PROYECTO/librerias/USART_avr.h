/*
 * USART_avr.h
 *
 * Created: 4/06/2022 12:13:38
 *  Author: abelh
 */ 


#ifndef USART_AVR_H_
#define USART_AVR_H_

/*INCLUDES*/
#include <avr/io.h>

/*MACROS*/
#define F_OSC 16000000UL
#define DOUBLE_SPEED U2X0
#define SINGLE_SPEED 0


#define URBB_VALUE(BAUD,U2x,Ubrr) { if(U2x == U2X0){\
										Ubrr = (uint16_t)((F_OSC/(8UL*BAUD)) - 1U);\
										UCSR0A |= 1U<<U2X0;}\
									else\
										Ubrr = (uint16_t)((F_OSC/(8UL*BAUD)) - 1U);}	

/***************************************************************/
/*					 PROTOTIPO DE FUNCIONES                    */
/***************************************************************/

/*CONFIGURACION DEL UART*/
/*
	speed : division entre 8 o 16
	baudios = tasa de baudios deseada
*/
void UART_Config(uint8_t speed,uint32_t baudios);


/*TRANSMITE UN BYTE POR EL PIN TX*/
/*
	data : byte a transmitir
*/
void UART_Transmit(uint8_t data);


/*LEE UN BYTE POR EL PIN TX*/
/*
	RETURN : byte recivido
*/
uint8_t UART_Receive(void);


/*TRANSMITE N BYTES*/
/*
	
*/

void UART_SendData(uint8_t *pData, uint16_t Size);

#endif /* USART_AVR_H_ */