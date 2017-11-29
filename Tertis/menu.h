#ifndef MENU_H
#define MENU_H

#include <allegro5/events.h>
#include "general.h"


int menu(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE *event_queue);
//Recibe puntero al display. 
//Devuelve 2 (QUIT),  1 (CONTINUE), 0 (START).
//En caso de error, devuelve -1.

enum{START,CONTINUE,QUIT};


#define MENUMARGIN 122
#define LETTERSIZE 24 //Obs: Las letras tienen de altura y ancho 24 pixeles.
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