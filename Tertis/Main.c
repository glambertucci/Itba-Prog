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
#ifdef RASP_PI
#include "front_init_pi.h"
#include "front_pi.h"
#include "states_pi.h"
#else
#include "front_init_allegro.h"
#include "front_allegro.h"
#include "states_allegro.h"
#endif
#include "al_backend_init.h"
#include "game_start.h"
#include "misc_functions.h"

int main(void) 
{
    int prev_state;
    PIECE matrix[TABLE_FIL][TABLE_COL]; //Matriz en donde se situan las piezas
    PIECE piece_matrix[MAT_PIECE_FIL][MAT_PIECE_COL]; //Matriz de 4x3 para cada pieza
    AL_UTILS al_utils = {0}; //Punteros a utilizar con allegro
    GAME_UTILS gamevars = {0}; //Variables de juego
    FRONTEND front_utils = {0}; //Variables de front end
    
    if((al_backend_init(&al_utils)) && (frontend_init(&front_utils, &al_utils))) { //Aca se inicializa el backend de allegro.
        
        do{
            game_start(matrix, piece_matrix, &gamevars); //Aca se inicializan las matrices y variables de juego.
            while(!(gamevars.quit))
            {
                    if((gamevars.state == PLAYING))
                    {

                        if (prev_state != gamevars.state )
                        {
                        al_stop_samples();
                        al_play_sample (front_utils . samples[0],0.75,0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL); 
                        prev_state = gamevars.state;
                        }
                        continueplay(&al_utils, &gamevars, matrix, piece_matrix);
                        playing_events(&al_utils, &gamevars, matrix, piece_matrix);
                    }
                    else if(gamevars.state == MENU)
                    {
                        
                        if (prev_state != gamevars.state )
                        {
                        al_stop_samples();
                        al_play_sample (front_utils . samples[1],1.25,0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL); 
                        prev_state = gamevars.state;
                        }
                        pauseplay(&al_utils, &gamevars);
                        menu_events(&al_utils, &front_utils, &gamevars);
                    }

                    draw_front(&al_utils, &front_utils, &gamevars, matrix);
            }
            
            if(gamevars.lose) 
            {
    
                       draw_front(&al_utils, &front_utils, &gamevars, matrix);
               
            }
            
        } while(gamevars.restart); //Si puse restart, entonces loopeo.

        al_backend_destroy(&al_utils);
        frontend_destroy(&front_utils);

        return (EXIT_SUCCESS);
        }
    else
        return (EXIT_FAILURE);
    
    }
    
    
    

