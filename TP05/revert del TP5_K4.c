#include <stdio.h>
#include <stdbool.h>

#define MAX_LENGTH 30
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int compareWords (char*, char*);
void Keyboard(char stringarr[MAX_LENGTH]);
int KeyboardVerif(char stringarr[MAX_LENGTH]);
int askConfirmation(char *array, char *invalidpointer);
void askWord(char*, char*, char*);
void resetArray(char array[MAX_LENGTH]);

int main (void)
{
	char firstword[MAX_LENGTH] = {0}, secondword[MAX_LENGTH] = {0};
	bool answer, conf;
	char *welcome_msg = "\n\n\nWelcome to progranagram!\nThis program evaluates whether the second word can be formed from the letters of the first word. The program is NOT case-sensitive.";
	char *first_ask = "Enter the first word: ";
	char *second_ask = "Enter the second word: ";
	char *invalid_input = "The input entered is invalid.\n";
	char *wish_next = "\nDo you wish to evaluate another anagram? (y/n).";
	char *instructions = "The valid characters are: a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z.\nThe limit amount of letters is: 50 letters.\n\n";
	char *wish_no = "Ending program...\n";
	char *valid_answer = "The letters of the first word CAN form the second word!";
	char *invalid_answer = "The letters of the first word CANNOT form the second word.";

	printf(ANSI_COLOR_BLUE"%s\n"ANSI_COLOR_RESET, welcome_msg);
	
	do{
	resetArray(firstword);
	resetArray(secondword);
	printf("%s\n", instructions);
	askWord(firstword, first_ask, invalid_input);
	askWord(secondword, second_ask, invalid_input);
	
	answer=compareWords(firstword, secondword);
	
	if (answer==true)
	    printf(ANSI_COLOR_GREEN"%s\n"ANSI_COLOR_RESET, valid_answer);
	else
		printf(ANSI_COLOR_RED"%s\n"ANSI_COLOR_RESET, invalid_answer);

	printf("%s\n", wish_next);
	conf=askConfirmation(firstword, invalid_input);
	} while (conf == true);

	printf("%s\n", wish_no);

	return 0;          
}

void askWord(char *array, char *askpointer, char *invalidpointer)
/*
  Le pide al usuario una palabra, si es invalida le pide denuevo.
  Input:
    -char *array: arreglo al que ira la palabra (sin terminador).
    -char *askpointer: puntero al string que anuncia el pedido de la palabra.
	-char *invalidpointer: puntero al string que anuncia que la palabra es invalida.
*/
{
	int err;
	do{
	    err=true;
	    printf("%s\n", askpointer);
	    Keyboard(array);
	    if((err=KeyboardVerif(array))==true)
	      printf("%s\n", invalidpointer);
	  } while (err==true);
}

int askConfirmation(char *array, char *invalidpointer)
/*
  Le pide al usuario una confirmacion de si/no
  Input:
    -char *array: arreglo al que ira el input del usuario
    -char *invalidpointer: pointer al string que anuncia que el input es invalido 
*/
{

int var=false, out;
	
	do
	{
		resetArray(array);
		Keyboard(array);
		
		if(array[1] == '\0')
		{
			var = true;
			switch(array[0])
			{
				case 'y':
					out = true;
					break;
				case 'Y':
					out = true;
					break;
				case 'n':
					out = false;
					break;
				case 'N':
					out = false;
					break;
			}
		}

		else
		{
			var = false;
			printf("%s\n", invalidpointer);
		}

	} while(var == false);

return out;
}


int compareWords (char* first_word, char* second_word)
/*
  Compara dos palabras y se fija si se puede formar la segunda palabra a partir de las letras de la primera
  Input:
    -char *first_word: arreglo al que va la primera palabra 
    -char *second_word: idem segund palabra
*/
{

    int array_aux [MAX_LENGTH + 1] = {0};
    int k;
    int i;
    int m;
    int v;
    int exit;
    int* punt_aux;

    punt_aux = array_aux;

    for (k=0; k<MAX_LENGTH + 1; k++)    //inicializo el arreglo auxiliar todo en 0 y con un terminador (2).
        array_aux[k] = 0;

    array_aux [MAX_LENGTH] = 2;

    for(i=0; second_word[i] != '\0'; i++)
    {                       //mientras no se encuentre al terminador, se escribira un 1 en la matriz auxiliar por cada letra
        *(punt_aux++)=1;    //de la segunda palabra
    }

    punt_aux = array_aux;   //restauro valor inicial
    v = 0;

    for(i=0; first_word[i] != '\0'; i++)  //se posiciona en cada letra de la primer palabra
    {
        for(m=0; (second_word[m] != '\0') && (v == 0); m++)   //compara dicha letra con todas las letras
        {                                                              //de la segunda palabra.
            if(second_word[m] == first_word[i])     //Si la letra de la prinmer palabra forma parte de la segunda palabra, escribe un 0 en la
            {       			                    //matriz auxiliar. De esta manera se "llevara un registro" de las letras que coinciden. Si alguna
                if (*punt_aux == 1)   				//letra se encuentra repetida en la primer palabra, cuando "coincida la busqueda" con una letra ya
                    {               			    //analizada de la segunda palabra, se encontrara con que ya hay un 0 en la matriz auxiliar, por lo
                        *punt_aux = 0;  			//que "ignorara" dicha letra y seguira comparando con las restantes.
                        v = 1;
                    }
            }
            punt_aux++;
        }

        punt_aux = array_aux;
        v = 0;
    }

    exit = true;

    for (punt_aux = array_aux; *punt_aux != 2; punt_aux++)      //Una vez terminada la comparacion de las letras, se fija si
    {                                                           //todo el arreglo auxiliar posee 0 (es decir, que coincidieron todas
		                                                        //las letras de la segunda palabra con las de la primera).
        if(*punt_aux == 1)          //Si todo el arreglo auxiliar posee 0, d    evuelve que si se puede formar la palabra.
 		                            //En caso de que haya por lo menos un 1 en la matriz auxiliar, significa que la segunda palabra
            exit = false;           //no se puede formar completamente con los caracteres de la primer palabra, por lo que devuelve
  			                        //que no se puede.
    }
    return exit;
}

int KeyboardVerif(char stringarr[MAX_LENGTH])
/*
  Analiza si un arreglo tiene elementos que son letras
  Input:
    -char *stringarr: el arreglo que verifica
*/
{
	char c;
	int abort = false;
	int counter = 0;

	while ((counter <= MAX_LENGTH) && (abort == false) && (c != 0))  //Loopea mientras falten elementos por analizar y no haya errores
	{
		c = stringarr[counter];	//C es la variable que usaré para analizar la validez de cada elemento del arreglo.
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == ' ')) //Si no es una letra o un espacio, produce un error. Si no, continúa
			counter++;
		else
			abort = true;
	}
	return abort;
}

void Keyboard(char stringarr[])
/*
  Toma el input del usuario y lo guarda en un arreglo sin un terminador
  Input:
    -char *stringarr: el arreglo donde se guarda el input
*/
{
	int counter=0;
	char c;

	while(( (c = getchar() ) != '\n') && (counter <= MAX_LENGTH))
			stringarr[counter++]=c;
}	

void resetArray(char array[MAX_LENGTH])
/*
  resetea un arreglo con todos los elementos iguals a '\0'
  Input:
    -char *array: el arreglo a resetear
*/
{
	int i;

	for(i=0;i<MAX_LENGTH;i++)
		array[i]='\0';
}