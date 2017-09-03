#include<stdio.h>

#define ENE 1 //Estas definiciones existen para que se entienda, en el código, que se trabaja con meses.
#define FEB 2 
#define MAR 3 
#define ABR 4 
#define MAY 5
#define JUN 6
#define JUL 7
#define AGO 8
#define SEP 9
#define OCT 10
#define NOV 11
#define DIC 12


#define YRMIN 1600 //Año mínimo en el que opera el programa
#define YRMAX 2600 //Año máximo en el que opera el programa

#define ASCII 48 //Útil para desplazar los valores de a1, a2, a3 y a4. EJ: SI a3 = 53, le resto 48 y su valor numérico es 6.
#define BARRA 47 //ASCII de la barra. Es definida para mejor comprensión de lectura del código.

#define BIS1 4 //Un año bisiesto son aquellos divisibles por 4 y no divisible por 100, excepto que sea divisible por 400
#define BIS2 100
#define BIS3 400

int check_input(int, int, int, int, int ,int ,int ,int, int, int);

int check_input(int d1, int d2, int b1, int m1, int m2, int b2, int a1, int a2, int a3, int a4)
{

	d1 = d1-ASCII;
	d2 = d2-ASCII;
	m1 = m1-ASCII;
	m2 = m2-ASCII;
	a1 = a1-ASCII;
	a2 = a2-ASCII; //No modifico a3 y a4 porque si su valor en ASCII es 0, se trata del terminador, el cual debo discriminar.

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
	else if((((a3 < 48) || (a3 > 57))) && (a3 != 0)) //Estos dos últimos pueden no estar (formato dd/mm/aa) por lo que evalúo...
	{
		return 1;
	}
	else if((((a4 < 48) || (a4 > 57))) && (a4 != 0))//...que si no son números, entonces aún pueden ser el terminador.
	{
		return 1; //Si tampoco son el terminador, será falso, puesto que el input es incorrecto.
	}
	else if((a3 == 0) && (a4 == 0))
	{
		format = 1; //1 indica que el número es válido pero en formato dd/mm/aa
	}
	else if((a3 != 0) && (a4 != 0))
	{
		format = 2; //2 indica que el número es válido pero en formato dd/mm/aaaa
	}	
	else
	{
		return 1;
	}


	if(format == 2)
	{
		year = ((a1*1000+a2*100+(a3-ASCII)*10+(a4-ASCII))); /* Compongo el año multiplicando los valores traducidos desde 									ASCII por 1000, 100, 10 y 1 correspondientementes y sumandolos. */
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
	}
	else //Todos los demás casos son meses de 30 días...
	{
		if(day > 30) //...Por lo que si el valor de la variable day es mayor a 30, el input es inválido.
		{
		return 1;
		}
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
	if(year < YRMIN || year > YRMAX) //Limito el rango en el que opera el programa.
	{
		return 2; //Devuelvo un error diferente para indicar que el input es técnicamente válido, pero el programa no lo trabaja.
	}
	return 0;

}
