#include <time.h>
#include "general.h"


/* void event_routine(EV_UTILS * ev_utils){
    
    while(!(ev_utils->ev_end)){
        static clock_t timezero;
        clock_t timedelta;
        long double msec;
        
        if(!(ev_utils->pause)){
            
            
            timedelta = (clock() - timezero);
            msec = timedelta/(CLOCKS_PER_SEC/1000);
            if( timedelta >= ev_util->timer_speed){
                ev_utils->timer_event = 1;
                timezero = clock();
            } 
        }    
    }
}*/