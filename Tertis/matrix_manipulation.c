#include "general.h"
#include "matrix_manipulation.h"
#include "matrix_validation.h"
#include "scored.h"
#include "front_allegro.h"

/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////MANEJO DE TABLERO/////
/////////////////////////////////////////////////////////////////////////////////////////

void all_static (PIECE tablero [TABLE_FIL][TABLE_COL]) {

    int i,j;

    for (i = 2; i < TABLE_FIL-2; i++)
    {
        for (j = 2; j < TABLE_COL-2; j++)
        {
            tablero[i][j].state=ESTATICO;
            tablero[i][j].pivot=false;
        } 
    }
}

void fall(PIECE matrix[TABLE_FIL][TABLE_COL]) {
    
    uint8_t i, j;
    
    for(i = TABLE_FIL-2; i >= 2; i--) 
    {
        for(j = TABLE_COL-2; j >= 1; j--) 
        {
            if(matrix[i][j].state == CAYENDO) {

                        //Copio data al espacio de abajo
                matrix[i+1][j].state = matrix[i][j].state;
                matrix[i+1][j].type = matrix[i][j].type;
                matrix[i+1][j].pivot = matrix[i][j].pivot;
                        //Borro la data del espacio original
                matrix[i][j].state = CAYENDO;
                matrix[i][j].type = BLANK;
                matrix[i][j].pivot = false;
            }
        }
    }
}

void fall_instant(PIECE matrix[TABLE_FIL][TABLE_COL]){
    
    while(check_fall(matrix)){
        fall(matrix);
        all_static(matrix);
    }
    
}

void move(PIECE matrix[TABLE_FIL][TABLE_COL], bool dir ) {
    
    uint8_t i, j;
    
    switch(dir) {

    	case LEFT:
	    	for(i = 2; i < TABLE_FIL-2; i++) { //Recorro las filas
	            for(j = 2; j < TABLE_COL-2; j++) { //Recorro las columnas, izq a der 
	                if((matrix[i][j].state == CAYENDO)) { //Si encuentro algo cayendo
	                    matrix[i][j-1].state = matrix[i][j].state; //Copio data al bloque
	                    matrix[i][j-1].type = matrix[i][j].type; //de la izquierda
                            matrix[i][j-1].pivot = matrix[i][j].pivot;
	                    matrix[i][j].state = ESTATICO; //y borro la data
	                    matrix[i][j].type = BLANK; //del original
                            matrix[i][j].pivot = false;
	                    
	                }
	            }
	        }
	    	break;

	    case RIGHT:
		   	for(i = 2; i < TABLE_FIL-2; i++) { //Recorro las filas
	            for(j = TABLE_COL-3; j >= 2; j--) { //Recorro las columnas, der a izq 
	                if((matrix[i][j].state == CAYENDO)) { //Si encuentro algo cayendo
	                    matrix[i][j+1].state = matrix[i][j].state; //Copio data al bloque
	                    matrix[i][j+1].type = matrix[i][j].type; //de la izquierda
                            matrix[i][j+1].pivot = matrix[i][j].pivot;
	                    matrix[i][j].state = ESTATICO; //y borro la data
	                    matrix[i][j].type = BLANK; //del original
                            matrix[i][j].pivot = false;
	                    
	                }
	            }
	        }
        	break;
    }
}

void rotate(PIECE matrix[TABLE_FIL][TABLE_COL]) {
    
    uint8_t pivot_fil, pivot_col, i, j, k=0, temp_type;
    uint8_t temp_fil[4], temp_col[4];
    
    for(i = 2; i < TABLE_FIL-2; i++){
        for(j = 2; j < TABLE_COL-2; j++){
            if(matrix[i][j].pivot){
                temp_type = matrix[i][j].type;
                pivot_fil = i;
                pivot_col = j; //solamente va a haber UN UNICO pivote cayendo siempre
            }   
        }  // Luego de los for, pivot_fil y pivot_col seran las coordenadas del pivote.
    }

    //Paso siguiente mover cada cuadradito a su lugar correspondiente borrando
    //el original. Esto se hace pensando al pivote como origen con las coordenadas
    //(x,y) a cada cuadradito a mover. (x,y) pasa a ser (y,-x) luego de la rotacion.
    for(i = pivot_fil-2; i <= pivot_fil+2; i++)
    {
        for(j = pivot_col-2; j <= pivot_col+2; j++)
        {
            if((matrix[i][j].state == CAYENDO) && (matrix[i][j].type == temp_type))
            {  //En la linea de abajo coloco el cuadradito nuevo
                *(temp_fil + k) = ((pivot_fil)+(j-pivot_col));
                *(temp_col + k) = ((pivot_col)-(i-pivot_fil));
                
                matrix[i][j].type = BLANK;      //Aca borro
                matrix[i][j].state = ESTATICO;  //el original
                k++;
            }
        }          
    }               
    for(i = 0; i < 4; i++)
    {     //Aca escribo en la matriz las nuevas posiciones.
        matrix[*(temp_fil + i)][*(temp_col + i)].type = temp_type;
        matrix[*(temp_fil + i)][*(temp_col + i)].state = CAYENDO;
    }
}

