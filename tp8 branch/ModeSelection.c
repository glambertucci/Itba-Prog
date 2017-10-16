#include <stdio.h>
#include <string.h>
#include "Colors.h"
#include "ModeSelection.h"
#include "KeyboardUtilities.h"

int  modeAsk(void)
{
	static int modo = 0;
	static int state = 0;
	char outputString[1000], outputChar;
	int outputFunction, tryAgain;

	if(state) //Se fija si debe preguntar por primera vez o no
	{
		printf("\nDesea seguir realizando operaciones en el modo seleccionado, cambiar de modo, o salir?\n");
		printf("Si desea continuar con el seleccionado, escriba "GREEN"'c'"COLOR_RESET"; si desea cambiar de modo, escriba "GREEN"'m'"COLOR_RESET"; si desea salir, escriba "GREEN"'e'\n"COLOR_RESET);
		do
		{
			tryAgain = 0;
			scanf("%c", &outputChar);
			cleanBuffer();
			switch(outputChar)
			{
				case 'c':	outputFunction = modo;
							printf("Se continuara en el modo actual.\n\n");
							break;
		
				case 'm':	if(modo == 1)
							{
								modo = 2;
								outputFunction = 2;
							}
							else
							{
								modo = 1;
								outputFunction = 1;
							}
							printf("Se cambiara de modo.\n\n");
							break;
		
				case 'e':	outputFunction = 0;
							break;
		
				default:	printf("Caracter invalido, probar nuevamente\n");
							tryAgain = 1;
			}
		} while (tryAgain);		//Solo sale cuando la entrada es valida.
	}
	else
	{
		state = 1;
		printf("Escriba '"GREEN"m1"COLOR_RESET"' si desea utilizar la calculadora con los operadores clasicos "GREEN"('+', '-','*','/','|','&','^')\n"COLOR_RESET);
		printf("De no ser asi, el programa admite la utilizacion de operadores alternativos "GREEN"('s','r','m','d','o,'a','x')"COLOR_RESET". Para seleccionar dicho modo escriba '"GREEN"m2'\n"COLOR_RESET);
			do
			{
				tryAgain = 0;
				scanf("%s", outputString);
				cleanBuffer();
				if(!(strcmp(outputString, "m1")))		//Funcion que ve si el primer string contiene el segundo string.
				{
					printf("Se ha elegido el primer modo.\n");
					outputFunction = 1;
					modo = 1;
				}
				else if(!(strcmp(outputString, "m2")))
				{
					printf("Se ha elegido el segundo modo.\n");
					outputFunction = 2;
					modo = 2;
				}
				else
				{
					printf("Caracteres invalidos, probar nuevamente\n");
					tryAgain = 1;
				}
			} while (tryAgain);			//Solo sale cuando la entrada sea valida
	}
	return outputFunction;
}
