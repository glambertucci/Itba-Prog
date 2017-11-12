/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "all_static.h"

void all_static (PIECE tablero [TABLE_FIL][TABLE_COL] )
{
  
    int i,j;
    for (j=0;j<=TABLE_FIL;j++)
    {
        for (i=0;i<=TABLE_COL;i++)
        {
            tablero[i][j].state=ESTATICO;
        } 
    }
}