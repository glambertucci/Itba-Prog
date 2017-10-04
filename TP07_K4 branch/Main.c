//Trabajo Práctico n°4  
/*Fecha de Creación: 08/09/2017
Grupo 4
Integrantes:
Lambertucci Guido	58009
Hrubisiuk 	Agustin	58311
Mechoulam	Alan	58438
Moriconi	Franco	58495


 El Juego de la Vida
Este programa muestra una matriz en pantalla que contiene células "vivas" y "muertas".
Las mismas bajo ciertas condiciones sobreviven, mueren o reviven.
Criterio a tener en cuenta: Se toma una matriz de tamaño nxn pero que de la cual 
realmente se mostrará (n-2)x(n-2). Esto a nivel de programación se realiza para que 
la función encargada de realizar el chequeo de los estados de las células colindantes 
no haga la verificación de estado con memoria basura o celulas no colindantes en los "bordes" de la matriz. 
Este programa tiene hardcodeado las celulas vivas del juego. Estas pueden ser modificadas,
 eliminadas o agregadas al mapa inicial, siempre y cuando respete la dimensión de la matriz escogida.
  Dicha función solo inicializa la primer matriz del juego.
En caso de querer finalizar toque ESC y enter, un enter avanza de generacion y si ingresa un numero avanza las generaciones ingresadas 
*/
#include <stdio.h>
#include "matrix.h"
#include "GameOfLife.h"
#include "keyboard.h"

#define DEAD ' '
#define ALIVE '*'



int main(void)
{
				/////////////////////////////////////////////
				int num;
				char matrix[HEIGHT][WIDTH] = {
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
				{' ',' ','*','*','*','*',' ', ' ',' ', ' '},
				{' ',' ','*','*',' ',' ',' ', ' ',' ', ' '},
				{' ',' ','*','*','*','*',' ', ' ',' ', ' '},
				{' ',' ','*','*','*','*',' ', ' ',' ', ' '}, //SEED MATRIX
				{' ',' ',' ',' ','*','*',' ', ' ',' ', ' '},
				{' ',' ','*',' ',' ',' ',' ', ' ',' ', ' '},
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' '},
				};
					char auxmatrix[HEIGHT][WIDTH];
				/////////////////////////////////////////////

	initMatrix(auxmatrix );
				// Se inicializa  auxmatrix con la finalidad de evitar que los bordes, los cuales no se modifican, contengan basura.
	printMatrix(auxmatrix);

	welcomeMsg(matrix);

	while ( (num = readNumber()) > INPUT_ERR)	//Mientras que el numero ingresado sea mayor a 0..
	{					//Si se recibe un enter, eso es igual a un 1
		while (num-->=MIN_INPUT)	//Hasta que el numero deje de ser mayor o igual a 1..
		{
			nextGen(matrix, auxmatrix);		//Calcula proxima generacion
			printMatrix(matrix);	//La imprime	
		}
	}

	printf("Terminando programa..\n\n"); //Al recibir algo menor o igual a un 0 se acaba el programa
	return 0;	
}
