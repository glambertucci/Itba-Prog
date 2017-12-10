#include "general.h"
#include "scored.h"
#include "matrix_manipulation.h"
#include "misc_functions.h"


void calculate_new_velocity(AL_UTILS* al_utils, GAME_UTILS * gamevars)
{
    
    SCORE score = gamevars->score;

    if(score >= 0)
        al_utils->timer_speed = INITIAL / 10.0;
    if(score >= 4)
        al_utils->timer_speed = VERYEASY / 10.0;
    if(score >= 9)
        al_utils->timer_speed = EASY / 10.0;
    if(score >= 15)
        al_utils->timer_speed = NORMAL / 10.0;
    if(score >= 23)
        al_utils->timer_speed = NORMALHARD / 10.0;
    if(score >= 31)
        al_utils->timer_speed = HARD / 10.0;
    if(score >= 40)
        al_utils->timer_speed = VERYHARD / 10.0;
    if(score >= 50)
        al_utils->timer_speed = IMPOSSIBLE / 10.0;
}

void change_velocity(AL_UTILS* al_utils) {

    if((al_get_timer_speed(al_utils->timer)) != (al_utils->timer_speed))
    {
        al_set_timer_speed(al_utils->timer, al_utils->timer_speed);
    }
}

void continueplay(AL_UTILS* al_utils, GAME_UTILS* gamevars, PIECE matrix[TABLE_FIL][TABLE_COL], PIECE piece_mat[MAT_PIECE_FIL][MAT_PIECE_COL])
{                                                    //Se fija si esta parado el timer, si lo esta, lo arranca
    if(!(gamevars->is_not_first_time))
    {
        copy_piece_to_mat(matrix, piece_mat);
        clean_piece_mat(piece_mat);
        next_piece(gamevars);
        fill_mat_piece(piece_mat, gamevars->currentpiece);
        gamevars->is_not_first_time = true;
    }
    
    if(!(al_get_timer_started(al_utils->timer))){
        al_start_timer(al_utils->timer);
    }
}

void pauseplay (AL_UTILS* al_utils, GAME_UTILS* gamevars){ //Cuando se entra al estado menu, se para el timer
    
    if(al_get_timer_started(al_utils->timer))
        al_stop_timer(al_utils->timer);
}

void next_piece(GAME_UTILS* gamevars) {

    gamevars->currentpiece.type =rand() %7 +1;
    gamevars->currentpiece.state = CAYENDO;
}
