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


int menu (ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE *event_queue){

    
  
   ALLEGRO_BITMAP * image; //PUntero a la imagen del menu
   int option = -1; //Esta variable va al return, indicando qué se presionó.
   
 //Registro los eventos de display y de mouse.
   
   image = al_load_bitmap("menu.jpg");
   al_draw_bitmap(image,0,0,0);
   al_flip_display();
   
   while(option == -1)
   {
      ALLEGRO_EVENT ev;
      al_wait_for_event(event_queue, &ev);
      
      if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
         break;
      } // Si se cierra el display, se corta el while.
      
      
      /* Estos else if cambian el valor de  la variable opcion cuando 
       * haga click en las coordenadas de START, CONTINUE o QUIT */
      
      else if((ev.mouse.x > MENUMARGIN && ev.mouse.y > (STARTPOSY)) &&
              (ev.mouse.x < (STARTPOSXEND) && ev.mouse.y < (STARTPOSYEND))){
          if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
              option = START;}
      } 
      
      else if((ev.mouse.x > MENUMARGIN && ev.mouse.y > (CONTPOSY)) &&
              (ev.mouse.x < (CONTPOSXEND) && ev.mouse.y < (CONTPOSYEND))){
          if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
              option = CONTINUE;
          }
       }

      else if((ev.mouse.x > MENUMARGIN && ev.mouse.y > QUITPOSY) &&
          (ev.mouse.x < QUITPOSXEND && ev.mouse.y < QUITPOSYEND))
          if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
              option = QUIT;}
     
   }
 
   
   al_destroy_display(display); //Cierro el display y la cola de eventos.
   al_destroy_event_queue(event_queue); //Pues estaré cerrando el juego.
    
 return option;
}