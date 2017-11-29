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
#include "tetrisInit.h"
#include "check_fall.h"
#include "fall.h"
#include "all_static.h"

int main(void) {
    
    PIECE matrix[TABLE_FIL][TABLE_COL]; //Matriz en donde se situan las piezas
    PIECE piece_matrix[MAT_PIECE_FIL][MAT_PIECE_COL]; //Matriz de 4x3 para cada pieza
    AL_UTILS* al_utils; //Punteros a utilizar con allegro
    GAME_UTILS* gamevars; //Variables de juego
    
    al_custom_init(al_utils); //Aca se inicializa allegro.
    tetrisInit(matrix, piece_matrix, gamevars); //Aca se inicializan las matrices y variables de juego.
    
    while(!(gamevars->quit)){
        
        while(gamevars->state == PLAYING){
            continueplay(al_utils, gamevars);
            getplayevents(al_utils, gamevars, matrix, piece_matrix);
        }
        while(gamevars->state == MENU){
            pauseplay(al_utils, gamevars);
            getmenuevents(al_utils, gamevars, matrix);
        }
        if((gamevars->draw)){
            gamevars->draw = false;
            al_draw_tablero(matrix);
        }
    }
    
    al_utils = al_custom_destroy();
    return 0;
    
}

