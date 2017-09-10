#include <stdio.h>

#define DEAD ' '
#define ALIVE '*'
#define HEIGHT 10
#define WIDTH 10
#define OUTERMATRIXCORRECTION 2
#define OFFSET 1
#define TRUE 1
#define FALSE 0
#define IS_ENTER '\n'
#define BASE_NUM 10
#define TIME 88889999
#define MIN_INPUT 1
#define INPUT_ENTER 1 ??
//#define BASE_NUM 10 ??
#define INPUT_ERR 0 ??

void printMatrix(char mat[M][N]);
//Printea una matriz

void delay (void);
//Pierde el tiempo

void welcomeMsg(void);
//Esta función imprime un mensaje de bienvenida

void nextGen(char[HEIGHT][WIDTH]);
//Toma una matriz con una determinada generacion y la modifica acorde a las reglas del juego para avanzar una generacion.
//Toma en consideracion que el cuadrado externo siempre son celulas externas.

int cellStatus(int, int, int[HEIGHT][WIDTH]);
//Se fija si la celula definida por valor de fila y columna estara viva o muerta EN LA PROXIMA GENERACION.

void transferMat(char[HEIGHT][WIDTH], char[HEIGHT][WIDTH]);
//En orden por argumento: transfiere los contenidos de la primera matriz a la segunda..

int readNumber(); 
//readNumber: lee un entero de la entrada estandar (teclado), devuelve el numero 
//ingresado en formato decimal.

int cellFate(int nalive, int status);
//Esta función decide, en función de los vecinos de la celda, si esta se mantiene, o muere.

int main(void)
{
	int num = 0;
	char matrix[HEIGHT][WIDTH] = {
	{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
	{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
	{' ',' ','*','*','*','*',' ', ' ',' ', ' '},
	{' ',' ','*','*','*',' ',' ', ' ',' ', ' '},
	{' ',' ','*','*','*','*',' ', ' ',' ', ' '},
	{' ',' ','*',' ',' ',' ',' ', ' ',' ', ' '},
	{' ',' ',' ','*','*',' ',' ', ' ',' ', ' '},
	{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
	{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
	{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
	};

/*		char seed_matrix[HEIGHT][WIDTH] = {
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
*/

	welcomeMsg();

	while ( (num = readNumber()) > INPUT_ERR)	//Mientras que el numero ingresado sea mayor a 0..
	{					//Si se recibe un enter, eso es igual a un 1
		while (num>=MIN_INPUT)	//Hasta que el numero deje de ser mayor o igual a 1..
		{
			nextGen(matrix);		//Calcula proxima generacion
			printMatrix(matrix);	//La imprime
			--num;		
		}
	}

	printf("Terminando programa..\n\n"); //Al recibir algo menor o igual a un 0 se acaba el programa
	return 0;	
}

void nextGen(char matrix[HEIGHT][WIDTH])
{
	int auxmatrix[HEIGHT][WIDTH];
	int m, n;
	int cellstate;

	for(m = 1; m < (HEIGHT)-(OUTERMATRIXCORRECTION); m++) //Ignorando la primera fila, hasta la cantidad total de filas menos dos.
	{
		for(n = 1; n < (WIDTH)-(OUTERMATRIXCORRECTION); n++) //Ignorando la primera columna, hasta la cantidad totales de columnas menos dos.
		{
			cellstate=cellStatus(m, n, auxmatrix); //Se fija si la fila m columna n va a estar viva o muerta
			auxmatrix[m][n] = cellstate; //Lo escribo en una matrix auxiliar, para no perturbar
							     //el analisis siguiente. 
		}//columna
	}//fila

	transferMat(auxmatrix, matrix); //Transfiere la matriz auxiliar a la matriz real
}

void transferMat(char copyfrom [HEIGHT][WIDTH], char copyto [HEIGHT][WIDTH])
{
	int m, n;

	for(m = 0; m<HEIGHT; m++) //Aunque el cuadrado exterior siempre sea cero, para reutilizar
	{							//la funcion copia cualquier ancho y cualquier alto.
		for(n = 0; n<WIDTH; n++)  //idem
		{
			copyto[m][n]=copyfrom[m][n];
		}
	}
}

void welcomeMsg (void)
{
	printf("Bienvenido al juego de la vida \n");
	printf("Configuracion: %dx%d \n",HEIGHT,WIDTH);
	printf("\n");

	printMatrix(seed_matrix[HEIGHT][WIDTH]);

	printf("\n");
	printf("Para avanzar a la siguiente generacion\n");
	printf("escriba el numero de generaciones que desea ver y presione enter.\n");
	printf("Si presiona enter se mostrara una sola generacion. Si escribe 0 se terminara el programa.\n");
}

int cellStatus (int row, int column, int matrix [HEIGHT][WIDTH])
{
      int actual_cell;
      int neighbour_alive = 0;
      int destiny;
      int aux_column;


      actual_cell = matrix [row] [column];   //estado actual de la celula, Dead o Alive
      aux_column = column-OFFSET;

      for(matrix [row-OFFSET][aux_column]; aux_column <= column+1; aux_column++) //analizo el estado de las 3 celulas superiores a la actual:
      {
            if (matrix[row-OFFSET][aux_column] == ALIVE)                           //diagonal superior izquierda, superior y
            	neighbour_alive++;                                             //diagonal superior derecha
      }

      aux_column = column-OFFSET;
	for(matrix [row+OFFSET][aux_column]; aux_column <= column+1; aux_column++) //analizo el estado de las 3 celulas inferiores a la actual:
	{
		if (matrix[row+OFFSET][aux_column] == ALIVE)                           //diagonal inferior izquierda, inferior y
	            neighbour_alive++;                                             //diagonal inferior derecha
	}

      aux_column = 0;

      if(matrix[row][column-OFFSET] == ALIVE) //analizo el estado de la celula laterale izquierda a la actual.
            neighbour_alive++;

      if(matrix[row][column+OFFSET] == ALIVE) //analizo el estado de la celula lateral derecha a la actual.
            neighbour_alive++;

      destiny = cellFate (neighbour_alive,actual_cell);

	return destiny;

}

int readNumber(){
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

int cellFate(int nalive, int status)
{
    int fate = 0;           //Esta variable contiene al destino de la celula analizada en función de la cantidad de vecinos 
    switch(nalive)
    {				         //Que se decide con este break
        		case 2:             //Se evalúa solo el 2 y el 3 ya que cualquier otro caso implica la muerte.
                	{	
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
    }
    return fate;
}

void printMatrix(char mat[M][N])
{
	int i, j;
	printf("\n");
	for (i = 0;i < N;i++){
		for (j = 0;j < M;j++){
			printf("|%c",mat[i][j]);
		}
		printf("|\n");
	}
	printf ("\n");
}

void delay (void)
{
	int a, b;

	a=b=TIME;
	while(a)	//perdiendo el timepo
	{
		while(b)
		{
			b--;
		}
		a--;
	}
}