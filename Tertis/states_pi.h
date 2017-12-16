/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   states_pi.h
 * Author: alan
 *
 * Created on December 3, 2017, 12:23 AM
 */
#ifdef RASP_PI
#ifndef STATES_PI_H
#define STATES_PI_H


// Esta funcion indica en que direccion se esta moviendo el joystick
//
// jcoord_t * joy : Es un puntero a una estructura que contiene la inclinacion en X y en Y del joystick.
int8_t what_direction ( jcoord_t * joy);
#define TILT (80)
void playing_events(FRONTEND* front_utils, GAME_UTILS* gamevars, PIECE matrix[TABLE_FIL][TABLE_COL], PIECE piece_mat[MAT_PIECE_FIL][MAT_PIECE_COL]) ;
#include "general.h"
#define MOVEUP -1
#define MOVEDOWN 1
#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* STATES_PI_H */

#endif