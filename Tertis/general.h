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
    
enum{BLANK,STICK,EL,JEY,BLOCK,ES,ZED,TEE,CEMENTO};
enum{ESTATICO,CAYENDO};

#define PIECE_TOTAL 8
//Matriz dibujada
#define MATRIX_WIDTH 10
#define MATRIX_HEIGHT 16
//Matriz real
#define TABLE_FIL 20
#define TABLE_COL 14

#define SCREEN_W 800
#define SCREEN_H 800
    
typedef struct { //Aca declaramos las piezas
    uint8_t type;
    bool state;
}PIECE;

#ifdef __cplusplus
}
#endif

#endif /* GENERAL_H */

