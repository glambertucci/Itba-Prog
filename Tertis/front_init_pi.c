#include "general.h"
#ifdef RASP_PI
#include "front_init_pi.h"
#include "disdrv.h"
#include "joydrv.h"
int frontend_init(FRONTEND* front_utils){
   joy_init(); //conservar nombres y lo que reciben para el dual platform
   display_init();
   set_joy_axis(NORMALL);
	set_display_axis(NORMALL);
   return 1;
}

void frontend_destroy(FRONTEND* front_utils){
    	//Omae Wa Mou Shindeiru
	display_clear();
	//Nani?!
}
#endif
