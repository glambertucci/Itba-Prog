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
Nota 1: El programa no acepta numeros negativos para fila o columna
Nota 2: El programa tiene un maximo definido de columnas y filas 
*/
#include <stdio.h>
#define FILAS 10
#define COLUMNAS 10							
#define MAX_COL 25							
#define MAX_FIL 25						
#define INVALIDO 0 

int main (void)
{
	unsigned int fil=FILAS,col=COLUMNAS;			//no signado asi ahorro el problema de numeros negativos
	int aux_col,aux_cont=0;							//aux col varia columna aux cont varia numero inicia por fila
	int screen;										//numero que ira a pantalla
	
	if ((col>MAX_COL) || (fil>MAX_FIL))
	{
		printf("El numero de fila o columna es muy grande\n");
	}
	else if ((col==INVALIDO)||(fil==INVALIDO))
	{
		printf("Matrices de 0 filas o columnas no son validas\n");
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
