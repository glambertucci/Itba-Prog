#include <stdio.h>

int main(void){


	#define masc1 0X21 //Esto es 00100001
	#define masc2 0XE7 //Esto es 11100111

	int port_A,z=0;    //Declaro variables
	((port_A == masc1) || (port_A == masc2)) ? (z++) : (z=0); //Me fijo si encaja en algun caso

	printf("%d\n",z);

	//printf("%d\n",!z); SI QUIERO IMPRIMIR EL NUMERO CONTRARIO (EJERCICIO 8)


	double N=18.3;
	N%1<=0.5?N-N%1:N+(1-N%1);
	printf("%d",N);

}



