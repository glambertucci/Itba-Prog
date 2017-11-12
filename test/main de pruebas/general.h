/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   General.h
 * Author: guido
 *
 * Created on November 11, 2017, 6:44 PM
 */

#ifndef GENERAL_H
#define GENERAL_H
#define SCREEN_W 800
#define SCREEN_H 800
#define CAYENDO 1
#define ESTATICO 0
#define TABLE_FIL 20
#define TABLE_COL 14
enum{BLANK, STICK,EL,JEY,BLOCK,ES,ZED,TEE,CEMENTO};
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct { //Aca declaramos las piezas
    uint8_t type;
    bool state;
}PIECE;
#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* GENERAL_H */

