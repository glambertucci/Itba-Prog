#include <stdio.h>
#define INCORRECTA 0
#define START 0					//////Definiciones//////
#define FINISH 1
#define TERMINATOR 0
#define YEAR -1
#define ASCII '0'

void get_input(void);			//////Prototipos/////
void get_date(int);
int check_input(void);
int make_num(int, int, int, int);
long int calc_days(int, int, int, int, int, int);

int d1=TERMINATOR, d2=TERMINATOR;	//Variables Globales: d=dia, m=mes, a=year
int b1=TERMINATOR, b2=TERMINATOR;	//Se eligio la utilizacion de variables globales para facilitar el pasaje de informacion
int m1=TERMINATOR, m2=TERMINATOR;	//a las funciones. Se inicializan todas en valor 0 menos las dos ultimas de year, las cuales
int a1=TERMINATOR, a2=TERMINATOR, a3=YEAR, a4=YEAR;	//si no son modificadas en get_input, se entiende que el usuario eligio
													//utilizar el formato corto de ano.

int main(void)				//////Funcion Main//////
{
	printf("Este programa calcula la cantidad de dias comprendidos entre una fecha
		inicial y una fecha final. Se pide que el formato de entrada de los dias sea de
		dd/mm/aaaa o alternativamente de dd/mm/aa.\n");

	int verif, startorfinish=START;
	int yearstart, monthstart, daystart;
	int yearend, monthend, dayend;
	long int daytotal;

	get_date(startorfinish);		//Se toma la fecha y se verifica su validez.
	
	yearstart = make_num(a1, a2, a3, a4);						//Luego, se compone el numero.
	monthstart = make_num(m1, m2, TERMINATOR, TERMINATOR);
	daystart = make_num(d1, d2, TERMINATOR, TERMINATOR);

	startorfinish = FINISH;			//Se informa que la fecha a recibir es ahora la final.
	get_date(startorfinish);		//Se toma la fecha y se verifica su validez.

	yearend = make_num(a1, a2, a3, a4);							//uego, se compone el numero.
	monthend = make_num(m1, m2, TERMINATOR, TERMINATOR);
	daystart = make_num(d1, d2, TERMINATOR, TERMINATOR);

	daytotal = calc_days(daystart, monthstart, yearstart, dayend, monthend, yearend); //Mediante el algoritmo, se calcula
																						//la cantidad totales de dias.
	printf("El numero de dias comprendido entre las fechas es de: %ld dias.\n\n", daytotal);//Y se la informa al usuario.

return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////


void get_date(int startorfinish)
{

	int verif;

	do {								//Funcion de verificacion y pedido de input de fecha.
										//No sale hasta que el usuario entregue una fecha valida.
		if(startorfinish == START)		//Tambien se checkea si la fecha a pedir es la inicial o la final.
			printf("Ingresar fecha inicial:\n");
		else
			printf("Ingresar fecha final:\n");	
					
		get_input();
		verif = check_input();
		
		if (verif == INCORRECTA)
			printf("Formato de fecha invalido.\n");
		else
			printf("Formato de fecha valido.\n\n");	

	} while (verif != INCORRECTA);

return;
}

//////////////////////////////////////////////////////////////////////////////////////////


void get_input(void)
{

	int caracter, count=0, freno=0;
	int i;

for(i=0 ; (i<10 && (freno <1)) ; i++)	//Si se recibe un enter, freno se activa y no itera.
	{
		caracter=getchar();
		count++;

		switch(count)	//Un caso para cada variable
		{				//Si el usuario apreta enter prematuramente, las variables no modificadas
			case 1:		//quedan con su valor de inicializacion.
				if(caracter== '\n' ) {
					freno=1;
				}
				else
					d1=caracter;
				break;
			case 2:
				if(caracter== '\n' ) {
					freno=1;
				}
				else
					d2=caracter;
				break;
			case 3:
				if(caracter== '\n' ) {
					freno=1;
				}
				else
					b1=caracter;
				break;
			case 4:
				if(caracter== '\n' ) {
					freno=1;
				}
				else
					m1=caracter;
				break;
			case 5:
				if(caracter== '\n' ) {
					freno=1;
				}
				else
					m2=caracter;
				break;
			case 6:
				if(caracter== '\n' ) {
					freno=1;
				}
				else
					b2=caracter;
				break;
			case 7:
				if(caracter== '\n' ) {
					freno=1;
				}
				else
					a1=caracter;
				break;
			case 8:
				if(caracter== '\n' ) {
					freno=1;
				}
				else
					a2=caracter;
				break;
			case 9:
				if(caracter== '\n' ) {
					freno=1;
				}
				else
					a3=caracter;
				break;
			case 10:
				if(caracter== '\n' )
				{
					freno=1;
					a4=caracter;
				}
				else
					a4=caracter;
				break;
		}
	}

return;
}