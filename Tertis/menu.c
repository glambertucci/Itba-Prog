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
#include <allegro5/allegro.h>
#include "menu.h"


void menu (AL_UTILS * al_utils, GAME_UTILS * gamevars){

    
  
   ALLEGRO_BITMAP * image; //Puntero a la imagen del menu
   
   image = al_load_bitmap("menu.jpg");
   al_draw_bitmap(image,0,0,0);
   al_flip_display();
   
      /* Estos else if cambian el valor de quit y state cuando 
       * haga click en las coordenadas de START, CONTINUE o QUIT */
     
      if((al_utils->mouse.x > MENUMARGIN && al_utils->mouse.y > (STARTPOSY)) &&
              (al_utils->mouse.x < (STARTPOSXEND) && al_utils->mouse.y < (STARTPOSYEND))){
          if(al_utils->mouse.mousepress == TRUE) {
              gamevars->restart = TRUE; //Con esto, reinicio el juego.
              gamevars->quit = TRUE; //Con esto, salgo del primer loop.
          }
      } 
   
      else if((al_utils->mouse.x > MENUMARGIN && al_utils->mouse.y > (CONTPOSY)) &&
              (al_utils->mouse.x < (CONTPOSXEND) && al_utils->mouse.y < (CONTPOSYEND))){
          if(al_utils->mouse.mousepress == TRUE) {
              gamevars->state = PLAYING;
          }
       }

      else if((al_utils->mouse.x > MENUMARGIN && al_utils->mouse.y > QUITPOSY) &&
          (al_utils->mouse.x < QUITPOSXEND && al_utils->mouse.y < QUITPOSYEND))
          if(al_utils->mouse.mousepress == TRUE) {
              gamevars->quit = TRUE;
          }
     
   }