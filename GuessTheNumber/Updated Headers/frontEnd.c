#include "printScreen.h"
#include "termlib.h"
#include "main.h"
#include <stdio.h>


void printScreen (int state, int time){
    
    clrscr();
    printTimer(time);
    printText(state);
}



void printTimer (int time) {
    printf("/t/t/t/t/t Time left: %d", time);
}




void printText (int state) {
    
    printf("\n\n");
    
    switch(state) {
        case INIT: printf("Welcome to Guess The Number!\nThe random number is set between 0 and %d. Your time is 10 seconds.\nGive it a try!", MAXRANDNUM); break;
        case TRYAGAIN: printf("Incorrect number, you can try again in 2 seconds."); break;
        case WIN: printf("YOU WON!!!\nPress any key to exit.."); break;
        case LOSE: printf("You lose, ha-ha.\nPress any key to exit.."); break;
    }
    
    
}