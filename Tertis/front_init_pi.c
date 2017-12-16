#include "general.h"
#ifdef RASP_PI
#include "front_init_pi.h"
#include "disdrv.h"
#include "joydrv.h"
void frontend_init(FRONTEND* front_utils, EV_UTILS* al_utils){
    joy_init(); //conservar nombres y lo que reciben para el dual platform
    display_init();
   set_joy_axis(NORMALL);
}

void frontend_destroy(FRONTEND* front_utils){
    //Nothing to do here
}
#endif