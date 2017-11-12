/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: guido
 *
 * Created on November 10, 2017, 9:29 PM
 */


#include "front.h"
#include "init_piece.h"
#include "general.h"
#include "check_fall.h"

/*
 * 
 */
PIECE tablero [TABLE_FIL][TABLE_COL]={0};

int main(int argc, char** argv) {

//recibo matriz y display
    ALLEGRO_DISPLAY * display = NULL;
 if (!al_init())
    {
        fprintf(stderr,"Allegro not initialized");
        return -1;
    }
    if (!(display = al_create_display(SCREEN_W,SCREEN_H)))
    {
        fprintf(stderr,"display not created");
        return -1;
    }
    if(!al_init_primitives_addon())
    {
        fprintf(stderr,"primitives not initialized");
        return -1;
    }
 /*(tablero[TABLE_FIL-3][TABLE_COL-6]).type=BLOCK;
 (tablero[TABLE_FIL-3][TABLE_COL-7]).type=BLOCK;
 (tablero[TABLE_FIL-2][TABLE_COL-6]).type=BLOCK;
 (tablero[TABLE_FIL-2][TABLE_COL-7]).type=BLOCK;
 (tablero[TABLE_FIL-2][TABLE_COL-2]).type=STICK;
 (tablero[TABLE_FIL-3][TABLE_COL-2]).type=STICK;
 (tablero[TABLE_FIL-4][TABLE_COL-2]).type=STICK;
 (tablero[TABLE_FIL-5][TABLE_COL-2]).type=STICK;
 (tablero[TABLE_FIL-8][TABLE_COL-8]).type=ES;
 (tablero[TABLE_FIL-9][TABLE_COL-8]).type=ES;
 (tablero[TABLE_FIL-9][TABLE_COL-9]).type=ES;
 (tablero[TABLE_FIL-10][TABLE_COL-9]).type=ES;
 (tablero[TABLE_FIL-2][TABLE_COL-12]).type=EL; 
 (tablero[TABLE_FIL-2][TABLE_COL-11]).type=EL;
 (tablero[TABLE_FIL-3][TABLE_COL-12]).type=EL; 
 (tablero[TABLE_FIL-4][TABLE_COL-12]).type=EL; 
  * 
(tablero[TABLE_FIL-5][TABLE_COL-11]).type=EL;
(tablero[TABLE_FIL-5][TABLE_COL-11]).state=CAYENDO;
(tablero[TABLE_FIL-4][TABLE_COL-11]).type=EL;
(tablero[TABLE_FIL-4][TABLE_COL-11]).state=CAYENDO;
(tablero[TABLE_FIL-2][TABLE_COL-4]).type=BLOCK;
(tablero[TABLE_FIL-2][TABLE_COL-4]).state=CAYENDO;
(tablero[TABLE_FIL-1][TABLE_COL-4]).type=CEMENTO;
(tablero[TABLE_FIL-1][TABLE_COL-4]).state=ESTATICO;
 */
(tablero[TABLE_FIL-2][TABLE_COL-4]).type=STICK;
(tablero[TABLE_FIL-2][TABLE_COL-4]).state=CAYENDO;
 (tablero[TABLE_FIL-3][TABLE_COL-4]).type=STICK;
 (tablero[TABLE_FIL-4][TABLE_COL-4]).type=STICK;
 (tablero[TABLE_FIL-5][TABLE_COL-4]).type=STICK;
 (tablero[TABLE_FIL-3][TABLE_COL-4]).state=CAYENDO;
 (tablero[TABLE_FIL-4][TABLE_COL-4]).state=CAYENDO;
 (tablero[TABLE_FIL-5][TABLE_COL-4]).state=CAYENDO;
 (tablero[TABLE_FIL-1][TABLE_COL-4]).type=CEMENTO;
(tablero[TABLE_FIL-1][TABLE_COL-4]).state=ESTATICO;

 srand(time(NULL));
 
 PIECE next_piece=init_piece();
 bool result;
 
al_clear_to_color(al_map_rgb(192,192,192));
al_draw_tablero(tablero);
result= check_fall (tablero);
al_draw_next_piece(next_piece);
printf("Puedo imprimir?\n %d ",result);
al_flip_display();
al_rest(10.0);
al_destroy_display(display);

    return (EXIT_SUCCESS);
}

