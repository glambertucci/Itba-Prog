#include "general.h"
#include "scored.h"
#include "matrix_manipulation.h"
#include "misc_functions.h"


void calculate_new_velocity(EV_UTILS* ev_utils, GAME_UTILS * gamevars)
{
    
    SCORE score = gamevars->score;

    if(score >= 0)
        ev_utils->timer_speed = INITIAL / 10.0;
    if(score >= 4*SCORE1)
        ev_utils->timer_speed = VERYEASY / 10.0;
    if(score >= 9*SCORE1)
        ev_utils->timer_speed = EASY / 10.0;
    if(score >= 15*SCORE1)
        ev_utils->timer_speed = NORMAL / 10.0;
    if(score >= 23*SCORE1)
        ev_utils->timer_speed = NORMALHARD / 10.0;
    if(score >= 31*SCORE1)
        ev_utils->timer_speed = HARD / 10.0;
    if(score >= 40*SCORE1)
        ev_utils->timer_speed = VERYHARD / 10.0;
    if(score >= 50*SCORE1)
        ev_utils->timer_speed = IMPOSSIBLE / 10.0;
}


//Change_velocity es evento-dependiente, entonces compilará según plataforma. Caso excepcional.

void continueplay(EV_UTILS* al_utils, GAME_UTILS* gamevars, PIECE matrix[TABLE_FIL][TABLE_COL], PIECE piece_mat[MAT_PIECE_FIL][MAT_PIECE_COL])
{   //Se fija si esta parado el timer, si lo esta, lo arranca
    if(!(gamevars->is_not_first_time))
    {
        copy_piece_to_mat(matrix, piece_mat, gamevars);
        clean_piece_mat(piece_mat);
        next_piece(gamevars);
        fill_mat_piece(piece_mat, gamevars->nextpiece);
        gamevars->is_not_first_time = true;
    }
    
    if(!(al_get_timer_started(al_utils->timer))){
        al_start_timer(al_utils->timer);
    }
}

void pauseplay (EV_UTILS* al_utils, GAME_UTILS* gamevars){ //Cuando se entra al estado menu, se para el timer
    
    if(al_get_timer_started(al_utils->timer))
        al_stop_timer(al_utils->timer);
}

void next_piece(GAME_UTILS* gamevars) {

    gamevars->nextpiece.type =rand() %7 +1;
    gamevars->nextpiece.state = CAYENDO;
}
