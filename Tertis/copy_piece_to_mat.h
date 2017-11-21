/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 


 * File:   copy_piece_to_mat.h
 * Author: guido
 *
 * Created on November 11, 2017, 10:19 PM
 */

#ifndef COPY_PIECE_TO_MAT_H
#define COPY_PIECE_TO_MAT_H
#include "general.h"
void copy_piece_to_mat (PIECE tablero [TABLE_FIL][TABLE_COL],PIECE next_piece_mat [MAT_PIECE_FIL][MAT_PIECE_COL]);
//RECIBE TABLERO Y PIEZA  hace lo que el nombre
bool can_i_copy (PIECE tablero [TABLE_FIL][TABLE_COL]);
//AVISA SI PODES COPIAR LA MATRIZ DE ARRIBA O NO DEVUELVE 1 SI PUEDE COPIARLA, 0 SI NO
#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* COPY_PIECE_TO_MAT_H */

