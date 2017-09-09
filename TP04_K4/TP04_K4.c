#include <stdio.h>

#define DEAD 0
#define ALIVE 1
#define HEIGHT 10
#define WIDTH 10
#define OUTERMATRIXCORRECTION 2
#define OFFSET 1
#define TRUE 1
#define FALSE 0
#define IS_ENTER '\n'
#define BASE_NUM 10

void welcomeMsg(void);
//Esta función imprime un mensaje de bienvenida

void nextGen(char[HEIGHT][WIDTH]);
//Toma una matriz con una determinada generacion y la modifica acorde a las reglas del juego para avanzar una generacion.
//Toma en consideracion que el cuadrado externo siempre son celulas externas.

int cellStatus(int, int, int[HEIGHT][WIDTH]);
//Se fija si la celula definida por valor de fila y columna estara viva o muerta EN LA PROXIMA GENERACION.

void transferMat(char[HEIGHT][WIDTH], char[HEIGHT][WIDTH]);
//En orden por argumento: transfiere los contenidos de la primera matriz a la segunda..

int leer_numero(); 
/* leer_numero: lee un entero de la entrada estandar (teclado), devuelve el numero 
   ingresado en formato decimal. */

int cell_fate(int nalive, int status);
//Esta función decide, en función de los vecinos de la celda, si esta se mantiene, o muere.

int main(void)
{
	int num = 0;
	char seed_matrix[HEIGHT][WIDTH];


	char real_matrix[HEIGHT][WIDTH] = {
	{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
	{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
	{' ',' ',' ','*',' ',' ',' ', ' ',' ', ' '},
	{' ',' ','*',' ','*',' ',' ', ' ',' ', ' '},
	{' ',' ','*',' ','*',' ',' ', ' ',' ', ' '},
	{' ',' ',' ','*','*',' ',' ', ' ',' ', ' '},
	{' ',' ','*',' ',' ',' ',' ', ' ',' ', ' '},
	{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
	{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
	{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
	};

	transferMat(real_matrix, seed_matrix);
	welcomeMsg();
	num = leer_numero();	

	while(num >= 0)
	{
	nextGen(seed_matrix);
	transferMat(seed_matrix, real_matrix);
	--num;
	}
	
	return 0;	

}

void nextGen(char matrix[HEIGHT][WIDTH])
{
	int auxmatrix[HEIGHT][WIDTH];
	int cell, m, n;	
	int cellstate;

	for(m = 1; m < HEIGHT-OUTERMATRIXCORRECTION; ++m) //Ignorando la primera fila, hasta la cantidad total de filas menos dos.
	{
		for(n = 1; n < WIDTH-OUTERMATRIXCORRECTION; ++n) //Ignorando la primera columna, hasta la cantidad totales de columnas menos dos.
		{
			cellstate=cellStatus(m, n, auxmatrix); //Se fija si la fila m columna n va a estar viva o muerta
			auxmatrix[m][n] = cellstate; //Lo escribo en una matrix auxiliar, para no perturbar
										  //El analisis siguiente. 
		}//columna
	}//fila

	transferMat(auxmatrix, matrix); //Transfiere la matriz auxiliar a la matriz real
}

void transferMat(char copyfrom [HEIGHT][WIDTH], char copyto [HEIGHT][WIDTH])
{
	int m, n;

	for(m = 1; m<HEIGHT; m++) //Aunque el cuadrado exterior siempre sea cero, para reutilizar
	{							//la funcion copia cualquier ancho y cualquier alto.
		for(n = 1; n<WIDTH; n++)  //idem
		{
			copyto[m][n]=copyfrom[m][n];
		}
	}
}

void welcomeMsg (void)
{
	printf("Bienvenido al juego de la vida \n");
	printf("Configuracion: %dx%d \n",HEIGHT,WIDTH);
	printf("-------------------- \n");
	printf("\n");
	printf("para avanzar a la siguiente generacion\n");
	printf("toque cualquier tecla\n");
}

int CellStatus (int fila, int column, int matrix [HEIGHT][WIDTH])
    {
        int Actual_Cell;
        int Neighbour_Alive = 0;
        int destiny;
        int aux_column = column-OFFSET;


        Actual_Cell = matrix [fila] [column];   //estado actual de la celula, Dead o Alive

        for(matrix [fila-OFFSET][aux_column]; aux_column <= column+1; aux_column ++) //analizo el estado de las 3 celulas superiores a la actual:
            {if (matrix[fila-OFFSET][aux_column] == ALIVE)                           //diagonal superior izquierda, superior y
                Neighbour_Alive++;                                             //diagonal superior derecha
            }
       aux_column = 0;

        if(matrix[fila][column-OFFSET] == ALIVE) //analizo el estado de la celula laterale izquierda a la actual.
                Neighbour_Alive++;


        if(matrix[fila][column+OFFSET] == ALIVE) //analizo el estado de la celula lateral derecha a la actual.
                Neighbour_Alive++;


        for(matrix [fila+OFFSET][aux_column]; aux_column <= column+1; aux_column ++) //analizo el estado de las 3 celulas inferiores a la actual:
            {if (matrix[fila+OFFSET][aux_column] == ALIVE)                           //diagonal inferior izquierda, inferior y
                Neighbour_Alive++;                                             //diagonal inferior derecha
            }

        destiny = cell_fate (Neighbour_Alive,Actual_Cell);

    return destiny;

    }

int leer_numero(){
	int ans = 0; // En el caso de que el usuario solo presione enter
	int abort = FALSE;
	int f_enter = IS_ENTER; // Flag para controlar si el usuario solo escribe enter

	char c;
	while ( (c = getchar()) != '\n'){
		if (c >= '0' && c <= '9'){
			ans *= BASE_NUM; // En este caso la base numerica es 10
			ans += (c - '0');
		}else{
			abort = TRUE; // Seguiremos iterando para vaciar el buffer
		}
		f_enter = NOT_ENTER;
	} 
	if (abort == TRUE){
		ans = INPUT_ERR;
	}
	if (f_enter == IS_ENTER){
		ans = INPUT_ENTER;
	}
	return ans;
}

int cell_fate(int nalive, int status)
{
    int fate = 0;           //Esta variable contiene al destino de la celula analizada en función de la cantidad de vecinos 
    switch(nalive){         //Que se decide con este break
        		case 2:             //Se evalúa solo el 2 y el 3 ya que cualquier otro caso implica la muerte.
                		if(status == ALIVE)
                		{
                   			fate = ALIVE;
                    			break;
                		}
                		else
                		{
                    			fate = DEAD;
                    			break;
                		}
        			case 3:
				{
                			fate = ALIVE; 
                			break;
				}
        			default:
				{
                			fate = DEAD;
                			break;
				}
    };
    return fate;
}

