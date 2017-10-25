#include <unistd.h>
#include <stdint.h>
#include "PortFunctions.h"
#include "PuertoD.h"

#define EXIT_SUCC 0
#define ERR_CODE 66666

uint32_t bitToggle (uint16_t bitID) 		//Devuelve ERR_CODE si hay error, y devuelve un 0 si ta todo bien.
{
	uint32_t returnValue, tempValue;
	
	tempValue = getBitValue(bitID);
	
	if (tempValue == 1 || tempValue == 0)
	{
		setBitValue(bitID, !tempValue);
		returnValue = EXIT_SUCC;
	}
	
	else
		returnValue = ERR_CODE;

	return returnValue;


}

uint32_t maskOn (uint16_t portID, uint16_t mask)
{
	uint32_t returnValue, tempValue;

	tempValue = getPortValue(portID);

	if (tempValue != ERR_CODE)
		returnValue = setPortValue(portID, (tempValue|mask));

	else
		returnValue = ERR_CODE;

	return returnValue;
}

uint32_t maskOff (uint16_t portID, uint16_t mask)
{
	uint32_t returnValue, tempValue;

	tempValue = getPortValue(portID);

	if (tempValue != ERR_CODE)
	{
		returnValue = setPortValue(portID, (tempValue & (~mask)));
	}
	else
		returnValue = ERR_CODE;

	return returnValue;
}

uint32_t maskToggle (uint16_t portID, uint16_t mask)
{
	uint32_t returnValue, tempValue;

	tempValue = getPortValue(portID);

	if (tempValue != ERR_CODE)
		returnValue = setPortValue(portID, (tempValue^mask));
	else
		returnValue = ERR_CODE;

	return returnValue;
}


#include <time.h>
#include <stdlib.h>
#include "nonblock.h"

uint32_t blinkPortOnceWithDelay(uint16_t portID)
{
	uint32_t returnValue, tempValue
	uint32_t x_seconds=0, x_miliseconds=0, time_in_secs=0,safe_print=10,abort=false;

	clock_t x_startTime,x_countTime;

	x_startTime=clock();

	while (!abort)
	{
		x_countTime=clock(); //actualizo timer
		x_miliseconds=x_countTime - x_startTime;
		x_seconds=(x_miliseconds/(CLOCKS_PER_SEC));
		if(!(x_seconds%1))
		{
			if(!(x_seconds==safe_print))
			{
				safe_print=x_seconds
				frontEndBlink("TODOS PUTOS\n");//aca va lo que imprime osea el puerto ahora imprime el tiempo

			}
		}
		nonblock(NB_ENABLE);
		if (kbhit())
		{
			abort=true;
		}
		nonblock(NB_DISABLE);
	}

}