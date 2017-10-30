#include <stdio.h>
#include <stdint.h>
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
		
		keyTest = kbhit();
		while((userInput = getch()) != ESC)
		{
			switch(userInput)
			{
				case 'b': state = 2; blinkFunction(bitArray, state); state = 1; updateScreen(bitArray, state); break;
				case 'c': setPortValue(PORTA,0x00); updateBitArray(bitArray); updateScreen(bitArray, state); break;
				case 's': setPortValue(PORTA,0xFF); updateBitArray(bitArray); updateScreen(bitArray, state); break;
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
			}
		}

	changemode(BUFFERED_ON);
	return 0;
}
