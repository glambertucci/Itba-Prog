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
void menu_events (AL_UTILS* al_utils, FRONTEND* front_utils, GAME_UTILS* gamevars);
//
void menu (AL_UTILS * al_utils, GAME_UTILS * gamevars);
//


#define MENUMARGIN 122
#define LETTERSIZE 24
#define STARTPOSY 418
#define STARTPOSYEND (STARTPOSY + LETTERSIZE)
#define STARTPOSXEND (MENUMARGIN + LETTERSIZE * 5)
#define CONTPOSY 492
#define CONTPOSYEND (CONTPOSY + LETTERSIZE)
#define CONTPOSXEND (MENUMARGIN + LETTERSIZE * 8)
#define QUITPOSY 566
#define QUITPOSYEND (QUITPOSY + LETTERSIZE)
#define QUITPOSXEND (MENUMARGIN + LETTERSIZE * 4)
   
#define MOVEUP -1
#define MOVEDOWN 1

#ifdef __cplusplus
}
#endif

#endif /* STATES_ALLEGRO_H */

