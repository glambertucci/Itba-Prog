//TP PRACTICO N°3 . Funciones, entrada y salida de datos
/*Fecha de creacion 1/9/2017
Grupo 4
Integrantes:
Lambertucci Guido	58009
Hrubisiuk 	Agustin	58311
Mechoulam	Alan	58438
Moriconi	Franco	58495
Este programa recibe por linea de comando dos fechas en formato dd/mm/aa o dd/mm/aaaa y devuelve por pantalla
la cantidad de dias comprendida entre ambas fechas
Nota 1: El programa si recibe fecha 1 > a fecha 2 devolvera la cantidad de dias igualmente
Nota 2: Los dias son tomados con dos cifras aunque sean < 10 ej: "2" debe ser ingresado como "02"
*/

#include <stdio.h>

//////CODIGOS DE ERROR//////

#define INCORRECT (1)
////////////FLAGS///////////////

#define START (0)					
#define FINISH (1)
#define DAY_MONTH 0
#define YEAR (-1)
#define YRMIN 1600 //Año mínimo en el que opera el programa
#define YRMAX 2600 //Año máximo en el que opera el programa
#define BARRA 47 //ASCII de la barra. Es definida para mejor comprensión de lectura del código.

//Enum para reconocer los meses, que se trabaja con meses.
enum {ENE=1,FEB,MAR,ABR,MAY,JUN,JUL,AGO,SET,OCT,NOV,DIC};


////////////////UTILES//////////////
#define ASCII ('0')
#define ASCII2 48 //Útil para desplazar los valores de a1, a2, a3 y a4. EJ: SI a3 = 53, le resto 48 y su valor numérico es 6.
#define BIS1 4 //Un año bisiesto son aquellos divisibles por 4 y no divisible por 100, excepto que sea divisible por 400
#define BIS2 100
#define BIS3 400
#define INPUT_FIRST_DATE 	(1)
#define INPUT_SECOND_DATE (2)

//////Prototipos/////
void reset_values(void);
//Resets the global functions
void get_input(void);			
//This function gets the input from the user
void get_date(int);
//This function gets a validated input from the user
int make_num (char first,char second, char third, char fourth);
//This function recives 4 chars, every number that lacks the third and fourth char must be sent with the proper code in those positions
//if the input is correct, you'll get the composed number  
long int calc_days(int, int, int, int, int, int);
//This function uses an algorithm to calculate the amount of days between both dates
void welcome_msg (void);
//This function doesnt recive or return anything, it gives the welcoming message 
void print_result (long int result);
//This function recives the difference betwen the dates from input and prints them and doesnt return anything
void print_orders (int order);
//This function indicates the user which date type, it recives the number of the order and doesn't return anything
void print_invalid (void);
//This function doesnt recive or return anything, it prints the msg if theres a invalid input
void print_cota (void);
//This function prints the max and min value for the year
int check_input(char, char, char, char, char, char, char, char, char, char);
//This functions checks if the input is valid

char d1=DAY_MONTH, d2=DAY_MONTH;			//Global Variables: d=day, m=month, a=year
char b1=DAY_MONTH, b2=DAY_MONTH;			//Global variables were chosen to facilitate the usage of functions in the program.
char m1=DAY_MONTH, m2=DAY_MONTH;			//All the variables are inicializated with a 0 value except for the years, which
char a1=YEAR, a2=YEAR, a3=YEAR, a4=YEAR;	//are inicializated with a -1 value.





//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(void)				//////Main function//////
{
	
	int startorfinish=START;
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
	dayend = make_num(d1, d2, DAY_MONTH, DAY_MONTH);

	daytotal = calc_days(daystart, monthstart, yearstart, dayend, monthend, yearend); //Mediante el algoritmo, se calcula
																						//la cantidad totales de dias.
	print_result(daytotal); //Y se la informa al usuario.

return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




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
	do {								//Asking and validating the input
		verif = 0;
		reset_values();								//The flow is locked until the user inputs something valid.
		if(startorfinish == START)		//Takes into consideration whether the program has to ask for final or starting date.
		{
			print_orders(INPUT_FIRST_DATE);
		}		
		else
		{
			print_orders(INPUT_SECOND_DATE);
		}
			
		get_input();
		verif = check_input(d1, d2, b1, m1, m2, b2, a1, a2, a3, a4);
		

		if(verif == INCORRECT)
		{
			print_invalid();				
		}
		else if(verif == 2)
		{
		print_cota ();
		}

	} while((verif == INCORRECT) || (verif == 2));

}

