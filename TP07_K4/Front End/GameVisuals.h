#ifndef GAMEVISUALS_H
#define GAMEVISUALS_H


// Este header contiene las definiciones y prototipos de las funciones que afectarán a la experiencia visual del usuario.


#define GREEN   "\x1b[32m"
#define BLUE    "\x1b[34m"
#define COLOR_RESET   "\x1b[0m"

/* Gracias a estas definiciones, al ejecutar The Game of Life en un sistema operativo Linux, el usuario visualizará
* el texto de mayor relevancia en color azul, y las células en verde.
*/

void printMatrix(char mat[HEIGHT][WIDTH]);
// Muestra al usuario el estado actual del tablero de The Game of Life.

void welcomeMsg(char matrix[HEIGHT][WIDTH]);
// Indica al usuario las instrucciones de The Game of Life.

void againMessage (void);
// Indica al usuario que introdujo un número inválido.

void endMessage(void);
// Indica al usuario que se finalizará The Game of Life.

#endif
