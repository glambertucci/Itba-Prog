
#define NO  0
#define SI  1



int comparar(char primera_palabra[], char segunda_palabra); //prototipo de funcion "comparar"

int main (void)
{

}

int comparar (&primer_palabra[0], &segunda_palabra[0])
{
    int matrix_aux [51] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2};
                    //1 mas del limite de letras para tener un terminador
    char* letra1;
    letra1 = &primer_palabra[0];    //posiciono al puntero apuntando a la primer letra de la primer palabra.
                                    //Este puntero ira comparando cada letra de la primer palabra con las de la segunda,
                                    //en cuanto coincidan o termine de escanear pasa a la siguiente letra de la primer palabra
                                    //y repite el proceso.
    char* letra2;
    letra2 = &segunda_palabra[0];   //voy a poner en 1 las posiciones del arreglo auxiliar que corresponden a una letra de
    char* punt_aux;                 //la segunda palabra.
    punt_aux = &matrix_aux[0];

    for(letra2 = &segunda_palabra[0],*letra2 =! '\0', letra2++)
    {                       //mientras no se encuentre al terminador, se escribira un 1 en la matriz auxiliar por cada letra
        *(punt_aux++)=1;    //de la segunda palabra
    }

    letra2 = &segunda_palabra;  //se posicionan ambos punteros nuevamente apuntando al inicio de sus respectivos arreglos
    punt_aux = &matrix_aux[0];

    for(letra1 = &primer_palabra[0],*letra1 =! '\0', letra1++)  //se posiciona en cada letra de la primer palabra
    {
        for(letra2 = &segunda_palabra[0], *letra2 =! '\0', letra2++)   //compara dicha letra con todas las letras
        {                                                              //de la segunda palabra.
            if(*letra2 == *letra1)      //Si la letra de la prinmer palabra forma parte de la segunda palabra, escribe un 0 en la
            {                           //matriz auxiliar. De esta manera se "llevara un registro" de las letras que coinciden. Si alguna
                if (*punt_aux == 1)     //letra se encuentra repetida en la primer palabra, cuando "coincida la busqueda" con una letra ya
                    {                   //analizada de la segunda palabra, se encontrara con que ya hay un 0 en la matriz auxiliar, por lo
                        *punt_aux = 0;  //que "ignorara" dicha letra y seguira comparando con las restantes.
                    }
            }
            punt_aux++;
        }

        punt_aux = &matrix_aux[0];
    }

    for (punt_aux = &matrix_aux, *punt_aux =! 2, punt_aux++)    //Una vez terminada la comparacion de las letras, se fija si
    {                                                           //todo el arreglo auxiliar posee 0 (es decir, que coincidieron todas
                                                                //las letras de la segunda palabra con las de la primera).
        if(*punt_aux == 1)          //Si todo el arreglo auxiliar posee 0, devuelve que si se puede formar la palabra.
        {                           //En caso de que haya por lo menos un 1 en la matriz auxiliar, significa que la segunda palabra
            return NO;              //no se puede formar completamente con los caracteres de la primer palabra, por lo que devuelve
        }                           //que no se puede.
    }
    return SI;

}
