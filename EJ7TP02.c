#include <stdio.h>

int main(void)
{
	int num = 981;//Numero a evaluar	//No hay tope del numero, entonces si le pones uno que supere 32k te da como negativo y te kb
	int numev=0;
	int divis = 2; //Números que dividen
	
	if(num<=0)
		printf("Solo los números naturales pueden ser primos\n");	//si le pones 1 no tira nada el output
	else
		numev=num;	//aca realmente no hace falta esto, podes trabajar directamente con num en ves de numev
	for(;divis<numev;divis++)
		{
			if (numev%divis == 0)
			{
				printf("No es un numero primo\n");
				break;				//intenta hacerlo sin el break este raro ni el continue
			}
			else
				continue;
		}
	if(divis == numev)
		printf("Es un numero primo\n");

	return 0; 
}


