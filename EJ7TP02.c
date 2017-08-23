#include <stdio.h>

int main(void)
{
	int num = 981;//Numero a evaluar
	int numev=0;
	int divis = 2; //Números que dividen
	
	if(num<=0)
		printf("Solo los números naturales pueden ser primos\n");
	else
		numev=num;
	for(;divis<numev;divis++)
		{
			if (numev%divis == 0)
			{
				printf("No es un numero primo\n");
				break;
			}
			else
				continue;
		}
	if(divis == numev)
		printf("Es un numero primo\n");

	return 0; 
}


