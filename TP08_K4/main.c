#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GREEN   "\x1b[32m"
#define BLUE    "\x1b[34m"
#define COLOR_RESET   "\x1b[0m"
 double calcRes (double num1, double num2, char op);
 int addOperation(char op, double (*functions) (double num1 ,double num2));
char operands[7]={'+','-','*','/','|','&','^'};
//double (*(functions[7])) (double,double);


int main (void)
{
	double num1,num2,result;
<<<<<<< HEAD
	char arr[1000],trash;
	char * pnum2, * find;
=======
	char arr[1000];
	char * pnum2;
	int modo;
>>>>>>> 9b20ac57ed470018bfc3ef1d30380b2987004042

	printf("Bienvenido a la calculadora \n");//Funciones
	printf("Las funciones basicas estan habilitadas incluyendo AND OR y XOR \n");
	printf("(siendo estas exclusivas para numeros enteros)\n");
	printf("Ingrese Numero Operador Numero y obtendra el resultado\n");
	printf("Considere que el formato es [NUMERO] [OPERADOR] [NUMERO] (sin los corchetes)\n");
	printf("y se tomaran los dos primeros numeros, el resto será ignorado\n");
	while (abort)
	{
<<<<<<< HEAD
//		mode();// va a ser funcion que preguntra el modo al inicio  y luego pregunte si quiere mantener, cambiarlo  o q para salir 
//		addOperation();//inicia funciones
=======
		modo = modeAsk();
//		initFun();//inicia funciones
>>>>>>> 9b20ac57ed470018bfc3ef1d30380b2987004042
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