#include <allegro5/allegro5.h>  
#include <allegro5/allegro_color.h> 
#include <allegro5/allegro_image.h> 
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>

#include "general.h"
#include "states_allegro.h"
#include "matrix_manipulation.h"
#include "matrix_validation.h"
#include "misc_functions.h"
#include "scored.h"


void playing_events(AL_UTILS* al_utils, GAME_UTILS* gamevars, PIECE matrix[TABLE_FIL][TABLE_COL], PIECE piece_mat[MAT_PIECE_FIL][MAT_PIECE_COL]) {
    
    ALLEGRO_EVENT event; //Esta funcion toma los eventos durante el estado playing
    bool madestatic = false;
    
    if(al_get_next_event(al_utils->queue, &event)){
        
        if(event.type == ALLEGRO_EVENT_KEY_DOWN){

            switch(event.keyboard.keycode) {

                case ALLEGRO_KEY_ESCAPE:
                    gamevars->state = MENU;
                    break;

                case ALLEGRO_KEY_LEFT:
                    if(checkMove(matrix, LEFT)) {
                        move(matrix, LEFT);
                        gamevars->draw = true;
                    }
                    break;

                case ALLEGRO_KEY_RIGHT:
                    if(checkMove(matrix, RIGHT)) {
                        move(matrix, RIGHT);
                        gamevars->draw = true;
                    }
                    break;

                case ALLEGRO_KEY_UP:
                    if(checkRotate(matrix)) {
                        rotate(matrix);
                        gamevars->draw = true;
                    }
                    break;

                case ALLEGRO_KEY_DOWN:
                    while(check_fall(matrix)) {
                        fall(matrix);
                    }
                    gamevars->draw = true;
                    break;
            }
        }

        if(event.type == ALLEGRO_EVENT_TIMER) {                

            if(gamevars->restart) { //Si el juego se habia reiniciado, copia la primera pieza al tablero
                gamevars->restart == false;
                copy_piece_to_mat(matrix, piece_mat);
                clean_piece_mat(piece_mat);
            }
 
            if(check_fall(matrix)) { //Si se puede caer la pieza, cae
                fall(matrix);
                gamevars->draw = true;  
            }

            else { //Si no se congela todo, se ve si hay linea completa y si la hay se borra, se suma score

                all_static(matrix);     //y se aumenta la velocidad si es necesario.

                if(scored(matrix)){
                    calculate_lines(matrix);
                    calculate_new_velocity(al_utils);
                    change_velocity(al_utils);
                    gamevars->draw = true;
                }

                else {
            
                    if(can_i_copy(matrix)){ //Se fija si se puede copiar una nueva pieza a la matriz
                        copy_piece_to_mat(matrix, piece_mat); //copiamos la pieza a la matriz
                        clean_piece_mat(piece_mat);
                        next_piece(gamevars); //calculamos la proxima pieza
                        fill_mat_piece(piece_mat, gamevars->currentpiece); //llenamos la matriz de pieza con la nueva
                    }
                    else{
                        copy_piece_to_mat(matrix, piece_mat);
                        gamevars->lose = true; //Si no se puede caer, ni copiar una nueva pieza, se pierde                  
                    }
                }
            }
        }
    }
}

void menu_events (AL_UTILS* al_utils, GAME_UTILS* gamevars) { //Esta funcion toma los eventos durante el
                                                               //estado de menu
    ALLEGRO_EVENT event;
    ALLEGRO_BITMAP * image; //Puntero a la imagen del menu
  
  
    
    int key_pressed = 0;
    int selected_op = CONTINUE; //Por default que sea continue (1)
    
    if(al_get_next_event(al_utils->queue, &event)){
        
        if(event.type == ALLEGRO_EVENT_KEY_DOWN){
            
            switch(event.keyboard.keycode) {
                
                case ALLEGRO_KEY_UP:
                {
                    if(selected_op>START){
                        selected_op -= 1;
                    }
                }
                    break;
                case ALLEGRO_KEY_DOWN:
                    if(selected_op<QUIT){
                        selected_op += 1;
                    }
                    break;
            }
        }
            
        if((event.mouse.x > MENUMARGIN && event.mouse.y > (STARTPOSY)) &&
        (event.mouse.x < (STARTPOSXEND) && event.mouse.y < (STARTPOSYEND))){
            selected_op = START;
               if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
              gamevars->restart = TRUE; //Con esto, reinicio el juego.
              gamevars->quit = TRUE; //Con esto, salgo del primer loop.
          }
        }
        else if((event.mouse.x > MENUMARGIN && event.mouse.y > (CONTPOSY)) &&
              (event.mouse.x < (CONTPOSXEND) && event.mouse.y < (CONTPOSYEND))){
              selected_op = CONTINUE;
                 if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
              gamevars->state = PLAYING;
          }
        }

        else if((event.mouse.x > MENUMARGIN && event.mouse.y > QUITPOSY) &&
          (event.mouse.x < QUITPOSXEND && event.mouse.y < QUITPOSYEND)){
            selected_op = QUIT;
               if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
              gamevars->quit = TRUE;    
          }
        }
    }



   }