#include <stdio.h>
#include <stdlib.h>
#define GREEN   "\x1b[32m"
#define BLUE    "\x1b[34m"
#define COLOR_RESET   "\x1b[0m"
 double calcres (double num1, double num2, char op);

char operands[7]={'+','-','*','/','|','&','^'};
//double (*(functions[7])) (double,double);


int main (void)
{
	double num1,num2,result;
	char arr[1000];
	char * pnum2;
	int modo;

	printf("Bienvenido a la calculadora \nLas funciones basicas estan habilitadas incluyendo AND OR y XOR \n(siendo estas exclusivas para numeros enteros)\nIngrese Numero Operador Numero y obtendra el resultado\n");
	while (abort)
	{
		modo = modeAsk();
//		initFun();//inicia funciones
		scanf("%lf%s", (&num1),arr);
		pnum2 = & arr[1];
		char op=arr[0];
						//fijate si op es valido
		num2= atof(pnum2);
		//aca te fijas si es valido num2 	
		result=	calcres(num1,num2,op);
		printf(""GREEN"Cuenta"COLOR_RESET": %lg %c % lg \n" BLUE"Resultado" COLOR_RESET ": % lg\n",num1,op,num2,result );
	}
}

double calcres (double num1, double num2, char op)
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