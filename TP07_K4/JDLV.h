#ifndef JDLV_H
#define JDLV_H

#include <stdio.h>
#include "general.h"


/* Este header contiene prototipos de funciones útiles en el contexto particular del juego de la vida.
 * Permiten:
 * - Avanzar una generación
 * - Analizar la cantidad de celulas vecinas vivas.
 * - Evaluar el destino de la célula
 */

void nextGen(char[HEIGHT][WIDTH], char[HEIGHT][WIDTH]);
//Toma una matriz con una determinada generacion y la modifica acorde a las reglas del juego para avanzar una generacion.
//Toma en consideracion que el cuadrado externo siempre son celulas externas.

int cellStatus(int, int, char [HEIGHT][WIDTH]);
//Se fija si la celula definida por valor de fila y columna estara viva o muerta EN LA PROXIMA GENERACION.

int cellFate(int nalive, int status);
//Esta función decide, en función de los vecinos de la celda, si esta se mantiene, o muere.

void welcomeMsg (char matrix[HEIGHT][WIDTH]);
//Esta función imprime un mensaje de bienvenida y muestra el estado inicial de una matriz

#define OUTERMATRIXCORRECTION 2
#define OFFSET 1
#define TIME 8000000
#define MIN_INPUT 1


#endif
