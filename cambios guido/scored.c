/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
 
#include "scored.h"


SCORE scored (PIECE tablero [TABLE_FIL][TABLE_COL]) 
{
    int i,j,lleno=0,scored=0;
    
    for (i=2;i<TABLE_FIL-2;i++)   //recorro la matriz
    {
        for (j=2;j<TABLE_COL-2;j++)
        {
            if ((tablero[i] [j].type != BLANK ) && (tablero[i][j].type != CEMENTO) )
            {
                lleno++;
                
            }
        }
        
        if (lleno == 10)
        {
            tablero[i] [0].type = SCORED; //pone el tipo scored en la esquina izquierda de la fila que hizo puntos para que la funcion deletefil la mate
            lleno=0;
            scored++;
        }
        else 
            lleno=0;
    }
    return scored; //devuelve la cantidad de lineas en las que se hizo puntos
}


void add_score (int lines_destroyed, GAME_UTILS * gamevars)
{ 
    
    switch (lines_destroyed)
    {
       case 1 : gamevars->score += 100;break;
       case 2 : gamevars->score += 250;break;
       case 3 : gamevars->score += 400;break;
       case 4 : gamevars->score += 600;break;
    }
}