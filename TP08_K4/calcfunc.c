#include <stdio.h>
#include <string.h>
#include "colordefines.h"

double calcRes (double num1, double num2, char op)
{
	double result;
	if (op==operands[0])
		result = num1+num2;
	if (op==operands[1])
		result = num1-num2;
	if (op==operands[2])
		result = num1*num2;
	if (op==operands[3])
		result = num1/num2;
	if (op==operands[4])
		result = (int)num1 | (int)num2;
	if (op==operands[5])
		result = (int)num1 & (int)num2;
	if (op==operands[6])
		result = (int)num1 ^ (int)num2;	
	return result;
}

int  modeAsk(void)
{
	static int modo = 0;
	static int state = 0;
	char outputString[1000], outputChar, trash;
	int outputFunction, tryAgain;

	if(state)
	{
		printf("Desea seguir realizando operaciones en el modo seleccionado, cambiar de modo, o salir?\n");
		printf("Si desea continuar con el seleccionado, escriba "GREEN"'c'"COLOR_RESET"; si desea cambiar de modo, escriba "GREEN"'m'"COLOR_RESET"; si desea salir, escriba "GREEN"'e'\n"COLOR_RESET);
		do
		{
			tryAgain = 0;
			scanf("%c", &outputChar);
			switch(outputChar)
			{
				case 'c':	outputFunction = modo; break;
				case 'm':	((modo==1)?(modo=2):(modo=1)); break;
				case 'e':	outputFunction = 0; break;

				default:	printf("Caracter invalido, probar nuevamente\n");
							tryAgain = 1;
							cleanbuffer();
			}
		} while (tryAgain);
	}
	else
	{
		state = 1;
		printf("Escriba '"GREEN"m1"COLOR_RESET"' si desea utilizar la calculadora con los operadores clasicos "GREEN"('+', '-','*','/','|','&','^')\n"COLOR_RESET);
		printf("De no ser asi, el programa admite la utilizacion de operadores alternativos "GREEN"('s','r','m','d','o,'a','x')"COLOR_RESET". Para seleccionar dicho modo escriba '"GREEN"m2'\n"COLOR_RESET);
			do
			{
				tryAgain = 0;
				scanf("%s",outputString);
				if(strcmp(outputString, "m1"))
				{
					outputFunction = 1;
					modo = 1;
				}
				else if(strcmp(outputString, "m2"))
				{
					outputFunction = 2;
					modo = 2;
				}
				else
				{
					printf("Caracteres invalidos, probar nuevamente\n");
					tryAgain = 1;
					cleanbuffer();
				}
			} while (tryAgain);
	}
	return outputFunction;
}


int addOperation(int mode )
{
	char classic[7]={'+','-','*','/','&','|','^'};
	char letters[7]={'s','r','m','d','a','o','x'};
	int index;
	if (mode == 2)
	{
		for (index=0;index<7;index++)
		{
			operands[index]=classic[index];
		}
	}
	else 
		for (index=0;index<7;index++)
		{
			operands[index]=letters[index];
		}

	double (* sum_pointer) (double, double)= &summ;
	double (* res_pointer) (double, double)=&ress;
	double (* mul_pointer) (double, double)=&mull;
 	double (* div_pointer) (double, double)=&divi;
	double (* and_pointer) (double, double)=&andd;
	double (* or_pointer) (double, double)=&orr;
	double (* xor_pointer) (double, double)=&xorr;

	functions[0] = sum_pointer;
	functions[1] = res_pointer;
	functions[2]= mul_pointer;
	functions[3]= div_pointer;
	functions[4]= and_pointer;
	functions[5]= or_pointer;
	functions[6]= xor_pointer;
}
double summ (double num1,double num2)
{
	return num1+num2;
}
double ress (double num1,double num2)
{
	return num1-num2;
}
double mull (double num1,double num2)
{
	return num1*num2;
}
double divi (double num1,double num2)
{
	return num1/num2;
}
double andd (double num1,double num2)
{
	return (int) num1& (int) num2;
}
double orr (double num1,double  num2)
{
	return (int)  num1|(int) num2;
}
double xorr (double num1,double  num2)
{
	return (int)  num1^ (int) num2;
}
