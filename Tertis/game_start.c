#include "general.h"
#include "game_start.h"
#include "matrix_manipulation.h"
#include "misc_functions.h"

void game_start (PIECE matrix[TABLE_FIL][TABLE_COL], PIECE piece_matrix[MAT_PIECE_FIL][MAT_PIECE_COL], GAME_UTILS* gamevars) 
{
    uint8_t i, j;
    
    //Inicializamos la matriz
    for(i = 0; i < TABLE_FIL; i++) {
        for(j = 0; j < TABLE_COL; j++) {
            matrix[i][j].pivot = false;
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
    next_piece(gamevars);
    
    //Inicializamos la matriz de cada pieza
    init_mat(piece_matrix);
    
    //Llenamos la matriz de la pieza
    fill_mat_piece(piece_matrix, gamevars->currentpiece);
    
    if(gamevars->restart){ //Si se presionó START/reiniciar, se espera que se inicie el juego.
        gamevars->quit = FALSE;                 //y se copia la primera pieza al tablero.
        gamevars->state= PLAYING;               //Si no se cumple es porque es el primer inicio del juego
        gamevars->restart = false;              //y debo quedarme en el menu.
        gamevars->is_not_first_time = false;
    }

    else {  
        gamevars->state = MENU;
    }
    
} 

void init_mat (PIECE next_piece_mat [MAT_PIECE_FIL][MAT_PIECE_COL])
{
    int i,j;
    for (i=0;i<MAT_PIECE_FIL;i++)
    {
        for (j=0;j<MAT_PIECE_COL;j++)
        {
            next_piece_mat[i][j].state=ESTATICO;
            next_piece_mat[i][j].type=BLANK;
        } 
    }
}
