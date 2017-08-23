//TP PRACTICO N°2. Bloques de control
/*Fecha de creacion 23/8/2017
Grupo 4
Integrantes:
Lambertucci Guido	58009
Hrubisiuk 	Agustin	58311
Mechoulam	Alan	58438
Moriconi	Franco	58495
Este programa tomara el numero ingresado a CANDIDATO e imprimira en pantalla
si el mismo es primo o compuesto.
Nota 1: El programa no aceptará numeros mayores a 15000000.
Nota 2: Numeros negativos no son validos.
Nota 3: El numero 1 no es considerado primo ni compuesto.
*/


#include <stdio.h>
#define CANDIDATO 104597 

int main (void)
{
	int numero_a_evaluar=CANDIDATO;		
	int divisor,cantidad_de_divisores=0;

	//Verificaciones de entrada
	if (numero_a_evaluar>15000000)		
	{
		printf("El numero es demasiado grande, ingrese otro\n");
	}	
	else if (numero_a_evaluar<1)
	{
		printf("El numero ingresado no es valido, vuelva a modificarlo\n");
	}
	else if (numero_a_evaluar==1)
	{
		printf("El numero %d no es primo ni compuesto\n",numero_a_evaluar);
	}
	//Una vez pasadas las verificaciones procede a analizar el numero
	//Basicamente divide el numero por todos los menores a el hasta el 1
	//como esto para numeros muy alto se hace muy largo decidimos acotar el numero
	//si el numero tiene mas de dos divisores automaticamente no es primo
	else 
	{	
		for(divisor=1;(divisor<=numero_a_evaluar) || (cantidad_de_divisores==3);divisor++)
		{
			if((numero_a_evaluar%divisor)==0)
			{
				cantidad_de_divisores++;
			}
		}
		if(cantidad_de_divisores==2)
		{
			printf("El numero %d es primo\n",numero_a_evaluar);
		}
		else 
		{
			printf("El numero %d es compuesto\n",numero_a_evaluar );
		}
	}
	return 0;
}	