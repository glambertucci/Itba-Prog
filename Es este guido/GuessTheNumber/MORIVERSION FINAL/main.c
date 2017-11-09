#include "guessNumberFunctions.h"
#include "frontEnd.h"
#include "termlib.h"
#include <stdio.h>
#include "general.h"

int main(void) {
    
    int RandomNumber = 0, Guess, Time = 0, Temp;             
    
    RandomNumber = initRandNum(MAXRANDNUM);                 //Calcula el numero aleatorio, con maximo 9 hardcodeado.
    printScreen(INIT, Time);                                //Printea la bienvenida
    while(kbhit() == 0){}                                   //Avanzará solo cuando se presione una tecla.
    
    while ((Time < MAXTIME) && (Guess != RandomNumber)) {
        Time = calcTime();                                  //Pregunta cuanto tiempo paso

	if(Time != calcTime())
        printScreen(GUESS, Time);
   
        if (((Guess = getch()) != RandomNumber)){             //Se fija si lo metido es el numero correcto
            Temp = Time;
            while ((Temp + PENALTY) > (Time = calcTime())) 
            {                                                  //Espera hasta que el tiempo de penalty haya pasado.
                if(Time != calcTime()){
                printScreen(TRYAGAIN, Time);                    //Printea la pantalla pidiendo otro numero
                }
            }
        
        }
    }
    if (Guess == RandomNumber) {                             //Si el numero es correcto
        printScreen(WIN, Time);
        getchar();
    }
    else {
        printScreen(LOSE, MAXTIME);                            //Si el numero es incorrecto
        getchar();
    }
    return 0;
}
