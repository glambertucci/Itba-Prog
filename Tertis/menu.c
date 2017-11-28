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


int menu (ALLEGRO_DISPLAY * display){

    
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   ALLEGRO_BITMAP * image; //PUntero a la imagen del menu
   int option = -1; //Esta variable va al return, indicando qué se presionó.
   
   al_init_image_addon(); //Permito poner una imagen en el display.
   
   if(!al_install_mouse()) {
      fprintf(stderr, "failed to initialize the mouse!\n");
      return -1;
   } //Instalo el mouse, indicando con un printf si hubo error.
   
   al_set_target_bitmap(al_get_backbuffer(display));
 
   event_queue = al_create_event_queue(); //Creo cola de eventos.
   
   if(!event_queue) {
      fprintf(stderr, "failed to create event_queue!\n");
      al_destroy_display(display);
      return -1;
   } //Corroboro que se haya creado exitosamente.
 
   al_register_event_source(event_queue, al_get_display_event_source(display));

   al_register_event_source(event_queue, al_get_mouse_event_source());
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
    
 return opcion;
}