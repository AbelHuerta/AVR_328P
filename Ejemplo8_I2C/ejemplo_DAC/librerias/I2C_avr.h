/*
 * I2C_avr.h
 *
 * Created: 4/06/2022 16:11:50
 *  Author: abelh
 */ 


#ifndef I2C_AVR_H_
#define I2C_AVR_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdint.h>
#include <stdio.h>

#define  I2C_WRITE 0x00
#define  I2C_READ  0x01
#define  F_SCL	   100000UL
#define  Preescaler	1UL
#define  Bit_Rate()	((((F_CPU/F_SCL)/Preescaler)-16UL)/2UL)


#define MT_SLA_ACK		0x18
#define MR_SLA_ACK		0x40
#define MT_DATA_ACK		0x28
#define MR_DATA_ACK		0x50
#define MR_DATA_NACK	0x58

//INICIALIZA EL PERIFERICO I2C
void I2C_AVR_Init(void);

//INICIALIZA LA COMUNICACION
uint8_t I2C_AVR_START(void);

//DIRECCIONAMIENTO AL ESCLAVO (DIRECCION , W/R)
uint8_t I2C_AVR_ADDREES_SLAVE(uint8_t Addres, uint8_t modo);

//
uint8_t I2C_AVR_Write_Data(uint8_t data);

//LEER DATA
uint8_t I2C_AVR_Read_Data(uint8_t *ptr_dato,uint8_t ack_nack);

//FINALIZA LA COMUNICACION
void I2C_AVR_Stop(void);

#endif /* I2C_AVR_H_ */