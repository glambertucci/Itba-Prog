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
    
enum{BLANK, STICK,EL,JEY,BLOCK,ES,ZED,TEE,CEMENTO};
enum{ESTATICO, CAYENDO};
enum{LEFT, RIGHT};
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define PIECE_TOTAL 8
//Matriz dibujada
#define MATRIX_WIDTH 10
#define MATRIX_HEIGHT 16
//Matriz real
#define TABLE_FIL 20
#define TABLE_COL 14
#define SCREEN_W 800
#define SCREEN_H 800
    
#define MAT_PIECE_FIL 4
#define MAT_PIECE_COL 3

typedef struct { //Aca declaramos las piezas
    uint8_t type;
    bool state;
    bool pivot;
}PIECE;

#ifdef __cplusplus
}
#endif

#endif /* GENERAL_H */

