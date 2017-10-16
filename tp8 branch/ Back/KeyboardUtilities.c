#include <stdio.h>
#include "KeyboardUtilities.h"

void cleanBuffer(void){
    char trash;
    while(trash=getchar() != '\n');
}
