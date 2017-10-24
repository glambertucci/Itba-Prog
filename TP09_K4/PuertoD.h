#ifndef PUERTOD_H
#define PUERTOD_H

/*
	Este archivo emula (en una arquitectura big endian) un puerto de 16 bits llamado puerto D
que a su vez contiene al puerto A y B ambos de 8 bits siendo A el high y B el low.
	Solamente se puede acceder a los datos del emulador mediante las funciones provistas. Estas
devuelven siempre un tipo de dato uint32_t, cuyo codigo de error es ERR_CODE (66666), y siempre
reciben un tipo de dato uint16_t. 
	Las funciones son las siguientes:
*/

uint32_t getPortValue (uint16_t);
//getea el valor de tanto el puerto principal (D) como el de uno de los subpuertos (A o B)
//devuelve el valor pedido o codigo de error y recibe de que puerto se desea leer (PORTA, PORTB, PORTD)

uint32_t setPortValue (uint16_t, uint16_t);
//setea el valor (segundo int) en el puerto pedido (primer int)
//devuelve codigo de error

uint32_t getBitValue (uint16_t);
//getea el valor del bit pedido (b0, b1, ..., b14, b15) y devuelve valor pedido o codigo de error.

uint32_t setBitValue (uint16_t, uint16_t);
//setea en valor (segundo int) del bit pedido (primer int) y devuelve codigo de error.

#define ERR_CODE 66666
enum{B0,B1,B2,B3,B4,B5,B6,B7,B8,B9,B10,B11,B12,B13,B14,B15}
enum{PORTA, PORTB, PORTD}

#endif