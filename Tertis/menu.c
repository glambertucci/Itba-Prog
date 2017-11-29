/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <allegro5/bitmap.h>
#include <allegro5/display.h>
#include <allegro5/bitmap_io.h>
#include <allegro5/allegro_color.h> 
#include <allegro5/allegro_image.h> 
#include <allegro5/allegro5.h> 
#include <allegro5/allegro_color.h> 
#include <allegro5/allegro_image.h> 
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>


#include "menu.h"
int menu (void)
{
    ALLEGRO_BITMAP * symbol;
    al_init_image_addon();
    
    al_clear_to_color(al_map_rgb(0,0,0));
    
     symbol=   al_create_bitmap(800,800);

      
    if (!(symbol= al_load_bitmap("menu.jpg") ))
    {
        fprintf(stderr, "Image not loaded");
        return -1;
    }  
    //aca deberia haber un while, que sea hasta que elija una de las opciones, estas siendo 4 que es close display quit continue y start, quit y close display devuelven QUIT
     //los otros segun el enum, para fijarse como detectar los click del mouse miren allegro.cc o el tp anterior, pero ahi esta hehco medio negro, encontre nuevas cosas en allegro,.cc que estn piola
     al_draw_bitmap(symbol,0,0,0);
     al_flip_display();
     al_rest(3.0);
     
 al_destroy_bitmap(symbol);
    return 0;
}