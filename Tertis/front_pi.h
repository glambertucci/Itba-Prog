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
void draw_front (EV_UTILS* al_utils, FRONTEND* front_utils, GAME_UTILS* gamevars, PIECE matrix [TABLE_FIL][TABLE_COL]);
void draw_tablero (PIECE matrix [TABLE_FIL][TABLE_COL]);//uNA ESTA MAL
void draw_next_piece (PIECE next_piece);
void draw_score (FRONTEND* front_utils, GAME_UTILS* gamevars);
void draw_options_and_highscore(FRONTEND* front_utils, GAME_UTILS* gamevars);
void draw_highscore(GAME_UTILS* gamevars);
void draw_s(void);
void draw_c(void);
void draw_q(void);
void draw_tetris (void);

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* FRONT_PI_H */

#endif