void calculate_lines(PIECE matrix[TABLE_FIL][TABLE_COL])
{
    
    uint8_t i, score;
    
    for(i = TABLE_FIL-2; i >= 2; i--) 
    {
        if(matrix[i][0].type == SCORED) 
        {
            delete_line(matrix, i);
          //  printf("lines scored to delete %d ",i);//DEBUG
            score++;
            printf("score %d\n",score);//DEBUG
        }
    }
    //printf("vivi hasta aca\n");//DEBUG
    add_score(score);
}


void delete_line(PIECE matrix[TABLE_FIL][TABLE_COL], uint8_t fila) {
    
    uint8_t i, j,abort=false;
    

    for(i = 2; i < fila; i++) 
    {
        for(j = 2; j < TABLE_COL-2; j++) 
        {
            matrix[i][j].state = CAYENDO;        
        }
    }
    for(j = 2; j < TABLE_COL-2; j++) 
    {
        matrix[fila][j].type = BLANK; //Pongo en blanco la linea, el pivote no importa
        matrix[fila][j].state=ESTATICO;//y en estatico
    }                                 //y ya van a estar estaticos.
  //  printf("POr entrar a al punto critico\n");//DEBUG
    while(!abort)
    {
        if (check_fall(matrix))
        {
        fall(matrix); 
     //   printf("entré\n");//DEBUG

        }
        else 
        {
            abort=true;
    //        printf("no entre\n");//DEBUG
        }
    }
   
        
    all_static(matrix);



}

///////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////MANEJO DE MATRIZ DE PIEZA NUEVA////
///////////////////////////////////////////////////////////////////////////////////////////

void copy_piece_to_mat (PIECE tablero [TABLE_FIL][TABLE_COL],PIECE next_piece_mat [MAT_PIECE_FIL][MAT_PIECE_COL]) {

    int i,j;

    for (i=0;i<MAT_PIECE_FIL;i++) {

        for(j=0;j<MAT_PIECE_COL;j++) {

            tablero[i+2][j+6].type = next_piece_mat[i][j].type;
            tablero[i+2][j+6].state = next_piece_mat[i][j].state;
            tablero[i+2][j+6].pivot = next_piece_mat[i][j].pivot;
        }
    }
}

void clean_piece_mat (PIECE mat [MAT_PIECE_FIL][MAT_PIECE_COL]){
    int i, j;
    for(i = 0; i < MAT_PIECE_FIL; i++){
        for(j = 0; j < MAT_PIECE_COL; j++){
            mat[i][j].type = BLANK;
            mat[i][j].state = ESTATICO;
            mat[i][j].pivot = false;
        }
    }
}

