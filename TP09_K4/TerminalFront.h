#ifndef TERMINALFRONT_H
#define TERMINALFRONT_H


void printPort(uint8_t *);
//Esta función recibe un puntero a un arreglo a un arreglo de 8 bits e imprime el valor actual de un puerto.

void message(uint8_t);
//Esta función recibe un estado (8 bits) e imprime un mensaje según en qué estado se haya el programa

void blinkFunction(uint8_t * bitarray, uint8_t state);
//Esta función enciende y apaga constantemente los LEDS encendidos que estén conectados a un puerto.

void updateScreen(uint8_t bitArray[8], uint8_t state);
//Esta función recibe un puntero a un arreglo de 8 elementos y un estado, los cuales usa para actualizar la pantalla en función de estos.

#endif
