/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "general.h"
#ifdef ALLEGRO
#include "front_allegro.h"
#include <allegro5/system.h>
#include <allegro5/color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
void draw_front(FRONTEND* front_utils, GAME_UTILS* gamevars, PIECE matrix [TABLE_FIL][TABLE_COL]) {
    

    switch(gamevars->state) {
        case PLAYING:
            al_draw_bitmap(front_utils->image[4],0,0,0);
            al_draw_tablero(matrix);
            al_draw_next_piece(gamevars->nextpiece);
            al_draw_score(front_utils, gamevars);
            al_draw_dance(front_utils);
            al_flip_display();
            break;
            
            
        case MENU:

        al_draw_bitmap(front_utils->image[front_utils->selected_op],0,0,0);
        al_draw_text(front_utils->font2, al_map_rgb(255,255,255),SCREEN_W-SEPARACION*6.2, SEPARACION*10.8,ALLEGRO_ALIGN_CENTRE,"CURRENT HIGHSCORE");
        al_draw_textf(front_utils->font2, al_map_rgb(255,255,255),SCREEN_W-SEPARACION*6.2, SEPARACION*11.8,ALLEGRO_ALIGN_CENTRE,"%06d",gamevars->highscore);

        al_flip_display();
        break;
    }
    if(gamevars->lose) {
        if(gamevars->highscore > gamevars->score){
            al_draw_bitmap(front_utils->image[3],0,0,0); //Imágenes diferentes según se haya hecho highscore nuevo o no.
            al_stop_samples();
            al_play_sample (front_utils->samples[2],0.75,0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);
        }
        else{
            al_draw_bitmap(front_utils->image[5],0,0,0);
            al_stop_samples();
            al_play_sample (front_utils->samples[3],0.75,0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);           
        }
        
        al_draw_filled_rectangle( SCREEN_W-SCREEN_W/2-SEPARACION*6, SEPARACION, SCREEN_W-SCREEN_W/2+SEPARACION*6, SEPARACION*3 , al_map_rgb(0,0,0));
        al_draw_textf(front_utils->font1, al_map_rgb(255,255,255),SCREEN_W-SCREEN_W/2, SEPARACION*2-SEPARACION/2,ALLEGRO_ALIGN_CENTRE,"YOUR SCORE: %06d", gamevars->score);

        
        if(gamevars->highscore < gamevars->score){
        al_draw_text(front_utils->font3, al_map_rgb(255,255,255),SCREEN_W-SCREEN_W/2.75, SEPARACION*3-SEPARACION/1.5,ALLEGRO_ALIGN_CENTRE,"New highscore!");
        }
        
        al_flip_display();
        

        if(gamevars->highscore > gamevars->score){ al_rest(3); }
        else{ al_rest(5);}
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


void al_draw_score(FRONTEND * front_utils, GAME_UTILS * gamevars){
    
    al_draw_filled_rectangle( SCREEN_W-SEPARACION*5, SEPARACION*9, SCREEN_W-SEPARACION*2, SEPARACION*10 , al_map_rgb(0,0,0));
    al_draw_filled_rectangle( SCREEN_W-SEPARACION*6, SEPARACION*10, SCREEN_W-SEPARACION*1, SEPARACION*12 , al_map_rgb(0,0,0));
    al_draw_text(front_utils->font1, al_map_rgb(255,255,255),SCREEN_W-SEPARACION*3.5, SEPARACION*8.9,ALLEGRO_ALIGN_CENTRE,"SCORE");
    al_draw_textf(front_utils->font1, al_map_rgb(255,255,255),SCREEN_W-SEPARACION*3.5, SEPARACION*10.5,ALLEGRO_ALIGN_CENTRE,"%06d",gamevars->score);
    
}


void al_draw_dance(FRONTEND * front_utils){
    
    static bool first_time = true;
    static char parswitch = 0;
    ALLEGRO_EVENT event;

    
    if(parswitch>99){
        parswitch = 0; //Reiniciamos parswitch cada tanto solo para estar seguros.
    }
    
    
    if(al_get_next_event(front_utils->ev_utils.rythmq, &event)){ parswitch++; }
    //Cambio la paridad -> Cambia la imagen    

    if((parswitch%2)){
        al_draw_bitmap(front_utils->image[6],574,497,0);
    }
    else{
        al_draw_bitmap(front_utils->image[7],574,497,0);
    }
}
    
    
    
#endif
