#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CalcFunc.h"
#include "KeyboardUtilities.h"
#include "Messages.h"
#include "ModeSelection.h"

char operands[7]={'+','-','*','/','|','&','^'};
double (* functions [7]) (double,double);

int main (void)
{
	double num1,num2,result;

	char arr[1000];
	char * pnum2, * find;
	int modo, abort = 1;

	welcomeMessage();

	while (abort)
	{
		modo = modeAsk();
		if ((modo == 0))
			abort = 0;
		addOperation(modo);//inicia funciones
		printf("Operands: %c%c%c%c%c%c%c\n",operands[0],operands[1],operands[2],operands[3],operands[4],operands[5],operands[6] );
		scanf("%lf%s", (&num1),arr);
		pnum2 = &arr[1];
		char op=arr[0];
		
		find =	strchr(operands, op);
		if (find == NULL)	//ACA VERIFIQCA SI EL OPERANDO ES VALIDO
		{
			invalidMessage();
		}
		else 
		{
			num2= atof(pnum2); 
			if (((arr[1]< '0' ) || (arr[1]>'9') ) && (arr[1] != '.'))
			{
				invalidMessage();
			}
			else
			{
				if (num2==0 && op == operands[3])
				{
					indefiniteMessage(); //Dividir por 0 es malo, y un conejito muere cada vez que lo intentas.
				} 	
				else 
				{
					result=	calcRes(num1,num2,op);
					answerMessage(num1, op, num2, result);
				}
			}
		}
		cleanBuffer();//Limpio el buffer
	}
	endMessage();
	return 0;
}
