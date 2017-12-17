#include "general.h"
#ifdef RASP_PI
#include "front_init_pi.h"
#include "disdrv.h"
#include "joydrv.h"
int frontend_init(FRONTEND* front_utils){
   joy_init(); //conservar nombres y lo que reciben para el dual platform
   display_init();
   set_joy_axis(NORMALL);
   //set_joy_display(NORMALL);
   return 1;
}

void frontend_destroy(FRONTEND* front_utils){
    //Nothing to do here
}
#endif
