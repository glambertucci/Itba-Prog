#include "general.h"

void tetrisInit (PIECE pieces[PIECE_TOTAL], PIECE matrix[TABLE_FIL][TABLE_COL]) 
{
    uint8_t i, j;
    
    //Inicializamos las piezas
    for(i = 0; i < 8; i++) {
        (pieces + i)->type = i;
        if(i == 7 || i == 0) //Pieza "cemento"
            (pieces + i)->state = ESTATICO;
        else
            (pieces + i)->state = CAYENDO;
    }
    
    //Inicializamos la matriz
    for(i = 0; i < TABLE_FIL; i++) {
        for(j = 0; j < TABLE_COL; j++) {
        	if(i<2||i>=TABLE_FIL-2||j<2||j>=TABLE_COL-2){
        		(matrix[i][j]).type = CEMENTO;
        		(matrix[i][j]).state = ESTATICO;
        	}
        	else {
            	(matrix[i][j]).type = BLANK;
            	(matrix[i][j]).state = ESTATICO;
        	}
        }
    
    //Incializamos la seed
    srand(time(NULL));

}
    


