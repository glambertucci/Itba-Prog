
#define NO  0
#define SI  1

int comparar (char*, char*);    //prototipo

int main (void)
{
    int imprimir;
    char arreglo1[] = "casa";
    char arreglo2[] = "sacar";

    imprimir = comparar(arreglo1, arreglo2);

    if(imprimir == 0)
        printf("No se puede formar la palabra");
    else
        printf("SE PUEDE FORMAR!!!");

return 0;

}
int comparar (char* primer_palabra, char* segunda_palabra)
{
    int array_aux [51];
    int k;
    int i;
    int m;
    int salida;

    int* punt_aux;
    punt_aux = array_aux;

    for (k=0; k<51; k++)    //inicializo el arreglo auxiliar todo en 0 y con un terminador (2).
    {
        array_aux[k] = 0;
    }
    array_aux [50] = 2;

    for(i=0; segunda_palabra[i] =! 0; i++)
    {                       //mientras no se encuentre al terminador, se escribira un 1 en la matriz auxiliar por cada letra
        *(punt_aux++)=1;    //de la segunda palabra
    }


    punt_aux = array_aux;   //restauro valor inicial



    for(i=0; primer_palabra[i] =! 0; i++)  //se posiciona en cada letra de la primer palabra
    {
        for(m=0; segunda_palabra[m] =! 0; m++)   //compara dicha letra con todas las letras
        {                                                              //de la segunda palabra.
            if(segunda_palabra[m] == primer_palabra[i])      //Si la letra de la prinmer palabra forma parte de la segunda palabra, escribe un 0 en la
            {                           //matriz auxiliar. De esta manera se "llevara un registro" de las letras que coinciden. Si alguna
                if (*punt_aux == 1)     //letra se encuentra repetida en la primer palabra, cuando "coincida la busqueda" con una letra ya
                    {                   //analizada de la segunda palabra, se encontrara con que ya hay un 0 en la matriz auxiliar, por lo
                        *punt_aux = 0;  //que "ignorara" dicha letra y seguira comparando con las restantes.
                    }
            }
            punt_aux++;
        }

        punt_aux = array_aux;
    }


    salida = SI;

    for (punt_aux = array_aux; *punt_aux =! 2; punt_aux++)      //Una vez terminada la comparacion de las letras, se fija si
    {                                                           //todo el arreglo auxiliar posee 0 (es decir, que coincidieron todas
                                                                //las letras de la segunda palabra con las de la primera).
        if(*punt_aux == 1)          //Si todo el arreglo auxiliar posee 0, devuelve que si se puede formar la palabra.
        {                           //En caso de que haya por lo menos un 1 en la matriz auxiliar, significa que la segunda palabra
            salida = NO;                        //no se puede formar completamente con los caracteres de la primer palabra, por lo que devuelve
        }                           //que no se puede.
    }
    return salida;

}
