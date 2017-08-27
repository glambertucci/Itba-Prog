#include <stdio.h>

#define FILAS 4
#define COLUMNAS 5

int main(void)
{

	int m, n, auxfil, auxcol;	//ya se que el tp dice m y n pero eso es mas ilustrativo, es mejor ponerles nombres como fil y col para claridad de codigo, se que no les importa el nombrecito 

	if(COLUMNAS>31)	//Magic Numbers!
		printf("WARNING: La dimension de la matriz puede alterar su correcta presentacion\n");	//Pienso que no deberia dejarte imprimir
	//aparte tambien deberias limitar las filas, sino cuando ponga un numero muy grande se va a ver una cascada de numeros hasta que termine de procesar
	if(FILAS==0||COLUMNAS==0)
		printf("WARNING: Dimension de matriz invalida \n");

	if(FILAS<0)
	{
		printf("WARNING: No se aceptan numeros negativos.\nSe tomara el numero de filas positivo\n");	//Creo que quedaria mejor solo puteando al usuario y no tomar el positivo
		auxfil=-FILAS;
	}
	
	else		//estos dos if los podes poner en uno solo con un OR ||
		auxfil=FILAS;

	if(COLUMNAS<0)
	{
		printf("WARNING: No se aceptan numeros negativos.\nSe tomara el numero de columnas positivo\n");
		auxcol=-COLUMNAS;
	}
	else
		auxcol=COLUMNAS;
		
	for(m=0;m<auxfil;m++)	//esto esta piolita
	{
		for(n=m;n<auxcol+m;n++)
		{
			printf("%d\t", n);
		}
		printf("\n");
	}
	

return 0;
}
