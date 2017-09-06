#include <stdio.h>

enum {DEAD, ALIVE}

#define HEIGHT 10
#define WIDTH 10
#define OUTERMATRIXCORRECTION 2

void nextGen(int[HEIGHT][WIDTH]);
//Toma una matriz con una determinada generacion y la modifica acorde a las reglas del juego para avanzar una generacion.
//Toma en consideracion que el cuadrado externo siempre son celulas externas.

int cellStatus(int, int, int[HEIGHT][WIDTH]);
//Se fija si la celula definida por valor de fila y columna estara viva o muerta EN LA PROXIMA GENERACION.

void transferMat(int[HEIGHT][WIDTH], int[HEIGHT][WIDTH]);
//En orden por argumento: transfiere los contenidos de la primera matriz a la segunda.

int main(void)
{

		// GUIDO CHAN OMG SEMPAII >W<;

}

void nextGen(int matrix[HEIGHT][WIDTH])
{
	int auxmatrix[HEIGHT][WIDTH];
	int cell, m, n;

	for(m = 1, m < HEIGHT-OUTERMATRIXCORRECTION, m++) //Ignorando la primera fila, hasta la cantidad total de filas menos dos.
	{
		for(n = 1, n < WIDTH-OUTERMATRIXCORRECTION, n++) //Ignorando la primera columna, hasta la cantidad totales de columnas menos dos.
		{
			cellstate=cellStatus(m, n, matrix); //Se fija si la fila m columna n va a estar viva o muerta
			auxmatrix[m][n] = cellstate; //Lo escribo en una matrix auxiliar, para no perturbar
										  //El analisis siguiente. 
		}//columna
	}//fila

	transferMat(auxmatrix, matrix); //Transfiere la matriz auxiliar a la matriz real
}

void transferMat(int copyfrom [HEIGHT][WIDTH], int copyto [HEIGHT][WIDTH])
{
	int m, n;

	for(m = 1, m<HEIGHT, m++) //Aunque el cuadrado exterior siempre sea cero, para reutilizar
	{							//la funcion copia cualquier ancho y cualquier alto.
		for(n = 1, n<WIDTH, n++)  //idem
		{
			copyto[m][n]=copyfrom[m][n];
		}
	}
}