#include <stdio.h>

#define NUM 2147483629 //Este es el número que será evaluado.

int main(void)
{
	long int num = NUM;//Numero a evaluar 
	//*********************//
	// sigue sin tener tope//
	//*********************//
	long int divis = 2; //Variable que irá dividiendo al número a evaluar.
	//***************************************//
	//este divis es mejor definirlo en el for//
	//***************************************//	
	//*****************************************************//
	//El or es lazy no te va  acorroborar la segunda opcion//
	//*****************************************************//
	
	if(num<=1 || num>2147483647) //Los números negativos o mayor a 2147483647 se descartan con esta misma condición.
	{
		printf("Su input no es válido o está fuera de rango.\nRecuerde que solo los números naturales distintos de 1 pueden ser primos.\n");
	}
	else 
	{	
	for(;divis<(num/2);divis++) //Evalúa cada división entre 2 y la mitad del número a evaluar, evitando con esto último divisiones cuyo resultado sea menor a 1 y, al truncar la parte decimal, se interpreten como "0".
		{
			if (num%divis == 0) //Si la división es entera, entonces el número no es primo.
			{
				printf("No es un numero primo\n");
				break;
				//***************************//
				//sigue habiendo un break q.q//
				//y nos van a putear por eso.//
			}
		}
	if(divis == (num/2))
	{
		printf("Es un numero primo\n"); //Si nunca se produjo una división con resto 0, entonces esta condición se cumplirá ya que fue necesaria para salir del loop.
	}
	}
	return 0; 
}


