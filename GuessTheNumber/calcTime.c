/*
 * 
 * 
 * 
 * 
 * TODO ESTO VA EN CALCTIME.H
 * 
 * 
 * 
 * 
 *  #include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calcTime(void);
// Devuelve la cantidad de tiempo transcurrido entre un llamado y otro. Pensado para llamados constantes.
// No recibe nada. Devuelve 0 el primer llamado y los siguientes serán el tiempo transcurrido desde el primer llamado al actual.

#define ON 1
#define OFF 0
#define RESETTIME 30 //Cantidad de segundos luego de la cual el programa bajará el flag.
*/
int calcTime(void)
{
    static long int ctInitFlag = OFF;//Inicializo el flag que usaré para distinguir el primer llamado de los siguientes. Static para persistencia.
    static long int ctStartValue; //En esta variable se guardará el segundo en el cual se levanta el flag y servirá de referencia para el paso del tiempo.
    static long int currentTime; //Aquí almaceno el tiempo actual para calcular la diferencia con el anterior
    long int timeDelta = 0; //En esta variable se almacena la diferencia de tiempo entre que se levantó el flag y el llamado actual.

    if (ctInitFlag == OFF)
    {
        ctInitFlag = ON; //Levanto el flag
        ctStartValue = time(NULL);
        timeDelta = 0; // Así devuelvo 0 el primer llamado, como se espera del programa.
        
    }
    else
    {
        currentTime = time(NULL); //Le asigno el valor del reloj actual a la variable correspondiente.
        timeDelta = (currentTime - ctStartValue); //Calculo la diferencia de tiempo entre llamados
    }
    
    
    if( timeDelta >= RESETTIME )
    {
     ctInitFlag = OFF; //Apago el flag, de esta manera luego ctStartValue se volverá a inicializar.
     timeDelta = RESETTIME;
    }
    
    
    return timeDelta;
}