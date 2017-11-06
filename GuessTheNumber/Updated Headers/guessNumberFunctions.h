#ifndef GUESSNUMBERFUNCTIONS_H
#define GUESSNUMBERFUNCTIONS_H

int calcTime(void);
// Esta función devuelve la cantidad de tiempo transcurrido entre un llamado y otro. Pensado para llamados constantes.
// No recibe nada. Devuelve 0 el primer llamado y los siguientes serán el tiempo transcurrido desde el primer llamado al actual.

int initRandNum(int maxnum);
//Esta función genera un número positivo al azar. Recibe como input el número máximo que se desea y devuelve 
//un número menor al módulo de dicho número.

#define RANDNUM -32
#define ON 1
#define OFF 0
#define RESETTIME 30 //Cantidad de segundos luego de la cual el programa bajará el flag.


#endif /* GUESSNUMBERFUNCTIONS_H */
