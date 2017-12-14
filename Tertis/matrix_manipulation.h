/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   matrix_manipulation.h
 * Author: alan
 *
 * Created on December 3, 2017, 12:17 AM
 */

#ifndef MATRIX_MANIPULATION_H
#define MATRIX_MANIPULATION_H

#ifdef __cplusplus
extern "C" {
#endif

void all_static (PIECE tablero [TABLE_FIL][TABLE_COL]);
//
void fall(PIECE matrix[TABLE_FIL][TABLE_COL]);
//
void move(PIECE matrix[TABLE_FIL][TABLE_COL], bool dir );
//
void rotate(PIECE matrix[TABLE_FIL][TABLE_COL]);
//
bool rotateWall(PIECE matrix[TABLE_FIL][TABLE_COL], GAME_UTILS * gamevars, bool dir);

void calculate_lines(PIECE matrix[TABLE_FIL][TABLE_COL]);
//
void delete_line(PIECE matrix[TABLE_FIL][TABLE_COL], uint8_t fila);
//
void clean_piece_mat (PIECE mat [MAT_PIECE_FIL][MAT_PIECE_COL]);
//
void copy_piece_to_mat (PIECE tablero [TABLE_FIL][TABLE_COL],PIECE next_piece_mat [MAT_PIECE_FIL][MAT_PIECE_COL], GAME_UTILS * gamevars);
//
void fill_mat_piece (PIECE next_piece_mat [MAT_PIECE_FIL][MAT_PIECE_COL], PIECE pieza);
//


#ifdef __cplusplus
}
#endif

#endif /* MATRIX_MANIPULATION_H */

