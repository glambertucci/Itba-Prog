#include <allegro5/allegro5.h>  
#include <allegro5/allegro_color.h> 
#include <allegro5/allegro_image.h> 
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>

#include "states_allegro.h"
#include "matrix_manipulation.h"
#include "matrix_validation.h"
#include "misc_functions.h"
#include "general.h"


void playing_events(AL_UTILS* al_utils, GAME_UTILS* gamevars, PIECE matrix[TABLE_FIL][TABLE_COL], PIECE piece_mat[MAT_PIECE_FIL][MAT_PIECE_COL]){
    
    ALLEGRO_EVENT event; //Esta funcion toma los eventos durante el estado playing
    bool madestatic = false;
    
    if(al_get_next_event(al_utils->queue, &event)){
        
        if(event.type == ALLEGRO_EVENT_KEY_DOWN){

            al_utils->keyboard.key = event.keyboard.keycode;
            switch(al_utils->keyboard.key) {

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

void menu_events (AL_UTILS* al_utils, GAME_UTILS* gamevars){ //Esta funcion toma los eventos durante el
                                                               //estado de menu
    ALLEGRO_EVENT event;
    int key_pressed = 0;
    
    if(al_get_next_event(al_utils->queue, &event)){
        
        if(event.type == ALLEGRO_EVENT_KEY_DOWN){
            al_utils->keyboard.keyboardpress = true;
            al_utils->keyboard.key = event.keyboard.keycode;
        }
        if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
            al_utils->mouse.mousepress = true;
            al_utils->mouse.x = event.mouse.x;
            al_utils->mouse.y = event.mouse.y;
        }
        if((al_utils->keyboard.keyboardpress) && (!(al_utils->mouse.mousepress))){
            /*
             
             
             
             ACA PONEMOS QUE PASA CANDO SE APRETA EL TECLADO
             
             
             
             
             */
        }
        if((!(al_utils->keyboard.keyboardpress)) && (al_utils->mouse.mousepress)){
            /*
             
             
             
             ACA PONEMOS QUE PAS CUADO SE APRETA EL MAUSE
             
             
             
             
             */
        }
    }
    
}

void menu (AL_UTILS * al_utils, GAME_UTILS * gamevars){

    
  
   ALLEGRO_BITMAP * image; //Puntero a la imagen del menu
   
   image = al_load_bitmap("menu.jpg");
   al_draw_bitmap(image,0,0,0);
   al_flip_display();
   
      /* Estos else if cambian el valor de quit y state cuando 
       * haga click en las coordenadas de START, CONTINUE o QUIT */
     
      if((al_utils->mouse.x > MENUMARGIN && al_utils->mouse.y > (STARTPOSY)) &&
              (al_utils->mouse.x < (STARTPOSXEND) && al_utils->mouse.y < (STARTPOSYEND))){
          if(al_utils->mouse.mousepress == TRUE) {
              gamevars->restart = TRUE; //Con esto, reinicio el juego.
              gamevars->quit = TRUE; //Con esto, salgo del primer loop.
          }
      } 
   
      else if((al_utils->mouse.x > MENUMARGIN && al_utils->mouse.y > (CONTPOSY)) &&
              (al_utils->mouse.x < (CONTPOSXEND) && al_utils->mouse.y < (CONTPOSYEND))){
          if(al_utils->mouse.mousepress == TRUE) {
              gamevars->state = PLAYING;
          }
       }

      else if((al_utils->mouse.x > MENUMARGIN && al_utils->mouse.y > QUITPOSY) &&
          (al_utils->mouse.x < QUITPOSXEND && al_utils->mouse.y < QUITPOSYEND))
          if(al_utils->mouse.mousepress == TRUE) {
              gamevars->quit = TRUE;
          }
     
   }