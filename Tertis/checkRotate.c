#include "general.h"

bool checkRotate(PIECE matrix[TABLE_FIL][TABLE_COL]) {
    //Rota siempre en sentido horario
    uint8_t pivot_fil, pivot_col, i, j, abort;
    
    pivot_fil=0;
    pivot_col=0;
    while((matrix[pivot_fil][pivot_col].pivot == false)||(matrix[pivot_fil][pivot_col].state = ESTATICO)) {
        pivot_fil++;//Luego del while, las variables pivot_fil y pivot_col
        pivot_col++;//quedaran con la fila y columna indice del pivote
    }
    //Paso siguiente chequear si esta vacio o hay algo cayendo en cada lugar
    //a donde tendria que ir cada cuadradito. Esto se hace de la siguiente forma
    //rotando un punto en el espacio respecto al pivote representado como (x,y)
    //(x,y)->(y,-x).
    for(i = pivot_fil-2; i < pivot_fil+2; i++){
        for(j = pivot_col-2; j < pivot_col+2; j++){
            if(matrix[i][j].state == CAYENDO){
                if(!(matrix[(pivot_fil)-(j-pivot_col)][(pivot_col)+(i-pivot_fil)].type == BLANK)){
                    if(!(matrix[(pivot_fil)-(j-pivot_col)][(pivot_col)+(i-pivot_fil)].state == CAYENDO))
                        abort++;
                }          
            }
        }
    }
    
    return abort == 0;
    
}

