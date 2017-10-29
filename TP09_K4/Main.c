#include <stdio.h>
#include <stdint.h>
#include "PortFunctions.h"
#include "PuertoD.h"
#include "TerminalFront.h"
#include "termlib.h"
#include "generaldefs.h"
#include "BitArray.h"



int main (void)
{
	uint8_t *bitArray = NULL, state = 0, abort = 0, keyTest;
	unsigned char userInput;

	bitArray = bitArrayInit();		//Inicializaciones
	
	updateScreen(bitArray, state);
	state = 1;

	changemode(BUFFERED_OFF);
	
	while(!abort)
	{	
		keyTest = kbhit();
		while(!keyTest)
		{
			userInput = getch();

			switch(userInput)
			{
				case 27: abort = 1; break;
				case 'b': state = 2; blinkFunction(bitArray, state); state = 1; break;
				case 'c': maskOff(PORTA,MASKOFF);
				case 's': maskOn(PORTA,MASKON);
				default:
				{
					userInput -= ASCIINUMDESP;
					if((userInput >= 0)&&(userInput < 8))
					{
						bitToggle(PORTA, userInput);
						updateBitArray(bitArray);
						updateScreen(bitArray, state);
						break;
					}
				}
			}//switch
		}//kbhit while
	}//abort while

	changemode(BUFFERED_ON);
	return 0;
}
