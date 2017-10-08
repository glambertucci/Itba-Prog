#ifndef GAMEVISUALS_H
#define GAMEVISUALS_H

#define GREEN   "\x1b[32m"
#define BLUE    "\x1b[34m"
#define COLOR_RESET   "\x1b[0m"

void printMatrix(char mat[HEIGHT][WIDTH]);

void welcomeMsg(char matrix[HEIGHT][WIDTH]);

void againMessage (void);

void endMessage(void);

#endif