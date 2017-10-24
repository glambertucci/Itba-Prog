/*
	comentarios: la union esta global con static y las funciones acceden a la union sin referencia por ser global, me
	parece bien asi, nos joderan por usar variables globales? o sea estoy emulando un objeto como nos dijo jacobi..

	todas las llamadas a funcion se deben de hacer con tipo de dato uint16_t y todos los datos que devuelven lasfucnines
	son detipo de dato uint32_t y el codigo de error que devuelven es el numero 66666.
*/

// PAL JEDER!!!
/*
		#define ERR_CODE 66666
		enum(PORTA, PORTB, PORT D)
		enum(b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15)
*/


#include <stdint.h>

typedef struct 
{
	uint16_t portD;
}word_t;

typedef struct 
{
	uint8_t portA;
	uint8_t portB;

}twobytes_t;

typedef struct
{
	uint16_t :1 b0;
	uint16_t :1 b1;
	uint16_t :1 b2;
	uint16_t :1 b3;
	uint16_t :1 b4;
	uint16_t :1 b5;
	uint16_t :1 b6;
	uint16_t :1 b7;
	uint16_t :1 b8;
	uint16_t :1 b9;
	uint16_t :1 b10;
	uint16_t :1 b11;
	uint16_t :1 b12;
	uint16_t :1 b13;
	uint16_t :1 b14;
	uint16_t :1 b15;		

}bit16_t;


static union EMULATEDPORT
{
	word_t		Mainport;
	byte2_t		Subport;
	bit16_t		Bits;

}

uint32_t getPortValue(int16_t portID) //Devuelve un uint32, porque si fuera un uint16 no dejaria margen para un buen
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

	if(((portID == PORTA)&&(returnValue > 255)) || ((portID == PORTB)&&(returnValue > 255)) || ((portID == PORTD)&&(returnValue > 65535)))
		returnValue = ERR_CODE; //Validacion extensiva

	return returnValue;
}

uint32_t getBitValue(uint16_t bitID)
{
	uint32_t returnValue;

	switch(bitID)
	{
		case b0: returnValue = (uint32_t) EMULATEDPORT.Bits.b0; break;
		case b1: returnValue = (uint32_t) EMULATEDPORT.Bits.b1; break;
		case b2: returnValue = (uint32_t) EMULATEDPORT.Bits.b2; break;
		case b3: returnValue = (uint32_t) EMULATEDPORT.Bits.b3; break;
		case b4: returnValue = (uint32_t) EMULATEDPORT.Bits.b4; break;
		case b5: returnValue = (uint32_t) EMULATEDPORT.Bits.b5; break;
		case b6: returnValue = (uint32_t) EMULATEDPORT.Bits.b6; break;
		case b7: returnValue = (uint32_t) EMULATEDPORT.Bits.b7; break;
		case b8: returnValue = (uint32_t) EMULATEDPORT.Bits.b8; break;
		case b9: returnValue = (uint32_t) EMULATEDPORT.Bits.b9; break;
		case b10: returnValue = (uint32_t) EMULATEDPORT.Bits.b10; break;
		case b11: returnValue = (uint32_t) EMULATEDPORT.Bits.b11; break;
		case b12: returnValue = (uint32_t) EMULATEDPORT.Bits.b12; break;
		case b13: returnValue = (uint32_t) EMULATEDPORT.Bits.b13; break;
		case b14: returnValue = (uint32_t) EMULATEDPORT.Bits.b14; break;
		case b15: returnValue = (uint32_t) EMULATEDPORT.Bits.b15; break;
		default: returnValue = ERR_CODE;
	}

	if((returnValue != ERR_CODE)||(returnValue != 1)||(returnValue != 0))
		returnValue = ERR_CODE; //Validacion extensiva
	
	return returnValue;
}

uint32_t setPortValue (uint16_t portID, uint16_t value)
{
	uint32_t returnValue;

	if((((portID == PORTA)&&(value > 255)) || ((portID == PORTB)&&(value > 255)) || ((portID == PORTD)&&(value > 65535))))
		returnValue = ERR_CODE; //Validacion extensiva
	else
	{
		switch(portID)
		{
			case PORTA: EMULATEDPORT.Subport.portA = (uint8_t) value; break;
			case PORTB: EMULATEDPORT.Subport.portB = (uint8_t) value; break;
			case PORTD: EMULATEDPORT.Mainport.portD = value; break;
			default: returnValue = ERR_CODE;
		}

	}

	return returnValue;
}

uint32_t setBitValue (uint16_t bitID, uint16_t value)
{
	uint32_t returnValue;

	if((value != 0) || (value != 1))
		returnValue = ERR_CODE	//Validacion extensiva
	else
	{
		switch(bitID)
		{
			case b0: EMULATEDPORT.Bits.b0 = value; break;
			case b1: EMULATEDPORT.Bits.b1 = value; break;
			case b2: EMULATEDPORT.Bits.b2 = value; break;
			case b3: EMULATEDPORT.Bits.b3 = value; break;
			case b4: EMULATEDPORT.Bits.b4 = value; break;
			case b5: EMULATEDPORT.Bits.b5 = value; break;
			case b6: EMULATEDPORT.Bits.b6 = value; break;
			case b7: EMULATEDPORT.Bits.b7 = value; break;
			case b8: EMULATEDPORT.Bits.b8 = value; break;
			case b9: EMULATEDPORT.Bits.b9 = value; break;
			case b10: EMULATEDPORT.Bits.b10 = value; break;
			case b11: EMULATEDPORT.Bits.b11 = value; break;
			case b12: EMULATEDPORT.Bits.b12 = value; break;
			case b13: EMULATEDPORT.Bits.b13 = value; break;
			case b14: EMULATEDPORT.Bits.b14 = value; break;
			case b15: EMULATEDPORT.Bits.b15 = value; break;
			default: returnValue = ERR_CODE;
		}
	}

	return returnValue;
}