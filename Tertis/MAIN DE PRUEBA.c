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
#include "all_static.h"
#include "linedelete.h"
#include "scored.h"
#include "init_piece.h"
#include "init_mat.h"
#include "Pieza.h"
#include "copy_piece_to_mat.h"
#include "check_fall.h"
#include "fall.h"

#define GREEN   "\x1b[32m"
#define BLUE    "\x1b[34m"
#define COLOR_RESET   "\x1b[0m"

void printmat(PIECE matrix [TABLE_FIL][TABLE_COL]);

int main(void) {

	PIECE currentpiece;
    
    PIECE piecemat [MAT_PIECE_FIL][MAT_PIECE_COL];

    PIECE pieces[PIECE_TOTAL]; //Arreglo de todas las piezas
    
    PIECE matrix[TABLE_FIL][TABLE_COL]; //Matriz en donde se situan las piezas
    
   

    tetrisInit(pieces, matrix); //Aca se inicializan las piezas y la matriz.

    currentpiece = init_piece();

    init_mat(piecemat);

  	fill_mat_piece(piecemat, currentpiece);

    if(can_i_copy(matrix)){
    	printf("si\n");
    	copy_piece_to_mat(matrix, piecemat);
    }

    printmat(matrix);

    while(check_fall(matrix)){
    	fall(matrix);
    	printmat(matrix);
    }

    all_static(matrix);
    printmat(matrix);

    /////////////////////////////

    currentpiece = init_piece();

    init_mat(piecemat);

  	fill_mat_piece(piecemat, currentpiece);

    if(can_i_copy(matrix)){
    	printf("si\n");
    	copy_piece_to_mat(matrix, piecemat);
    }

    printmat(matrix);

    while(check_fall(matrix)){
    	fall(matrix);
    	printmat(matrix);
    }

    all_static(matrix);
    printmat(matrix);
}

void printmat(PIECE matrix [TABLE_FIL][TABLE_COL]){
	int i, j;
	for(i = 0; i < TABLE_FIL; i++){
		printf("\n");
		for(j = 0; j < TABLE_COL; j++){
			if(matrix[i][j].state == CAYENDO)
				printf(GREEN"%d "COLOR_RESET, matrix[i][j].type);
			else
				printf(BLUE"%d "COLOR_RESET, matrix[i][j].type);
		}
	}
	printf("\n\n");
}


