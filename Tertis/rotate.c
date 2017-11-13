#include "rotate.h"

void rotate(PIECE matrix[TABLE_FIL][TABLE_COL]) {
    
    uint8_t pivot_fil, pivot_col, i, j;
    
    pivot_fil=0;
    pivot_col=0;
    while((matrix[pivot_fil][pivot_col].pivot == false)) {
        pivot_fil++;//Luego del while, las variables pivot_fil y pivot_col
        pivot_col++;//quedaran con la fila y columna indice del pivote
    }

    //Paso siguiente mover cada cuadradito a su lugar correspondiente borrando
    //el original. Esto se hace pensando al pivote como origen con las coordenadas
    //(x,y) a cada cuadradito a mover. (x,y) pasa a ser (y,-x) luego de la rotacion.
    for(i = pivot_fil-2; i < pivot_fil+2; i++){
        for(j = pivot_col-2; j < pivot_col+2; j++){
            if(matrix[i][j].state == CAYENDO){  //En la linea de abajo coloco el cuadradito nuevo
                matrix[(pivot_fil)-(j-pivot_col)][(pivot_col)+(i-pivot_fil)].type = matrix[i][j].type;
                matrix[i][j].type = BLANK;      //Aca borro
                matrix[i][j].state = ESTATICO;  //el original
                }          
            }
        }
}