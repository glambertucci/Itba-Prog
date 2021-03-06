//Trabajo Práctico n°7  
/*Fecha de Creación: 08/10/2017
Grupo 4
Integrantes:
Lambertucci Guido	58009
Hrubisiuk 	Agustin	58311
Mechoulam	Alan	58438
Moriconi	Franco	58495


     El Juego de la Vida con multiarchivo 
Este programa muestra una matriz en pantalla que contiene células "vivas" y "muertas".
Las mismas bajo ciertas condiciones sobreviven, mueren o reviven.
Criterio a tener en cuenta: Se toma una matriz de tamaño nxn pero que de la cual 
realmente se mostrará (n-2)x(n-2). Esto a nivel de programación se realiza para que 
la función encargada de realizar el chequeo de los estados de las células colindantes 
no haga la verificación de estado con memoria basura o celulas no colindantes en los "bordes" de la matriz. 
Este programa tiene hardcodeado las celulas vivas del juego. Estas pueden ser modificadas,
eliminadas o agregadas al mapa inicial, siempre y cuando respete la dimensión de la matriz escogida.
Dicha función solo inicializa la primer matriz del juego.
En caso de querer finalizar toque cualquier numero no natural, un enter avanza de generacion y si ingresa un numero avanza las generaciones ingresadas 

ADVERTENCIA: Este programa se ejecuta correctamente solamente en sistemas operativos Linux.
*/

#include "Standard.h"
#include "GameVisuals.h"
#include "MatrixLogic.h"
#include "Keyboard.h"
#include "GameLogic.h"
#define MAX 1000
int main(void)
{

				/////////////////////////////////////////////
				int num;

				char matrix[HEIGHT][WIDTH] = {
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' ', ' '},
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' ', ' '},
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' ', ' '},
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' ', ' '},
				{' ',' ',' ',' ',' ','*',' ', ' ',' ', ' ', ' '},
				{' ',' ',' ',' ','*','*','*', ' ',' ', ' ', ' '}, //SEED MATRIX
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' ', ' '},
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' ', ' '},
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' ', ' '},
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' ', ' '},
				{' ',' ',' ',' ',' ',' ',' ', ' ',' ', ' ', ' '},
				};
					char auxmatrix[HEIGHT][WIDTH];
				/////////////////////////////////////////////
	transferMat(matrix,auxmatrix);

	welcomeMsg(matrix);

	while ( (num = readNumber()))	//Mientras que el numero ingresado sea mayor a 0..
	{
		if (num<MAX)
		{					//Si se recibe un enter, eso es igual a un 1
			while ((num--)>=1)	//Hasta que el numero deje de ser mayor o igual a 1..
			{
				nextGen(matrix, auxmatrix);		//Calcula proxima generacion
				printMatrix(matrix);	//La imprime	
			}
		}
		else 
		againMessage();
	}

	endMessage(); //Al recibir algo menor o igual a un 0 se acaba el programa

		
}
