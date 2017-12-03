#include "general.h"
#include "scored.h"


void calculate_new_velocity(AL_UTILS* al_utils){
    
    int score = get_score();

    if(score >= 0)
        al_utils->timer_speed = INITIAL / 10.0;
    else if(score >= 4)
        al_utils->timer_speed = VERYEASY / 10.0;
    else if(score >= 9)
        al_utils->timer_speed = EASY / 10.0;
    else if(score >= 15)
        al_utils->timer_speed = NORMAL / 10.0;
    else if(score >= 23)
        al_utils->timer_speed = NORMALHARD / 10.0;
    else if(score >= 31)
        al_utils->timer_speed = HARD / 10.0;
    else if(score >= 40)
        al_utils->timer_speed = VERYHARD / 10.0;
    else if(score >= 50)
        al_utils->timer_speed = IMPOSSIBLE / 10.0;
}

void change_velocity(AL_UTILS* al_utils) {

    if((al_get_timer_speed(al_utils->timer)) != (al_utils->timer_speed)){
        al_set_timer_speed(al_utils->timer, al_utils->timer_speed);
    }
}

void continueplay(AL_UTILS* al_utils, GAME_UTILS* gamevars, PIECE matrix[TABLE_FIL][TABLE_COL], PIECE piece_mat[MAT_PIECE_FIL][MAT_PIECE_COL]){ //Se fija si esta parado el timer, si lo esta, lo arranca
    if(!(al_get_timer_started(al_utils->timer))){
        al_start_timer(al_utils->timer);
    }
}

void pauseplay (AL_UTILS* al_utils, GAME_UTILS* gamevars){ //Cuando se entra al estado menu, se para el timer
    
    if(al_get_timer_started(al_utils->timer))
        al_stop_timer(al_utils->timer);
}

void next_piece(GAME_UTILS* gamevars) {

    gamevars->currentpiece.type = rand() %7 +1;
    gamevars->currentpiece.state = CAYENDO;
}
