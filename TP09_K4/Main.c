#include <stdio.h>
#include <stdint.h>
#include "PortFunctions.h"
#include "PuertoD.h"
#include "TerminalFront.h"
#include "termlib.h"
#include "generaldefs.h"



int main (void)
{
	uint8_t *bitArray = NULL, state = 0, abort = 0, ketTest;
	unsigned char userInput;

	bitArray = bitArrayInit();		//Inicializaciones
	
	updateScreen(bitArray, state);
	state = 1;

	changemode(BUFFERING_OFF);
	
	while(!abort)
	{	
		keyTest = kbhit();
		while(!keyTest)
		{
			userInput = getch();

			switch(userInput)
			{
				case 'ESC': abort = 1; break;
				case 'b': state = 2; blinkFunction(bitArray); state = 1; break;
				default:
				{
					if((userInput >= 0)&&(userInput < 8))
					{
						toggleBit(PORTA, userInput);
						updateBitArray(bitArray);
						updateScreen(bitArray, state);
					}
				}
			}//switch
		}//kbhit while
	}//abort while

	changemode(BUFFERING_ON);
	return 0;
}
