/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Main.c
 * Author: alan
 *
 * Created on November 10, 2017, 3:11 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    
    PIECE pieces[PIECE_TOTAL]; //Arreglo de todas las piezas
    
    PIECE matrix[MATRIX_WIDTH][MATRIX_HEIGHT]; //Matriz en donde se situan las piezas
    
  //PIECE auxmatrix[MATRIX_WIDTH + 2][MATRIX_HEIGHT + 2]; //Matriz con la cual trabajamos
    
    tetrisInit(pieces, matrix); //Aca se inicializan las piezas y la matriz.
    
    
    
    
    
    
    
}

