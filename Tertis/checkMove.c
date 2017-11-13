#include "checkMove.h"

//Si el movimiento es posible devuelve 1.
//Si no es posible devuelve 0.

bool checkMove (PIECE matrix[TABLE_FIL][TABLE_COL], bool dir){
    
    uint8_t i, j, abort = 0;
    
    if(dir == LEFT) { //Si se pide mover a la izquierda o a la derecha      
        for(i = 2; i < TABLE_FIL-2; i++) {//Se recorre la matriz
            for(j = 2; j < TABLE_COL-2; j++) {
                if(matrix[i][j].state == CAYENDO) {//Al encontrar un bloque cayendo
                    if(!((matrix[i][j-1].type == BLANK)||(matrix[i][j-1].state == CAYENDO)))
                        abort++;              //Si a la izquierda no tiene algo que este cayendo
                }                             //o un espacio en blanco, no se puede mover.
            }
        }
    }
   
    else if(dir == RIGHT) { //Idem arriba
        for(i = 2; i < TABLE_FIL-2; i++) {
            for(j = 2; j < TABLE_COL-2; j++) {              
                if(matrix[i][j].state == CAYENDO) {
                    if(!((matrix[i][j+1].type == BLANK)||(matrix[i][j+1].state == CAYENDO)))
                        abort++;                   
                }
            }
        }        
    }

    return abort == 0;
}