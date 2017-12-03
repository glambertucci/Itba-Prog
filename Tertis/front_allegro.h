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

#ifndef FRONT_H
#define FRONT_H
//TAMAÑO DE LA PANTALLA

//SEPARACION ENTRE CUBO Y CUBO
#define SEPARACION (40.0)
//TAMAÑO DE NUESTRA MATRIZ

//ALLEGRO
#include <allegro5/system.h>
#include <allegro5/color.h>
#include <allegro5/allegro_primitives.h>
//STANDAR
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "general.h"
//ESTRUCTURA DE PIEZAS

//Piezas enumeradas como en la foto



void  al_draw_tablero(PIECE tablero [TABLE_FIL][TABLE_COL]);
//al_draw_tablero recibe matriz de PIECE y la imprime por allegro
void al_draw_next_piece (PIECE future );
//imprime la proxima ficha en pantalla
PIECE create_next (PIECE * piece);
//Creates next
#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* FRONT_H */

