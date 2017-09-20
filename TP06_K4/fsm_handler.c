#define INICIAL 0
#define FULL_KBZA 1
#define APROACHING 2 //aproaching ()
#define L_TURN 3//izqierda
#define R_TURN 4
#define MIN_DIST
#define MAX_DIST
izquierdo=adelante
derecha=derecha
enum {MOTOR_IZQ, MOTOR_DER, CANT_MOTORES};
int fsm_handler(int state)
{
    updateDistance();
    distance_in_front = getDistanceMm(DIST_IZQ);
    distance_right = getDistanceMm(DIST_DER);
    if (state==INICIAL)
        state=FULL_KBZA; // fullcabeza(int -100/100 )
    else if (state == FULL_KBZA)
    {
        if (distance_in_front > MIN_DIST)
        {
            if (distance_right > MIN_DIST)
            {
                state=APPROACHING
            }
            else state=FULL_KBZA

        }
         else
         {
            if (!(distance_right>MIN_DIST))
                state=L_TURN
         }
    }
    else if (state== APPROACHING)
    {


    }

}
