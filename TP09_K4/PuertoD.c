/*

	LEER EL HEADER PARA INFORMARSE SOBRE LA UTILIZACION DE LOS SERVICIOS PROVISTOS POR EL ARCHIVO.

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
		returnValue = EXIT_SUCC;

	return returnValue;
}

uint32_t getBitValue(uint16_t bitID)
{
	uint32_t returnValue;
	
	if(bitID >=16) //El puerto solo posee 16 bits.
	{
		returnvalue = ERR_CODE; //Indico que hubo un error.
	}
	
	else
	{
		returnValue = *((EMULATEDPORT.Bits)+bitID); //La variable del retorno toma el valor del bit que el usuario busca.
	}
	return returnValue;
}	


uint32_t setPortValue (uint16_t portID, uint16_t value)
{
	uint32_t returnValue;

	if((((portID == PORTA)&&(value > UINT8_MAX)) || ((portID == PORTB)&&(value > UINT8_MAX)) || ((portID == PORTD)&&(value > UINT16_MAX))))
		returnValue = ERR_CODE; //Validacion extensiva
	else
	{
		if(portID == PORTD)
		{	
			EMULATEDPORT.Mainport.portD = value; //Seteo el puerto D entero al valor correspondiente.
			returnValue = EXIT_SUCC; //Indico que no hay error.
		}
		else
		{	
			*((EMULATEDPORT.Subport)+portID) = (uint8_t) value; //Seteo el puerto A o B (depende del ID) al valor corresopndiente.
			returnValue = EXIT_SUCC; //Indico que no hay error.
		}
	}

	return returnValue;
}

uint32_t setBitValue (uint16_t bitID, uint16_t value)
{
	uint32_t returnValue;

	if((value != 0) || (value != 1)) //Únicos inputs válidos para un bit.
		returnValue = ERR_CODE;	//Validacion extensiva
	else
	{
		*((EMULATEDPORT.Bits)+bitID) = value; //Me desplazo al bit correspondiente y le asigno el valor deseado
		returnValue = EXIT_SUCC; //Seteo la variable del retorno a 0, para indicar que no hubo error.
	}
	return returnValue;
}
