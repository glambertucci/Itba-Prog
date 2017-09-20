#include <stdio.h>
#include <stdlib.h>


enum {MOTOR_IZQ, MOTOR_DER, CANT_MOTORES};

#define MOT_DUTY_MAX_POS  100
#define MOT_DUTY_OFF      0
#define MOT_DUTY_MAX_NEG  (-MOT_DUTY_MAX_POS)

void initMotor(void);
void writeMotorDuty(char motId, int duty);


enum {DIST_IZQ, DIST_DER, CANT_DISTS};

void initDistance(void);
void updateDistance(void);
int getDistanceMm(char sensorId);


int runRobotFsm(int state);

#define ROBOT_RADIUS 80

int main(void)
{
    int state = 0; // estado inicial

    printf("** Comienza programa de prueba de FSM para robot **\n\n");
    while (state >= 0)
    {
        state = runRobotFsm(state); // se llama a esta función cada 100ms
        while(getchar()) {} // simulo delay
    }

    return 0;
}


/******************************************************************************
                            FUNCIONES STUBS
 ******************************************************************************/

void initMotor(void)
{
    printf("Motor... CONFIGURADO!\n");
}

void writeMotorDuty(char motId, int duty)
{
    switch (motId) // verifico motor a escribir
    {
    case MOTOR_IZQ:
        printf("Motor IZQUIERDO: %d\n", duty);
        break;

    case MOTOR_DER:
        printf("Motor DERECHO: %d\n", duty);
        break;

    default:
        printf("Motor INVALIDO\n");
        break;
    }
}

void initDistance(void)
{
    printf("Sensor de distancia... CONFIGURADO!\n");
}

void updateDistance(void)
{
    printf("Sensor de distancia... ACTUALIZADO!\n");
}

int getDistanceMm(char sensorId)
{
    int distancia = 58;
    switch (sensorId) // verifico sensor a leer
    {
    case DIST_IZQ:
        printf("Sensor IZQUIERDO: %d\n", distancia);
        break;

    case DIST_DER:
        printf("Sensor DERECHO: %d\n", distancia);
        break;

    default:
        printf("Sensor INVALIDO\n");
        break;
    }
    return distancia;
}


/******************************************************************************
                     PARTE A COMPLETAR POR LOS GRUPOS
 ******************************************************************************/

int runRobotFsm(int state)
{
    return state;
}

void Aproaching(void)
{

	int frontdistance;
	int distance2aproach;

	updateDistance();
	frontdistance = getDistanceMm(DIST_IZQ);
	distance2aproach = (frontdistance/2) + ROBOT_RADIUS;

	do{

		fullcabeza(70);
		updateDistance();

	} while((frontdistance=getDistanceMm(DIST_IZQ) > (distance2aproach + 10));

		fullcabeza(0);
}
