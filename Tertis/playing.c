/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <allegro5/timer.h>
#include <allegro5/keycodes.h>

#include "playing.h"
#include "general.h"

void continueplay(AL_UTILS* al_utils, GAME_UTILS* gamevars){

    if(!(al_get_timer_started)){
        al_start_timer(al_utils->timer); //Se fija si esta parado el timer, si lo esta, lo arranca
    }
    
    
    if((al_get_timer_speed(al_utils->timer)) != (gamevars->timer_speed)){
        al_set_timer_speed(al_utils->timer, gamevars->timer_speed); // Se fija si cambio la velocidad, si lo hizo
    }                                                     // cambia la velocidad del timer.
    
}

void getplayevents(AL_UTILS* al_utils, GAME_UTILS* gamevars, PIECE matrix[TABLE_FIL][TABLE_COL], PIECE piece_mat[MAT_PIECE_FIL][MAT_PIECE_COL]){
    
    ALLEGRO_EVENT event;
    int key_pressed = 0;
    
    if(al_get_next_event(al_utils->queue, &event)){ //Me fijo si hay eventos
        
        if(event.type == ALLEGRO_EVENT_KEY_DOWN){
            al_utils->keyboard = true;
            key_pressed = event.keyboard.keycode;
        }

        if(event.type == ALLEGRO_EVENT_TIMER){         
            gamevars->draw = true;         
            if(al_utils->keyboard){               
                al_utils->keyboard = false;               
                switch(key_pressed){
                    case ALLEGRO_KEY_ESCAPE: gamevars->state = MENU; break;
                    case ALLEGRO_KEY_UP:
                        if(check_rotate(matrix))
                            rotate(matrix);
                        break;
                    case ALLEGRO_KEY_DOWN:
                        fall_instant(matrix);
                        break;
                    case ALLEGRO_KEY_RIGHT:
                        if(checkMove(matrix, RIGHT))
                            move(matrix, RIGHT);
                        break;
                    case ALLEGRO_KEY_LEFT:
                        if(checkMove(matrix, LEFT))
                            move(matrix, LEFT);
                        break;
                }
            }               
            if(check_fall(matrix))
                fall(matrix);
            else if(can_i_copy(matrix)){
                copy_piece_to_mat(matrix, piece_mat); //copiamos la pieza a la matriz
                gamevars->currentpiece = init_piece(); //calculamos la proxima pieza
                fill_mat_piece(piece_mat, gamevars->currentpiece); //llenamos la matriz de pieza con la nueva
            }
            else
                gamevars->lose = true; //Si no se puede caer, ni copiar una nueva pieza, se pierde                  
        }   
    }
    
}