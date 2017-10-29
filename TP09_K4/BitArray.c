#include "BitArray.h"
#include "PuertoD.h"

uint8_t* bitArrayInit (void)
{
	static uint8_t bitArray[8] = {0};

	return (uint8_t*) bitArray;
}

void updateBitArray (uint8_t * array)
{
	uint8_t i;

	for(i = 0; i < 8; i++)
		(*(array+i) = (bitGet(PORTA, i)));
}

