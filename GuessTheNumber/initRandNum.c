#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int initRandNum(int maxnum);
//Esta función genera un número positivo al azar. Recibe como input el número máximo que se desea y devuelve un número menor al módulo de dicho número

#define RANDNUM -32

int main(void)
{
    int x;
    
    printf("Pensando en un número...\n");
        
    x = initRandNum(RANDNUM);
    

    printf("OK, el número es %d\n",x);
    
    return 0;
}


int initRandNum(int maxnum)
{
    if(maxnum < 0) //Si el número es menor a 0, para simplificar la lógica le hago el módulo....
    {
        maxnum *= (-1); //...pues esta función a fin de cuentas debe devoler un número positivo.
    }
    
    int num = (maxnum+1); //Inicializado de esta manera para poder entrar al while.
    
    srand(time(NULL));

    
        while(num > maxnum)
        {
            num = rand(); //Asignará valores a num hasta dar con uno menor al máximo. No se evalúa que sea mayor a 0 pues rand solo devuelve positivos.
        }
}