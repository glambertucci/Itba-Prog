#include "rotate.h"

void rotate(PIECE matrix[TABLE_FIL][TABLE_COL]) {
    
    uint8_t pivot_fil, pivot_col, i, j;
    
    for(i = 2; i < TABLE_FIL-2; i++){
        for(j = 2; j < TABLE_COL-2; j++){
            if((matrix[i][j].pivot == true) && (matrix[i][j].state == CAYENDO)){
                pivot_fil = i;
                pivot_col = j; //solamente va a haber UN UNICO pivote cayendo siempre
            }   
        }  // Luego de los for, pivot_fil y pivot_col seran las coordenadas del pivote.
    }

    //Paso siguiente mover cada cuadradito a su lugar correspondiente borrando
    //el original. Esto se hace pensando al pivote como origen con las coordenadas
    //(x,y) a cada cuadradito a mover. (x,y) pasa a ser (y,-x) luego de la rotacion.
    for(i = pivot_fil-2; i < pivot_fil+2; i++){
        for(j = pivot_col-2; j < pivot_col+2; j++){
            if(matrix[i][j].state == CAYENDO){  //En la linea de abajo coloco el cuadradito nuevo
                matrix[(pivot_fil)-(j-pivot_col)][(pivot_col)+(i-pivot_fil)].type = matrix[i][j].type;
                if(!(pivot_fil == i && pivot_col == j)){
                    matrix[i][j].type = BLANK;      //Aca borro
                    matrix[i][j].state = ESTATICO;  //el original
                }
            }          
        }
    }
}