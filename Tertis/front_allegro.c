/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "general.h"
#include "front_allegro.h"

void draw_front(AL_UTILS* al_utils, FRONTEND* front_utils, GAME_UTILS* gamevars, PIECE matrix [TABLE_FIL][TABLE_COL]) {
    
    switch(gamevars->state) {
        case PLAYING:
            al_draw_bitmap(front_utils->image[4],0,0,0);
            al_draw_tablero(matrix);
            al_draw_next_piece(gamevars->currentpiece);
            al_draw_score(gamevars);
            al_flip_display();
            break;
        case MENU:
            al_draw_bitmap(front_utils->image[front_utils->selected_op],0,0,0); 
            al_flip_display();
            break;
    }
    if(gamevars->lose) {
        gamevars->lose = false;
        al_draw_bitmap(front_utils->image[3],0,0,0);
        al_flip_display();
        al_rest(3);
    }
}


void al_draw_tablero(PIECE tablero [TABLE_FIL][TABLE_COL])
{
    int i,j;
    for (j=2;j<=TABLE_FIL-2;j++)
    {
        for (i=2;i<=TABLE_COL-2;i++)
        {
            if ((tablero [j] [i]).type == BLANK){
                al_draw_filled_rectangle(SEPARACION*i , SEPARACION*j, SEPARACION*i+SEPARACION , SEPARACION*j+SEPARACION ,  al_map_rgb(132,132,132));
                }
            else if (tablero[j][i].type == STICK){
                al_draw_filled_rectangle(SEPARACION*i , SEPARACION*j, SEPARACION*i+SEPARACION , SEPARACION*j+SEPARACION ,  al_map_rgb(255,0,0));
                al_draw_rectangle(SEPARACION*i, SEPARACION*j, SEPARACION*i+SEPARACION, SEPARACION*j+SEPARACION,  al_map_rgb(0,0,0),OUTLINE);
            }
            else if (tablero[j][i].type == EL){
                al_draw_filled_rectangle(SEPARACION*i , SEPARACION*j, SEPARACION*i+SEPARACION , SEPARACION*j+SEPARACION ,  al_map_rgb(139,0,139));
                al_draw_rectangle(SEPARACION*i, SEPARACION*j, SEPARACION*i+SEPARACION, SEPARACION*j+SEPARACION, al_map_rgb(0,0,0),OUTLINE);}
                
            else if (tablero[j][i].type == JEY){
                al_draw_filled_rectangle(SEPARACION*i , SEPARACION*j, SEPARACION*i+SEPARACION , SEPARACION*j+SEPARACION ,  al_map_rgb(0,200,200));
                al_draw_rectangle(SEPARACION*i, SEPARACION*j, SEPARACION*i+SEPARACION, SEPARACION*j+SEPARACION,  al_map_rgb(0,0,0),OUTLINE);
            }
            
            else if (tablero[j][i].type == BLOCK){
                al_draw_filled_rectangle(SEPARACION*i , SEPARACION*j, SEPARACION*i+SEPARACION , SEPARACION*j+SEPARACION ,  al_map_rgb(0,0,255));
                al_draw_rectangle(SEPARACION*i , SEPARACION*j, SEPARACION*i+SEPARACION, SEPARACION*j+SEPARACION,  al_map_rgb(0,0,0),OUTLINE);
            }
            
            else if (tablero[j][i].type == ES){
                 al_draw_filled_rectangle(SEPARACION*i , SEPARACION*j, SEPARACION*i+SEPARACION , SEPARACION*j+SEPARACION ,  al_map_rgb(0,255,0));
                 al_draw_rectangle(SEPARACION*i, SEPARACION*j, SEPARACION*i+SEPARACION, SEPARACION*j+SEPARACION,  al_map_rgb(0,0,0),OUTLINE);
            }
            
            else if (tablero[j][i].type == ZED){
                al_draw_filled_rectangle(SEPARACION*i , SEPARACION*j, SEPARACION*i+SEPARACION , SEPARACION*j+SEPARACION ,  al_map_rgb(0,255,255));
                al_draw_rectangle(SEPARACION*i, SEPARACION*j, SEPARACION*i+SEPARACION, SEPARACION*j+SEPARACION ,  al_map_rgb(0,0,0),OUTLINE);
            }
            
            else if (tablero[j][i].type == TEE){
               al_draw_filled_rectangle(SEPARACION*i , SEPARACION*j, SEPARACION*i+SEPARACION , SEPARACION*j+SEPARACION ,  al_map_rgb(139,69,19));
               al_draw_rectangle(SEPARACION*i, SEPARACION*j, SEPARACION*i+SEPARACION , SEPARACION*j+SEPARACION,  al_map_rgb(0,0,0),OUTLINE);
            }
        } 
    }
}

