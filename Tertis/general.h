/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   general.h
 * Author: alan
 *
 * Created on November 10, 2017, 4:30 PM
 */

#ifndef GENERAL_H
#define GENERAL_H

#ifdef __cplusplus
extern "C" {
#endif
    

enum{BLANK,STICK,EL,JEY,BLOCK,ES,ZED,TEE,CEMENTO,SCORED}; //Cada tipo de bloque 1x1. Cemento nunca se mueve, gralmente para calcuar cosas. Scored es indicador de linea llena.

enum{INITIAL = 1.5,
     VERYEASY = 1.4, 
     EASY = 1.3, 
     NORMAL = 1.2, 
     NORMALHARD = 1, 
     HARD = 0.8, 
     VERYHARD = 0.6, 
     IMPOSSIBLE = 0.3}; //Para el timer

enum{ESTATICO, CAYENDO}; //Estado de cada bloque 1x1
enum{PLAYING, MENU}; //Para fsm.
enum{LEFT, RIGHT}; //Para funcion mover pieza
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
//Matriz de tablero
#define TABLE_FIL 20
#define TABLE_COL 14
//Para display
#define SCREEN_W 800
#define SCREEN_H 800
//Para matriz chiquita de cada pieza nueva
#define MAT_PIECE_FIL 4
#define MAT_PIECE_COL 3

typedef struct { //Aca declaramos la estructura de cada bloque 1x1
    uint8_t type;
    bool state;
    bool pivot;
}PIECE;

typedef struct {
    ALLEGRO_TIMER* timer = NULL;
    ALLEGRO_EVENT_QUEUE* queue = NULL;
    ALLEGRO_DISPLAY* display = NULL;
    bool keyboard = false;
    bool mouse = false;
}AL_UTILS;
    
typedef struct {
    PIECE currentpiece;
    bool lose = false;
    bool quit = false;
    bool state = MENU;
    bool draw = false;
    double timer_speed = INITIAL;
}GAME_UTILS;

#ifdef __cplusplus
}
#endif

#endif /* GENERAL_H */

