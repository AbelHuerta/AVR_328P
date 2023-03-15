/*
 * I2C_avr.c
 *
 * Created: 4/06/2022 16:11:42
 *  Author: abelh
 */ 

#include "I2C_avr.h"

void I2C_AVR_Init(void){
	
	//PREESCALADOR 1:1
	TWSR &= ~(1<<TWPS0) & ~(1<<TWPS1);
	
	//BIT RATE
	TWBR = (uint8_t)Bit_Rate();	//100KHz
}


uint8_t I2C_AVR_START(void){
	uint8_t status;
	
	//INICIALIZA LA CONDICION DEL BIT START
	TWCR |= (1<<TWEN)|(1<<TWSTA)|(1<<TWINT);
	
	//ESPERAMOS QUE SE ENVIE EL START
	while((TWCR & (1<<TWINT))==0);
	
	status = (TWSR & 0xF8);
	
	if((status == 0x08)||(status == 0x10)){
		
		return 1; //OPERACION EXITOSA
	}
	return status; //OPERACION INCORRECTA
}


uint8_t I2C_AVR_ADDREES_SLAVE(uint8_t Addres, uint8_t modo){
	uint8_t status = 0;
	
	//ENVIO ADDRESS
	TWDR = ((Addres & 0xFE) | (modo & 0x01));
	
	//INICIA LA TRANSMISION
	TWCR = (1<<TWEN)|(1<<TWINT);
	
	//ESPERAMOS EL ENVIO DE DATOS
	while ((TWCR & (1<<TWINT))== 0);
	
	status = (TWSR & 0xF8);
	
	if((status == MT_SLA_ACK)||(status == MR_SLA_ACK)){
		
		return 1; //OPERACION EXITOSA
	}
	return status; //
}


uint8_t I2C_AVR_Write_Data(uint8_t data){
	uint8_t status = 0;
	
	//ESCRIBIMOS EL DATO A TX
	TWDR = data;
	
	//INICIA LA TRANSMISION
	TWCR = (1<<TWEN)|(1<<TWINT);
	
	while ((TWCR & (1<<TWINT))== 0); //ESPERAMOS
	
	status = (TWSR & 0xF8);
	
	if((status == MT_DATA_ACK)){
		
		return 1; //OPERACION EXITOSA
	}
	return status; //
}


uint8_t I2C_AVR_Read_Data(uint8_t *ptr_dato,uint8_t ack_nack){
	uint8_t status;
	
	return 1;
}


void I2C_AVR_Stop(void){
	TWCR |= (1<<TWEN)|(1<<TWSTO)|(1<<TWINT);
	//ESPERAMOS QUE SE COMPLETE EL STOP
	while((TWCR & (1<<TWSTO))==0);
}