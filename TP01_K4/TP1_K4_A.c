//TP PRACTICO N°1. Constantes, variables y operadores
/*Fecha de creacion 16/8/2017
Grupo 4
Integrantes:
Lambertucci Guido	58009
Hrubisiuk 	Agustin	58311
Mechoulam	Alan	58438
Moriconi	Franco	58495
Este programa simula el puerto A del HC11, debera imprimir un 1 si los bits
0 y 5 estan prendidos o cuando los bits 3 y 4 lo esten, caso contrario 0.
*/

#include <stdio.h>
#define bits1y5 0x21		//0x21 = 0010 0001 bits 0 y 5 encendidos 
#define bits3y4 0x18		//0x18 = 0001 1000 bits 3 y 4 encendidos


int main (void)
{
	int portA=35;

	printf("%d\n",((portA & bits1y5)==bits1y5)||((portA&bits3y4)== bits3y4));
//si el puerto a tiene los leds encendidos de la mascara imprimira 1 sino 0 
return 0;
}