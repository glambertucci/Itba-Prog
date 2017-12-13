#include "general.h"


int check_fall(PIECE tablero [TABLE_FIL][TABLE_COL]) {
 //  static int c=0;//DEBUG

int i,j,abort=OK,count=0;
bool fullstatic = true;

    for (i=2;i<=TABLE_FIL-2;i++) 
    {
        for (j=2;j<=TABLE_COL-2;j++) 
        {                                                       //estos dos ciclos recorren la matriz
            if (tablero[i][j].state == CAYENDO) 
            {   
                fullstatic = false;
                if((tablero [i+1] [j].type != BLANK ) ) 
                {                                          //si no es estatico el de abajo 
                    if ((tablero[i+1][j].state != CAYENDO)) 
                    {
                        abort=NOT_OK;                        
                    }
                }
                
            }
        }
    }

    for (i=2;i<=TABLE_FIL-2;i++) 
    {
        for (j=2;j<=TABLE_COL-2;j++) 
        { 
            if (tablero[i][j].state != CAYENDO)
            {
                count++;
            }
        }
    }

    if (count == PIECENUM)
    {
        abort = NO_NEW;
    }
    
    if(fullstatic)
    {
        abort = NOT_OK;
    }

//printf("Abort vale %d entre %d veces\n",abort,++c );//DEBUG
return abort;
}

bool checkMove (PIECE matrix[TABLE_FIL][TABLE_COL], bool dir) {
    
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
   
    else if(dir == RIGHT) 
    {                                        //Idem arriba
        for(i = 2; i < TABLE_FIL-2; i++) {
            for(j = 2; j < TABLE_COL-2; j++) {              
                if(matrix[i][j].state == CAYENDO) {
                    if(!((matrix[i][j+1].type == BLANK)||(matrix[i][j+1].state == CAYENDO))){
                        abort++;  
                    }
                }
            }
        }        
    }
    
    return abort == 0;
}

bool checkRotate(PIECE matrix[TABLE_FIL][TABLE_COL]) { //Rota siempre en sentido horario

    uint8_t pivot_fil, pivot_col, i, j, abort=0;
    
    
    for(i = 2; i < TABLE_FIL-2; i++){
        for(j = 2; j < TABLE_COL-2; j++){
            if(matrix[i][j].pivot){
                pivot_fil = i;
                pivot_col = j; //solamente va a haber UN UNICO pivote siempre
            }   
        }  // Luego de los for, pivot_fil y pivot_col seran las coordenadas del pivote.
    }
     
    	//Paso siguiente chequear si esta vacio o hay algo cayendo en cada lugar
    	//a donde tendria que ir cada cuadradito. Esto se hace de la siguiente forma
    	//rotando un punto en el espacio respecto al pivote representado como (x,y)
    	//(x,y)->(y,-x).
      
    if((pivot_fil < (TABLE_FIL - 2)) && (pivot_col < (TABLE_COL-2))) { //Condición para no tocar memoria fuera de la matriz.
        for(i = pivot_fil-2; i <= pivot_fil+2; i++){
            for(j = pivot_col-2; j <= pivot_col+2; j++){
                if(matrix[i][j].state == CAYENDO){
                    if(!(matrix[(pivot_fil)+(j-pivot_col)][(pivot_col)-(i-pivot_fil)].type == BLANK)){
                        if(!(matrix[(pivot_fil)+(j-pivot_col)][(pivot_col)-(i-pivot_fil)].state == CAYENDO))
                        abort++;
                    }          
                }
            }
        }
    }
 
    return (!abort);
    
}

bool can_i_copy (PIECE tablero [TABLE_FIL][TABLE_COL]) {

    int i,j,abort=0;

        for (i=2;i<MAT_PIECE_FIL+2;i++) {
            for(j=6;j<MAT_PIECE_COL+6;j++) {
                if (tablero[i][j].type != BLANK) {
                    abort++;
                }
            }
        }
        
    return (!abort);
}

/*
bool checkRotate (PIECE matrix[TABLE_FIL][TABLE_COL]) {
    
    bool abort = 0;
    int i, j, m, n;
    
    for(i = 2; i < TABLE_FIL-2; i++)   {
        for(j = 2; j < TABLE_COL-2; j++) {
            if(matrix[i][j].pivot)         {
                printf("found pivot at (%d,%d)", j, i);
                for(m = i-2; m <= i+2; m++)  {
                    for(n = j-2; n <= j+2; n++){
                        if(matrix[i+(-(n-j))][j+(m-i)].type == CEMENTO) {
                            abort++;
                        }
                    }
                }
            }
        }
    }
    return (!abort);
} */
