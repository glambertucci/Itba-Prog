/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   misc_functions.h
 * Author: alan
 *
 * Created on December 3, 2017, 12:15 AM
 */

#ifndef MISC_FUNCTIONS_H
#define MISC_FUNCTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

void calculate_new_velocity(AL_UTILS* al_utils, GAME_UTILS * gamevars);
//
void change_velocity(AL_UTILS* al_utils);
//
void continueplay(AL_UTILS* al_utils, GAME_UTILS* gamevars, PIECE matrix[TABLE_FIL][TABLE_COL], PIECE piece_mat[MAT_PIECE_FIL][MAT_PIECE_COL]);
//
void pauseplay (AL_UTILS* al_utils, GAME_UTILS* gamevars);
//
void next_piece(GAME_UTILS* gamevars);
//

#ifdef __cplusplus
}
#endif

#endif /* MISC_FUNCTIONS_H */

