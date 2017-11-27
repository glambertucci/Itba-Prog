/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "all_static.h"

void all_static (PIECE tablero [TABLE_FIL][TABLE_COL] )
{
  
    int i,j;
    for (i = 2; i < TABLE_FIL-2; i++)
    {
        for (j = 2; j < TABLE_COL-2; j++)
        {
            tablero[i][j].state=ESTATICO;
        } 
    }
}
