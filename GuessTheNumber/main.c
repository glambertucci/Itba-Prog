#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>

int main(void)
{
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    
    if(!al_init()) {  //Inicializamos allegro
        fprintf(stderr, "Failed to initialize allegro.");
        return (EXIT_FAILURE);
    }
    
    display = al_create_display(640, 480); //Creamos el display
    if(!display) {
        fprintf(stderr, "Failed to create a display.");
        return (EXIT_FAILURE);
    }
    
    
    /////////////By RUbidio, asi que es probable que tenga errores, pero para que vean la idea///////////
    
    //Bueno, manteniendo la idea de ir mostrandole al usuario la cuenta regresiva, me parece que la manera mas
    //"sencilla" es teniendo una imagen por numero (para una cuenta regresiva de 15 segundos habria que 
    //tener 15.jpg, 14.jpg, ..., 9.jpg, 8.jpg, etc...).
    //Para eso hay que crear un timer y setearlo con al_set_timmer_count que arranque desde -15. Yo haria un
    //if gigante que vaya tomando el valor del timer y vea en que segundo se esta comparandolo con dos int
    //(por ejemplo, si esta en el segundo 12 daria TRUE el IF correspondiente a 
    //if((al_get_timer_count() < 13) && (al_get_timer_count() > 11).
    //Dentro del IF, solamente tendriamos que mostrar la imagen correspondiente al 12. Cuando entre a otro IF,
    //(en este caso, a el del 11), simplemente se imprimiria la imagen del 11 sobre la del 12, y asi
    //con todos los siguientes.
    //
    
    timer = al_create_timer(1.0 / FPS); //crea el timer pero NO empieza a correr
	if(!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}
 
	event_queue = al_create_event_queue();
	if(!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_timer(timer);
		return -1;
    
    
    
    
    return (EXIT_SUCCESS);
}

