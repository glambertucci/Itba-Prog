#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    
    PIECE pieces[PIECE_TOTAL]; //Arreglo de todas las piezas
    
    PIECE matrix[TABLE_FIL][TABLE_COL]; //Matriz en donde se situan las piezas
    
    tetrisInit(pieces, matrix); //Aca se inicializan las piezas y la matriz.
    
    
}

