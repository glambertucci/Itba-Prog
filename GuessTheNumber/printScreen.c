#include "printScreen.h"

void printScreen (int state, int time){
    
    clrscr();
    printTimer(time);
    printText(state);