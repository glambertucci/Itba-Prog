#include "general.h"
#include "front_init_allegro.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

bool frontend_init(FRONTEND* front_utils, AL_UTILS* al_utils){

    int abort = 0;

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

    if(!(front_utils->display = al_create_display(SCREEN_W, SCREEN_H))){
        fprintf(stderr, "Display failed to load.");
        abort = 1;
        al_destroy_display(front_utils->display);
    }

    front_utils->image[0] = al_load_bitmap("menus.jpg");
    front_utils->image[1] = al_load_bitmap("menuc.jpg");
    front_utils->image[2] = al_load_bitmap("menuq.jpg");
    front_utils->image[3] = al_load_bitmap("lose.jpg");
    
    al_register_event_source(al_utils->queue, al_get_display_event_source(front_utils->display));
    al_register_event_source(al_utils->queue, al_get_keyboard_event_source());
    al_register_event_source(al_utils->queue, al_get_mouse_event_source());
    
    return !(abort);
}

void frontend_destroy(FRONTEND* front_utils){
	al_destroy_display(front_utils->display);
}