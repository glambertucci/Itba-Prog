#include <stdio.h>
#include <stdint.h>
#include "PuertoD.h"
#include "TerminalFront.h"
#include "termlib.h"
#include "generaldefs.h"
#include "BitArray.h"

#define ASCIINUMDESP 48 //Corrección entre el ASCII de los números y su valor correspondiente.

int main (void)
{
	uint8_t *bitArray = NULL, state = 0;
	unsigned char userInput;		

	bitArray = bitArrayInit();		//Inicializaciones
	
	updateScreen(bitArray, state);		//Se muestra el mensaje inicial
	state = 1;

	changemode(BUFFERED_OFF);
		
		while((userInput = getch()) != ESC) //Se loopea hasta que el usuario ponga ESC
		{
			switch(userInput)
			{
				case 'b': state = 2; updateScreen(bitArray, state); blinkFunction(bitArray, state); state = 1; updateScreen(bitArray, state); break; //Si toca B, se actualiza el mensaje en pantalla y blinkea hasta que presione ESC.
				case 'c': maskOff(PORTA,MASKON); updateBitArray(bitArray); updateScreen(bitArray, state); break; //Seteo todo en 0
				case 's': maskOn(PORTA,MASKON); updateBitArray(bitArray); updateScreen(bitArray, state); break; //Seteo todo en 1
				default:
				{
					userInput -= ASCIINUMDESP; //Como el input es un numero, lo reduzco en 48 pues el 48 en ASCII es el 0.
					if((userInput >= 0)&&(userInput < 8))
					{
						bitToggle(PORTA, userInput); //Toggleo el bit deseado
						updateBitArray(bitArray); //Lo actualizo en el puerto
						updateScreen(bitArray, state); //Actualizo la pantalla
						break;
					}
				}
			}
		}
	clrscr();
	changemode(BUFFERED_ON);
	return 0;
}
