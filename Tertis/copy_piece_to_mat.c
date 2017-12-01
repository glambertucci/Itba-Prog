
#include "copy_piece_to_mat.h"

void copy_piece_to_mat (PIECE tablero [TABLE_FIL][TABLE_COL],PIECE next_piece_mat [MAT_PIECE_FIL][MAT_PIECE_COL])
{
    int i,j;
    for (i=0;i<MAT_PIECE_FIL;i++)
    {
        for(j=0;j<MAT_PIECE_COL;j++)
        {
            tablero[i+2][j+6].type = next_piece_mat[i][j].type;
            tablero[i+2][j+6].state = next_piece_mat[i][j].state;
            tablero[i+2][j+6].pivot = next_piece_mat[i][j].pivot;
        }
    }
}

bool can_i_copy (PIECE tablero [TABLE_FIL][TABLE_COL])
{
    int i,j,abort=0;
        for (i=2;i<MAT_PIECE_FIL+2;i++)
        {
            for(j=6;j<MAT_PIECE_COL+6;j++)
            {
                if (tablero[i][j].type != BLANK)
                {
                    abort++;
                }
            }
        }
    return abort==0;
}

void clean_piece_mat (PIECE mat [MAT_PIECE_FIL][MAT_PIECE_COL]){
    int i, j;
    for(i = 0; i < MAT_PIECE_FIL; i++){
        for(j = 0; j < MAT_PIECE_COL; j++){
            mat[i][j].type = BLANK;
            mat[i][j].state = ESTATICO;
            mat[i][j].pivot = false;
        }
    }
}