/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   playing.h
 * Author: alan
 *
 * Created on November 28, 2017, 7:50 PM
 */

#ifndef PLAYING_H
#define PLAYING_H

void continueplay(AL_UTILS* al_utils, GAME_UTILS* gamevars);
void getplayevents(AL_UTILS* al_utils, GAME_UTILS* gamevars, PIECE matrix[TABLE_FIL][TABLE_COL], PIECE piece_mat[MAT_PIECE_FIL][MAT_PIECE_COL]);

#endif
