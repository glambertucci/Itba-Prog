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


void menu (AL_UTILS * p2al_utils, GAME_UTILS * p2gamevars){

    
  
   ALLEGRO_BITMAP * image; //Puntero a la imagen del menu
   
   image = al_load_bitmap("menu.jpg");
   al_draw_bitmap(image,0,0,0);
   al_flip_display();
   
      /* Estos else if cambian el valor de quit y state cuando 
       * haga click en las coordenadas de START, CONTINUE o QUIT */
     
      if((p2al_utils->mouse->x > MENUMARGIN && p2al_utils->mouse->y > (STARTPOSY)) &&
              (p2al_utils->mouse->x < (STARTPOSXEND) && p2al_utils->mouse->y < (STARTPOSYEND))){
          if(p2al_utils->mouse->mousepress == TRUE) {
              p2gamevars->restart = TRUE; //Con esto, reinicio el juego.
              p2gamevars->quit = TRUE; //Con esto, salgo del primer loop.
          }
      } 
   
      else if((p2al_utils->mouse->x > MENUMARGIN && p2al_utils->mouse->y > (CONTPOSY)) &&
              (p2al_utils->mouse->x < (CONTPOSXEND) && p2al_utils->mouse->y < (CONTPOSYEND))){
          if(p2al_utils->mouse->mousepress == TRUE) {
              p2gamevars->state = PLAYING;
          }
       }

      else if((p2al_utils->mouse->x > MENUMARGIN && p2al_utils->mouse->y > QUITPOSY) &&
          (p2al_utils->mouse->x < QUITPOSXEND && p2al_utils->mouse->y < QUITPOSYEND))
          if(p2al_utils->mouse->mousepress == TRUE) {
              p2gamevars->quit = TRUE;
          }
     
   }