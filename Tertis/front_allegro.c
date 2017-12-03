/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "front_allegro.h"

void al_draw_tablero(PIECE tablero [TABLE_FIL][TABLE_COL])
{
    int i,j ;
    for (j=2;j<=TABLE_FIL-2;j++)
    {
        for (i=2;i<=TABLE_COL-2;i++)
        {
            if ((tablero [j] [i]).type == BLANK)
                al_draw_filled_rectangle(SEPARACION*i , SEPARACION*j, SEPARACION*i+SEPARACION , SEPARACION*j+SEPARACION ,  al_map_rgb(0,0,0));
            else if (tablero[j][i].type == STICK)
                al_draw_filled_rectangle(SEPARACION*i , SEPARACION*j, SEPARACION*i+SEPARACION , SEPARACION*j+SEPARACION ,  al_map_rgb(255,0,0));
            else if (tablero[j][i].type == EL)
                al_draw_filled_rectangle(SEPARACION*i , SEPARACION*j, SEPARACION*i+SEPARACION , SEPARACION*j+SEPARACION ,  al_map_rgb(139,0,139));
            else if (tablero[j][i].type == JEY)
                al_draw_filled_rectangle(SEPARACION*i , SEPARACION*j, SEPARACION*i+SEPARACION , SEPARACION*j+SEPARACION ,  al_map_rgb(255,255,255));
            else if (tablero[j][i].type == BLOCK)
                al_draw_filled_rectangle(SEPARACION*i , SEPARACION*j, SEPARACION*i+SEPARACION , SEPARACION*j+SEPARACION ,  al_map_rgb(0,0,255));
            else if (tablero[j][i].type == ES)
                 al_draw_filled_rectangle(SEPARACION*i , SEPARACION*j, SEPARACION*i+SEPARACION , SEPARACION*j+SEPARACION ,  al_map_rgb(0,255,0));
            else if (tablero[j][i].type == ZED)
                al_draw_filled_rectangle(SEPARACION*i , SEPARACION*j, SEPARACION*i+SEPARACION , SEPARACION*j+SEPARACION ,  al_map_rgb(0,255,255));
            else if (tablero[j][i].type == TEE)
               al_draw_filled_rectangle(SEPARACION*i , SEPARACION*j, SEPARACION*i+SEPARACION , SEPARACION*j+SEPARACION ,  al_map_rgb(139,69,19));
        } 
    }

}

void al_draw_next_piece (PIECE future )
{
    al_draw_filled_rectangle(SCREEN_W-SEPARACION*6 , SEPARACION*2, SCREEN_W-SEPARACION*1 , SEPARACION*8 ,  al_map_rgb(0,0,0));

    if (future.type == STICK)
    {
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*3, SCREEN_W-SEPARACION*3, SEPARACION*7 ,  al_map_rgb(255,0,0));
    }
    else if (future.type == EL)
    {
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*3, SCREEN_W-SEPARACION*3, SEPARACION*6 , al_map_rgb(139,0,139));
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*5, SCREEN_W-SEPARACION*2, SEPARACION*6 , al_map_rgb(139,0,139));
    }
        else if (future.type == JEY)
    {
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*3, SCREEN_W-SEPARACION*3, SEPARACION*6 , al_map_rgb(255,255,255));
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*5, SCREEN_W-SEPARACION*5, SEPARACION*6 , al_map_rgb(255,255,255));
    }
        else if (future.type == BLOCK)
    {
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*4, SCREEN_W-SEPARACION*2, SEPARACION*6 ,  al_map_rgb(0,0,255));
    }
        else if (future.type == ES)
    {
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*5, SEPARACION*5, SCREEN_W-SEPARACION*3, SEPARACION*6 ,  al_map_rgb(0,255,0));
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*4, SCREEN_W-SEPARACION*2, SEPARACION*5 ,  al_map_rgb(0,255,0));
    }
        else if (future.type == ZED)
    {
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*5, SCREEN_W-SEPARACION*2, SEPARACION*6 , al_map_rgb(0,255,255));
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*5, SEPARACION*4, SCREEN_W-SEPARACION*3, SEPARACION*5 , al_map_rgb(0,255,255));
    }
        else if (future.type == TEE)
    {
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*3, SCREEN_W-SEPARACION*3, SEPARACION*6 , al_map_rgb(139,69,19));
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*5, SCREEN_W-SEPARACION*5, SEPARACION*4 , al_map_rgb(139,69,19));
    }
    
}

