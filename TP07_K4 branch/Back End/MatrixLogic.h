#ifndef MATRIXLOGIC_H
#define MATRIXLOGIC_H

#include "Definitions.h"
#include <stdio.h>

/*
 * Este header contiene prototipos de funciones que trabajan con matrices en general.
 * Funciones incluidas:
 * - Inicializar una matriz con algún valor en particular en todas sus celdas.
 * - Imprimir un mensaje y una matriz.
 * - Copiar una matriz a otra (No verifica que los tamaños coincidan).
 */ 

void initMatrix (char mat1[HEIGHT][WIDTH]);
//Inicializa la matriz en 0

void transferMat(char [HEIGHT][WIDTH], char [HEIGHT][WIDTH]);
//En orden por argumento: transfiere los contenidos de la primera matriz a la segunda.

#endif