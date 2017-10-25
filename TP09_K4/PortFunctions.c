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

uint32_t blinkPortOnceWithDelay(uint16_t portID)
{
	uint32_t returnValue, tempValue

}