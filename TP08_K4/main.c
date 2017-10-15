#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modeAsk.c"
#define GREEN   "\x1b[32m"
#define BLUE    "\x1b[34m"
#define COLOR_RESET   "\x1b[0m"
double xorr (double num1,double  num2);
double summ (double num1,double num2);
double ress (double num1,double num2);
double mull (double num1,double num2);
double divi (double num1,double num2);
double andd (double num1,double num2);
double orr (double num1,double  num2);


double calcRes (double num1, double num2, char op);
int addOperation(int mode);
char operands[7];
double (* functions [7]) (double, double);


int main (void)
{
	double num1,num2,result;

	char arr[1000],trash;
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
		printf("%d\n",modo );
		addOperation(modo);//inicia funciones
		printf("%c%c%c%c%c%c%c\n",operands[0],operands[1],operands[2],operands[3],operands[4],operands[5],operands[6] );
		scanf("%lf%s", (&num1),arr);
		pnum2 = &arr[1];
		char op=arr[0];
		
		find =	strchr(operands, op);
		if (find == NULL)	//ACA VERIFIQUE SI OP ES VALIDO
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
					printf("Indefinido\n"); //Dividir por 0 es malo
				} 	
				else 
				{
					result=	calcRes(num1,num2,op);
					printf(""GREEN"Cuenta"COLOR_RESET": %lg %c % lg \n" BLUE"Resultado" COLOR_RESET ": % lg\n",num1,op,num2,result );
				}
			}
		}
		while(trash=getchar() != '\n');//Limpio el buffer Esto deberia ser una funcion
	}
}

double calcRes (double num1, double num2, char op)
{
	double result;
	if (op==operands[0])
		result = functions[0] (num1,num2);
	if (op==operands[1])
		result = functions[1] (num1,num2);
	if (op==operands[2])
		result = functions[2] (num1,num2);
	if (op==operands[3])
		result = functions[3] (num1,num2);
	if (op==operands[4])
		result = functions[4] ((int) num1, (int) num2);
	if (op==operands[5])
		result = functions[5] ((int) num1,(int) num2);
	if (op==operands[6])
		result = functions[6] ((int) num1,(int) num2);	
	return result;
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