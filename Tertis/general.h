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
//#define RASP_PI

#define ALLEGRO
#ifndef GENERAL_H
#define GENERAL_H

#ifdef __cplusplus
extern "C" {
#endif
    
    enum{INITIAL = 15,VERYEASY = 12,EASY = 10, NORMAL = 8, NORMALHARD = 7, HARD = 5, VERYHARD = 4, IMPOSSIBLE = 3}; //Para el timer
    enum{BLANK,STICK,EL,JEY,BLOCK,ES,ZED,TEE,CEMENTO,SCORED}; //Cada tipo de bloque 1x1. Cemento nunca se mueve, gralmente para calcuar cosas. Scored es indicador de linea llena.
    enum{ESTATICO, CAYENDO}; //Estado de cada bloque 1x1
    enum{PLAYING, MENU}; //Para fsm.
    enum{LEFT, RIGHT,UP,DOWN}; //Para funcion mover pieza
    enum{START,CONTINUE,QUIT};
    enum{NOT_OK,OK};
    enum{SCORE1 = 100, SCORE2 = 250, SCORE3 = 400, SCORE4 = 600};
    
#include <allegro5/allegro.h>

    
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
    //Matriz de tablero
#define TABLE_FIL 20
#define TABLE_COL 14
  
    //Para matriz chiquita de cada pieza nueva
#define MAT_PIECE_FIL 4
#define MAT_PIECE_COL 3
#define TRUE 1
#define FALSE 0
    
    typedef int SCORE;
    
    typedef struct { //Aca declaramos la estructura de cada bloque 1x1
        uint8_t type;
        bool state;
        bool pivot;
    }PIECE;
    
    
    
    typedef struct { //Estructura con variables de juego
        
        PIECE nextpiece;
        PIECE currentpiece;
        SCORE highscore;
        SCORE score;
        bool is_not_first_time;
        bool lose;
        bool quit;
        bool prev_state;
        bool state;
        bool restart;
        bool draw;
    }GAME_UTILS;
    

#ifdef RASP_PI
    
        typedef struct { //Estructura para manejo de eventos en pi
            ALLEGRO_TIMER * timer;
            ALLEGRO_EVENT_QUEUE * queue;      
            double timer_speed;
        }EV_UTILS;
    
    typedef struct 
    {                     //Estructura para front de allegro
        EV_UTILS ev_utils;  
        int selected_op;
        int key_pressed;
        int mouse_x;
        bool option;
        bool menu_drawed;
        int mouse_y;
    } FRONTEND;
        

#endif

#ifdef ALLEGRO
        
#include<allegro5/allegro_font.h>
#include <allegro5/timer.h>
#include <allegro5/display.h>
#include <allegro5/keycodes.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
    
          //Para display
#define SCREEN_W 800
#define SCREEN_H 800
#define TOTAL_IMAGES 6
#define TOTAL_MUSICA 3
    
        
        typedef struct { //Estructura para manejo de allegro
            ALLEGRO_TIMER * timer;
            ALLEGRO_EVENT_QUEUE * queue;
            double timer_speed;
        }EV_UTILS;    
        
        typedef struct { //Estructura para front de allegro
            EV_UTILS ev_utils;
            ALLEGRO_BITMAP * image[TOTAL_IMAGES];
            ALLEGRO_DISPLAY* display;
            ALLEGRO_SAMPLE * (samples[TOTAL_MUSICA]);
            ALLEGRO_FONT * font1;
            ALLEGRO_FONT * font2;
            ALLEGRO_FONT * font3;    
            int selected_op;
            int key_pressed;
            int mouse_x;
            int mouse_y;
        }FRONTEND;
        
#endif
        
#endif