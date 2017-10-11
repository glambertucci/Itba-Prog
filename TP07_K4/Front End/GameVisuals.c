#include "Standard.h"
#include <stdio.h>
#include "GameVisuals.h"

void printMatrix(char mat[][WIDTH])
{
	int i, j;
	printf("\n");
	for (i = 0;i < WIDTH;i++){
		for (j = 0;j < HEIGHT;j++){
			if (mat[i][j] == ' ')
				printf("|%c",mat[i][j]);
			else
				printf("|" GREEN "%c" COLOR_RESET, mat[i][j]);
		}
		printf("|\n");
	}
	putchar('\n');
}

void welcomeMsg (char matrix[][WIDTH])
{
	printf("\n\n\n\n\n\nBienvenido al juego de la vida! \n");
	printf(BLUE"ADVERTENCIA: Este programa se ejecuta correctamente solamente en sistemas operativos Linux.\n" COLOR_RESET);
	printf("Configuracion: " BLUE "%d" COLOR_RESET "x" BLUE "%d" COLOR_RESET "\n",HEIGHT,WIDTH);
	printf("\n");

	printMatrix(matrix);

	printf("\n");
	printf("Para avanzar a la siguiente generacion " BLUE "escriba el " COLOR_RESET);
	printf(BLUE"numero de generaciones que desea ver y presione enter.\n\n"COLOR_RESET);
	printf("Si presiona" BLUE " enter" COLOR_RESET" se mostrara una sola generacion.\nSi escribe  un "BLUE"numero no natural (a menos que sea enter)"COLOR_RESET" se terminara el programa.\n");
}

void againMessage (void)
{
	printf("Numero muy grande, ingrese un numero menor\n");
}
void endMessage(void)
{
	printf(BLUE "Terminando programa..\n" COLOR_RESET);
}
