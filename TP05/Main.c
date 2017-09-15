#define WELCOME_MSG "Welcome to progranagram!\n
                     This program evaluates wether the second word can be formed
                     from the letters of the first word. The program is NOT case-sensitive.\n\n
                     The valid characters are: a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z.\n
                     The limit amount of letters is: 50 letters.\n\n"
#define WM "Welcome to progranagram!\nThis program evaluates wether the second word can be formed from the letters of the first word. The program is NOT case-sensitive.\n\nThe valid characters are: a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z.\nThe limit amount of letters is: 50 letters.\n\n"
//optamos por usar estos define, mas alla de que sea obvio el uso de el mensaje para mayor comidad si se desea cambiar el mensaje o lenguaje
#define FIRST_ASK "Enter the first word: "
#define SECOND_ASK "Enter the second word: "
#define INVALID_INPUT "The word entered is invalid.\n
                       Valid characters are: a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z.\n"
#define INVALID_INPUT "The word entered is invalid.\nValid characters are: a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z.\n"
#define WISH_NEXT "Process finished.\nDo you wish to evaluate another anagram? (y/n)."
#define WISH_YES "The valid characters are: a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z.\n"
#define WISH_NO "Why not? Enter first word:"

 int comparar(char primera_palabra[], char segunda_palabra); //prototipo de funcion "comparar"

 int main (void)
 {
     char firstword[MAX_LENGTH], secondword[MAX_LENGTH], auxword[MAX_LENGTH];
     initArray(firstword);
     initArray(secondword);
     initArray(auxword);
     char * welcome_msg =
     printf("%s", char*p=WELCOME_MSG)

 }

 void initArray(char array[MAX_LENGTH])
 {
     for(i=0; i<MAX_LENGTH); i++)
         array[i] = 0;
 }
