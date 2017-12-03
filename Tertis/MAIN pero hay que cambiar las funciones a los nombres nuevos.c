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

//#ifdef AL_TETRIS
#include "front_al.h"
//#else
//#include "front_pi.h"
//#endif

#include "general.h"
#include "al_custom_init.h"
#include "tetrisInit.h"
#include "playing.h"
#include "statemenu.h"


int main(void) {
    
    PIECE matrix[TABLE_FIL][TABLE_COL]; //Matriz en donde se situan las piezas
    PIECE piece_matrix[MAT_PIECE_FIL][MAT_PIECE_COL]; //Matriz de 4x3 para cada pieza
    AL_UTILS al_utils = {0}; //Punteros a utilizar con allegro
    GAME_UTILS gamevars = {0}; //Variables de juego
    
    gamevars.restart = true;  //DEBUG
    
    al_custom_tetris_init(&al_utils); //Aca se inicializa allegro.

    do{
    	tetrisInit(matrix, piece_matrix, &gamevars); //Aca se inicializan las matrices y variables de juego.
    	while(!(gamevars.quit)){
            gamevars.state = PLAYING;  //DEBUG
        	if((gamevars.state == PLAYING)){
        	    continueplay(&al_utils, &gamevars, matrix, piece_matrix);
        	    getplayevents(&al_utils, &gamevars, matrix, piece_matrix);
       		}
       		else if(gamevars.state == MENU){
            	pauseplay(&al_utils, &gamevars);
            	getmenuevents(&al_utils, &gamevars);
        	}
    /*
     * 
     * 
     * 
     *  VER COMO AGREGAR TODO LO QUE ES FRONT PARA PI Y PARA ALLEGRO AFUERA DE TODO LO QUE ES BACKEND
     * 
     * 
     */        
        	al_draw_tablero(matrix);
        	al_draw_next_piece(gamevars.currentpiece);
                al_flip_display();
     
        }
    
    }while(gamevars.restart); //Si puse restart, entonces loopeo.
        
    al_custom_destroy(&al_utils);
    
    return 0;
    
    }
    
    
    

