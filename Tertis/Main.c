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
 *

                 (__) 
                 (oo) 
           /------\/ 
          / |    ||   
         *  /\---/\ 
            ~~   ~~   
..."Have you mooed today?"...*/

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

#include "al_events.h"
#include "game_start.h"
#include "misc_functions.h"

int main(void) 
{
    PIECE matrix[TABLE_FIL][TABLE_COL]; //Matriz en donde se situan las piezas
    PIECE piece_matrix[MAT_PIECE_FIL][MAT_PIECE_COL]; //Matriz de 4x3 para cada pieza
    GAME_UTILS gamevars = {0}; //Variables de logica juego
    FRONTEND front_utils = {0}; //Variables de front end y de eventos.
    FILE * highscore;
    
    
    if((events_init(&front_utils.ev_utils)) && (frontend_init(&front_utils))) { //Aca se inicializan los eventos y frontend según corresponde a la plataforma.
        
        
        do{
            game_start(matrix, piece_matrix, &gamevars); //Aca se inicializan las matrices y variables de juego.
            calculate_new_velocity(&front_utils.ev_utils, &gamevars); //Es importante que si se reinicia el juego...
            change_velocity(&front_utils.ev_utils);//...se resetee la velocidad del timer.
            
            
            highscore = fopen("highscore.txt", "r"); //Accedemos al archivo donde se almacena el highscore...
            fscanf(highscore, "%d",&(gamevars.highscore)); //...y extraemos el mismo.
            fclose(highscore);
            
            while(!(gamevars.quit))
            {
                if((gamevars.state == PLAYING)) //Funciones del propio juego
                {
                    continueplay(&front_utils.ev_utils, &gamevars, matrix, piece_matrix); 
                    playing_events(&front_utils, &gamevars, matrix, piece_matrix);
                }
                else if(gamevars.state == MENU) //Funciones del menú
                {
                    pauseplay(&front_utils.ev_utils, &gamevars);
                    menu_events(&front_utils, &gamevars);
                }
                
                
                if(gamevars.lose){ //gg ez
                    
                    if((gamevars.highscore) < (gamevars.score)){ //Si hay una nueva puntuación más alta...
                        
                        highscore = fopen("highscore.txt", "w"); //...se guarda en highscore.txt.
                        fprintf(highscore, "%06d", gamevars.score);
                        fclose(highscore);
                    }

                }
                
                draw_front(&front_utils, &gamevars, matrix); //Actualización del front.
            }
            
            
            
        } while(gamevars.restart); //Si puse restart, entonces loopeo.
        
        events_destroy(&front_utils.ev_utils); //Cerramos eventos y front end antes de terminar el programa.
        frontend_destroy(&front_utils);
        
        return (EXIT_SUCCESS);
    }
    else
        return (EXIT_FAILURE); //Si algo no se puedo inicializar bien, el programa se cierra e indica el error.
    
}




