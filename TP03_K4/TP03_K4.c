#include <stdio.h>
#include <stdlib.h>
#define VAR_QUANTITY 10

int check_input(int, int, int, int, int, int, int, int, int, int);

int main(void)
{
	int diastotales;
	int counter=0; char caracter; int i;
	int d1, d2, b1, m1, m2, b2, a1, a2, a3, a4; //d: dia, m: mes, a: ano, b: barra

	for (i = 0; i<2; i++) //recibe fecha inicial, luego final
	{	
		for (i = 1; i <= VAR_QUANTITY; i++)	//loop 10 veces, una vez por variable
		{
			caracter = getchar();
			counter++;

			switch(counter)
			{
				case 1: d1 = caracter;
				case 2: d2 = caracter;
				case 3:	b1 = caracter;
				case 4:	m1 = caracter;
				case 5:	m2 = caracter;
				case 6: b2 = caracter;
				case 7: a1 = caracter;
				case 8:	a2 = caracter;	
					
				case 9: 
					if(caracter == '\n')
						a3 = 0;
					else
						a3 = caracter;
				
				case 10:
					if(caracter == '\n')
						a4 = 0;
					else
						a4 = caracter;
			}
					//ACA ESTARIAN LOS DEMAS MODULOS
		}
	}
					//CERRADO EL FOR ACA ENTRA EL MODULO QUE CUENTA LOS DIAS
				printf("La cantidad de dias entre las fechas compredidas es de %d\n", diastotales);
return 0;
}

