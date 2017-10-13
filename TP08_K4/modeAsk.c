#include <stdio.h>
#include <string.h>
#define GREEN   "\x1b[32m"
#define BLUE    "\x1b[34m"
#define COLOR_RESET   "\x1b[0m"

int  modeAsk(void)
{
	static int modo = 0;
	static int state = 0;
	char outputString[1000], outputChar;
	int outputFunction, tryAgain;

	if(state)
	{
		printf("Desea seguir realizando operaciones en el modo seleccionado, cambiar de modo, o salir?\n");
		printf("Si desea continuar con el seleccionado, escriba "GREEN"'c'"COLOR_RESET"; si desea cambiar de modo, escriba "GREEN"'m'"COLOR_RESET"; si desea salir, escriba "GREEN"'e'\n"COLOR_RESET);
		do
		{
			tryAgain = 0;
			scanf("%c", &outputChar);
			switch(outputChar)
			{
				case 'c':	outputFunction = modo; break;
				case 'm':	((modo==1)?(modo=2):(modo=1)); break;
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
					outputFunction = 1;
					modo = 1;
				}
				else if(strcmp(outputString, "m2"))
				{
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
