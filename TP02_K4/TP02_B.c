//TP PRACTICO N°2. Bloques de control
/*Fecha de creacion 23/8/2017
Grupo 4
Integrantes:
Lambertucci Guido	58009
Hrubisiuk 	Agustin	58311
Mechoulam	Alan	58438
Moriconi	Franco	58495
Este programa imprimirá una matriz de n x m (fil, col). Imprimira en pantalla
una matriz de números crecientes de izquierda a derecha y de arriba hacia abajo
*/
#include <stdio.h>
#define FILAS 5
#define COLUMNAS 5							//define que se usa para asignar las variables

int main (void)
{
	unsigned int fil=FILAS,col=COLUMNAS;	//no signado asi ahorro el problema de numeros negativos
	int aux_col,aux_cont=0;					//variables usadas para imprimir en pantalla
	int screen;								//numero que ira a pantalla
	
	if ((col>25) || (fil>25))
	{
		printf("El numero de fila o columna es muy grande\n");
	}

	else while (fil--)
	{	
		aux_col=col;
		screen=aux_cont++;
		while(aux_col--)					//contador para aumentar el numero de fila a fila
		{
			printf("%d\t",screen++);		//imprime las columnas luego las filas, usa un 
					
		}
		printf("\n");
	}
	return 0;
}