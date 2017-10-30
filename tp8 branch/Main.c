
/*Fecha de creacion 15/10/2017
TP8 - ADVANCED POINTERS 
Grupo 4
Integrantes:
Lambertucci Guido	58009
Hrubisiuk 	Agustin	58311
Mechoulam	Alan	58438
Moriconi	Franco	58495 
El siguiente programa es una calculadora basica, realiza suma resta multiplicacion y division, y aparte cuenta con 3 funciones
logicas AND OR XOR, se elige en tiempo de ejecucion que formato de input es el deseado, este programa funciona apropiadamente en 
Linux
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CalcFunc.h"
#include "KeyboardUtilities.h"
#include "Messages.h"
#include "ModeSelection.h"


char operands[MAX_OP]={'+','-','*','/','|','&','^'};			//Arreglos globales por consigna
double (* functions [MAX_OP]) (double,double);

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
