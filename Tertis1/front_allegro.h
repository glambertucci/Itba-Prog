/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   front.h
 * Author: guido
 *
 * Created on November 10, 2017, 10:27 PM
 */
#ifdef ALLEGRO
#ifndef FRONT_H
#define FRONT_H
#define SEPARACION (38.0)
#define OUTLINE 2

#include "general.h"

void draw_front(FRONTEND* front_utils, GAME_UTILS* gamevars, PIECE matrix [TABLE_FIL][TABLE_COL]);
//
void  al_draw_tablero(PIECE tablero [TABLE_FIL][TABLE_COL]);
//al_draw_tablero recibe matriz de PIECE y la imprime por allegro
void al_draw_next_piece (PIECE future );
//imprime la proxima ficha en pantalla
PIECE create_next (PIECE * piece);
//Creates next
void al_draw_score(FRONTEND * front_utils, GAME_UTILS * gamevars);
//Dibuja la puntuación en pantalla
void al_draw_dance(FRONTEND * front_utils);
//Dibuja dos imagenes alternandolas entre si para simular un baile

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* FRONT_H */

#endif
