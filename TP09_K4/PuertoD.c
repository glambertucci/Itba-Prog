/*
	LEER EL HEADER PARA INFORMARSE SOBRE LA UTILIZACION DE LOS SERVICIOS PROVISTOS POR EL ARCHIVO.
*/

#include <stdio.h>
#include <stdint.h>
#include "PuertoD.h"
#include "generaldefs.h"

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
		case PORTA: returnValue = (uint32_t) EMULATEDPORT.Subport.portA; break; //Tomaré el valor del puerto que busco y lo devuelvo en el return.
		case PORTB: returnValue = (uint32_t) EMULATEDPORT.Subport.portB; break;
		case PORTD: returnValue = (uint32_t) EMULATEDPORT.Mainport.portD; break;
		default: returnValue = ERR_CODE;
	}

	if(((portID == PORTA)&&(returnValue > UINT8_MAX)) || ((portID == PORTB)&&(returnValue > UINT8_MAX)) || ((portID == PORTD)&&(returnValue > UINT16_MAX)))
		returnValue = ERR_CODE; //Validacion extensiva

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
			case PORTA: EMULATEDPORT.Subport.portA =  value; returnValue = 0; break; //Cambio el valor del puerto por el pasado como parámetro.
			case PORTB: EMULATEDPORT.Subport.portB =  value; returnValue = 0; break;
			case PORTD: EMULATEDPORT.Mainport.portD = value; returnValue = 0; break;
			default: returnValue = ERR_CODE;
		}

	}

	return returnValue;
}

uint32_t bitSet (uint16_t portID, uint16_t bitID)
{
	uint32_t returnValue;
	uint32_t mask = MASK;
	
	if((bitID > MAXBITID) || ((portID < PORTD) && (bitID > MINBITID)))
		returnValue = ERR_CODE;	//Validacion extensiva
	else
	{
		if(portID == PORTD)
		{
			mask = (mask << bitID); //Seteo el '1' de la máscara al lugar del bit objetivo.
			EMULATEDPORT.Mainport.portD = (EMULATEDPORT.Mainport.portD | mask); //Con un OR BITWISE, el bit que quiero modificar se enciende obligatoriamente.
		}
		else
		{	
			mask = (mask << bitID);
			if(portID==PORTA)
			{	
			EMULATEDPORT.Subport.portA = (EMULATEDPORT.Subport.portA | (uint8_t) mask); //Se repite la misma lógica.
			}
			else
			{	
			EMULATEDPORT.Subport.portB = (EMULATEDPORT.Subport.portB | (uint8_t) mask);
			}
		}
		returnValue = ERR_SUCC;
	}
	return returnValue;
}
	   
uint32_t bitClr (uint16_t portID, uint16_t bitID)
{

	uint32_t returnValue;

	uint32_t mask = MASK;
	
	if((bitID > MAXBITID) || ((portID < PORTD) && (bitID > MINBITID)))
		returnValue = ERR_CODE;	//Validacion extensiva
	else
	{
		if(portID == PORTD)
		{
			mask = (mask << bitID); //Seteo el '0' de la mascara al bit correspondiente
			mask = ~mask;
			EMULATEDPORT.Mainport.portD = (EMULATEDPORT.Mainport.portD & mask); //Se modifica unicamente, con un and bitwise, el bit deseado.
		}
		else
		{
			mask = (mask << bitID);
			mask = ~mask;
			if(portID==PORTA)
			{	
			EMULATEDPORT.Subport.portA = (EMULATEDPORT.Subport.portA & (uint8_t) mask); //Se repite la lógica
			}
			else
			{	
			EMULATEDPORT.Subport.portB = (EMULATEDPORT.Subport.portB & (uint8_t) mask);
			}
		}
		returnValue = ERR_SUCC;	
	}
	return returnValue;
}

uint32_t bitToggle (uint16_t portID, uint16_t bitID)
{

	uint32_t returnValue;
	uint32_t bit;
	
	if( ((portID==PORTD)&&(bitID > MAXBITID)) || ((portID < PORTD) && (bitID > MINBITID)))
		returnValue = ERR_CODE;	//Validacion extensiva
	else
	{
		bit = getBitValue(portID,bitID); //Obtengo el valor del bit.
	
		if(bit == 0) //Si es 0, debo encenderlo. Uso bitset para encender ese bit en particular.
		{
			bitSet(portID,bitID);
		}
		else //Si es 1, debo apagarlo. Uso bitclr para apagar ese bit en particular.
		{
			bitClr(portID,bitID);
		}

		returnValue = ERR_SUCC;	
	}
	return returnValue;
}



uint32_t bitGet(uint16_t portID, uint16_t bitID)
{
	uint32_t returnvalue;
	uint32_t mask = MASK;
	
	if(bitID < MAXBITID) //Es Unsigned, por lo que solo debo comprobar que no sea mayor al ID máximo.
	{
		mask = (mask << bitID); //El '1' de la máscara estará en el mismo lugar del bit  que busco para luego hacer un AND  con el puerto y guardar ese valor.

		if(portID == PORTD)
		{
			returnvalue = (EMULATEDPORT.Mainport.portD & mask); //Guardo en el valor de retorno el bit en esa posición.
		}
		else if(portID==PORTA)
		{		
			returnvalue = (EMULATEDPORT.Subport.portA & (uint8_t) mask);
		}
		else
		{	
			returnvalue = (EMULATEDPORT.Subport.portB & (uint8_t) mask);
		}
	}
	else
	{
		returnvalue = ERR_CODE;
	}
	
	return returnvalue;	

}

uint32_t getBitValue(uint16_t portID,uint16_t bitID)
{
	uint32_t returnValue;

	uint32_t mask = (MASK << bitID); //Inicializo la máscara y coloco el '1' en la posición del bit que busco.
	uint32_t tempValue = getPortValue(portID); //Obtengo el valor actual de ese puerto para poder trabajarlo.

	tempValue = (tempValue & mask); //Obtengo el valor actual del bit en esa posición.
	tempValue = !(!tempValue); //Me devolverá 0 o 1, dependiendo si era 0 o un 1 (que al estar desplazado se leería como otro número)
	returnValue = tempValue;
	return returnValue;
}

uint32_t maskOn (uint16_t portID, uint16_t mask)
{
	uint32_t returnValue, tempValue;

	tempValue = getPortValue(portID); //Guardo el valor actual del puerto

	if (tempValue != ERR_CODE)
		returnValue = setPortValue(portID, (tempValue|mask)); //Hago un OR BITWISE para poner en 1 los bits de la máscara sin modificar el resto.

	else
		returnValue = ERR_CODE;

	return returnValue;
}

uint32_t maskOff (uint16_t portID, uint16_t mask)
{
	uint32_t returnValue, tempValue;

	tempValue = getPortValue(portID); //Guardo el valor actual del puerto

	if (tempValue != ERR_CODE)
	{
		returnValue = setPortValue(portID, (tempValue & (~mask))); //Se hace una negación y un AND BITWISE para que, en la máscara, queden en 0 los que se busca apagar y no alterar los que el usuario no pretende modificar, pues estarían en 1.
	}
	else
		returnValue = ERR_CODE;

	return returnValue;
}

uint32_t maskToggle (uint16_t portID, uint16_t mask)
{
	uint32_t returnValue, tempValue;

	tempValue = getPortValue(portID);

	if (tempValue != ERR_CODE)
		returnValue = setPortValue(portID, (tempValue^mask));
	else
		returnValue = ERR_CODE;

	return returnValue;
}
