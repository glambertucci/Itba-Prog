#include "move.h"

//Mueve la pieza hacia la derecha o izquierda en el tablero

void move(PIECE matrix[TABLE_FIL][TABLE_COL], bool dir ) {
    
    uint8_t i, j;
    
    if(dir == LEFT) {
        for(i = 2; i < TABLE_FIL-2; i++) { //Recorro las filas
            for(j = 2; j < TABLE_COL-2; j++) { //Recorro las columnas, izq a der 
                if((matrix[i][j].state == CAYENDO)) { //Si encuentro algo cayendo
                    matrix[i][j-1].state = matrix[i][j].state; //Copio data al bloque
                    matrix[i][j-1].type = matrix[i][j].type; //de la izquierda
                    matrix[i][j].state = ESTATICO; //y borro la data
                    matrix[i][j].type = BLANK; //del original
                    
                }
            }
        }
    }
    
    if(dir == RIGHT) {
        for(i = 2; i < TABLE_FIL-2; i++) { //Recorro las filas
            for(j = TABLE_COL-3; j >= 2; j--) { //Recorro las columnas, der a izq 
                if((matrix[i][j].state == CAYENDO)) { //Si encuentro algo cayendo
                    matrix[i][j+1].state = matrix[i][j].state; //Copio data al bloque
                    matrix[i][j+1].type = matrix[i][j].type; //de la izquierda
                    matrix[i][j].state = ESTATICO; //y borro la data
                    matrix[i][j].type = BLANK; //del original
                    
                }
            }
        }
    }
    
}