void al_draw_next_piece (PIECE future )
{
    al_draw_filled_rectangle(SCREEN_W-SEPARACION*6 , SEPARACION*2, SCREEN_W-SEPARACION*1 , SEPARACION*8 ,  al_map_rgb(132,132,132));

    if (future.type == STICK)
    {   al_draw_filled_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*3, SCREEN_W-SEPARACION*3, SEPARACION*7 ,  al_map_rgb(255,0,0));
        al_draw_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*3, SCREEN_W-SEPARACION*3, SEPARACION*4 ,  al_map_rgb(0,0,0),OUTLINE);
        al_draw_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*4, SCREEN_W-SEPARACION*3, SEPARACION*5 ,  al_map_rgb(0,0,0),OUTLINE);
        al_draw_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*5, SCREEN_W-SEPARACION*3, SEPARACION*6 ,  al_map_rgb(0,0,0),OUTLINE);
        al_draw_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*6, SCREEN_W-SEPARACION*3, SEPARACION*7 ,  al_map_rgb(0,0,0),OUTLINE);
       
        
    }
    else if (future.type == EL)
    {
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*3, SCREEN_W-SEPARACION*3, SEPARACION*6 , al_map_rgb(139,0,139));
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*5, SCREEN_W-SEPARACION*2, SEPARACION*6 , al_map_rgb(139,0,139));
        al_draw_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*3, SCREEN_W-SEPARACION*3, SEPARACION*4 , al_map_rgb(0,0,0),OUTLINE);
        al_draw_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*4, SCREEN_W-SEPARACION*3, SEPARACION*5 , al_map_rgb(0,0,0),OUTLINE);        
        al_draw_rectangle( SCREEN_W-SEPARACION*3, SEPARACION*5, SCREEN_W-SEPARACION*2, SEPARACION*6 , al_map_rgb(0,0,0),OUTLINE);
        al_draw_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*5, SCREEN_W-SEPARACION*3, SEPARACION*6 , al_map_rgb(0,0,0),OUTLINE);   
    }
    
        else if (future.type == JEY)
    {
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*3, SCREEN_W-SEPARACION*3, SEPARACION*6 , al_map_rgb(0,200,200));
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*5, SEPARACION*5, SCREEN_W-SEPARACION*4, SEPARACION*6 , al_map_rgb(0,200,200));
        al_draw_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*3, SCREEN_W-SEPARACION*3, SEPARACION*4 , al_map_rgb(0,0,0),OUTLINE);
        al_draw_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*4, SCREEN_W-SEPARACION*3, SEPARACION*5 , al_map_rgb(0,0,0),OUTLINE);
        al_draw_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*5, SCREEN_W-SEPARACION*3, SEPARACION*6 , al_map_rgb(0,0,0),OUTLINE);
        al_draw_rectangle( SCREEN_W-SEPARACION*5, SEPARACION*5, SCREEN_W-SEPARACION*4, SEPARACION*6 , al_map_rgb(0,0,0),OUTLINE);
    }
        else if (future.type == BLOCK)
    {
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*4, SCREEN_W-SEPARACION*2, SEPARACION*6 ,  al_map_rgb(0,0,255));
        al_draw_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*4, SCREEN_W-SEPARACION*3, SEPARACION*5 ,  al_map_rgb(0,0,0),OUTLINE);
        al_draw_rectangle( SCREEN_W-SEPARACION*3, SEPARACION*4, SCREEN_W-SEPARACION*2, SEPARACION*5 ,  al_map_rgb(0,0,0),OUTLINE);
        al_draw_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*5, SCREEN_W-SEPARACION*2, SEPARACION*6 ,  al_map_rgb(0,0,0),OUTLINE);
        al_draw_rectangle( SCREEN_W-SEPARACION*3, SEPARACION*5, SCREEN_W-SEPARACION*2, SEPARACION*6 ,  al_map_rgb(0,0,0),OUTLINE);
    }
        else if (future.type == ES)
    {
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*5, SEPARACION*5, SCREEN_W-SEPARACION*3, SEPARACION*6 ,  al_map_rgb(0,255,0));
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*4, SCREEN_W-SEPARACION*2, SEPARACION*5 ,  al_map_rgb(0,255,0));
        al_draw_rectangle( SCREEN_W-SEPARACION*5, SEPARACION*5, SCREEN_W-SEPARACION*4, SEPARACION*6 ,  al_map_rgb(0,0,0),OUTLINE);
        al_draw_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*5, SCREEN_W-SEPARACION*3, SEPARACION*6 ,  al_map_rgb(0,0,0),OUTLINE);
        al_draw_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*4, SCREEN_W-SEPARACION*3, SEPARACION*5 ,  al_map_rgb(0,0,0),OUTLINE);
        al_draw_rectangle( SCREEN_W-SEPARACION*3, SEPARACION*4, SCREEN_W-SEPARACION*2, SEPARACION*5 ,  al_map_rgb(0,0,0),OUTLINE);
        
    }
        else if (future.type == ZED)
    {
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*5, SCREEN_W-SEPARACION*2, SEPARACION*6 , al_map_rgb(0,255,255));
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*5, SEPARACION*4, SCREEN_W-SEPARACION*3, SEPARACION*5 , al_map_rgb(0,255,255));
        al_draw_rectangle( SCREEN_W-SEPARACION*5, SEPARACION*4, SCREEN_W-SEPARACION*4, SEPARACION*5 ,  al_map_rgb(0,0,0),OUTLINE);
        al_draw_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*5, SCREEN_W-SEPARACION*3, SEPARACION*6 ,  al_map_rgb(0,0,0),OUTLINE);
        al_draw_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*4, SCREEN_W-SEPARACION*3, SEPARACION*5 ,  al_map_rgb(0,0,0),OUTLINE);
        al_draw_rectangle( SCREEN_W-SEPARACION*3, SEPARACION*5, SCREEN_W-SEPARACION*2, SEPARACION*6 ,  al_map_rgb(0,0,0),OUTLINE);        
    }
        else if (future.type == TEE)
    {
        al_draw_filled_rectangle(SCREEN_W-SEPARACION*2, SEPARACION*5 ,SCREEN_W-SEPARACION*5, SEPARACION*6 , al_map_rgb(139,69,19));
        al_draw_filled_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*4 , SCREEN_W-SEPARACION*3, SEPARACION*5, al_map_rgb(139,69,19));
        al_draw_rectangle( SCREEN_W-SEPARACION*5, SEPARACION*5, SCREEN_W-SEPARACION*4, SEPARACION*6 ,  al_map_rgb(0,0,0),OUTLINE);
        al_draw_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*5, SCREEN_W-SEPARACION*3, SEPARACION*6 ,  al_map_rgb(0,0,0),OUTLINE);
        al_draw_rectangle( SCREEN_W-SEPARACION*4, SEPARACION*4, SCREEN_W-SEPARACION*3, SEPARACION*5 ,  al_map_rgb(0,0,0),OUTLINE);
        al_draw_rectangle( SCREEN_W-SEPARACION*3, SEPARACION*5, SCREEN_W-SEPARACION*2, SEPARACION*6 ,  al_map_rgb(0,0,0),OUTLINE);         
    }
}


void al_draw_score(GAME_UTILS * gamevars){
    
    ALLEGRO_FONT *font;
    
   if(!(font = al_load_ttf_font("pixelated.ttf",FONTSIZE,0))){
       printf("Could not load pixelated.ttf.");
   }
   
    al_draw_filled_rectangle( SCREEN_W-SEPARACION*5, SEPARACION*9, SCREEN_W-SEPARACION*2, SEPARACION*10 , al_map_rgb(0,0,0));
    al_draw_filled_rectangle( SCREEN_W-SEPARACION*6, SEPARACION*10, SCREEN_W-SEPARACION*1, SEPARACION*12 , al_map_rgb(0,0,0));
    al_draw_text(font, al_map_rgb(255,255,255),SCREEN_W-SEPARACION*3.5, SEPARACION*8.9,ALLEGRO_ALIGN_CENTRE,"SCORE");
    al_draw_textf(font, al_map_rgb(255,255,255),SCREEN_W-SEPARACION*3.5, SEPARACION*10.5,ALLEGRO_ALIGN_CENTRE,"%05d",gamevars->score);
    
}