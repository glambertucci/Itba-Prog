/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <allegro5/system.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#include "general.h"
#include "al_custom_init.h"

void al_custom_init (AL_UTILS* al_utils){
    
    int abort = 0;
    
    if(!(al_init())){
        fprintf(stderr, "Allegro failed to initialize.");
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
    
    if(!(al_install_mouse())){
        fprintf(stderr, "Mouse failed to initialize.");
        abort = 1;
    }
    
    if(!(al_utils->timer = al_create_timer(INITIAL))){
        fprintf(stderr, "Timer failed to load.");
        abort = 1;
        al_destroy_timer(al_utils->timer);
    }
    
    if(!(al_utils->queue = al_create_event_queue())){
        fprintf(stderr, "Event queue failed to load.");
        abort = 1;
        al_destroy_event_queue(al_utils->queue);
        al_destroy_timer(al_utils->timer);
    }
    
    if(!(al_utils->display = al_create_display(SCREEN_W, SCREEN_H))){
        fprintf(stderr, "Display failed to load.");
        abort = 1;
        al_destroy_display(al_utils->display);
        al_destroy_event_queue(al_utils->queue);
        al_destroy_timer(al_utils->timer);
    }

    al_start_timer(al_utils->timer);
    al_register_event_source(al_utils->queue, al_get_display_event_source(al_utils.display));
    al_register_event_source(al_utils->queue, al_get_timer_event_source(al_utils.timer));
    al_register_event_source(al_utils->queue, al_get_keyboard_event_source());
    al_register_event_source(al_utils->queue, al_get_mouse_event_source());
}

