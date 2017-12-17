
#include "front_pi.h"
#ifdef RASP_PI
#include "disdrv.h"
#include "joydrv.h"
void draw_front ( FRONTEND* front_utils, GAME_UTILS* gamevars, PIECE matrix [TABLE_FIL][TABLE_COL]) {
    switch(gamevars->state) 
    {
        case PLAYING:
            draw_tablero(matrix);
            draw_next_piece(gamevars->currentpiece);
            draw_score(front_utils, gamevars);
            display_update();
            break;
        case MENU:
            draw_options_and_highscore(front_utils, gamevars);
            display_update();
        break;
    }
    
    if(gamevars->lose) {
        gamevars->lose = false;
 //       draw_gameover();
        display_update();
    }
}

void draw_tablero (PIECE matrix [TABLE_FIL][TABLE_COL]) {
    
    int i, j;
    
    for(i = 2; i < TABLE_FIL-2; i++) {
        for(j = 2; j < TABLE_COL-2; j++) {
            if((matrix[i][j].type) != 0)
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
            if((temp[i][j].type) != 0)
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

void draw_options_and_highscore(FRONTEND* front_utils, GAME_UTILS* gamevars) {
    
    if(!(front_utils->menu_drawed)){
    draw_s();
 //       printf("Estado start"); //DEBUG
    draw_c();
 //       printf("Estado cONTINUE"); //DEBUG
    draw_q();
//        printf("Estado quit"); //DEBUG
    draw_highscore(gamevars);
    front_utils->menu_drawed = true;
    }
    
    switch(front_utils->option) {
        case START:
            display_write(1, 6, D_ON);
        case CONTINUE:
            display_write(7, 6, D_ON);
            display_write(8, 6, D_ON);
        case QUIT:
            display_write(14, 6, D_ON);
    }
}

void draw_highscore(GAME_UTILS* gamevars) {
    
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
            display_write(7+(2*i), 15-j, D_ON);    //prende todo desde 0 hasta el numero correspondiente
        }
        for(j = temp[i]; j< 9; j++) {
            display_write(7+(2*i), 15-j, D_OFF);   //apaga todo desde el numero correspondiente hasta 9
        }
    }
    
    display_write(0, 14, D_ON);
    display_write(0, 13, D_ON);
    display_write(0, 12, D_ON);
    display_write(1, 13, D_ON);
    display_write(2, 14, D_ON);
    display_write(2, 13, D_ON);
    display_write(2, 12, D_ON);
    display_write(3, 15, D_ON);
    display_write(3, 13, D_ON);
    display_write(3, 12, D_ON);
    display_write(3, 11, D_ON);
    display_write(4, 15, D_ON);
    display_write(4, 13, D_ON);
    display_write(4, 11, D_ON);
    display_write(5, 15, D_ON);
    display_write(5, 14, D_ON);
    display_write(5, 13, D_ON);
    display_write(5, 11, D_ON);
}

void draw_s(void)
{
    display_write(0,0, D_ON);
    display_write(0,1, D_ON);
    display_write(0,2, D_ON);
    display_write(1,0, D_ON);
    display_write(2,0, D_ON);
    display_write(2,1, D_ON);
    display_write(2,2, D_ON);
    display_write(3,2, D_ON);
    display_write(4,0, D_ON);
    display_write(4,1, D_ON);
    display_write(4,2, D_ON);
}
void draw_q(void)
{
    display_write(0,13, D_ON);
    display_write(0,14, D_ON);
    display_write(0,15, D_ON);
    display_write(1,13, D_ON);
    display_write(1,15, D_ON);
    display_write(2,13, D_ON);
    display_write(2,15, D_ON);
    display_write(3,13, D_ON);
    display_write(3,14, D_ON);
    display_write(3,15, D_ON);
    display_write(4,14, D_ON);    
}
void draw_c(void)
{
    display_write(0,6, D_ON);
    display_write(0,7, D_ON);
    display_write(0,8, D_ON);
    display_write(0,9, D_ON);
    display_write(1,6, D_ON);
    display_write(2,6, D_ON);
    display_write(3,6, D_ON);
    display_write(4,6, D_ON);
    display_write(4,7, D_ON);
    display_write(4,8, D_ON);
    display_write(4,9, D_ON);    
}
void draw_tetris (void)
{
    display_clear(); //funcion fantasma

    //----------T---------//
    display_write(0,0, D_ON);
    display_write(0,1, D_ON);
    display_write(0,2, D_ON);
    display_write(1,1, D_ON);
    display_write(2,1, D_ON);
    display_write(3,1, D_ON);
    display_write(4,1, D_ON);
    //---------E---------//
    display_write(0,4, D_ON);
    display_write(0,5, D_ON);
    display_write(0,6, D_ON);
    display_write(1,4, D_ON);
    display_write(2,4, D_ON);
    display_write(2,5, D_ON);
    display_write(3,4, D_ON);
    display_write(4,4, D_ON);
    display_write(4,5, D_ON);
    display_write(4,6, D_ON);
    //--------T----------//
    display_write(6,5, D_ON);
    display_write(6,6, D_ON);
    display_write(6,7, D_ON);
    display_write(7,6, D_ON);
    display_write(8,6, D_ON);
    display_write(9,6, D_ON);
    display_write(10,6, D_ON);
    //--------R----------//
    display_write(6,9, D_ON);
    display_write(6,10, D_ON);
    display_write(6,11, D_ON);
    display_write(7,9, D_ON);
    display_write(7,11, D_ON);
    display_write(8,9, D_ON);
    display_write(8,10, D_ON);
    display_write(8,11, D_ON);
    display_write(9,9, D_ON);
    display_write(9,10, D_ON);
    display_write(10,9, D_ON);
    display_write(10,11, D_ON);
    //--------I----------//
    //El punto forma parte de la R, por eso no se vuelve a escribir
    display_write(12,11, D_ON);
    display_write(13,11, D_ON);
    display_write(14,11, D_ON);
    display_write(15,11, D_ON);
    //--------S----------//
    display_write(11,13, D_ON);
    display_write(11,14, D_ON);
    display_write(11,15, D_ON);
    display_write(12,13, D_ON);
    display_write(13,13, D_ON);
    display_write(13,14, D_ON);
    display_write(13,15, D_ON);
    display_write(14,15, D_ON);
    display_write(15,13, D_ON);
    display_write(15,14, D_ON);
    display_write(15,15, D_ON);
}
#endif