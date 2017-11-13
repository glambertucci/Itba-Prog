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

#include "general.h"
#include "tetrisInit.h"
#include "checkMove.h"
#include "move.h"

int main(void) {
    
    PIECE pieces[PIECE_TOTAL]; //Arreglo de todas las piezas
    
    PIECE matrix[TABLE_FIL][TABLE_COL]; //Matriz en donde se situan las piezas
    
    tetrisInit(pieces, matrix); //Aca se inicializan las piezas y la matriz.
    
    
    /*    
    for(i=0;i<TABLE_FIL;i++) {
    	printf("\n\n");
    	for(j=0;j<TABLE_COL;j++) {
    		printf("%d-%d", matrix[i][j].state, matrix[i][j].type);
    	}
    }
    */
    
}

