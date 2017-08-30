#include <stdio.h>

#define NUM 212 //Este es el número que será evaluado.
#define MAX_NUM 2147483647
int main(void)
{
	long int num = NUM;//Numero a evaluar
	long int divis = 2; //Variable que irá dividiendo al número a evaluar.

	if(num<=1 || num>MAX_NUM) //Los números negativos o mayor a 2147483647 se descartan con esta misma condición.
	{
		printf("Su input no es válido o está fuera de rango.\nRecuerde que solo los números naturales distintos de 1 pueden ser primos.\n");
	}
	else
	{
    if (num==2 || num==3)   //Casos especificos
        printf("Es un numero primo\n");
    if (num==4)
        printf("No es un numero primo\n");
	while(divis<(num/2)) //Evalúa cada división entre 2 y la mitad del número a evaluar, evitando con esto último divisiones cuyo resultado sea menor a 1 y, al truncar la parte decimal, se interpreten como "0".
		{
			if (num%divis == 0) //Si la división es entera, entonces el número no es primo.
			{
				printf("No es un numero primo\n");
				divis = num/2; //esto es para que salga del ciclo while porque ya se supo que no es un numero primo
            }
            divis++;
		}
    if (num%divis == 0)
    {   //esto es para que, si antes se dijo que era NO un numero primo, que no imprima ahora que ES un numero primo

    }
    else
        if(divis == (num/2))
        {
            printf("Es un numero primo\n"); //Si nunca se produjo una división con resto 0, entonces esta condición se cumplirá ya que fue necesaria para salir del loop.
        }
	}
	return 0;
}


