#ifndef CALCTIME_H
#define CALCTIME_H

int calcTime(void);
// Esta función devuelve la cantidad de tiempo transcurrido entre un llamado y otro. Pensado para llamados constantes.
// No recibe nada. Devuelve 0 el primer llamado y los siguientes serán el tiempo transcurrido desde el primer llamado al actual.

#define ON 1
#define OFF 0
#define RESETTIME 30 //Cantidad de segundos luego de la cual el programa bajará el flag.


#endif /* CALCTIME_H */