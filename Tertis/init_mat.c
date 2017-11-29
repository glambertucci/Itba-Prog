/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "init_mat.h"
void init_mat (PIECE next_piece_mat [MAT_PIECE_FIL][MAT_PIECE_COL])
{
    int i,j;
    for (i=0;i<MAT_PIECE_FIL;i++)
    {
        for (j=0;j<MAT_PIECE_COL;j++)
        {
            next_piece_mat[i][j].state=ESTATICO;
            next_piece_mat[i][j].type=BLANK;
        } 
    }
}
