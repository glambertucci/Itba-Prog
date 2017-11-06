#include "frontEnd.h"
#include "termlib.h"
#include <stdio.h>
#include "general.h"


void printScreen (int state, int time){
    
    clrscr();
    printTimer(time);
    printText(state);
}



void printTimer (int time) {
    printf("\t\t\t\t Time left: %d", MAXTIME-time);
}




void printText (int state) {
    
    printf("\n\n");
    
    switch(state) {
        case INIT: printf("Welcome to Guess The Number! The random number is set between 0 and %d. Your time is 10 seconds. Press any key to begin.", MAXRANDNUM); break;
        case TRYAGAIN: printf("Incorrect number, you can try again in 2 seconds."); break;
        case GUESS: printf("What number am I thinking of?"); break;
        case WIN: printf("YOU WON!!!\nPress any key to exit.."); break;
        case LOSE: printf("You lose, loser.\nPress any key to exit.."); break;
    }
    
    
}