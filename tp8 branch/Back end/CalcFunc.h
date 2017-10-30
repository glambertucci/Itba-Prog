#ifndef CALCFUNC_H
#define CALCFUNC_H

double calcRes(double, double, char);
//Realiza las operaciones aritmeticas dependiendo de lo que recibe
#define MAX_OP 7
//addOperation, se encarga de rellenar los arreglos globales con los operadores y punteros necesarios
void addOperation(int);

//calcRes: recibe numeros (double) y el operador, con los cuales realiza la cuenta y la devuelve 
double calcRes (double num1, double num2 , char op);

//Funciones basicas de calculo
double xorr (double, double);
double summ (double, double);
double ress (double, double);
double mull (double, double);
double divi (double, double);
double andd (double, double);
double orr (double, double);

#endif