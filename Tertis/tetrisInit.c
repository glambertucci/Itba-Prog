#include "general.h"
#include "tetrisInit.h"

void tetrisInit (PIECE pieces[PIECE_TOTAL], PIECE matrix[MATRIX_WIDTH][MATRIX_HEIGHT]) 
{
    uint8_t i, j;
    
    //Inicializamos las piezas
    for(i = 0; i < 8; i++) {
        (pieces + i)->type = i;
        if((i = 7)) //Pieza "cemento"
            (pieces + i)->state = 1;
        else
            (pieces + i)->state = 0;
    }
    
    //Inicializamos la matriz
    for(i = 0; i < MATRIX_HEIGHT; i++) {
        for(j = 0; j < MATRIX_WIDTH; j++) {
            if(i<2||i>=TABLE_FIL-2||j<2||j>=TABLE_COL-2){
        	(matrix[i][j]).type = CEMENTO;
       		(matrix[i][j]).state = ESTATICO;
            }
            else {
            	(matrix[i][j]).type = BLANK;
            	(matrix[i][j]).state = ESTATICO;
            }
        }
    }
    
    //Incializamos la seed
    srand(time(NULL));

}
    


