#include <stdio.h>
#define NO  0
#define YES  1

int compareWords (char*, char*);    //prototipo

int main (void)     //HAY QUE ELIMINAR ESTE MAIN, ES SOLO PARA PROBAAAAAR
{
    int imprimir;
    char arreglo1[] = "sacar";
    char arreglo2[] = "casa";

    imprimir = compareWords(arreglo1, arreglo2);

    if(imprimir == 0)
        printf("No se puede formar la palabra");
    else
        printf("SE PUEDE FORMAR!!!");

return 0;

}
int compareWords (char* first_word, char* second_word)
{
    int array_aux [51];
    int k;
    int i;
    int m;
    int v;
    int exit;

    int* punt_aux;
    punt_aux = array_aux;

    for (k=0; k<51; k++)    //inicializo el arreglo auxiliar todo en 0 y con un terminador (2).
    {
        array_aux[k] = 0;
    }
    array_aux [50] = 2;


    for(i=0; second_word[i] != '\0'; i++)
    {                       //mientras no se encuentre al terminador, se escribira un 1 en la matriz auxiliar por cada letra
        *(punt_aux++)=1;    //de la segunda palabra
    }


    punt_aux = array_aux;   //restauro valor inicial

    v = 0;

    for(i=0; first_word[i] != '\0'; i++)  //se posiciona en cada letra de la primer palabra
    {
        for(m=0; (second_word[m] != '\0') && (v == 0); m++)   //compara dicha letra con todas las letras
        {                                                              //de la segunda palabra.
            if(second_word[m] == first_word[i])      //Si la letra de la prinmer palabra forma parte de la segunda palabra, escribe un 0 en la
            {                           //matriz auxiliar. De esta manera se "llevara un registro" de las letras que coinciden. Si alguna
                if (*punt_aux == 1)     //letra se encuentra repetida en la primer palabra, cuando "coincida la busqueda" con una letra ya
                    {                   //analizada de la segunda palabra, se encontrara con que ya hay un 0 en la matriz auxiliar, por lo
                        *punt_aux = 0;  //que "ignorara" dicha letra y seguira comparando con las restantes.
                        v = 1;
                    }
            }
            punt_aux++;
        }

        punt_aux = array_aux;
        v = 0;
    }


    exit = YES;

    for (punt_aux = array_aux; *punt_aux != 2; punt_aux++)      //Una vez terminada la comparacion de las letras, se fija si
    {                                                           //todo el arreglo auxiliar posee 0 (es decir, que coincidieron todas
                                                                //las letras de la segunda palabra con las de la primera).
        if(*punt_aux == 1)          //Si todo el arreglo auxiliar posee 0, devuelve que si se puede formar la palabra.
        {                           //En caso de que haya por lo menos un 1 en la matriz auxiliar, significa que la segunda palabra
            exit = NO;                        //no se puede formar completamente con los caracteres de la primer palabra, por lo que devuelve
        }                           //que no se puede.
    }
    return exit;

}
