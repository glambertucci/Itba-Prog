/*
	comentarios: la union esta global con static y las funciones acceden a la union sin referencia por ser global, me
	parece bien asi, nos joderan por usar variables globales? o sea estoy emulando un objeto como nos dijo jacobi..

	todas las llamadas a funcion se deben de hacer con tipo de dato uint16_t y todos los datos que devuelven lasfucnines
	son detipo de dato uint32_t y el codigo de error que devuelven es el numero 66666.

	POR ALGUNA RAZON DA ERROR LOS TYPEDEF AL COMPILAR, NO SE POR UQE
*/

#include <stdio.h>
#include <stdint.h>
#include "PuertoD.h"

typedef struct {uint16_t portD;} full16_t;

typedef struct {uint8_t portA; uint8_t portB;} twobytes_t;

typedef struct
{
	uint16_t b0 :1;
	uint16_t b1 :1;
	uint16_t b2 :1;
	uint16_t b3 :1;
	uint16_t b4 :1; 
	uint16_t b5 :1;
	uint16_t b6 :1;
	uint16_t b7 :1;
	uint16_t b8 :1;
	uint16_t b9 :1;
	uint16_t b10 :1;
	uint16_t b11 :1;
	uint16_t b12 :1;
	uint16_t b13 :1;
	uint16_t b14 :1;
	uint16_t b15 :1;		

}bit16_t;


static union
{
	full16_t Mainport;
	twobytes_t Subport;
	bit16_t Bits;

}EMULATEDPORT;

uint32_t getPortValue(uint16_t portID) //Devuelve un uint32, porque si fuera un uint16 no dejaria margen para un buen
{									//sistema de errores. En este caso, si se da un error en la funcion, el valor retornado
	uint32_t returnValue;			//sera ERR_CODE (66666), valor imposible para un puerto de 16bits. Esto es asi en todas las
									//funciones, no sera repetido.
	switch(portID)
	{
		case PORTA: returnValue = (uint32_t) EMULATEDPORT.Subport.portA; break;
		case PORTB: returnValue = (uint32_t) EMULATEDPORT.Subport.portB; break;
		case PORTD:	returnValue = (uint32_t) EMULATEDPORT.Mainport.portD; break;
		default: returnValue = ERR_CODE;
	}

	if(((portID == PORTA)&&(returnValue > UINT8_MAX)) || ((portID == PORTB)&&(returnValue > UINT8_MAX)) || ((portID == PORTD)&&(returnValue > UINT16_MAX)))
		returnValue = ERR_CODE; //Validacion extensiva
	else
		returnValue = 0;

	return returnValue;
}

uint32_t getBitValue(uint16_t bitID)
{
	uint32_t returnValue;

	switch(bitID)
	{
		case B0: returnValue = (uint32_t) EMULATEDPORT.Bits.b0; break;
		case B1: returnValue = (uint32_t) EMULATEDPORT.Bits.b1; break;
		case B2: returnValue = (uint32_t) EMULATEDPORT.Bits.b2; break;
		case B3: returnValue = (uint32_t) EMULATEDPORT.Bits.b3; break;
		case B4: returnValue = (uint32_t) EMULATEDPORT.Bits.b4; break;
		case B5: returnValue = (uint32_t) EMULATEDPORT.Bits.b5; break;
		case B6: returnValue = (uint32_t) EMULATEDPORT.Bits.b6; break;
		case B7: returnValue = (uint32_t) EMULATEDPORT.Bits.b7; break;
		case B8: returnValue = (uint32_t) EMULATEDPORT.Bits.b8; break;
		case B9: returnValue = (uint32_t) EMULATEDPORT.Bits.b9; break;
		case B10: returnValue = (uint32_t) EMULATEDPORT.Bits.b10; break;
		case B11: returnValue = (uint32_t) EMULATEDPORT.Bits.b11; break;
		case B12: returnValue = (uint32_t) EMULATEDPORT.Bits.b12; break;
		case B13: returnValue = (uint32_t) EMULATEDPORT.Bits.b13; break;
		case B14: returnValue = (uint32_t) EMULATEDPORT.Bits.b14; break;
		case B15: returnValue = (uint32_t) EMULATEDPORT.Bits.b15; break;
		default: returnValue = ERR_CODE;
	}

	if((returnValue != ERR_CODE)||(returnValue != 1)||(returnValue != 0))
		returnValue = ERR_CODE; //Validacion extensiva
	else
		returnValue = 0;
	
	return returnValue;
}

uint32_t setPortValue (uint16_t portID, uint16_t value)
{
	uint32_t returnValue;

	if((((portID == PORTA)&&(value > UINT8_MAX)) || ((portID == PORTB)&&(value > UINT8_MAX)) || ((portID == PORTD)&&(value > UINT16_MAX))))
		returnValue = ERR_CODE; //Validacion extensiva
	else
	{
		switch(portID)
		{
			case PORTA: EMULATEDPORT.Subport.portA = (uint8_t) value; returnValue = 0; break;
			case PORTB: EMULATEDPORT.Subport.portB = (uint8_t) value; returnValue = 0; break;
			case PORTD: EMULATEDPORT.Mainport.portD = value; returnValue = 0; break;
			default: returnValue = ERR_CODE;
		}

	}

	return returnValue;
}

uint32_t setBitValue (uint16_t bitID, uint16_t value)
{
	uint32_t returnValue;

	if((value != 0) || (value != 1))
		returnValue = ERR_CODE;	//Validacion extensiva
	else
	{
		switch(bitID)
		{
			case B0: EMULATEDPORT.Bits.b0 = value; returnValue = 0; break;
			case B1: EMULATEDPORT.Bits.b1 = value; returnValue = 0; break;
			case B2: EMULATEDPORT.Bits.b2 = value; returnValue = 0; break;
			case B3: EMULATEDPORT.Bits.b3 = value; returnValue = 0; break;
			case B4: EMULATEDPORT.Bits.b4 = value; returnValue = 0; break;
			case B5: EMULATEDPORT.Bits.b5 = value; returnValue = 0; break;
			case B6: EMULATEDPORT.Bits.b6 = value; returnValue = 0; break;
			case B7: EMULATEDPORT.Bits.b7 = value; returnValue = 0; break;
			case B8: EMULATEDPORT.Bits.b8 = value; returnValue = 0; break;
			case B9: EMULATEDPORT.Bits.b9 = value; returnValue = 0; break;
			case B10: EMULATEDPORT.Bits.b10 = value; returnValue = 0; break;
			case B11: EMULATEDPORT.Bits.b11 = value; returnValue = 0; break;
			case B12: EMULATEDPORT.Bits.b12 = value; returnValue = 0; break;
			case B13: EMULATEDPORT.Bits.b13 = value; returnValue = 0; break;
			case B14: EMULATEDPORT.Bits.b14 = value; returnValue = 0; break;
			case B15: EMULATEDPORT.Bits.b15 = value; returnValue = 0; break;
			default: returnValue = ERR_CODE;
		}
	}

	return returnValue;
}