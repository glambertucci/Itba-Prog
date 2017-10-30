#include <stdint.h>
#include <stdio.h>
#include "termlib.h"
#include "TerminalFront.h"
#include "generaldefs.h"
#include "PuertoD.h"

void printPort(uint8_t bit[8])
{
	uint8_t i;

	gotoxy(30,3);
	printf(RED_TEXT"+--------+");
	gotoxy(30,4);
	printf("|"WHITE_TEXT);
	for(i = 0; i<8; i++)
	{
		gotoxy(31+i,4);
		printf(BLUE_TEXT "%d" WHITE_TEXT, *(bit+i));
	}
	gotoxy(39,4);
	printf(RED_TEXT "|");
	gotoxy(30,5);
	printf("+--------+" WHITE_TEXT);
	putchar('\n');
}

void message(uint8_t state)
{

	switch(state)
	{
		case 0:	printf("\t\t16 Bit Port Simulator"); printf(GREEN_TEXT "\n\n\n\n\n\nTo exit press 'ESC', to enter blinking mode press 'b'. Press 's' to turn on every LED and 'c' to turn them off."); printf("To toggle a bit, press (0-7)." WHITE_TEXT);
				break;
		case 1: printf(GREEN_TEXT "\n\n\n\n\n\nTo exit press 'ESC', to enter blinking mode press 'b'. Press 's' to turn on every LED and 'c' to turn them off. "); printf("To toggle a bit, press (0-7)." WHITE_TEXT);
				break;
		case 2: printf(GREEN_TEXT "\n\n\n\n\n\nYou just entered blinking mode. To exit, press 'ESC'. To set or clear a bit, please exit the mode first.\n" WHITE_TEXT);
				break;
	}

}

uint8_t* bitArrayInit (void)
{
	static uint8_t bitArray[8] = {0};

	return (uint8_t*) bitArray;
}

void updateBitArray (uint8_t * array)
{
	uint8_t i;

	for(i = 0; i < 8; i++)
		(*(array+i) = (getBitValue(PORTA, i)));
}

void updateScreen(uint8_t bitArray[8], uint8_t state)
{
	clrscr();
	printPort(bitArray);
	message(state);
}


void blinkFunction(uint8_t * array, uint8_t state)
{
	while(getch() != ESC)
	{
	
		uint8_t tempValue = getPortValue(PORTA);
		
		maskOff(PORTA, MASKOFF);
		updateScreen(array, state);
		
		//ACA IRIA EL DELAY
		
		maskOn(PORTA, MASKON);
		updateScreen(array,state);
	
	}		

}
