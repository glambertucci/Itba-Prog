#include "general.h"

bool checkRotate(PIECE matrix[TABLE_FIL][TABLE_COL]) {
    //Rota siempre en sentido horario
    uint8_t pivot_fil, pivot_col, i, j, abort;
    
    for(i = 2; i < TABLE_FIL-2; i++){
        for(j = 2; j < TABLE_COL-2; j++){
            if((matrix[i][j].pivot == true) && (matrix[i][j].state == CAYENDO)){
                pivot_fil = i;
                pivot_col = j; //solamente va a haber UN UNICO pivote cayendo siempre
            }   
        }  // Luego de los for, pivot_fil y pivot_col seran las coordenadas del pivote.
    }
    //Paso siguiente chequear si esta vacio o hay algo cayendo en cada lugar
    //a donde tendria que ir cada cuadradito. Esto se hace de la siguiente forma
    //rotando un punto en el espacio respecto al pivote representado como (x,y)
    //(x,y)->(y,-x).
    for(i = pivot_fil-2; i < pivot_fil+2; i++){
        for(j = pivot_col-2; j < pivot_col+2; j++){
            if(matrix[i][j].state == CAYENDO){
                if(!(matrix[(pivot_fil)+(j-pivot_col)][(pivot_col)-(i-pivot_fil)].type == BLANK)){
                    if(!(matrix[(pivot_fil)+(j-pivot_col)][(pivot_col)-(i-pivot_fil)].state == CAYENDO))
                        abort++;
                }          
            }
        }
    }
    
    return abort == 0;
    
}

