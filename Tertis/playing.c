/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <allegro5/timer.h>
#include <allegro5/keycodes.h>

#include "checkMove.h"
#include "move.h"
#include "checkRotate.h"
#include "rotate.h"
#include "check_fall.h"
#include "fall.h"
#include "fall_instant.h"
#include "playing.h"
#include "general.h"

void continueplay(AL_UTILS* al_utils, GAME_UTILS* gamevars){ //Se fija si esta parado el timer, si lo esta, lo arranca

    if(!(al_get_timer_started)){
        al_start_timer(al_utils->timer);
    }
}

void getplayevents(AL_UTILS* al_utils, GAME_UTILS* gamevars, PIECE matrix[TABLE_FIL][TABLE_COL], PIECE piece_mat[MAT_PIECE_FIL][MAT_PIECE_COL]){
    
    ALLEGRO_EVENT event; //Esta funcion toma los eventos durante el estado playing
    
    if(al_get_next_event(al_utils->queue, &event)){
        
        if(event.type == ALLEGRO_EVENT_KEY_DOWN){
            al_utils->keyboard->pressed = true;
            al_utils->keyboard->key = event.keyboard.keycode;
        }

        if(event.type == ALLEGRO_EVENT_TIMER){         
            gamevars->draw = true;         
            if(al_utils->keyboard->pressed){               
                al_utils->keyboard->pressed = false;               
                switch(al_utils->keyboard->key){
                    case ALLEGRO_KEY_ESCAPE:
                        gamevars->state = MENU;
                        break;
                    case ALLEGRO_KEY_UP:
                        if(checkRotate(matrix))
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
            if(check_fall(matrix)) //Si se puede caer la pieza, cae
                fall(matrix);
            else{ //Si no se congela todo, se ve si hay linea completa y si la hay se borra, se suma score
                all_static(matrix);     //y se aumenta la velocidad si es necesario.
                if(scored(matrix)){
                    calculate_lines(matrix);
                    calculate_new_velocity(gamevars);
                    if((al_get_timer_speed(al_utils->timer)) != (al_utils->timer_speed)){
                        al_set_timer_speed(al_utils->timer, al_utils->timer_speed);
                    }
                }
                if(can_i_copy(matrix)){ //Se fija si se puede copiar una nueva pieza a la matriz
                    copy_piece_to_mat(matrix, piece_mat); //copiamos la pieza a la matriz
                    gamevars->currentpiece = init_piece(); //calculamos la proxima pieza
                    fill_mat_piece(piece_mat, gamevars->currentpiece); //llenamos la matriz de pieza con la nueva
                }
                else
                    gamevars->lose = true; //Si no se puede caer, ni copiar una nueva pieza, se pierde     
            }             
        }   
    }
}