#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CalcFunc.h"
#include "KeyboardUtilities.h"
#include "Messages.h"
#include "ModeSelection.h"

#define MAX_SIZE 1000

char operands[7]={'+','-','*','/','|','&','^'};			//Arreglos globales por consigna
double (* functions [7]) (double,double);

int main (void)
{
	double num1,num2,result;

	char arr[MAX_SIZE];
	char * pnum2, * find;
	int modo, abort = 1;

	welcomeMessage(); 			//Se muestra el mensaje de bienvenida

	while (abort)				//Mientras que no se detecte que el usuario quiera terminar el programa
	{
		modo = modeAsk();		//Pregunta al usuario con que operaciones desea realizar cuentas
		if ((modo == 0))		//Si quiere terminar programa
			abort = 0;
		else
		{
			addOperation(modo);	//inicia funciones
			scanf("%lf%s", (&num1),arr);
			pnum2 = &arr[1];
			char op=arr[0];
			
			find =	strchr(operands, op);
			if (find == NULL)	//ACA VERIFICA SI EL OPERANDO ES VALIDO
			{
				invalidMessage();
			}
			else 
			{
				num2= atof(pnum2); //compone segunda mitad de cuenta
				if (((arr[1]< '0' ) || (arr[1]>'9') ) && (arr[1] != '.'))
				{
					invalidMessage(); //mas validacion
				}
				else
				{
					if (num2==0 && op == operands[3])
					{
						indefiniteMessage(); //Dividir por 0 es malo, y un conejito muere cada vez que lo intentas.
					} 	
					else 
					{
						result=	calcRes(num1,num2,op);	//finalmente calcula
						answerMessage(num1, op, num2, result);
					}
				}
			}
			cleanBuffer();
		}
	}
	endMessage();
	return 0;
}
