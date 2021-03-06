#include "general.h"
#ifdef ALLEGRO
#include "front_init_allegro.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

bool frontend_init(FRONTEND * front_utils){

    int abort = false; 

      if (!al_init_acodec_addon())				// 
    {											
        fprintf(stderr,"Codec not initialized");
        abort = 1;
    }
    
    if(!(al_init_image_addon())){
        fprintf(stderr, "Image addon failed to initialize.");
        abort = 1;
    }
    
    if(!(al_init_primitives_addon())){
        fprintf(stderr, "Primitives addon failed to initialize.");
        abort = 1;
    }
    
    if(!(al_install_keyboard())){
        fprintf(stderr, "Keyboard failed to initialize.");
        abort = 1;
    }
    
    if (!al_install_audio())					//
    {								
        fprintf(stderr,"Audio not installed");
        abort = 1;  
 
    }
    
    if(!(al_install_mouse())){
        fprintf(stderr, "Mouse failed to initialize.");
        abort = 1;
    }

    if(!(front_utils->display = al_create_display(SCREEN_W, SCREEN_H))){
        fprintf(stderr, "Display failed to load.");
        abort = 1;
        al_uninstall_audio();
    }

    if (!(front_utils->image[0] = al_load_bitmap("menus.jpg")))
    {
        al_destroy_display(front_utils->display);
        al_uninstall_audio();
        abort=1;
    }
    if(!(front_utils->image[1] = al_load_bitmap("menuc.jpg")))
    {
        al_destroy_bitmap(front_utils->image[0]);
        al_destroy_display(front_utils->display);
        al_uninstall_audio();
        abort=1;
    }
    if(!(front_utils->image[2] = al_load_bitmap("menuq.jpg")))
    {
        al_destroy_bitmap(front_utils->image[1]);
        al_destroy_bitmap(front_utils->image[0]);
        al_destroy_display(front_utils->display);
        al_uninstall_audio();
        abort=1;
    }
    if(!(front_utils->image[3] = al_load_bitmap("gameover.jpg")))
    {
        al_destroy_bitmap(front_utils->image[2]);
        al_destroy_bitmap(front_utils->image[1]);
        al_destroy_bitmap(front_utils->image[0]);
        al_destroy_display(front_utils->display);
        al_uninstall_audio();
        abort=1;
    }
   
    if(!(front_utils->image[4] = al_load_bitmap("TBG.jpg")))
    {
        al_destroy_bitmap(front_utils->image[3]);
        al_destroy_bitmap(front_utils->image[2]);
        al_destroy_bitmap(front_utils->image[1]);
        al_destroy_bitmap(front_utils->image[0]);
        al_destroy_display(front_utils->display);
        al_uninstall_audio();
        abort=1;
    }
    
    if(!(front_utils->image[5] = al_load_bitmap("highscore.jpg")))
    {
        al_destroy_bitmap(front_utils->image[4]);
        al_destroy_bitmap(front_utils->image[3]);
        al_destroy_bitmap(front_utils->image[2]);
        al_destroy_bitmap(front_utils->image[1]);
        al_destroy_bitmap(front_utils->image[0]);
        al_destroy_display(front_utils->display);
        al_uninstall_audio();
        abort=1;
    }
    
    if(!(front_utils->image[6] = al_load_bitmap("DCL.jpg")))
    {
        al_destroy_bitmap(front_utils->image[5]);
        al_destroy_bitmap(front_utils->image[4]);
        al_destroy_bitmap(front_utils->image[3]);
        al_destroy_bitmap(front_utils->image[2]);
        al_destroy_bitmap(front_utils->image[1]);
        al_destroy_bitmap(front_utils->image[0]);
        al_destroy_display(front_utils->display);
        al_uninstall_audio();
        abort=1;
    }        
    
    if(!(front_utils->image[7] = al_load_bitmap("DCR.jpg")))
    {
        al_destroy_bitmap(front_utils->image[6]);
        al_destroy_bitmap(front_utils->image[5]);
        al_destroy_bitmap(front_utils->image[4]);
        al_destroy_bitmap(front_utils->image[3]);
        al_destroy_bitmap(front_utils->image[2]);
        al_destroy_bitmap(front_utils->image[1]);
        al_destroy_bitmap(front_utils->image[0]);
        al_destroy_display(front_utils->display);
        al_uninstall_audio();
        abort=1;
    }
   
      
    
    al_reserve_samples(3);
 
    if (!((front_utils->samples[0]) = al_load_sample( "playing2.wav" )))
    {
        fprintf(stderr,"sample 1 not loaded\n");
        al_destroy_bitmap(front_utils->image[7]);
        al_destroy_bitmap(front_utils->image[6]);
        al_destroy_bitmap(front_utils->image[5]);
        al_destroy_bitmap(front_utils->image[4]);        
        al_destroy_bitmap(front_utils->image[3]);
        al_destroy_bitmap(front_utils->image[3]);
        al_destroy_bitmap(front_utils->image[2]);
        al_destroy_bitmap(front_utils->image[1]);
        al_destroy_bitmap(front_utils->image[0]);
        al_destroy_display(front_utils->display);
        al_uninstall_audio();
        abort=1;
    }
    
   if(!(front_utils->samples[1] = al_load_sample("menu.wav")))
   {
        fprintf(stderr,"sample 2 not loaded\n");
        al_destroy_sample(front_utils->samples[0]);
        al_destroy_bitmap(front_utils->image[7]);
        al_destroy_bitmap(front_utils->image[6]);
        al_destroy_bitmap(front_utils->image[5]);
        al_destroy_bitmap(front_utils->image[4]);          
        al_destroy_bitmap(front_utils->image[3]);
        al_destroy_bitmap(front_utils->image[3]);
        al_destroy_bitmap(front_utils->image[2]);
        al_destroy_bitmap(front_utils->image[1]);
        al_destroy_bitmap(front_utils->image[0]);
        al_destroy_display(front_utils->display);
        al_uninstall_audio();
        abort=1;
   }
    
   if(!(front_utils->samples[2] = al_load_sample("lost.wav")))
   {
        fprintf(stderr,"sample 3 not loaded\n");    
        al_destroy_sample(front_utils->samples[1]);      
        al_destroy_sample(front_utils->samples[0]);
        al_destroy_bitmap(front_utils->image[7]);
        al_destroy_bitmap(front_utils->image[6]);
        al_destroy_bitmap(front_utils->image[5]);
        al_destroy_bitmap(front_utils->image[4]);          
        al_destroy_bitmap(front_utils->image[3]);        
        al_destroy_bitmap(front_utils->image[3]);
        al_destroy_bitmap(front_utils->image[2]);
        al_destroy_bitmap(front_utils->image[1]);
        al_destroy_bitmap(front_utils->image[0]);
        al_destroy_display(front_utils->display);
        al_uninstall_audio();
        abort=1;
    }
    
    
       if(!(front_utils->samples[3] = al_load_sample("win.wav")))
   {
        fprintf(stderr,"sample 4 not loaded\n");
        al_destroy_sample(front_utils->samples[2]);        
        al_destroy_sample(front_utils->samples[1]);      
        al_destroy_sample(front_utils->samples[0]);
        al_destroy_bitmap(front_utils->image[7]);
        al_destroy_bitmap(front_utils->image[6]);
        al_destroy_bitmap(front_utils->image[5]);
        al_destroy_bitmap(front_utils->image[4]);          
        al_destroy_bitmap(front_utils->image[3]);        
        al_destroy_bitmap(front_utils->image[3]);
        al_destroy_bitmap(front_utils->image[2]);
        al_destroy_bitmap(front_utils->image[1]);
        al_destroy_bitmap(front_utils->image[0]);
        al_destroy_display(front_utils->display);
        al_uninstall_audio();
        abort=1;
    }
    
     al_init_font_addon();
     al_init_ttf_addon();
    
     if(!(front_utils->font1 = al_load_font("pixelated.ttf", FONTSIZE, 0)))
     {
        fprintf(stderr, "Font 1 failed to initialize");
        al_destroy_sample(front_utils->samples[3]);        
        al_destroy_sample(front_utils->samples[2]);  
        al_destroy_sample(front_utils->samples[1]);      
        al_destroy_sample(front_utils->samples[0]);
        al_destroy_bitmap(front_utils->image[7]);
        al_destroy_bitmap(front_utils->image[6]);
        al_destroy_bitmap(front_utils->image[5]);
        al_destroy_bitmap(front_utils->image[4]);          
        al_destroy_bitmap(front_utils->image[3]);        
        al_destroy_bitmap(front_utils->image[3]);
        al_destroy_bitmap(front_utils->image[2]);
        al_destroy_bitmap(front_utils->image[1]);
        al_destroy_bitmap(front_utils->image[0]);
        al_destroy_display(front_utils->display);
        al_uninstall_audio();
        abort = 1;
     }
     
     if(!(front_utils->font2 = al_load_font("pixelated.ttf", FONTSIZE-10, 0)))
     {
         fprintf(stderr, "Font 2 failed to initialize");
         al_destroy_font(front_utils->font1);
         al_destroy_sample(front_utils->samples[3]); 
         al_destroy_sample(front_utils->samples[2]);
         al_destroy_sample(front_utils->samples[1]);      
         al_destroy_sample(front_utils->samples[0]);
         al_destroy_bitmap(front_utils->image[7]);
        al_destroy_bitmap(front_utils->image[6]);
         al_destroy_bitmap(front_utils->image[5]);
         al_destroy_bitmap(front_utils->image[4]);  
         al_destroy_bitmap(front_utils->image[3]);        
         al_destroy_bitmap(front_utils->image[3]);
         al_destroy_bitmap(front_utils->image[2]);
         al_destroy_bitmap(front_utils->image[1]);
         al_destroy_bitmap(front_utils->image[0]);
         al_destroy_display(front_utils->display);
         al_uninstall_audio();
         abort = 1;
     } 
     
     if(!(front_utils->font3 = al_load_font("pixelated.ttf", FONTSIZE-20, 0)))
     {
         fprintf(stderr, "Font 3 failed to initialize");
         al_destroy_font(front_utils->font2);    
         al_destroy_font(front_utils->font1);
         al_destroy_sample(front_utils->samples[3]); 
         al_destroy_sample(front_utils->samples[2]);         
         al_destroy_sample(front_utils->samples[1]);      
         al_destroy_sample(front_utils->samples[0]);
         al_destroy_bitmap(front_utils->image[7]);
         al_destroy_bitmap(front_utils->image[6]);
         al_destroy_bitmap(front_utils->image[5]);
         al_destroy_bitmap(front_utils->image[4]);           
         al_destroy_bitmap(front_utils->image[3]);        
         al_destroy_bitmap(front_utils->image[3]);
         al_destroy_bitmap(front_utils->image[2]);
         al_destroy_bitmap(front_utils->image[1]);
         al_destroy_bitmap(front_utils->image[0]);
         al_destroy_display(front_utils->display);
         al_uninstall_audio();
         abort = 1;
     }      
     
     
    al_register_event_source(front_utils->ev_utils.queue, al_get_display_event_source(front_utils->display));
    al_register_event_source(front_utils->ev_utils.queue, al_get_keyboard_event_source());
    al_register_event_source(front_utils->ev_utils.queue, al_get_mouse_event_source());
    
    return !(abort);
}

void frontend_destroy(FRONTEND* front_utils)
{
        al_destroy_font(front_utils->font1);
        al_destroy_font(front_utils->font2);
        al_destroy_sample(front_utils->samples[3]); 
        al_destroy_sample(front_utils->samples[2]); 
        al_destroy_sample(front_utils->samples[1]);       
        al_destroy_sample(front_utils->samples[0]);
        al_destroy_bitmap(front_utils->image[7]);
        al_destroy_bitmap(front_utils->image[6]);
        al_destroy_bitmap(front_utils->image[5]);          
        al_destroy_bitmap(front_utils->image[4]);
        al_destroy_bitmap(front_utils->image[3]);
        al_destroy_bitmap(front_utils->image[2]);
        al_destroy_bitmap(front_utils->image[1]);
        al_destroy_bitmap(front_utils->image[0]);
        al_destroy_display(front_utils->display);
        al_uninstall_audio();
}
#endif