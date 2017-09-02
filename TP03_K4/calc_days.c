#include <stdio.h>
#include <stdlib.h>

int calc_days(int, int, int, int, int, int); //Prototipo de calc_days

int main(void)
{
 int vuelto;
vuelto = calc_days( 1,1,1996,30,8,2017);
printf("Dias transcurridos : %d \n", vuelto);
}

int calc_days(int d1, int m1, int a1, int d2, int m2, int a2)
{
    int dia1 = d1;
    int mes1 = 0;
    int anio1 = 0;
    int bisiestos_1 = 0;    //la inicializo para limpiarla preventivamente
    int cantidad_1 = 0;
    int dia2 = d2;
    int mes2 = 0;
    int anio2 = 0;
    int bisiestos_2 = 0;    //la inicializo para limpiarla preventivamente
    int cantidad_2 = 0;
    int total = 0;

 //fecha inicial
    anio1 = (a1-1)*365; //calculo la cantidad de dias de los años ya transcurridos

    printf("dias anio 1 = %d\n",anio1);

    if (m1 == 1)        //dependiendo de qué mes sea, sumo la cantidad de dias de los meses ya transcurridos
        mes1 = 0;
    if (m1 == 2)
        mes1 = 31;
    if (m1 == 3)
        mes1 = 31+28;
    if (m1 == 4)
        mes1 = 31+28+31;
    if (m1 == 5)
        mes1 = 31+28+31+30;
    if (m1 == 6)
        mes1 = 31+28+31+30+31;
    if (m1 == 7)
        mes1 = 31+28+31+30+31+30;
    if (m1 == 8)
        mes1 = 31+28+31+30+31+30+31;
    if (m1 == 9)
        mes1 = 31+28+31+30+31+30+31+31;
    if (m1 == 10)
        mes1 = 31+28+31+30+31+30+31+31+30;
    if (m1 == 11)
        mes1 = 31+28+31+30+31+30+31+31+30+31;
    if (m1 == 12)
        mes1 = 31+28+31+30+31+30+31+31+30+31+30;

    printf("dias mes 1 = %d\n", mes1);

    bisiestos_1 = (a1/4) - (a1/100) + (a1/400); //Un año es bisiesto si: es divisible por 4 pero no por 100.
                                                //                       es divisible por 100 y es divisible por 400.
                                                //Acá primero consideramos todos los bisiestos que habria "a grandes rasgos" (al considerar
                                                //que hay un bisiesto cada 4 años); luego le restamos la cantidad de años que cambia de centena
                                                //(porque si solo es divisible por 100 y no por 400 no es bisiesto, como el 1700 o el 1900);
                                                //y por ultimo sumamos los años que "eliminamos por error" en la resta anterior (habiamos eliminado
                                                //todos los divisibles por 100, pero los que son divisibles por 100 y por 400 a la vez SI son bisiestos,
                                                //como el 1600 y el 2000).

    printf("dias bisiestos 1 = %d\n", bisiestos_1);

    cantidad_1 = anio1 + mes1 + dia1 + bisiestos_1; //obtengo la cantidad de dias transcurridos hasta la fecha introducida

    printf("cantidad de dias fecha 1 = %d\n\n", cantidad_1);


//fecha final
    anio2 = (a2-1)*365; //calculo la cantidad de dias de los años ya transcurridos

    printf("dias anio 2 = %d\n",anio2);


    if (m2 == 1)    //dependiendo de qué mes sea, sumo la cantidad de dias de los meses ya transcurridos
        mes2 = 0;
    if (m2 == 2)
        mes2 = 31;
    if (m2 == 3)
        mes2 = 31+28;
    if (m2 == 4)
        mes2 = 31+28+31;
    if (m2 == 5)
        mes2 = 31+28+31+30;
    if (m2 == 6)
        mes2 = 31+28+31+30+31;
    if (m2 == 7)
        mes2 = 31+28+31+30+31+30;
    if (m2 == 8)
        mes2 = 31+28+31+30+31+30+31;
    if (m2 == 9)
        mes2 = 31+28+31+30+31+30+31+31;
    if (m2 == 10)
        mes2 = 31+28+31+30+31+30+31+31+30;
    if (m2 == 11)
        mes2 = 31+28+31+30+31+30+31+31+30+31;
    if (m2 == 12)
        mes2 = 31+28+31+30+31+30+31+31+30+31+30;

    printf("dias mes 2 = %d\n", mes2);

    bisiestos_2 = (a2/4)- (a2/100) + (a2/400);  //un año es bisiesto si: es divisible por 4 pero no por 100.
                                                //                       es divisible por 100 y es divisible por 400.
                                                //acá primero consideramos todos los bisiestos que habria "a grandes rasgos" (al considerar
                                                //que hay un bisiesto cada 4 años); luego le restamos la cantidad de años que cambia de centena
                                                //(porque si solo es divisible por 100 y no por 400 no es bisiesto, como el 1700 o el 1900);
                                                //y por ultimo sumamos los años que "eliminamos por error" en la resta anterior (habiamos eliminado
                                                //todos los divisibles por 100, pero los que son divisibles por 100 y por 400 a la vez SI son bisiestos,
                                                //como el 1600 y el 2000).


    printf("dias bisiestos 2 = %d\n", bisiestos_2);

    cantidad_2 = anio2 + mes2 + dia2 + bisiestos_2; //obtengo la cantidad de dias transcurridos hasta la fecha introducida

    printf("cantidad de dias fecha 2 = %d\n\n", cantidad_2);


//calculo de dias
    if (cantidad_1 < cantidad_2)
        total = cantidad_2 - cantidad_1;   //obtengo la cantidad de dias transcurridos entre las fechas introducidas
    else
        total = cantidad_1 - cantidad_2;

    printf("cantidad de dias transcurridos entre ambas fechas = %d\n",total);

    return total;
}


