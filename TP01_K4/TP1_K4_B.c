//TP PRACTICO N°1. Constantes, variables y operadores
/*Fecha de creacion 16/8/2017
Grupo 4
Integrantes:
Lambertucci Guido	58009
Hrubisiuk 	Agustin	58311
Mechoulam	Alan	58438
Moriconi	Franco	58495
Este programa dada una variable, la imprimira de diversas formas
*/
#include <stdio.h>
#define small 1e-10	//si n es entero para hacer el superior obtendria n+1 y no n, por eso le resto este pequeño numero
int main (void)
{
	double  var=-3.141592,parte_decimal,rendon_2dec,aux;	//aux: variable usada para la utilizacion de numeros negativos
	int entero_redondeado,entero_sup,entero_inf;
	
	aux= (var > 0 ? 0 :(-1+small));
	entero_redondeado= (int) (aux+var+0.5);
	entero_sup = (int) (aux+var+1.0-small);
	entero_inf = (int) (aux+var);
	parte_decimal = (var) - (int) var;
	rendon_2dec= (double) ((int) (aux+0.5 + (var*100.0)))/100.0;

	printf("Numero original %lf\n",var);
	printf("------------------------------------\n");
	printf("Redondeado:\t\t\t\t\t%d\n",entero_redondeado);
	printf("Superior:\t\t\t\t\t%d\n",entero_sup);
	printf("Inferior:\t\t\t\t\t%d\n",entero_inf);
	printf("Parte decimal:\t\t\t\t%f\n", parte_decimal);
	printf("Redondeado dos decimales:\t%f\n", rendon_2dec );
}
