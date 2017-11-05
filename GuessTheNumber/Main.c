#include "Main.h"
#include "printScreen.h"
#include "initRandNum.h"
#include "termlib.h"

enum {INIT, TRYAGAIN, WIN, LOSE};  //esto
#define MAXRANDNUM 9                //esto
#define MAXTIME 10                      //esto
#define PENALTY 2                   //y esto van en el main.h AGUUUUUUUUUUUUUUS

int main(void) {
    
    int RandomNumber = 0, Guess, Time = 0, Temp;             
    
    printScreen(INIT, Time);                                //Printea la bienvenida
    RandomNumber = initRandomNumber(MAXRANDNUM);                     //Calcula el numero aleatorio, con maximo 9 hardcodeado.
    scanf("%d", &Guess);                                    //Bloquea el programa antes de empezar el tiempo
    
    while ((Time < MAXTIME) ||(Guess != RandomNumber)) {
        Time = calcTime();                                  //Pregunta cuanto tiempo paso
        if ((Guess = getch()) != RandomNumber){             //Se fija si lo metido es el numero correcto
            printScreen(TRYAGAIN, Time);                    //Printea la pantalla pidiendo otro numero
            Temp = Time;
            while ((Temp + PENALTY) != (Time = calcTime())) {//Espera hasta que el tiempo de penalty haya pasado. 
            }
        }
    }
    if (Guess = RandomNumber) {                             //Si el numero es correcto
        printScreen(WIN, Time);
        getchar();
    }
    else {
        printScreen(LOSE, Time);                            //Si el numero es incorrecto
        getchar();
    }
    return 0;
}

