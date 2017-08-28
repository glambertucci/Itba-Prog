#include <stdio.h>

#define FILAS 9
#define COLUMNAS 9
#define MAX 20	//Limite de dimension de matriz

int main(void)
{
	int fil, col, auxfil, auxcol;

	if(COLUMNAS>MAX||FILAS>MAX||FILAS<-MAX||COLUMNAS<-MAX)	//Comprueba que la dimension no exceda el limite
		printf("ERROR: Dimension de la matriz excede el limite. (Limite = %d)\n",MAX);
	else if(COLUMNAS==0||FILAS==0)	//Comprueba que la dimension no sea cero
		printf("ERROR: La dimesion de la matriz no debe ser cero.\n");
	else
	{
		if(FILAS<0)	//Comprueba que la dimension no sea negativa, si lo es, tira warning
		{
			printf("WARNING: No se aceptan numeros negativos.\nSe tomara el numero de filas positivo\n");	
			auxfil=-FILAS;
		}
		else
			auxfil=FILAS;
		

		if(COLUMNAS<0)	//Comprueba que la dimension no sea negativa, si lo es, tira warning
		{
			printf("WARNING: No se aceptan numeros negativos.\nSe tomara el numero de columnas positivo\n");
			auxcol=-COLUMNAS;
		}
		else
			auxcol=COLUMNAS;
		

		for(fil=0;fil<auxfil;fil++)	//Algoritmo de creacion de matriz, itera el primer for por cada fila
		{
			for(col=fil;col<(auxcol+fil);col++)	//y luego itera por cada numero en las columnas
			{
				printf("%d\t", col);
			}
			printf("\n");
		}

	}
return 0;
}
