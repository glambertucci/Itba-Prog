#include "general.h"
#include "al_events.h"
#include <allegro5/allegro5.h>

bool events_init (EV_UTILS* al_utils)
{
    
    bool abort = false;
    
    if(!(al_init()))
    {
        fprintf(stderr, "Allegro failed to initialize.");
        abort = true;
    }
    
    if(!(al_utils->timer = al_create_timer(INITIAL / 10.0))){
        fprintf(stderr, "Timer failed to load.");
        abort = true;
        al_destroy_timer(al_utils->timer);
    }
    
    if(!(al_utils->rythm = al_create_timer(RYTHM))){
        fprintf(stderr, "Timer failed to load.");
        abort = true;
        al_destroy_timer(al_utils->rythm);
        al_destroy_timer(al_utils->timer);
    }
        
    
    if(!(al_utils->queue = al_create_event_queue()))
    {
        fprintf(stderr, "Event queue failed to load.");
        abort = true;
        al_destroy_event_queue(al_utils->queue);
        al_destroy_timer(al_utils->timer);
        al_destroy_timer(al_utils->rythm);
    }
    
    if(!(al_utils->rythmq = al_create_event_queue()))
    {
        fprintf(stderr, "Event queue failed to load.");
        abort = true;
        al_destroy_event_queue(al_utils->rythmq);
        al_destroy_event_queue(al_utils->queue);
        al_destroy_timer(al_utils->timer);
        al_destroy_timer(al_utils->rythm);
    }
    
    al_start_timer(al_utils->timer);
    al_register_event_source(al_utils->queue, al_get_timer_event_source(al_utils->timer));
    
    al_start_timer(al_utils->rythm);
    al_register_event_source(al_utils->rythmq, al_get_timer_event_source(al_utils->rythm));
    
    
    return !(abort);
}

void events_destroy(EV_UTILS* al_utils)
{
    al_destroy_event_queue(al_utils->queue);
    al_destroy_event_queue(al_utils->rythmq);
    al_destroy_timer(al_utils->rythm);
    al_destroy_timer(al_utils->timer);
}


void change_velocity(EV_UTILS * ev_utils) 
{

    if((al_get_timer_speed(ev_utils->timer)) != (ev_utils->timer_speed))
    {
        al_set_timer_speed(ev_utils->timer, ev_utils->timer_speed);
    }

}
