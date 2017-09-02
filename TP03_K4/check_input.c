#include<stdio.h>

#define ENE 1 //Estas definiciones me permitiran trabajar con los meses
#define FEB 2 //El objetivo es determinar el mes componiendolo a partir de las variables m1 y m2
#define MAR 3 //Una vez hecho esto, puedo determinar las condiciones de los días (EJ: Abril no puede tener mas de 30 días)
#define ABR 4 //Si no hiciera esta composición con m1 y m2, evaluar los días en función de m1 y m2 sería mucho más difícil.
#define MAY 5
#define JUN 6
#define JUL 7
#define AGO 8
#define SEP 9
#define OCT 10
#define NOV 11
#define DIC 12

#define ASCII 48 //Útil para desplazar los valores de a1, a2, a3 y a4. EJ: SI a3 = 53, le resto 48 y su valor numérico es 6.

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

	int dia;
	int mes;
	int year;
	int format;

	switch(m1 == 1) //¿El primer dígito es 1?
	{
	case 1:
		if(m2 == 0) //Si lo es, evalúo si es octubre, noviembre o diciembre.
		{
			mes = OCT;
		}
		else if(m2 == 1)
		{
			mes = NOV;
		}
		else if(m2 == 2)
		{
			mes = DIC;
		}
		else 
		{
			return 0; // Si el primer dígito es 1 pero el segundo es mayor a 2, entonces el input es inválido.
		}
	case 0:
		switch(m1 == 0) //Evalúo los casos en los que el primer dígito es 1.
		{
			case 1:
				if(m2 == 0)
				{
					return 0;
				}
				else if(m2 == 1)
				{
					mes = ENE;
				}
				else if(m2 == 2)
				{
					mes = FEB;
				}
				else if(m2 == 3)
				{
					mes = MAR;
				}
 				else if(m2 == 4)
				{
					mes = ABR;
				}
				else if(m2 == 5)
				{
					mes = MAY;
				}
				else if(m2 == 6)
				{
					mes = JUN; 
				}
				else if(m2 == 7)
				{
					mes = JUL;
				}
				else if(m2 == 8)
				{
					mes = AGO;
				}
				else if(m2 == 9)
				{
					mes = SEP;
				}
			case 0:
				{
				return 0; //Si el primer dígito no es 0 o 1, el input es inválido.
				}
			default:
				{
				return 0;
				}
		}
	}
	

/******************
	Barras
******************/

	if(b1 != 47) //Los caracteres 3 y 6 deben ser "/", cuyo valor en ASCII es 47, debido al formato dd/mm/aaaa o dd/mm/aa.
	{
		return 0;
	}
	else if(b2 != 47) //Nuevamente , tiene que haber un slash en esta posición.
	{
		return 0;
	}

/*******************
	Años
*******************/
	
	else if(a1 < 0 || a1 > 9) //Los años pueden tomar cualquier valor en cualquier cifra.
	{
		return 0;
	}
	else if(a2 < 0 || a2 > 9) 
	{
		return 0;
	}
	else if((a3 < 48 || a3 > 57) && a3 != 0) //Estos dos últimos pueden no estar (formato dd/mm/aa) por lo que evalúo...
	{
		return 0;
	}
	else if((a4 < 48 || a4 > 57) && a4 != 0)//...que si no son números, entonces aún pueden ser el terminador.
	{
		return 0; //Si tampoco son el terminador, será falso, puesto que el input es incorrecto.
	}
	else if (a3 == 0 && a4 == 0)
	{
		format = 2; //2 indica que el número es válido pero en formato dd/mm/aa
	}
	else
	{
		format = 1; //1 indica que el número es válido pero en formato dd/mm/aaaa
	}

	if(format == 1)
	year = ((a1*1000+a2*100+(a3-ASCII)*10+(a4-ASCII))); /* Compongo el año multiplicando los valores traducidos desde ASCII
							por 1000, 100, 10 y 1 correspondientementes y sumandolos. */
	else if(format==2) //Si es es el formato 2, asumo que es el siglo XXI y multiplico los componentes por 10 y 1 para sumarlos.
	year = 2000+a1*10+a2;

/*********************
	Días
**********************/
	if((mes == ENE) || (mes == MAR) || (mes == MAY) || (mes == JUL) || (mes == AGO) || (mes == OCT) || (mes == DIC))
	{
		if((d1 == 3) && (d2 > 1)) //Si el primer dígito es 3, el segundo no puede ser mayor a 1.
		{
			return 0;
		}
		else if(d1 > 3) //Y si el primero es mayor a 3, el input es inválido.
		{
			return 0;
		}
	}
	else if((mes == FEB))
	{
		if(d1 == 3)
		{
			return 0;
		}
		else if((d1 == 2) && (d2 == 9) && (((year % BIS1) == 0)) && (((year%BIS2) != 0) || ((year%BIS3) == 0))) 
		/* "Si es 29 y no es bisiesto, es error*/
		{
			return 0;
		}
	}
	else //Todos los demás casos son meses de 30 días...
	{
		if(d1 == 3 && d2 > 0) //...Por lo que si el primer dígito es 3 y el segundo es mayor a 0, hay error.
		{
		return 0;
		}
		
	}
	dia = (d1*10+d2);
	return 1;

}
