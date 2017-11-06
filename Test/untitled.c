#include <stdio.h>
#define	FILAS1	2
#define	COLUMNAS1	3
#define FILAS2	3
#define	COLUMNAS2	2

void inicializar_matriz(int, int, int, int);	//prototipo
void multi (int, int, int, int, int);

int main (void)

{
	int matrix_datos_1 [FILAS1] [COLUMNAS1] = {{1,2,3},{4,5,6}};		//matrices 														   "dadas en consigna"
	int matrix_datos_2 [FILAS2] [COLUMNAS2] = {{1,2}, {3,4}, {5,6}};

	int matrix1 [FILAS1][COLUMNAS1] = {0};
	int matrix2 [FILAS2] [COLUMNAS2] = {0};
	int mult_matrix [FILAS1][COLUMNAS2] = {0};

	/*int *val_mat_1;
	int *val_mat_2;

	val_mat_1 = matrix_datos_1;
	val_mat_2 = matrix_datos_2;*/

	inicializar_matriz(matrix1, matrix_datos_1, FILAS1, COLUMNAS1);	//PASAR:
																//1) Matriz a trabajar.
																//2) Puntero con valores para la matriz.
																//3) Cantidad de filas de la matriz.
																//4) Cantidad de columnas de la matriz.
	inicializar_matriz(matrix2, matrix_datos_2, FILAS2, COLUMNAS2);

	multi(matrix1, matrix2, mult_matrix, FILAS1, COLUMNAS2);

	for(l=0; l < FILAS1; l++)
	{
		for(p=0; p<COLUMNAS2; p++)
		{
			printf("%d \t"; mult_matrix[l][p]);

		}
	}

	return (0);

}



void inicializar_matriz(int *matriz_posta[][], int *matriz_consigna, int filss, int colss)
{
	int i;
	int n;

	for (i=0; i<filss; i++)
	{
		for (n=0; n<colss; n++)
		{
			matriz_posta[i][n] = matriz_consigna[i][n];
		}
	}

	
}


void multi(int matrix1, int matrix2, int mult_matrix, int filss, int colss)

{
	int h;
	int m;
	int sumterm = COLUMNAS1;
	

	for (h=0; h < filss; h++)
	{
		for (m=0; m < colss; m++)
		{
			for (sumterm = 0; sumterm < COLUMNAS2; sumterm++)
			{
				mult_matrix [h][m] = mult_matrix [h][m] + (matrix1[h][sumterm] * matrix2[sumterm][h]);
			}


		}
	}
	

}

