#include "linedelete.h"
#include "scored.h"
#include "all_static.h"
#include "check_fall.h"
#include "fall.h"

void calculateLines(PIECE matrix[TABLE_FIL][TABLE_COL]) {
    
    uint8_t i, score;
    
    
    for(i = TABLE_FIL-3; i >= 2; i--) {
        if(matrix[i][2].type == SCORED) {
            deleteLine(matrix, i);
            score++;
        }
    }
    
    add_score(score);
}


void deleteLine(PIECE matrix[TABLE_FIL][TABLE_COL], uint8_t fila) {
    
    uint8_t i, j;
    
    for(i = 2; i < TABLE_COL-2; i++) {
        matrix[fila][j].type = BLANK; //Pongo en blanco la linea, el pivote no importa
    }                                 //y ya van a estar estaticos.

    for(i = fila; i >= 2; i++) {
        for(j = 2; j < TABLE_COL-2; j++) {
            matrix[i][j].state = CAYENDO;
        }
    }
    
    while(check_fall(matrix)){
        fall(matrix);
    }
    
    all_static(matrix);

}