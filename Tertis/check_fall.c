#include "check_fall.h"

bool check_fall(PIECE tablero [TABLE_FIL][TABLE_COL])
{
int i,j,abort=0 ;
    for (i=2;i<=TABLE_FIL-2;i++)
    {
        for (j=2;j<=TABLE_COL-2;j++)//estos dos ciclos recorren la matriz
        {
            if (tablero[i][j].state == CAYENDO)
            {   
                if(!(tablero [i+1] [j].type == BLANK ))//si no es estatico el de abajo 
                {
                    if (!(tablero[i+1][j].state == CAYENDO))
                    {
                    abort++;                        
                    }
                }
            }
        }
    }
return abort==0;
        
}