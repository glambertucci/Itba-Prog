/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Main.c
 * Author: alan
 *
 * Created on November 10, 2017, 3:11 PM
 */

#include "general.h"
#include "al_backend_init.h"
#include "game_start.h"
#include "misc_functions.h"

int main(void) {
    
    PIECE matrix[TABLE_FIL][TABLE_COL]; //Matriz en donde se situan las piezas
    PIECE piece_matrix[MAT_PIECE_FIL][MAT_PIECE_COL]; //Matriz de 4x3 para cada pieza
    AL_UTILS al_utils = {0}; //Punteros a utilizar con allegro
    GAME_UTILS gamevars = {0}; //Variables de juego
    FRONTEND front_utils = {0}; //Variables de front end
    
    gamevars.restart = true;  //DEBUG
    
    if(al_backend_init(&al_utils)) { //Aca se inicializa el backend de allegro.
        
        do{
            game_start(matrix, piece_matrix, &gamevars); //Aca se inicializan las matrices y variables de juego.
            while(!(gamevars.quit)){
                gamevars.state = PLAYING;  //DEBUG
                    if((gamevars.state == PLAYING)){
                        continueplay(&al_utils, &gamevars, matrix, piece_matrix);
                        playing_events(&al_utils, &gamevars, matrix, piece_matrix);
                    }
                    else if(gamevars.state == MENU){
                    pauseplay(&al_utils, &gamevars);
                    menu_events(&al_utils, &gamevars);
                    }

                    //draw_front();
                
                    al_draw_tablero(matrix);                    //DEBUG
                    al_draw_next_piece(gamevars.currentpiece);  //DEBUG
                    al_flip_display();                          //DEBUG
            }

        } while(gamevars.restart); //Si puse restart, entonces loopeo.

        al_backend_destroy(&al_utils);

        return (EXIT_SUCCESS);
        }
    else
        return 1;
    
    }
    
    
    

