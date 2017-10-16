#include <stdio.h>
#include <string.h>
#include "CalcFunc.h"


extern char operands[];
extern double (* functions []) (double, double);


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
	else if (mode == 1)
	{
		for (index=0;index<7;index++)
		{
			operands[index]=letters[index];
		}
	}

	double (* sum_pointer) (double, double)= &summ;
	double (* res_pointer) (double,double)=&ress;
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
