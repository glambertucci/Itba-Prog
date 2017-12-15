#include <time.h>
#include "general.h"

void event_routine(EV_UTILS * ev_utils){
    
    while(!(ev_utils->ev_end)){ //EL while terminará cuando se cierren los eventos.
        static clock_t timezero; //Empieza el timer en un valor.
        clock_t timedelta; //Diferencia de tiempo en ticks del procesador.
        long double msec; //Diferencia de tiempo en segundos (con precisión de milisegundos)
        
        if(!(ev_utils->pause)){   //Si el timer no está pausado, está andando.
            timedelta = (clock() - timezero); //La diferencia de tiempo es el tiempo actual menos el inicial.
            msec = timedelta/(float) (CLOCKS_PER_SEC); //Lo convertimos a segundos.
            
            if( msec >= ev_util->timer_speed){ //Comparamos esta coversión al tiempo en el cual debe tirar eventos.
                ev_utils->timer_event = 1; //Si lo superó, indicamos un evento de timer.
                timezero = clock(); //Finalmente, seteamos el tiempo actual como el nuevo inicial 
            } 
        }    
    }
}
