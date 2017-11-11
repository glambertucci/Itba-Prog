#include "general.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void tetrisInit (PIECE pieces[PIECE_TOTAL], PIECE matrix[MATRIX_WIDTH][MATRIX_HEIGHT]) 
{
    uint8_t i, j;
    
    //Inicializamos las piezas
    for(i = 0; i < 8; i++) {
        (pieces + i)->type = i;
        if(i = 7) //Pieza "cemento"
            (pieces + i)->state = 1;
        else
            (pieces + i)->state = 0;
    }
    
    //Inicializamos la matriz
    for(i = 0; i < MATRIX_HEIGHT; i++) {
        for(j = 0; j < MATRIX_WIDTH; j++) {
            (matrix[i][j])->type = 0;
            (matrix[i][j])->state = 0;
        }
    }
    
    //Incializamos la seed
    srand(time(NULL));

}
    


