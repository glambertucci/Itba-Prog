#include "tetrisInit.h"
void tetrisInit (PIECE matrix[TABLE_FIL][TABLE_COL], PIECE piece_matrix[MAT_PIECE_FIL][MAT_PIECE_COL], GAME_UTILS* gamevars) 
{
    uint8_t i, j;
    
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
    }
    
    //Incializamos la seed
    srand(time(NULL));
    
    //Inicializamos la siguiente pieza
    gamevars->currentpiece = init_piece();
    
    //Inicializamos la matriz de cada pieza
    init_mat(piece_matrix);
    
    //Llenamos la matriz de la pieza
    fill_mat_piece(piece_matrix, gamevars->currentpiece);
}
    


