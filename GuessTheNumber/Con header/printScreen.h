#ifndef PRINTSCREEN_H
#define PRINTSCREEN_H

void printScreen (int state, int time);
//Esta funcion se encarga de invocar individualmente a las funciones para imprimir en pantalla los mensajes al usuario y
//el tiempo restante.


void printTimer (int time);
//Esta función imprime en pantalla el tiempo restante que le queda al usuario para hallar el número correcto


void printText (int state);
//Esta función es la encargada de imprimir en pantalla los mensajes requeridos por el usuario para la comprensión del programa
//(Instrucciones, "castigos", si ganó o perdió)


#endif /* PRINTSCREEN_H */