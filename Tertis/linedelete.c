#include "linedelete.h"

void calculateLines(PIECE matrix[TABLE_FIL][TABLE_COL]) {
    
    uint8_t i, score;
    
    
    for(i = TABLE_FIL-3; i >= 2; i--) {
        if(matrix[i][2].type == SCORE) {
            deleteLine(PIECE matrix[TABLE_FIL][TABLE_COL], i);
            score++;
        }
    }
    
    addScore(score);
}


void deleteLine(PIECE matrix[TABLE_FIL][TABLE_COL], uint8_t fila) {
    
    uint8_t j;
    
    for(j = 2; j < TABLE_COL-2; j++) {
        matrix[fila][j].type = BLANK; //Pongo en blanco la linea, el pivote no importa
    }                                 //y ya van a estar estaticos.

    for( /* */ ; fila >= 2; fila++) {
        for(j = 2; j < TABLE_COL-2; j++) {
            matrix[fila][j].state = CAYENDO;
        }
    }
    
    while(check_fall(matrix))
        fall(matrix);
    
    all_static(matrix);

}