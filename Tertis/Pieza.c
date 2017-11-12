
#include "general.h"

#include "Pieza.h"
void fill_mat_piece (PIECE next_piece_mat [MAT_PIECE_FIL][MAT_PIECE_COL], PIECE pieza)
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
    }
    else if (pieza.type == EL)
    {
       next_piece_mat[1][1].type=EL;
       next_piece_mat[1][1].state=CAYENDO;
       next_piece_mat[2][1].type=EL;
       next_piece_mat[2][1].state=CAYENDO;
       next_piece_mat[3][1].type=EL;
       next_piece_mat[3][1].state=CAYENDO;
       next_piece_mat[3][2].type=EL;
       next_piece_mat[3][2].state=CAYENDO;
    }
        else if (pieza.type == JEY)
    {
       next_piece_mat[1][1].type=JEY;
       next_piece_mat[1][1].state=CAYENDO;
       next_piece_mat[2][1].type=JEY;
       next_piece_mat[2][1].state=CAYENDO;
       next_piece_mat[3][1].type=JEY;
       next_piece_mat[3][1].state=CAYENDO;
       next_piece_mat[3][0].type=JEY;
       next_piece_mat[3][0].state=CAYENDO;
    }
        else if (pieza.type == BLOCK)
    {
       next_piece_mat[2][0].type=BLOCK;
       next_piece_mat[2][0].state=CAYENDO;
       next_piece_mat[2][1].type=BLOCK;
       next_piece_mat[2][1].state=CAYENDO;
       next_piece_mat[3][1].type=BLOCK;
       next_piece_mat[3][1].state=CAYENDO;
       next_piece_mat[3][0].type=BLOCK;
       next_piece_mat[3][0].state=CAYENDO;
    }
        else if (pieza.type == ES)
    {
       next_piece_mat[2][1].type=ES;
       next_piece_mat[2][1].state=CAYENDO;
       next_piece_mat[2][2].type=ES;
       next_piece_mat[2][2].state=CAYENDO;
       next_piece_mat[3][1].type=ES;
       next_piece_mat[3][1].state=CAYENDO;
       next_piece_mat[3][0].type=ES;
       next_piece_mat[3][0].state=CAYENDO;
    }
        else if (pieza.type == ZED)
    {
       next_piece_mat[2][1].type=ZED;
       next_piece_mat[2][1].state=CAYENDO;
       next_piece_mat[2][0].type=ZED;
       next_piece_mat[2][0].state=CAYENDO;
       next_piece_mat[3][1].type=ZED;
       next_piece_mat[3][1].state=CAYENDO;
       next_piece_mat[3][2].type=ZED;
       next_piece_mat[3][2].state=CAYENDO;
    }
        else if (pieza.type == TEE)
    {
       next_piece_mat[3][2].type=TEE;
       next_piece_mat[3][2].state=CAYENDO;
       next_piece_mat[2][1].type=TEE;
       next_piece_mat[2][1].state=CAYENDO;
       next_piece_mat[3][1].type=TEE;
       next_piece_mat[3][1].state=CAYENDO;
       next_piece_mat[3][0].type=TEE;
       next_piece_mat[3][0].state=CAYENDO;
    }
}
 