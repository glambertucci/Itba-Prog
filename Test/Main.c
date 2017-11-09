#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/display.h>
#include <allegro5/timer.h>

#define FPS 60.0
#define DISPLAY_WIDTH 640
#define DISPLAY_HEIGHT 480
#define SQUARE_SIZE 32

int main(void) {

    ALLEGRO_DISPLAY *Display = NULL;
    ALLEGRO_BITMAP *Square = NULL;
    ALLEGRO_TIMER *Timer = NULL;
    ALLEGRO_EVENT_QUEUE *Queue = NULL;
    
    float Square_x = DISPLAY_WIDTH / 2.0 - SQUARE_SIZE / 2.0;
    float Square_y = DISPLAY_HEIGHT / 2.0 - SQUARE_SIZE / 2.0;
    
    bool exit;
    
    if(!al_init()) {
        fprintf(stderr, "Failed to initialize Allegro!");
        return -1;
    }
    
    if(!(al_install_keyboard())) {
        fprintf(stderr, "Failed to install keyboard");
        return -1;
    }    
    
    if(!(Timer = al_create_timer(5))) {
        fprintf(stderr, "Failed to create timer");
        return -1;
    }
    
    if(!(Queue = al_create_event_queue())) {
        fprintf(stderr, "Failed to create event queue");
        al_destroy_timer(Timer);
        return -1;
    }
    
    if(!(Square = al_create_bitmap(SQUARE_SIZE, SQUARE_SIZE))) {
        fprintf(stderr, "Failed to create bitmap");
        al_destroy_timer(Timer);
        al_destroy_event_queue(Queue);
        return -1;
    }
    
    if(!(al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT))) {
        fprintf(stderr, "Failed to create display");
        al_destroy_timer(Timer);
        al_destroy_event_queue(Queue);
        al_destroy_bitmap(Square);
        return -1;
    }
    
    al_set_target_bitmap(Square);
    al_clear_to_color(al_map_rgb(0,0,255));
    al_set_target_bitmap(al_get_backbuffer(Display));
    
    al_register_event_source(Queue, al_get_display_event_source(Display));
    al_register_event_source(Queue, al_get_timer_event_source(Timer));
    al_register_event_source(Queue, al_get_keyboard_event_source());
    
    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();
    al_start_timer(Timer);
    
    
    while(!exit) {
        
        ALLEGRO_EVENT Event;
        if(al_get_next_event(Queue, &Event)) {
            if(Event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                exit = true;
            if(Event.type == ALLEGRO_EVENT_TIMER)
                exit = true;
                
        }
        
    }
    
    al_destroy_timer(Timer);
    al_destroy_event_queue(Queue);
    al_destroy_bitmap(Square);
    al_destroy_display(Display);
    
    return (EXIT_SUCCESS);
}

