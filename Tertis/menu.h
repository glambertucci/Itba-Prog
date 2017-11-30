#ifndef MENU_H
#define MENU_H

#include <allegro5/events.h>
#include "general.h"


void menu(AL_UTILS * p2al_utils, GAME_UTILS * p2gamevars);
//Recibe puntero al display, a la cola de eventos y a la estructura con variables del juego.
//Si el usuario presiona QUIT, pone QUIT en 1.
//Si el usuario presiona CONTINUE, pone state en PLAYING.
//Si el usuario presiona START, pone QUIT y STATE en 1/PLAYING, indicando un reinicio. 

enum{START,CONTINUE,QUIT};


#define MENUMARGIN 122
#define LETTERSIZE 24 //Obs: Las letras tienen de altura y anchura 24 pixeles.
#define STARTPOSY 418
#define STARTPOSXEND (MENUMARGIN + LETTERSIZE * 4)
#define STARTPOSYEND (STARTPOSY + LETTERSIZE)
#define CONTPOSY 492 
#define CONTPOSXEND (MENUMARGIN + LETTERSIZE * 8)
#define CONTPOSYEND (CONTPOSY + LETTERSIZE)
#define QUITPOSY 566
#define QUITPOSXEND (MENUMARGIN + LETTERSIZE * 4)
#define QUITPOSYEND (QUITPOSY + LETTERSIZE)

#endif