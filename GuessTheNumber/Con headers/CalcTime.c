#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "calcTime.h"

int main()
{
    int x = 0;
    int y1 = RESETTIME;
    int y2 = 0;
    
    while (y1 != 0)
    {

        x = calcTime();
        y1 = RESETTIME - x;
        
        if(y1 != y2)
        {
            y2 = y1;
            printf("Pasaron %d segundos\n", x);
        }
    }
    
    printf("ahre\n");
    
    return 0;
}

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
