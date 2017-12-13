#include <pthread.h>

#include "general.h"
#include "front_init_pi.h"
#include "joydrv.h"

void frontend_init(FRONTEND* front_utils, AL_UTILS* al_utils) {
    display_init();
    joy_init();
    display_clear();
    draw_title();
    wait_for_joypress(front_utils);
    pthread_create(&(front_utils->timer), NULL, front_utils->event_routine(), NULL);
}

void frontend_destroy(FRONTEND* front_utils) {
    pthread_join(front_utils->timer, NULL);
    display_clear();
}