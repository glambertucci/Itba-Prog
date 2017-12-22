/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   front_pi.h
 * Author: alan
 *
 * Created on December 3, 2017, 12:30 AM
 */

#ifndef FRONT_PI_H
#define FRONT_PI_H
#include "general.h"
#ifdef RASP_PI
#include "disdrv.h"
#include "joydrv.h"
#include "matrix_manipulation.h"
void draw_front ( FRONTEND* front_utils, GAME_UTILS* gamevars, PIECE matrix [TABLE_FIL][TABLE_COL]);
//Funcion principal de dibujo, dibuja en relacion al estado y las variables de juego
void draw_tablero (PIECE matrix [TABLE_FIL][TABLE_COL]);
//Dibuja tablero de juego
void draw_next_piece (PIECE next_piece);
//Dibuja proxima pieza en tablero
void draw_score (FRONTEND* front_utils, GAME_UTILS* gamevars);
//Dibuja puntaje en tablero
void draw_options_and_highscore(FRONTEND* front_utils, GAME_UTILS* gamevars);
//Dibuja menu
void draw_highscore(GAME_UTILS* gamevars);
//Dibuja tipo bumetro (lineas verticales correspondientes a unidades de decena, centena, mil con altura igual a el valor del numero)
//las unidades en el puntaje se omiten porque siempre son 0.
void draw_s(void);
//S
void draw_c(void);
//C
void draw_q(void);
//Q
void draw_tetris (void);
//Dibuja titulo de lanzamiento de juego
void draw_gameover (void);
//Dibuja gameover al perder
#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* FRONT_PI_H */

#endif
