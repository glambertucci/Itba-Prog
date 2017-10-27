#include <stdint.h>
#include <stdio.h>
#include "termlib.h"
#include "TerminalFront.h"

int main(void)
{
	uint8_t bit[8] = {1,0,1,0,0,1,0,1};
	uint8_t bit2[8] = {0,0,0,1,0,1,0,0};
	uint8_t state = 0;

	clrscr();
	message(state);
	printPort(bit);

				getchar();

	clrscr();
	state = 1;
	message(state);
	printPort(bit2);

	getchar();

	return 0;
}

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
		case 0:	printf("\t\t16 Bit Port Simulator")
				printf(GREEN_TEXT "\n\n\n\n\n\nTo exit press 'ESC', to enter blinking mode press 'b'.");
				printf("To toggle a bit, press (0-7)." WHITE_TEXT);
				break;
		case 1: printf(GREEN_TEXT "\n\n\n\n\n\nTo exit press 'ESC', to enter blinking mode press 'b'.");
				printf("To toggle a bit, press (0-7)." WHITE_TEXT);
				break;
		case 2: printf(GREEN_TEXT "\n\n\n\n\n\nYou just entered blinking mode. To exit, press 'ESC'. To set or clear a bit, please exit the mode first.\n" WHITE_TEXT);
				break;
	}

}

uint8_t* bitArrayInit (void)
{
	static uint8_t[8] = {0};

	return (uint8_t*) uint8_t;
}

void updateBitArray (*uint8_t array)
{
	uint8_t i;

	for(i = 0; i < 8; i++)
		(*(array+i) = (getBitValue(PORTA, i)));
}