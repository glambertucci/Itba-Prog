#include "general.h"
#include "front_pi.h"
#include "matrix_manipulation.h"

void draw_front (AL_UTILS* al_utils, FRONTEND* front_utils, GAME_UTILS* gamevars, PIECE matrix [TABLE_FIL][TABLE_COL]) {
    
    switch(gamevars->state) {
        case PLAYING:
            draw_tablero(matrix);
            draw_next_piece(gamevars->currentpiece);
            draw_score(front_utils, gamevars);
            display_update();
            break;
        case MENU:
            draw_title();
            wait_for_joypress(frontend);
            draw_highscore(frontend);
            draw_options(frontend);
            display_update();
        break;
    }
    
    if(gamevars->lose) {
        gamevars->lose = false;
        draw_gameover();
        display_update();
    }
}

void draw_tablero (PIECE matrix [TABLE_FIL][TABLE_COL]) {
    
    int i, j;
    
    for(i = 2; i < TABLE_FIL-2; i++) {
        for(j = 2; j < TABLE_COL-2; j++) {
            if((matrix->type) != 0)
                display_write(j-2, i-2, D_ON);
            else
                display_write(j-2, i-2, D_OFF);
        }
    }
}

void draw_next_piece (PIECE next_piece) {
    
    PIECE temp [MAT_PIECE_FIL][MAT_PIECE_FIL] = {0};
    int i, j;
    
    fill_mat_piece(temp, next_piece);
    
    for(i = 0; i < MAT_PIECE_FIL; i++) {
        for(j = 0; j < MAT_PIECE_COL; j++) {
            if((temp->type) != 0)
                display_write(12+j, i, D_ON);
            else
                display_write(12+j, i, D_OFF);
        }
    }
}

void draw_score (FRONTEND* front_utils, GAME_UTILS* gamevars) {
    
    int temp[5] = {0}, i, j;
    
    for(i = 0; i < 5; i++) { //para cada centena, decena, etc
        switch(i) {          // obtengo del numero la decena, centena, etc
            case 0:
                temp[i] = (gamevars->score) % 10000;
                break;
            case 1:
                temp[i] = ((gamevars->score) % 1000) - ((temp[i-1])*10);
                break;
            case 2:
                temp[i] = ((gamevars->score) % 100) - ((temp[i-1])*10) - ((temp[i-2])*100);
                break;
            case 3:
                temp[i] = ((gamevars->score) % 100) - ((temp[i-1])*10) - ((temp[i-2])*100) - ((temp[i-3])*1000);
                break;
            case 4:
                temp[i] = ((gamevars->score) % 100) - ((temp[i-1])*10) - ((temp[i-2])*100) - ((temp[i-3])*1000) - ((temp[i-4]*10000));
        }
    }
    
    for(i = 0; i < 5; i++) {                    //para cada decena, centena etc
        for(j = 0; j < temp[i]; j++) {
            display_write(11+i, 15-j, D_ON);    //prende todo desde 0 hasta el numero correspondiente
        }
        for(j = temp[i]; j< 9; j++) {
            display_write(11+i, 15-j, D_OFF);   //apaga todo desde el numero correspondiente hasta 9
        }
    }
}