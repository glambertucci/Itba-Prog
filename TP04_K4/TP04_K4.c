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
#define TIME 214483687
#define MIN_INPUT 1
#define INPUT_ENTER 1
#define NOT_ENTER 0
#define BASE_NUM 10
#define INPUT_ERR 0

void printMatrix(char mat[HEIGHT][WIDTH]);
//Printea una matriz

void delay (void);
//Pierde el tiempo

void welcomeMsg (char matrix[HEIGHT][WIDTH]);
//Esta función imprime un mensaje de bienvenida

void nextGen(char[HEIGHT][WIDTH], char[HEIGHT][WIDTH]);
//Toma una matriz con una determinada generacion y la modifica acorde a las reglas del juego para avanzar una generacion.
//Toma en consideracion que el cuadrado externo siempre son celulas externas.

int cellStatus(int, int, char [HEIGHT][WIDTH]);
//Se fija si la celula definida por valor de fila y columna estara viva o muerta EN LA PROXIMA GENERACION.

void transferMat(char [HEIGHT][WIDTH], char [HEIGHT][WIDTH]);
//En orden por argumento: transfiere los contenidos de la primera matriz a la segunda..

int readNumber(); 
//readNumber: lee un entero de la entrada estandar (teclado), devuelve el numero 
//ingresado en formato decimal.

int cellFate(int nalive, int status);
//Esta función decide, en función de los vecinos de la celda, si esta se mantiene, o muere.

int main(void)
{
				/////////////////////////////////////////////
				int num;
				char matrix[HEIGHT][WIDTH] = {
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
				{' ',' ','*','*','*','*',' ', ' ',' ', ' '},
				{' ',' ','*',' ',' ',' ',' ', ' ',' ', ' '},
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
				{' ',' ','*',' ',' ',' ',' ', ' ',' ', ' '},
				{' ',' ',' ','*','*','*',' ', '*','*', ' '},
				{' ',' ',' ',' ',' ','*',' ', '*','*', ' '},
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
				};

					char auxmatrix[HEIGHT][WIDTH] = {
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
				};
				// Se define auxmatrix con la finalidad de evitar que los bordes, los cuales no se modifican, contengan basura.


	welcomeMsg(matrix);

	while ( (num = readNumber()) > INPUT_ERR)	//Mientras que el numero ingresado sea mayor a 0..
	{					//Si se recibe un enter, eso es igual a un 1
		while (num>=MIN_INPUT)	//Hasta que el numero deje de ser mayor o igual a 1..
		{
			nextGen(matrix, auxmatrix);		//Calcula proxima generacion
			printMatrix(matrix);	//La imprime
			--num;		
		}
	}

	printf("Terminando programa..\n\n"); //Al recibir algo menor o igual a un 0 se acaba el programa
	return 0;	
}

void nextGen(char matrix[HEIGHT][WIDTH], char auxmatrix[HEIGHT][WIDTH])
{

	int m=1, n=1;
	int cellstate;

	for(m = 1; m <= ((HEIGHT)-(OUTERMATRIXCORRECTION)); m++) //Ignorando la primera fila, hasta la cantidad total de filas menos dos.
	{
		for(n = 1; n <= ((WIDTH)-(OUTERMATRIXCORRECTION)); n++) //Ignorando la primera columna, hasta la cantidad totales de columnas menos dos.
		{
			cellstate=cellStatus(m, n, matrix); //Se fija si la fila m columna n va a estar viva o muerta
			if (cellstate == DEAD)	    	//Lo escribo en una matrix auxiliar, para no perturbar
				auxmatrix[m][n] = DEAD; 	//el analisis siguiente. 
			else
				auxmatrix[m][n] = ALIVE;

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

void welcomeMsg (char matrix[HEIGHT][WIDTH])
{
	printf("\n\n\n\n\n\nBienvenido al juego de la vida! \n");
	printf("Configuracion: %dx%d \n",HEIGHT,WIDTH);
	printf("\n");

	printMatrix(matrix);

	printf("\n");
	printf("Para avanzar a la siguiente generacion escriba el\n");
	printf("numero de generaciones que desea ver y presione enter.\n\n");
	printf("Si presiona enter se mostrara una sola generacion.\nSi escribe 0 o un numero negativo se terminara el programa.\n");
}

int cellStatus (int m, int n, char matrix[HEIGHT][WIDTH])
{
      char current_cell = 0;
      int neighbour_alive = 0;
      int destiny = 0;
      int i=0;
      int upperrow = m-OFFSET;
      int bottomrow = m+OFFSET;

      current_cell = matrix [m] [n];   //estado actual de la celula, Dead o Alive
      
      for(i=(n - OFFSET); i<=(n + OFFSET); i++)	//analizo el estado de las 3 celulas superiores a la actual:
      {
            if (matrix[upperrow][n] == ALIVE)   //diagonal superior izquierda, superior y superior derecha.
            	neighbour_alive++;

            n++;
      }

      for(i=(n - OFFSET); i<=(n + OFFSET); i++)	//analizo el estado de las 3 celulas inferiore a la actual:
      {
            if (matrix[bottomrow][n] == ALIVE)  //diagonal inferior izquierda, inferior e inferior derecha.
            	neighbour_alive++;

            n++;
      }
    

      if(matrix[m][n-OFFSET] == ALIVE) //analizo el estado de la celula laterale izquierda a la actual.
            neighbour_alive++;

      if(matrix[m][n+OFFSET] == ALIVE) //analizo el estado de la celula lateral derecha a la actual.
            neighbour_alive++;
/*
	if (matrix [m-OFFSET] [n-OFFSET] == ALIVE)	//analizo la celula diagonal superior izquierda
		neighbour_alive++;
	
	if (matrix [m-OFFSET] [n] == ALIVE)	//analizo la celula superior central
		neighbour_alive++;
	
	if (matrix [m-OFFSET] [n+OFFSET] == ALIVE)	//analizo la celula diagonal superior derecha 
		neighbour_alive++;
	
	if (matrix [m] [n-OFFSET] == ALIVE)	//analizo la celula izquierda
		neighbour_alive++;
	
	if (matrix [m] [n+OFFSET] == ALIVE)	//analizo la celula derecha
		neighbour_alive++;
	
	if (matrix [m+OFFSET] [n-OFFSET] == ALIVE)	//analizo la celula diagonal inferior izquierda
		neighbour_alive++;
	
	if (matrix [m+OFFSET] [n] == ALIVE)	//analizo la celula inferior central
		neighbour_alive++;
	
	if (matrix [m+OFFSET] [n+OFFSET] == ALIVE)	//analizo la celula diagonal inferior derecha
		neighbour_alive++;
	*/
	
      destiny = cellFate (neighbour_alive, current_cell);

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
	int fate;           //Esta variable contiene al destino de la celula analizada en función de la cantidad de vecinos 
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

void printMatrix(char mat[HEIGHT][WIDTH])
{
	int i, j;
	printf("\n");
	for (i = 0;i < WIDTH;i++){
		for (j = 0;j < HEIGHT;j++){
			printf("|%c",mat[i][j]);
		}
		printf("|\n");
	}
	printf ("\n");
}

void delay (void)
{
	int a, b, i, j;

	a=b=i=j=TIME;
	while(a)	//perdiendo el tiempo
	{
		for(j=TIME;j>0;j--);
		while(b)
		{
			for (i=TIME;i>0;i--);
			b--;
			b++;
			b--;
		}
		a--;
	}
}
