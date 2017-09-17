#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define WELCOME_MSG "Welcome to progranagram!\nThis program evaluates wether the second word can be formed from the letters of the first word. The program is NOT case-sensitive.\n\nThe valid characters are: a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z.\nThe limit amount of letters is: 50 letters.\n\n"
//optamos por usar estos define, mas alla de que sea obvio el uso de el mensaje para mayor comodidad si se desea cambiar el mensaje o lenguaje
#define FIRST_ASK "Enter the first word: "
#define SECOND_ASK "Enter the second word: "
#define INVALID_INPUT "The input entered is invalid.\n"
#define WISH_NEXT "Process finished.\nDo you wish to evaluate another anagram? (y/n)."
#define WISH_YES "The valid characters are: a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z.\n"
#define WISH_NO "Ending program..."
#define VALID_ANSWER "The letters of the first word CAN form the second word!"
#define INVALID_ANSWER "The letters of the first word CANNOT form the second word."
#define MAX_LENGTH 30
#define false 0


int compareWords (char*, char*);    //prototipo
void keyboard(char stringarr[MAX_LENGTH]);
int kbverif(char stringarr[MAX_LENGTH]);
int askConfirmation(char *array, char *invalidpointer);

 int main (void)
 {
      char firstword[MAX_LENGTH] = {0}, secondword[MAX_LENGTH], auxword[MAX_LENGTH];
      bool err, answer, conf;
     
      char *welcome_msg = WELCOME_MSG, *first_ask = FIRST_ASK, *second_ask = SECOND_ASK, *invalid_input = INVALID_INPUT;
      char *wish_next = WISH_NEXT, *wish_yes = WISH_YES, *wish_no = WISH_NO, *valid_answer = VALID_ANSWER, *invalid_answer = INVALID_ANSWER;
      //Por mas que sean obvias las asignaciones, las cuales las utilizamos para los printf, decidimos hacerlo asi para no hacer mas pesado al programa,
      //que en este caso no es necesario pero para adquirir la buena practica.
      
      do{
        initArray(firstword);
        initArray(secondword);
        printf("%s\n", welcome_msg);
        askWord(firstword, first_ask, invalid_input);
        askWord(secondword, second_ask, invalid_input);
        answer=compareWords(firstword, secondword);
        if (answer==true)
        {
            printf("%s\n", valid_answer);
        }
        else
        {
        printf("%s\n", invalid_answer);
        }
        printf("%s\n", wish_next);
        conf=askConfirmation(firstword, invalid_input);
        } while (conf == true);
      
      printf("%s\n", wish_no);
      
      return 0;          
 }

 void initArray(char array[MAX_LENGTH])
 {

     for(int i=0; (i<MAX_LENGTH); i++)
         array[i] = 0;
 }

void askWord(char *array, char *askpointer, char *invalidpointer)
{
  int err;
  do{
        err=true;
        printf("%s\n", askpointer);
        keyboard(array);
        if((err=kbverif(array))==true)
          printf("&s\n", invalidpointer);
      } while (err==true);
}
/*
  explica
  Input:
    -char * array: 
    -

*/
int askConfirmation(char *array, char *invalidpointer)
{
  int var=false, out;
  do{
     initArray(array);
     keyboard(array);
    if(((array[0] == 'y') || (array[0] == 'Y')) && (array[1] == '\0')) //CAMBIAR LA VERIFICACION A UN SWITCH
    {
      out = true;
      var = true;
    }
    else if(((array[0] == 'n') || (array [0] == 'N')) && (array[1] == '\0'))
    {
      out = false;
      var = true;
    }
    else
    {
      var = false;
      printf("%s\n", invalidpointer);
    }
    }while(var == false);

  return out;
}

int compareWords (char* first_word, char* second_word)
{
    int array_aux [51];
    int k;
    int i;
    int m;
    int v;
    int exit;

    int* punt_aux;
    punt_aux = array_aux;

    for (k=0; k<51; k++)    //inicializo el arreglo auxiliar todo en 0 y con un terminador (2).
    {
        array_aux[k] = 0;
    }
    array_aux [50] = 2;


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
            if(second_word[m] == first_word[i])      //Si la letra de la prinmer palabra forma parte de la segunda palabra, escribe un 0 en la
            {                           //matriz auxiliar. De esta manera se "llevara un registro" de las letras que coinciden. Si alguna
                if (*punt_aux == 1)     //letra se encuentra repetida en la primer palabra, cuando "coincida la busqueda" con una letra ya
                    {                   //analizada de la segunda palabra, se encontrara con que ya hay un 0 en la matriz auxiliar, por lo
                        *punt_aux = 0;  //que "ignorara" dicha letra y seguira comparando con las restantes.
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
        {                           //En caso de que haya por lo menos un 1 en la matriz auxiliar, significa que la segunda palabra
            exit = false;           //no se puede formar completamente con los caracteres de la primer palabra, por lo que devuelve
        }                           //que no se puede.
    }
    return exit;

}

int kbverif(char stringarr[MAX_LENGTH])
{
	char c;
	int abort = false;
	int counter = 0;

	
	while ((counter <= MAX_LENGTH) && (abort == false) && (c != 0))  //Loopea mientras falten elementos por analizar y no haya errores
	{
		c = stringarr[counter];	//C es la variable que usaré para analizar la validez de cada elemento del arreglo.
		
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == ' ')) //Si no es una letra o un espacio, produce un error. Si no, continúa.
		{
			counter++;
		}
		else
		{
			abort = true;
		}
	}
	return abort;
}


void keyboard(char stringarr[])
{
	int counter=0;
	char c;
	
	while(( (c = getchar() ) != '\n') && (counter <= MAX_LENGTH))
	{
			stringarr[counter++]=c;
	}
	return 0;
}	