void fill_mat_piece (PIECE next_piece_mat [MAT_PIECE_FIL][MAT_PIECE_COL], PIECE pieza) { 

    switch(pieza.type) {
        
        case STICK:
            next_piece_mat[0][1].type=STICK;
            next_piece_mat[0][1].state=CAYENDO;
            next_piece_mat[0][1].pivot=false;
            next_piece_mat[1][1].type=STICK;
            next_piece_mat[1][1].state=CAYENDO;
            next_piece_mat[1][1].pivot=false;
            next_piece_mat[2][1].type=STICK;
            next_piece_mat[2][1].state=CAYENDO;
            next_piece_mat[2][1].pivot=true;
            next_piece_mat[3][1].type=STICK;
            next_piece_mat[3][1].state=CAYENDO;
            next_piece_mat[3][1].pivot=false;
            break;
            
        case EL:
            next_piece_mat[1][1].type=EL;
            next_piece_mat[1][1].state=CAYENDO;
            next_piece_mat[1][1].pivot=false;
            next_piece_mat[2][1].type=EL;
            next_piece_mat[2][1].state=CAYENDO;
            next_piece_mat[2][1].pivot=false;
            next_piece_mat[3][1].type=EL;
            next_piece_mat[3][1].state=CAYENDO;
            next_piece_mat[3][1].pivot=true;
            next_piece_mat[3][2].type=EL;
            next_piece_mat[3][2].state=CAYENDO;
            next_piece_mat[3][2].pivot=false;
            break;
            
        case JEY:
            next_piece_mat[1][1].type=JEY;
            next_piece_mat[1][1].state=CAYENDO;
            next_piece_mat[1][1].pivot=false;
            next_piece_mat[2][1].type=JEY;
            next_piece_mat[2][1].state=CAYENDO;
            next_piece_mat[2][1].pivot=false;
            next_piece_mat[3][1].type=JEY;
            next_piece_mat[3][1].state=CAYENDO;
            next_piece_mat[3][1].pivot=true;
            next_piece_mat[3][0].type=JEY;
            next_piece_mat[3][0].state=CAYENDO;
            next_piece_mat[3][0].pivot=false;
            break;
            
        case BLOCK:
            next_piece_mat[2][0].type=BLOCK;
            next_piece_mat[2][0].state=CAYENDO;
            next_piece_mat[2][0].pivot=false;
            next_piece_mat[2][1].type=BLOCK;
            next_piece_mat[2][1].state=CAYENDO;
            next_piece_mat[2][1].pivot=false;
            next_piece_mat[3][1].type=BLOCK;
            next_piece_mat[3][1].state=CAYENDO;
            next_piece_mat[3][1].pivot=false;
            next_piece_mat[3][0].type=BLOCK;
            next_piece_mat[3][0].pivot=true;
            next_piece_mat[3][0].state=CAYENDO;
            break;
            
        case ES:
            next_piece_mat[2][1].type=ES;
            next_piece_mat[2][1].state=CAYENDO;
            next_piece_mat[2][1].pivot=false;
            next_piece_mat[2][2].type=ES;
            next_piece_mat[2][2].state=CAYENDO;
            next_piece_mat[2][2].pivot=false;
            next_piece_mat[3][1].type=ES;
            next_piece_mat[3][1].state=CAYENDO;
            next_piece_mat[3][1].pivot=true;
            next_piece_mat[3][0].type=ES;
            next_piece_mat[3][0].state=CAYENDO;
            next_piece_mat[3][0].pivot=false;
            break;
            
        case ZED:
            next_piece_mat[2][1].type=ZED;
            next_piece_mat[2][1].state=CAYENDO;
            next_piece_mat[2][1].pivot=false;
            next_piece_mat[2][0].type=ZED;
            next_piece_mat[2][0].state=CAYENDO;
            next_piece_mat[2][0].pivot=false;
            next_piece_mat[3][1].type=ZED;
            next_piece_mat[3][1].state=CAYENDO;
            next_piece_mat[3][1].pivot=true;
            next_piece_mat[3][2].type=ZED;
            next_piece_mat[3][2].state=CAYENDO;
            next_piece_mat[3][2].pivot=false;
            break;
            
        case TEE:
            next_piece_mat[3][2].type=TEE;
            next_piece_mat[3][2].state=CAYENDO;
            next_piece_mat[3][2].pivot=false;       
            next_piece_mat[2][1].type=TEE;
            next_piece_mat[2][1].state=CAYENDO;
            next_piece_mat[2][1].pivot=false;            
            next_piece_mat[3][1].type=TEE;
            next_piece_mat[3][1].state=CAYENDO;
            next_piece_mat[3][1].pivot=true;
            next_piece_mat[3][0].type=TEE;
            next_piece_mat[3][0].state=CAYENDO;
            next_piece_mat[3][0].pivot=false;
            break;
    }
}

/*
void rotate (PIECE matrix[TABLE_FIL][TABLE_COL]) {
    
    int i, j, m, n, k = 0;
    int pivot_fil, pivot_col;
    int new_x_pos[4];
    int new_y_pos[4];
    
    //BUSCO PIVOTE
    for(i = 2; i < TABLE_FIL-2; i++)   {
        for(j = 2; j < TABLE_COL-2; j++) {
            if(matrix[i][j].pivot)         {
                printf("found pivot at (%d,%d)", j, i);
                pivot_fil = i;
                pivot_col = j;
                for(m = i-2; m <= i+2; m++)  {
                    for(n = j-2; n <= j+2; n++){
                        if((matrix[m][n].type == matrix[i][j].type) && (matrix[m][n].state == CAYENDO) && (!(matrix[m][n].pivot))) {
                            new_x_pos[k] = m-i;
                            new_y_pos[k] = -(n-j);
                            k++;
                            matrix[m][n].type = BLANK;
                            matrix[m][n].state = ESTATICO;
                        }
                    }
                }
            }
        }
    }
    for(k = 0; k < 4; k++){
                matrix[i+new_y_pos[k]][j+new_x_pos[k]].type = matrix[pivot_fil][pivot_col].type;
                matrix[i+new_y_pos[k]][j+new_x_pos[k]].state = CAYENDO;
    }
} */