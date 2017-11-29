#include "linedelete.h"
#include "scored.h"
#include "all_static.h"
#include "check_fall.h"
#include "fall.h"

void calculate_lines(PIECE matrix[TABLE_FIL][TABLE_COL]) {
    
    uint8_t i, score;
    
    for(i = TABLE_FIL-3; i >= 2; i--) {
        if(matrix[i][2].type == SCORED) {
            delete_line(matrix, i);
            score++;
        }
    }
    
    add_score(score);
}


void delete_line(PIECE matrix[TABLE_FIL][TABLE_COL], uint8_t fila) {
    
    uint8_t i, j;
    
    for(i = 2; i < TABLE_COL-2; i++) {
        matrix[fila][j].type = BLANK; //Pongo en blanco la linea, el pivote no importa
    }                                 //y ya van a estar estaticos.

    for(i = fila; i >= 2; i++) {
        for(j = 2; j < TABLE_COL-2; j++) {
            matrix[i][j].state = CAYENDO;
        }
    }
    
    while(check_fall(matrix)){
        fall(matrix);
    }
    
    all_static(matrix);

}

void calculate_new_velocity(AL_UTILS* al_utils){
    
    int score = get_score();

    if(score >= 0)
        al_utils->timer_speed = INITIAL;
    else if(score >= 4)
        al_utils->timer_speed = VERYEASY;
    else if(score >= 9)
        al_utils->timer_speed = EASY;
    else if(score >= 15)
        al_utils->timer_speed = NORMAL;
    else if(score >= 23)
        al_utils->timer_speed = NORMALHARD;
    else if(score >= 31)
        al_utils->timer_speed = HARD;
    else if(score >= 40)
        al_utils->timer_speed = VERYHARD;
    else if(score >= 50)
        al_utils->timer_speed = IMPOSSIBLE;
}