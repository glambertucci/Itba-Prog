#ifndef PUERTOD_H
#define PUERTOD_H

/*
	IMPORTANTE: El concepto de este archivo (y consigo por que la union es global y privada al archivo),
es que el usuario no deberia de tener acceso directo a los datos del puerto, sino primero pasando por
una validacion extensiva provista por los servicios que brindan el archivo.
	(IMPORTANTE 2: si quisiera emular mas de un puerto haria la union con un typedef e instanciaria
un arreglo de uniones.)
	
	Este archivo emula (en una arquitectura big endian) un puerto de 16 bits llamado puerto D
que a su vez contiene al puerto A y B ambos de 8 bits siendo A el high y B el low.
	Solamente se puede acceder a los datos del emulador mediante las funciones provistas. Estas
devuelven siempre un tipo de dato uint32_t, cuyo codigo de error es ERR_CODE (66666), y siempre
reciben un tipo de dato uint16_t. 
	
	Las estructuras y uniones usadas son:

		typedef struct {uint16_t portD;} full16_t;

		typedef struct {uint8_t portA; uint8_t portB;} twobytes_t;

		typedef struct
		{
		uint16_t b0 :1;
		uint16_t b1 :1;
		.
		.
		.
		uint16_t b14 :1;
		uint16_t b15 :1;		

		}bit16_t;

		static union
		{
			full16_t Mainport;
			twobytes_t Subport;
			bit16_t Bits;

		}EMULATEDPORT;



Las funciones son las siguientes:
*/

uint32_t getPortValue (uint16_t);
//getea el valor de tanto el puerto principal (D) como el de uno de los subpuertos (A o B)
//devuelve el valor pedido o codigo de error y recibe de que puerto se desea leer (PORTA, PORTB, PORTD)

uint32_t setPortValue (uint16_t, uint16_t);
//setea el valor (segundo int) en el puerto pedido (primer int)
//devuelve codigo de error

uint32_t getBitValue (uint16_t, uint16_t);
//getea el valor del bit pedido (b0, b1, ..., b14, b15) y devuelve valor pedido o codigo de error.

uint32_t bitSet (uint16_t, uint16_t);
//setea en 1 el puerto pedido (primer valor) en un bit en específico (segundo valor) y devuelve codigo de error.

uint32_t bitClear (uint16_t, uint16_t);
//setea en 0 el puerto pedido (primer valor) en un bit en específico (segundo valor) y devuelve codigo de error.

uint32_t bitGet (uint16_t, uint16_t);
//setea en 0 el puerto pedido (primer valor) en un bit en específico (segundo valor) y devuelve codigo de error.

uint32_t bitToggle (uint16_t, uint16_t);
//Recibe la dirección del puerto y el bit que se busca togglear. Si el bit que se buscó es 1, lo transforma en 0 y viceversa.

uint32_t maskOn (uint16_t, uint16_t);

uint32_t maskOff (uint16_t, uint16_t);

uint32_t maskToggle (uint16_t, uint16_t);


#define MASK 0x01    //  Puedo rotarlo bitID veces y usarlo como máscara para modificar el bit deseado.
#define MAXBITID 15
#define MINBITID 7
enum{B0,B1,B2,B3,B4,B5,B6,B7,B8,B9,B10,B11,B12,B13,B14,B15};
enum{PORTA, PORTB, PORTD};

#endif
