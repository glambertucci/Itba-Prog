#include <stdio.h>

//////Definiciones//////

#define INCORRECTA (0)
#define START (0)					
#define FINISH (1)
#define DAY_MONTH 0
#define YEAR (-1)
#define ASCII ('0')
#define INPUT_FIRST_DATE 	(1)
#define INPUT_SECOND_DATE (2)


//////Prototipos/////

void get_input(void);			

void get_date(int);

int check_input(void);

int make_num (char first,char second, char third, char fourth);
//This function recives 4 chars, every number that lacks the third and fourth char must be sent with the proper code in those positions
//if the input is correct, you'll get the composed number  

long int calc_days(int, int, int, int, int, int);

void welcome_msg (void);
//this function doesnt recive or return anything, it gives the welcoming message 
void print_result (long int result);
//this function recives the difference betwen the dates from input and prints them and doesnt return anything
void print_orders (int order);
//this function indicates the user which date type, it recives the number of the order and doesent return anything
void print_invalid (void);
//this function doesnt recive or return anything, it prints the msg if theres a invalid input

char d1=DAY_MONTH, d2=DAY_MONTH;	//Variables Globales: d=dia, m=mes, a=year
char b1=DAY_MONTH, b2=DAY_MONTH;	//Se eligio la utilizacion de variables globales para facilitar el pasaje de informacion
char m1=DAY_MONTH, m2=DAY_MONTH;	//a las funciones. Se inicializan todas en valor 0 menos las dos ultimas de year, las cuales
char a1=YEAR, a2=YEAR, a3=YEAR, a4=YEAR;	//si no son modificadas en get_input, se entiende que el usuario eligio
													//utilizar el formato corto de ano.

int main(void)				//////Main function//////
{
	
	int verif, startorfinish=START;
	int yearstart, monthstart, daystart;
	int yearend, monthend, dayend;
	long int daytotal;

	welcome_msg();

	get_date(startorfinish);		//Se toma la fecha y se verifica su validez.
	
	yearstart = make_num(a1, a2, a3, a4);						//Luego, se compone el numero.
	monthstart = make_num(m1, m2, DAY_MONTH, DAY_MONTH);
	daystart = make_num(d1, d2, DAY_MONTH, DAY_MONTH);

	startorfinish = FINISH;			//Se informa que la fecha a recibir es ahora la final.
	get_date(startorfinish);		//Se toma la fecha y se verifica su validez.

	yearend = make_num(a1, a2, a3, a4);							//uego, se compone el numero.
	monthend = make_num(m1, m2, DAY_MONTH, DAY_MONTH);
	daystart = make_num(d1, d2, DAY_MONTH, DAY_MONTH);

	daytotal = calc_days(daystart, monthstart, yearstart, dayend, monthend, yearend); //Mediante el algoritmo, se calcula
																						//la cantidad totales de dias.
	print_result(daytotal); //Y se la informa al usuario.

return 0;
}

////////////////////////////MAKING THE NUMBER///////////////////////////////////////////////

int make_num (char first,char second, char third, char fourth)
{
	int number;
	
	if (third == DAY_MONTH )	//it checks which format is the number, or if its a year ir day/month 
	{
		number= (((first-ASCII)*10)+(second-ASCII));
	}
        else if (third == YEAR)
        {
                number= (2000+((first-ASCII)*10)+(second-ASCII));
        }	
	
	else 
	{
		number=(((first-ASCII)*1000)+((second-ASCII)*100)+((third-ASCII)*10)+(fourth-ASCII));
	}

	return number;
}

///////////////////////////////////////////////////////////////////////////////////////////
void get_date(int startorfinish)
{

	int verif;

	do {								//Funcion de verificacion y pedido de input de fecha.
										//No sale hasta que el usuario entregue una fecha valida.
		if(startorfinish == START)		//Tambien se checkea si la fecha a pedir es la inicial o la final.
			print_orders(INPUT_FIRST_DATE);
		else
			print_orders(INPUT_SECOND_DATE);
					
		get_input();
		verif = check_input();
		
		if (verif == INCORRECTA)
			print_invalid();				

	} while (verif != INCORRECTA);
}

///////////////////////////////////SCREEN FUNCTIONS///////////////////////////////////////////////

void welcome_msg (void)
{
	printf("Este programa calcula la cantidad de dias comprendidos entre una fecha");
	printf("inicial y una fecha final. Se pide que el formato de entrada de los dias sea de");		
	printf("dd/mm/aaaa o alternativamente de dd/mm/aa.\n");	
}

void print_result (long int result)
{
	printf("El numero de dias comprendido entre las fechas es de: %ld dias.\n\n", result);
}
void print_orders (int order)
{
	if (order==INPUT_FIRST_DATE)
		printf("Ingresar fecha inicial:\n");
	else 
		printf("Ingresar fecha final:\n");
}
void print_invalid (void)
{
	printf("Formato de fecha invalido.\n");
}

//////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////IMPUT FUNCTION/////////////////////////////////////////
void get_input(void)
{
	int caracter, count=0, freno=0;
	int i;
for(i=0 ; (i<10 && (freno <1)) ; i++)	//Si se recibe un enter, freno se activa y no itera.
	{
		caracter=getchar();
		switch(++count)	//Un caso para cada variable
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
}
//////////////////////////////////////////////////////////////////////////////////////////
