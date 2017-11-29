/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
 
#include "scored.h"
static unsigned int score=0;
bool scored (PIECE tablero [TABLE_FIL][TABLE_COL]) 
{
    int i,j,lleno=0;
    bool scored=false;
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
            tablero[i] [2].type = SCORED; //pone el tipo scored en la esquina izquierda de la fila que hizo puntos para que la funcion deletefil la mate
            lleno=0;
            scored=true;
        }
        else 
            lleno=0;
    }
    return scored!=0; //devuelve 1 si hiciste puntos, 0 si no
}


void add_score (int lines_destoyed)
{

    switch (lines_destoyed)
    {
        case 1 : score++;break;
        case 2 : score+=2; break;
        case 3 : score+=3; break;
        case 4 : score+=4; break;
    }
    
}
int get_score (void)
{
    return score;
}
