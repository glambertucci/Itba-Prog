/*Operaciones*/

double sum (double num1, double num2);

double res (double num1, double num2);

double mul (double num1, double num2);

double div (double num1, double num2);

double and (double num1, double num2);

double or (double num1, double num2);

double xor (double num1, double num2);


// Arreglos globales
double (* actions [MAX_OPERATORS]) (double, double);
char operator [MAX_OPERATORS];

