/*#include "general.h"
#include "Pieza.h"
PIECE * fill_mat_piece (PIECE next_piece_mat [4][3], PIECE pieza)
{
    if (pieza.type == STICK)
    {
        
        next_piece_mat[0][1].type=STICK;
        next_piece_mat[0][1].state=CAYENDO;
        next_piece_mat[1][1].type=STICK;
        next_piece_mat[1][1].state=CAYENDO;
        next_piece_mat[2][1].type=STICK;
        next_piece_mat[2][1].state=CAYENDO;
        next_piece_mat[3][1].type=STICK;
        next_piece_mat[3][1].state=CAYENDO;
        next_piece_mat[0][0].type=BLANK;
        next_piece_mat[0][0].state=ESTATICO;
        next_piece_mat[0][2].type=BLANK;
        next_piece_mat[0][2].state=ESTATICO;
        next_piece_mat[1][0].type=BLANK;
        next_piece_mat[1][2].state=ESTATICO;
        next_piece_mat[1][3].type=BLANK;
        next_piece_mat[2][0].state=ESTATICO;
        next_piece_mat[2][2].type=BLANK;
        next_piece_mat[2][3].state=ESTATICO;
        next_piece_mat[3][0].type=BLANK;
        next_piece_mat[3][0].state=ESTATICO;
    }
    else if (pieza.type == EL)
    {
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*3, SCREEN_W-SEPARACION*3, SEPARACION*6 , al_map_rgb(139,0,139));
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*5, SCREEN_W-SEPARACION*2, SEPARACION*6 , al_map_rgb(139,0,139));
    }
        else if (pieza.type == JEY)
    {
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*3, SCREEN_W-SEPARACION*3, SEPARACION*6 , al_map_rgb(255,255,255));
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*5, SCREEN_W-SEPARACION*5, SEPARACION*6 , al_map_rgb(255,255,255));
    }
        else if (pieza.type == BLOCK)
    {
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*4, SCREEN_W-SEPARACION*2, SEPARACION*6 ,  al_map_rgb(0,0,255));
    }
        else if (pieza.type == ES)
    {
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*5, SEPARACION*5, SCREEN_W-SEPARACION*3, SEPARACION*6 ,  al_map_rgb(0,255,0));
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*4, SCREEN_W-SEPARACION*2, SEPARACION*5 ,  al_map_rgb(0,255,0));
    }
        else if (pieza.type == ZED)
    {
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*5, SCREEN_W-SEPARACION*2, SEPARACION*6 , al_map_rgb(0,255,255));
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*5, SEPARACION*4, SCREEN_W-SEPARACION*3, SEPARACION*5 , al_map_rgb(0,255,255));
    }
        else if (pieza.type == TEE)
    {
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*3, SCREEN_W-SEPARACION*3, SEPARACION*6 , al_map_rgb(139,69,19));
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*5, SCREEN_W-SEPARACION*5, SEPARACION*4 , al_map_rgb(139,69,19));
    }
}
 * */