#include <stdio.h>
#include "Colors.h"
#include "Messages.h"

void welcomeMessage(void);
{
	printf("Bienvenido a la calculadora \n");
	printf("Las funciones basicas estan habilitadas incluyendo AND OR y XOR \n");
	printf("(siendo estas exclusivas para numeros enteros)\n");
	printf("Ingrese Numero Operador Numero y obtendra el resultado\n");
	printf("Considere que el formato es [NUMERO] [OPERADOR] [NUMERO] (sin los corchetes)\n");
	printf("y se tomaran los dos primeros numeros, el resto será ignorado\n");
}

void invalidMessage(void)
{
	printf("Entrada invalida.\n");
}

void indefiniteMessage(void)
{
	printf("Indefinido.\n");
}

void answerMessage(double num1, char op, double num2, double result)
{
	printf(""GREEN"Cuenta"COLOR_RESET": %lg %c % lg \n" BLUE"Resultado" COLOR_RESET ": % lg\n",num1,op,num2,result );
}

void endMessage
{
	printf("Terminando programa...\n");
}
