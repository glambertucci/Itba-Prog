/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "general.h"


void pauseplay (AL_UTILS* al_utils, GAME_UTILS* gamevars){ //Cuando se entra al estado menu, se para el timer
    
    if(al_get_timer_started(al_utils->timer))
        al_stop_timer(al_utils->timer);
}

void getmenuevents (AL_UTILS* al_utils, GAME_UTILS* gamevars){ //Esta funcion toma los eventos durante el
                                                               //estado de menu
    ALLEGRO_EVENT event;
    int key_pressed = 0;
    
    if(al_get_next_event(al_utils->queue, &event)){
        
        if(event.type == ALLEGRO_EVENT_KEY_DOWN){
            al_utils->keyboard->keyboardpress = true;
            al_utils->keyboard->key = event.keyboard.keycode;
        }
        if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
            al_utils->mouse->mousepress = true;
            al_utils->mouse->x = event.mouse.x;
            al_utils->mouse->y = event.mouse.y;
        }
        if((al_utils->keyboard->keyboardpress) && (!(al_utils->mouse->mousepress))){
            /*
             
             
             
             ACA PONEMOS QUE PASA CANDO SE APRETA EL TECLADO
             
             
             
             
             */
        }
        if((!(al_utils->keyboard->keyboardpress)) && (al_utils->mouse->mousepress)){
            /*
             
             
             
             ACA PONEMOS QUE PAS CUADO SE APRETA EL MAUSE
             
             
             
             
             */
        }
    }
    
}