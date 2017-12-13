#include "general.h"
#include "al_backend_init.h"
#include <allegro5/allegro5.h>

bool al_backend_init (AL_UTILS* al_utils){
    
    bool abort = false;
    
    if(!(al_init())){
        fprintf(stderr, "Allegro failed to initialize.");
        abort = true;
    }
    
    if(!(al_utils->timer = al_create_timer(INITIAL / 10.0))){
        fprintf(stderr, "Timer failed to load.");
        abort = true;
        al_destroy_timer(al_utils->timer);
    }
    
    if(!(al_utils->queue = al_create_event_queue())){
        fprintf(stderr, "Event queue failed to load.");
        abort = true;
        al_destroy_event_queue(al_utils->queue);
        al_destroy_timer(al_utils->timer);
    }

    al_start_timer(al_utils->timer);
    al_register_event_source(al_utils->queue, al_get_timer_event_source(al_utils->timer));
    
    return !(abort);
}

void al_backend_destroy(AL_UTILS* al_utils){
        al_destroy_event_queue(al_utils->queue);
        al_destroy_timer(al_utils->timer);
}
