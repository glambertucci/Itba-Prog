/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   game_start.h
 * Author: alan
 *
 * Created on December 3, 2017, 12:24 AM
 */

#ifndef GAME_START_H
#define GAME_START_H

#ifdef __cplusplus
extern "C" {
#endif

void game_start (PIECE matrix[TABLE_FIL][TABLE_COL], PIECE piece_matrix[MAT_PIECE_FIL][MAT_PIECE_COL], GAME_UTILS* gamevars);
//Inicializa o reinicia todas las variables de juego
void init_mat (PIECE next_piece_mat [MAT_PIECE_FIL][MAT_PIECE_COL]);
//inicializa la matriz pequena para las piezas individuales


#ifdef __cplusplus
}
#endif

#endif /* GAME_START_H */

