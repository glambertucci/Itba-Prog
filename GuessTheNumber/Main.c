#include <stdio.h>
#include <stdlib.h>
#include <termlib.h>

enum {INIT, ASKNUM, TRYAGAINLOL, WIN, LOSE}

int main(void) {
    
    int RandomNumber = 0, Guess = -1, Time = 0;             //Guess en -1 por si no se ingreso ningun numero
    
    printScreen(INIT);                                      //Printea la bienvenida
    RandomNumber = initRandomNumber();                      //Calcula el numero aleatorio
    
    while ((Time != 30) ||(Guess != RandomNumber)) {
        Time = calcTime();                                  //Pregunta cuanto tiempo paso
        printScreen(ASKNUM);                                //Printea la pantalla pidiendo numero
        if ((Guess = getch()) != RandomNumber)              //Se fija si lo metido es el numero correcto
            printScreen(TRYAGAINLOL);                       //Printea la pantalla pidiendo otro numero
    }
    
    if (Guess = RandomNumber) {                             //Si el numero es correcto
        printScreen(WIN);
        getchar();
    }
    
    else {
        printScreen(LOSE);                                  //Si el numero es incorrecto
        getchar();
    }

    
    return (EXIT_SUCCESS);
}

