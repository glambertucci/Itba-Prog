#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calcfunc.h"
#include "keyboard.h"
#include "colordefines.h"
char operands[7]={'+','-','*','/','|','&','^'};
//double (*(functions[7])) (double,double);


int main (void)
{
	double num1,num2,result;

	char arr[1000];
	char * pnum2, * find;
	int modo; 

	printf("Bienvenido a la calculadora \n");//Funciones
	printf("Las funciones basicas estan habilitadas incluyendo AND OR y XOR \n");
	printf("(siendo estas exclusivas para numeros enteros)\n");
	printf("Ingrese Numero Operador Numero y obtendra el resultado\n");
	printf("Considere que el formato es [NUMERO] [OPERADOR] [NUMERO] (sin los corchetes)\n");
	printf("y se tomaran los dos primeros numeros, el resto será ignorado\n");
	while (abort)
	{

		modo = modeAsk();
//		addOperation();//inicia funciones

		scanf("%lf%s", (&num1),arr);
		pnum2 = &arr[1];
		char op=arr[0];
	
		find =	strchr(operands, op);
		if (find == NULL)	//ACA VERIFIQCA SI EL OPERANDO ES VALIDO
		{
			printf("Entrada invalida\n");
		}
		else 
		{
			num2= atof(pnum2); 
			if (((arr[1]< '0' ) || (arr[1]>'9') ) && (arr[1] != '.'))
			{
				printf("Entrada invalida\n");
			}
			else
			{
				if (num2==0 && op == operands[3])
				{
					printf("Indefinido\n"); //Dividir por 0 es malo, y un conejito muere cada vez que lo intentas.
				} 	
				else 
				{
					result=	calcRes(num1,num2,op);
					printf(""GREEN"Cuenta"COLOR_RESET": %lg %c % lg \n" BLUE"Resultado" COLOR_RESET ": % lg\n",num1,op,num2,result );
				}
			}
		}
		cleanbuffer();//Limpio el buffer
	}
	return 0;
}