/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   states_allegro.h
 * Author: alan
 *
 * Created on December 3, 2017, 12:30 AM
 */

#ifndef STATES_ALLEGRO_H
#define STATES_ALLEGRO_H

#ifdef __cplusplus
extern "C" {
#endif

void playing_events(AL_UTILS* al_utils, GAME_UTILS* gamevars, PIECE matrix[TABLE_FIL][TABLE_COL], PIECE piece_mat[MAT_PIECE_FIL][MAT_PIECE_COL]);
//
void menu_events (AL_UTILS* al_utils, GAME_UTILS* gamevars);
//
void menu (AL_UTILS * al_utils, GAME_UTILS * gamevars);
//


#ifdef __cplusplus
}
#endif

#endif /* STATES_ALLEGRO_H */

