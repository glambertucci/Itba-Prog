/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tetrisInit.h
 * Author: alan
 *
 * Created on November 11, 2017, 10:31 PM
 */

#ifndef TETRISINIT_H
#define TETRISINIT_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include "general.h"
void tetrisInit (PIECE matrix[TABLE_FIL][TABLE_COL], PIECE piece_matrix[MAT_PIECE_FIL][MAT_PIECE_COL], GAME_UTILS* gamevars);


#ifdef __cplusplus
}
#endif

#endif /* TETRISINIT_H */

