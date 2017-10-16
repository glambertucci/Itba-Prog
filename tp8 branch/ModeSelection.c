#include <stdio.h>
#include <string.h>
#include "Colors.h"
#include "ModeSelection.h"

int  modeAsk(void)
{
	static int modo = 0;
	static int state = 0;
	char outputString[1000], outputChar;
	int outputFunction, tryAgain;

	if(state)
	{
		printf("\nDesea seguir realizando operaciones en el modo seleccionado, cambiar de modo, o salir?\n");
		printf("Si desea continuar con el seleccionado, escriba "GREEN"'c'"COLOR_RESET"; si desea cambiar de modo, escriba "GREEN"'m'"COLOR_RESET"; si desea salir, escriba "GREEN"'e'\n"COLOR_RESET);
		do
		{
			tryAgain = 0;
			scanf("%c", &outputChar);
			switch(outputChar)
			{
				case 'c':	outputFunction = modo; printf("Se continuara en el modo actual.\n\n"); break;
				case 'm':	((modo==1)?(modo=2):(modo=1)); printf("Se cambiara de modo.\n\n"); break;
				case 'e':	outputFunction = 0; break;
				default:	printf("Caracter invalido, probar nuevamente\n"); tryAgain = 1;
			}
		} while (tryAgain);
	}
	else
	{
		state = 1;
		printf("Escriba '"GREEN"m1"COLOR_RESET"' si desea utilizar la calculadora con los operadores clasicos "GREEN"('+', '-','*','/','|','&','^')\n"COLOR_RESET);
		printf("De no ser asi, el programa admite la utilizacion de operadores alternativos "GREEN"('s','r','m','d','o,'a','x')"COLOR_RESET". Para seleccionar dicho modo escriba '"GREEN"m2'\n"COLOR_RESET);
			do
			{
				tryAgain = 0;
				scanf("%s",outputString);
				if(strcmp(outputString, "m1"))
				{
					printf("Se ha elegido el primer modo.\n");
					outputFunction = 1;
					modo = 1;
				}
				else if(strcmp(outputString, "m2"))
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
			} while (tryAgain);
	}
	return outputFunction;
}
