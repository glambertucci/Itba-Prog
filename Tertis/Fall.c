#include "general.h"

void Fall(PIECE matrix[TABLE_FIL][TABLE_COL]) {
    
    uint8_t i, j;
    
    for(i = TABLE_FIL; i = 0; i--) {
        for(j = TABLE_COL; j = 0; j--) {
            if(matrix[i][j].state = CAYENDO) {
                        //Copio data al espacio de abajo
                matrix[i+1][j].state = matrix[i][j].state;
                matrix[i+1][j].type = matrix[i][j].type;
                        //Borro la data del espacio original
                matrix[i][j].state = ESTATICO;
                matrix[i][j].type = BLANK;
            }
        }
    }
}