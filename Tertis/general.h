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
    
enum{INITIAL = 15,VERYEASY = 14,EASY = 13, NORMAL = 12, NORMALHARD = 10, HARD = 8, VERYHARD = 6, IMPOSSIBLE = 3}; //Para el timer
enum{BLANK,STICK,EL,JEY,BLOCK,ES,ZED,TEE,CEMENTO,SCORED}; //Cada tipo de bloque 1x1. Cemento nunca se mueve, gralmente para calcuar cosas. Scored es indicador de linea llena.
enum{ESTATICO, CAYENDO}; //Estado de cada bloque 1x1
enum{PLAYING, MENU}; //Para fsm.
enum{LEFT, RIGHT}; //Para funcion mover pieza
enum{START,CONTINUE,QUIT};

#include <allegro5/allegro.h>
#include <allegro5/timer.h>
#include <allegro5/display.h>
#include <allegro5/keycodes.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

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
#define TRUE 1
#define FALSE 0

typedef struct { //Aca declaramos la estructura de cada bloque 1x1
    uint8_t type;
    bool state;
    bool pivot;
}PIECE;

typedef struct { //Estructura para manejo de allegro
    ALLEGRO_TIMER * timer;
    ALLEGRO_EVENT_QUEUE * queue;
    double timer_speed;
}AL_UTILS;
    
typedef struct { //Estructura con variables de juego
    PIECE currentpiece;
    bool lose;
    bool quit;
    bool state;
    bool restart;
    bool draw;
}GAME_UTILS;

#ifdef RASP_PI
typedef struct { //Estructura para front de pi
    
}FRONTEND;

#define UPKEY
#define DOWNKEY

#else
typedef struct { //Estructura para front de allegro
    ALLEGRO_DISPLAY* display;
    int key_pressed;
    int mouse_x;
    int mouse_y;
}FRONTEND;

#define UPKEY   
#define DOWNKEY

#endif

#endif