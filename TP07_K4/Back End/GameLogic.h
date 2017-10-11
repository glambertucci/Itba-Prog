#ifndef GAMELOGIC_H
#define GAMELOGIC_H

/* Este header contiene prototipos de funciones útiles en el contexto particular del juego de la vida.
 * Permiten:
 * - Avanzar una generación
 * - Analizar la cantidad de celulas vecinas vivas.
 * - Evaluar el destino de la célula
 */

void nextGen(char[HEIGHT][WIDTH], char[HEIGHT][WIDTH]);
//Toma una matriz con una determinada generacion y la modifica acorde a las reglas del juego para avanzar una generacion.
//Toma en consideracion que el cuadrado externo siempre son celulas externas.

#endif
