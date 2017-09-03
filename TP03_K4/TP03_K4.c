#include <stdio.h>

//////Definiciones//////

#define INCORRECT (0)
#define START (0)					
#define FINISH (1)
#define DAY_MONTH 0
#define YEAR (-1)
#define ASCII ('0')
#define INPUT_FIRST_DATE 	(1)
#define INPUT_SECOND_DATE (2)


//////Prototipos/////
void reset_values(void);
//Resets the global functions
void get_input(void);			
//This function gets the input from the user
void get_date(int);
//This function gets a validated input from the user
int check_input(void);
//This function validates the input from the user
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
//This function indicates the user which date type, it recives the number of the order and doesent return anything
void print_invalid (void);
//This function doesnt recive or return anything, it prints the msg if theres a invalid input

char d1=DAY_MONTH, d2=DAY_MONTH;			//Global Variables: d=day, m=month, a=year
char b1=DAY_MONTH, b2=DAY_MONTH;			//Global variables were chosen to facilitate the usage of functions in the program.
char m1=DAY_MONTH, m2=DAY_MONTH;			//All the variables are inicializated with a 0 value except for the years, which
char a1=YEAR, a2=YEAR, a3=YEAR, a4=YEAR;	//are inicializated with a -1 value.





//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	reset_values();
	get_date(startorfinish);		//Se toma la fecha y se verifica su validez.

	yearend = make_num(a1, a2, a3, a4);							//uego, se compone el numero.
	monthend = make_num(m1, m2, DAY_MONTH, DAY_MONTH);
	daystart = make_num(d1, d2, DAY_MONTH, DAY_MONTH);

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
										//The flow is locked until the user inputs something valid.
		if(startorfinish == START)		//Takes into consideration whether the program has to ask for final or starting date.
			print_orders(INPUT_FIRST_DATE);
		else
			print_orders(INPUT_SECOND_DATE);
					
		get_input();
		verif = check_input();
		
		if (verif == INCORRECT)
			print_invalid();				

	} while (verif != INCORRECT);
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
	int character, count=0, brake=0;
	int i;
for(i=0 ; (i<10 && (brake <1)) ; i++)	//When enter is read, brake activates and the loop is broken.
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
				else
					a4=character;
				break;
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////

void reset_values(void)
{
	d1=d2=b1=m1=m2=b2=DAY_MONTH;	//Resets global values
	a1=a2=a3=a4=YEAR;
	
}