///////////////////////////////////SCREEN FUNCTIONS///////////////////////////////////////////////

void welcome_msg (void)
{
	printf("Este programa calcula la cantidad de dias comprendidos entre una fecha ");
	printf("inicial y una fecha final. Se pide que el formato de entrada de los dias sea de ");		
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
void print_cota (void)
{
	printf("El programa opera entre los años %d y %d. Ingrese una fecha entre esos años.\n", YRMIN, YRMAX);
}

//////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////INPUT FUNCTION/////////////////////////////////////////
void get_input(void)
{
	int character=0, count=0, brake=0;
	int i;

	for(i=0 ; (i<10 && (brake != 1)) ; i++)	//When enter is read, brake activates and the loop is broken.
	{
		character=getchar();
		
		switch(++count)	//A case for each variable
		{				//If a variable is not modificated, it remains with the inicial value. This is important, as it
			case 1:		//contributes to the flow of the program.
				if(character== '\n' ) {
					brake=1;
				}
				else
					d1=character;
				break;
			case 2:
				if(character== '\n' ) {
					brake=1;
				}
				else
					d2=character;
				break;
			case 3:
				if(character== '\n' ) {
					brake=1;
				}
				else
					b1=character;
				break;
			case 4:
				if(character== '\n' ) {
					brake=1;
				}
				else
					m1=character;
				break;
			case 5:
				if(character== '\n' ) {
					brake=1;
				}
				else
					m2=character;
				break;
			case 6:
				if(character== '\n' ) {
					brake=1;
				}
				else
					b2=character;
				break;
			case 7:
				if(character== '\n' ) {
					brake=1;
				}
				else
					a1=character;
				break;
			case 8:
				if(character== '\n' ) {
					brake=1;
				}
				else
					a2=character;
				break;
			case 9:
				if(character== '\n' ) {
					brake=1;
				}
				else
					a3=character;
				break;
			case 10:
				if(character== '\n' )
				{
					brake=1;
					a4=character;

				}
				else {
					a4=character;
					character=getchar();
				}
				break;
		}
	}

}
//////////////////////////////////////////////////////////////////////////////////////////

void reset_values(void)
{
	b2=m2=m1=b1=d2=d1=DAY_MONTH;
	a4=a3=a2=a1=YEAR;
}

//////////////////////////////////////////////////////////////////////////////////////////
int check_input(char d1, char d2, char b1, char m1, char m2, char b2, char a1, char a2, char a3, char a4)
{

	d1 = d1-ASCII2;
	d2 = d2-ASCII2;
	m1 = m1-ASCII2;
	m2 = m2-ASCII2;
	a1 = a1-ASCII2;
	a2 = a2-ASCII2; //No modifico a3 y a4 porque si su valor en ASCII es 0, se trata del terminador, el cual debo discriminar.

	int day;
	int month;
	int year;
	int format;

/***********************
	Mes
***********************/

	if((m1 < 0) || (m1 > 1) || (m2 < 0) || (m2 > 9)) //Si m1 o m2 son distintos de 0/1 o 0-9 el input es erroneo
	{
		return 1;
	}

	month = (m1*10+m2); //Defino month como la suma de los números que el usuario haya introducido.

	if((month > 12) || (month < 1)) //Si la suma de números no da un número de 1 a 12, el input es invalido (Ej: 00 o 17 no son meses)
	{
		return 1;
	}


/******************
	Barras
******************/

	if(b1 != BARRA) //Los caracteres 3 y 6 deben ser "/", cuyo valor en ASCII es 47, debido al formato dd/mm/aaaa o dd/mm/aa.
	{
		return 1;
	}
	else if(b2 != BARRA) //Nuevamente , tiene que haber un slash en esta posición.
	{
		return 1;
	}

/*******************
	Años
*******************/
	
	if((a1 < 0) || (a1 > 9)) //Los años pueden tomar cualquier valor en cualquier cifra.
	{
		return 1;
	}
	else if((a2 < 0) || (a2 > 9)) 
	{
		return 1;
	}
	else if((((a3 < 48) || (a3 > 57))) && (a3 != -1)) //Estos dos últimos pueden no estar (formato dd/mm/aa) por lo que evalúo...
	{
		return 1;
	}
	else if(((a4 < 48) || (a4 > 57)) && (a4 != -1))//...que si no son números, entonces aún pueden ser el terminador.
	{
		return 1; //Si tampoco son el terminador, será falso, puesto que el input es incorrecto.
	}
	else if((a3 == -1))
	{
		format = 1; //1 indica que el número es válido pero en formato dd/mm/aa
	}
	else if((a3 != -1))
	{
		format = 2; //2 indica que el número es válido pero en formato dd/mm/aaaa
	}	


	if(format == 2)
	{
		year = ((a1*1000+a2*100+(a3-ASCII2)*10+(a4-ASCII2))); /* Compongo el año multiplicando los valores traducidos desde 									ASCII por 1000, 100, 10 y 1 correspondientementes y sumandolos. */
	}
	else if(format == 1) //Si es es el formato 1, asumo que es el siglo XXI y multiplico los componentes por 10 y 1 para sumarlos.
	{
		year = 2000+a1*10+a2;
	}

/*********************
	Días
**********************/
//Evaluación del día (Validez de la fecha introducida)

	if(((d1 > 3) || (d1 < 0)) || ((d2 < 0) || (d2 > 9)))//Si d1 o d2 son distintos de 0-3 o 0-9 el input es erroneo
	{
		return 1;
	}

	day = (d1*10+d2); //Defino day como la suma de los números que el usuario haya introducido.


	if(day > 31 || day < 1) //Si la suma de números no da un número de 1 a 12, el input es invalido (Ej: 00 o 32 no son dias)
	{
		return 1;	
	}


//Evaluación del día (Valor en relación a los meses o años que pertenezca)

	if((month == ENE) || (month == MAR) || (month == MAY) || (month == JUL) || (month == AGO) || (month == OCT) || (month == DIC))
	{
		if(day > 31) //Los meses dentro del if son aquellos con 31 días.
		{
			return 1;
		}
	}
	else if((month == FEB))
	{
		if(day > 29) //Febrero tiene 28 días, 29 en bisiestos.
		{
			return 1;
		}
		else if((day == 29) && !((((year % BIS1) == 0)) && (((year%BIS2) != 0) || ((year%BIS3) == 0)))) 
		/* "Si es 29 y no es bisiesto, es error*/
		{
			return 1;
		}

	}
	else //Todos los demás casos son meses de 30 días...
	{
		if(day > 30) //...Por lo que si el valor de la variable day es mayor a 30, el input es inválido.
		{
		return 1;
		}
	}		

	if(year < YRMIN || year > YRMAX) //Limito el rango en el que opera el programa.
	{
		return 2; //Devuelvo un error diferente para indicar que el input es técnicamente válido, pero el programa no lo trabaja.
	}
	return 0;

}

long int calc_days(int d1, int m1, int a1, int d2, int m2, int a2)
{
    int dia1 = d1;
    int mes1 = 0;
    int anio1 = 0;
    int bisiestos_1 = 0;    //la inicializo para limpiarla preventivamente
    int cantidad_1 = 0;
    int dia2 = d2;
    int mes2 = 0;
    int anio2 = 0;
    int bisiestos_2 = 0;    //la inicializo para limpiarla preventivamente
    int cantidad_2 = 0;
    int total = 0;

 //fecha inicial
    anio1 = (a1-1)*365; //calculo la cantidad de dias de los años ya transcurridos

    if (m1 == 1)        //dependiendo de qué mes sea, sumo la cantidad de dias de los meses ya transcurridos
        mes1 = 0;
    if (m1 == 2)
        mes1 = 31;
    if (m1 == 3)
        mes1 = 31+28;
    if (m1 == 4)
        mes1 = 31+28+31;
    if (m1 == 5)
        mes1 = 31+28+31+30;
    if (m1 == 6)
        mes1 = 31+28+31+30+31;
    if (m1 == 7)
        mes1 = 31+28+31+30+31+30;
    if (m1 == 8)
        mes1 = 31+28+31+30+31+30+31;
    if (m1 == 9)
        mes1 = 31+28+31+30+31+30+31+31;
    if (m1 == 10)
        mes1 = 31+28+31+30+31+30+31+31+30;
    if (m1 == 11)
        mes1 = 31+28+31+30+31+30+31+31+30+31;
    if (m1 == 12)
        mes1 = 31+28+31+30+31+30+31+31+30+31+30;

    bisiestos_1 = (a1/4) - (a1/100) + (a1/400); //Un año es bisiesto si: es divisible por 4 pero no por 100.
                                                //                       es divisible por 100 y es divisible por 400.
                                                //Acá primero consideramos todos los bisiestos que habria "a grandes rasgos" (al considerar
                                                //que hay un bisiesto cada 4 años); luego le restamos la cantidad de años que cambia de centena
                                                //(porque si solo es divisible por 100 y no por 400 no es bisiesto, como el 1700 o el 1900);
                                                //y por ultimo sumamos los años que "eliminamos por error" en la resta anterior (habiamos eliminado
                                                //todos los divisibles por 100, pero los que son divisibles por 100 y por 400 a la vez SI son bisiestos,
                                                //como el 1600 y el 2000).


    cantidad_1 = anio1 + mes1 + dia1 + bisiestos_1; //obtengo la cantidad de dias transcurridos hasta la fecha introducida


//fecha final
    anio2 = (a2-1)*365; //calculo la cantidad de dias de los años ya transcurridos


    if (m2 == 1)    //dependiendo de qué mes sea, sumo la cantidad de dias de los meses ya transcurridos
        mes2 = 0;
    if (m2 == 2)
        mes2 = 31;
    if (m2 == 3)
        mes2 = 31+28;
    if (m2 == 4)
        mes2 = 31+28+31;
    if (m2 == 5)
        mes2 = 31+28+31+30;
    if (m2 == 6)
        mes2 = 31+28+31+30+31;
    if (m2 == 7)
        mes2 = 31+28+31+30+31+30;
    if (m2 == 8)
        mes2 = 31+28+31+30+31+30+31;
    if (m2 == 9)
        mes2 = 31+28+31+30+31+30+31+31;
    if (m2 == 10)
        mes2 = 31+28+31+30+31+30+31+31+30;
    if (m2 == 11)
        mes2 = 31+28+31+30+31+30+31+31+30+31;
    if (m2 == 12)
        mes2 = 31+28+31+30+31+30+31+31+30+31+30;


    bisiestos_2 = (a2/4)- (a2/100) + (a2/400);  //un año es bisiesto si: es divisible por 4 pero no por 100.
                                                //                       es divisible por 100 y es divisible por 400.
                                                //acá primero consideramos todos los bisiestos que habria "a grandes rasgos" (al considerar
                                                //que hay un bisiesto cada 4 años); luego le restamos la cantidad de años que cambia de centena
                                                //(porque si solo es divisible por 100 y no por 400 no es bisiesto, como el 1700 o el 1900);
                                                //y por ultimo sumamos los años que "eliminamos por error" en la resta anterior (habiamos eliminado
                                                //todos los divisibles por 100, pero los que son divisibles por 100 y por 400 a la vez SI son bisiestos,
                                                //como el 1600 y el 2000).


    cantidad_2 = anio2 + mes2 + dia2 + bisiestos_2; //obtengo la cantidad de dias transcurridos hasta la fecha introducida

//calculo de dias
    if (cantidad_1 < cantidad_2)
        total = cantidad_2 - cantidad_1;   //obtengo la cantidad de dias transcurridos entre las fechas introducidas
    else
        total = cantidad_1 - cantidad_2;

    return total;
}

