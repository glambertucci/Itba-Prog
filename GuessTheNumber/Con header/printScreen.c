#include "printScreen.h"
#include "printText.h"
#include "printTimer.h"
#include "termlib.h"


void printScreen (int state, int time){
    
    clrscr();
    printTimer(time);
    printText(state);
}