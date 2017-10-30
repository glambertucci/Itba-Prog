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
		printf(BLUE_TEXT "%d" WHITE_TEXT, !(!(*(bit+i)))); //Doble negación para que imprima 1 o 0 según corresponda
	}
	gotoxy(39,4);
	printf(RED_TEXT "|");
	gotoxy(30,5);
	printf("+--------+" WHITE_TEXT);
	putchar('\n');
}

void message(uint8_t state)
{

	switch(state) //Elijo los mensajes según el estado actual del programa.
	{
		case 0:	printf(WHITE_TEXT"\t\t\t16 Bit Port Simulator"); printf(GREEN_TEXT "\n\n\n\n\n\nTo exit press 'ESC', to enter blinking mode press 'b'.\nPress 's' to turn on every bit and 'c' to turn them off. "); printf("To toggle a bit, press (0-7)." WHITE_TEXT);
				break;
		case 1: printf(GREEN_TEXT "\n\n\n\n\n\nTo exit press 'ESC' or any arrow , to enter blinking mode press 'b'.\nPress 's' to turn on every bit and 'c' to turn them off. "); printf("To toggle a bit, press (0-7)." WHITE_TEXT);
				break;
		case 2: printf(GREEN_TEXT "\n\n\n\n\n\nYou just entered blinking mode. To exit, press any key. To set or clear a bit, please exit the mode first.\n" WHITE_TEXT);
				break;
	}

}


void updateScreen(uint8_t bitArray[8], uint8_t state)
{
	clrscr(); //Se limpia la pantalla
	message(state); //Se imprime el mensaje correspondiente según el estado actual del programa
	printPort(bitArray); //Se imprime el valor actual del puerto
}


void blinkFunction(uint8_t * array, uint8_t state)
{
			uint8_t ceroArray[8] = {0};
            
            // VARIABLES UTILES
            uint32_t safe_print=10;  //Asegura que no se imprima muchas veces el mensaje del tiempo    
            uint32_t blinkk=0;  //Se usa para variar entre arreglos        
            uint32_t abort=FALSE;
            //COSAS DE TIMER
            clock_t x_startTime,x_countTime;     
            x_startTime=clock();  // comienza reloj
            uint32_t  x_seconds=0;   
            uint32_t x_milliseconds=0;
           
            while (!abort) 
                {
                        x_countTime = clock();    //actualizo el timer
                        x_milliseconds=x_countTime-x_startTime;
                        x_seconds=(x_milliseconds/(CLOCKS_PER_SEC));

                      

                        if (!((x_seconds*2)%1)) //es multiplicado por dos para que titile dos veces por segundo
                        {
                            if (!(x_seconds==safe_print))	
                            {
                            	safe_print=x_seconds;
                            	if (blinkk==FALSE)
                            	{
                            		updateScreen(ceroArray,state);
                            		blinkk=TRUE;
                            	}
                            	else
                          		{
                            		updateScreen(array,state);
                    	       		blinkk=FALSE;
                   	    		}
                            }
                        }
                        if (kbhit())
                        {
                            abort=TRUE;
                        }
                        
                }
}