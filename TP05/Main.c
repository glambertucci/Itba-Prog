#include <stdbool.h>
#include <ctype.h>
#define WELCOME_MSG "Welcome to progranagram!\nThis program evaluates wether the second word can be formed from the letters of the first word. The program is NOT case-sensitive.\n\nThe valid characters are: a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z.\nThe limit amount of letters is: 50 letters.\n\n"
//optamos por usar estos define, mas alla de que sea obvio el uso de el mensaje para mayor comodidad si se desea cambiar el mensaje o lenguaje
#define FIRST_ASK "Enter the first word: "
#define SECOND_ASK "Enter the second word: "
#define INVALID_INPUT "The input entered is invalid.\n"
#define WISH_NEXT "Process finished.\nDo you wish to evaluate another anagram? (y/n)."
#define WISH_YES "The valid characters are: a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z.\n"
#define WISH_NO "Okay, bye :("
#define VALID_ANSWER "The letters of the first word CAN form the second word!"
#define INVALID_ANSWER "The letters of the first word CANNOT form the second word."

 int comparar(char primera_palabra[], char segunda_palabra); //prototipo de funcion "comparar"

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
         if (answer==TRUE)
              printf("%s\n", valid_answer);
         else
              printf("%s\n", invalid_answer);
         printf("%s\n", wish_next);
         conf=askConfirmation(firstword, invalid_input);
       } while (conf== true);
      
      printf("%s\n", wish_no);
      
      return 0;          
 }

 void initArray(char array[MAX_LENGTH])
 {
     for(i=0; i<MAX_LENGTH); i++)
         array[i] = 0;
 }

void askWord(char *array, char *askpointer, char *invalidpointer)
{
  int err;
  do{
        err=TRUE;
        printf("%s\n", askpointer);
        keyboard(array);
        if((err=kbverif(array))==TRUE)
          printf("&s\n", invalidpointer);
      } while (err==TRUE);
}
/*
  explica
  Input:
    -char * array: 
    -

*/
void askConfirmation(char *array, char *invalidpointer)
{
  int var=FALSE, out;
  do{
     initArray(array);
     keyboard(array);
    if(((array[0] == 'y') || (array[0] == 'Y')) && (array[1] == '\0')) //CAMBIAR LA VERIFICACION A UN SWITCH
      out = TRUE;
      var = TRUE;
    elseif(((array[0] == 'n') || (array [0] == 'N')) && (array[1] == 0))
      out = FALSE;
      var = TRUE;
    else
      var = FALSE;
      printf("%s\n", invalidpointer);
    }while(var == FALSE);
  return out;
}
    
