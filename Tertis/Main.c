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
#include "al_custom_init.h"
#include "tetrisInit.h"
#include "playing.h"
#include "statemenu.h"
#include "front.h"

int main(void) {
    
    PIECE matrix[TABLE_FIL][TABLE_COL]; //Matriz en donde se situan las piezas
    PIECE piece_matrix[MAT_PIECE_FIL][MAT_PIECE_COL]; //Matriz de 4x3 para cada pieza
    AL_UTILS al_utils = {0}, * p2al_utils = &al_utils; //Punteros a utilizar con allegro
    GAME_UTILS gamevars = {0}, *p2gamevars = &gamevars; //Variables de juego
    
    al_custom_tetris_init(p2al_utils); //Aca se inicializa allegro.
    
    do{
    tetrisInit(matrix, piece_matrix, p2gamevars); //Aca se inicializan las matrices y variables de juego.
    
    while(!(p2gamevars->quit)){
        
        if(p2gamevars->state == PLAYING){
            continueplay(p2al_utils, p2gamevars);
            getplayevents(p2al_utils, p2gamevars, matrix, piece_matrix);
        }
        else if(p2gamevars->state == MENU){
            pauseplay(p2al_utils, p2gamevars);
            getmenuevents(p2al_utils, p2gamevars);
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
     
        }
    
    }while(p2gamevars->restart); //Si puse restart, entonces loopeo.
        
    al_custom_destroy(p2al_utils);
    
    return 0;
    
    }
    
    
    

