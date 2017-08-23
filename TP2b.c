#include <stdio.h>

#define FILAS 4
#define COLUMNAS 5

int main(void)
{

	int m, n, auxfil, auxcol;

	if(COLUMNAS>31)
		printf("WARNING: La dimension de la matriz puede alterar su correcta presentacion\n");

	if(FILAS==0||COLUMNAS==0)
		printf("WARNING: Dimension de matriz invalida \n");

	if(FILAS<0)
	{
		printf("WARNING: No se aceptan numeros negativos.\nSe tomara el numero de filas positivo\n");
		auxfil=-FILAS;
	}
	
	else
		auxfil=FILAS;

	if(COLUMNAS<0)
	{
		printf("WARNING: No se aceptan numeros negativos.\nSe tomara el numero de columnas positivo\n");
		auxcol=-COLUMNAS;
	}
	else
		auxcol=COLUMNAS;
		
	for(m=0;m<auxfil;m++)
	{
		for(n=m;n<auxcol+m;n++)
		{
			printf("%d\t", n);
		}
		printf("\n");
	}
	

return 0;
}