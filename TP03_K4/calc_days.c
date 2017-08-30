#include <stdio.h>
#include <stdlib.h>
long int calc_days (int, int, int, int, int, int);   //Prototipo calc_days
int main(void)
{
 int vuelto;
vuelto = calc_days( 17,5,1997,30,8,2017);
printf("Dias transcurridos : %d \n", vuelto);
}


long int calc_days(int d1, int m1, int a1, int d2, int m2, int a2)   //d=dia, m=mes, a=año
{
    int dias_a1;
    int dias_m1;
    int dias_d1;
    int dias_bisiesto_1;
    int cant_dias_1;
    int dias_a2;
    int dias_m2;
    int dias_d2;
    int dias_bisiesto_2;
    int cant_dias_2;
    long int dias_transcurridos;

    dias_a1 = (a1-1)*365;  //aca ya conte la cantidad de dias "en crudo", ahora le voy a ir sumando los dias "con mas presicion"
    dias_m1 = m1-1;
    if (dias_m1 == 0)
    {
        //no hago nada porque estaria en enero
    }
    if (dias_m1 == 1)
        dias_m1 = 31;    //si estoy en cualquier dia de febrero, estoy seguro que ya pasaron los 31 dias de enero

    if (dias_m1 == 2)
        dias_m1 = 31 + 28;  //si estoy en marzo, estoy seguro que ya pasaron los 31 dias de enero y los 28 de febrero
                            //mas adelante considerare si es un año bisiesto o no.
    if ((dias_m1!= 1)&&(dias_m1!= 2)&&((dias_m1%2)!= 0)) //si estoy en un mes par, se aplica este algoritmo (recordar que m1 es (mes actual - 1),
        dias_m1 = (31+28) + ((dias_m1/2) * 31) + ((dias_m1/2)-1) * 30; //osea que m1 daria impar.

    if ((dias_m1!= 1)&&(dias_m1!= 2)&&((dias_m1%2)== 0))
        dias_m1 = (31+28) + ((dias_m1/2)*31) + ((dias_m1/2)-2) * 30;

    dias_d1 = d1;

    dias_bisiesto_1 = (a1 - 1900)/4; //analizo cuantos años bisiestos hubo, y sumo 1 dia por cada uno de ellos

    cant_dias_1 = dias_a1 + dias_m1 + dias_d1 + dias_bisiesto_1;


    dias_a2 = (a2-1)*365;  //aca ya conte la cantidad de dias "en crudo", ahora le voy a ir sumando los dias "con mas presicion"
    dias_m2 = m2-1;
    if (dias_m2 == 0)
    {
        //no hago nada porque estaria en enero
    }
    if (dias_m2 == 1)
        dias_m2 = 31;    //si estoy en cualquier dia de febrero, estoy seguro que ya pasaron los 31 dias de enero

    if (dias_m2 == 2)
        dias_m2 = 31 + 28;  //si estoy en marzo, estoy seguro que ya pasaron los 31 dias de enero y los 28 de febrero
                            //mas adelante considerare si es un año bisiesto o no.
    if ((dias_m2!= 1)&&(dias_m2!= 2)&&((dias_m1%2)!= 0)) //si estoy en un mes par, se aplica este algoritmo (recordar que m1 es (mes actual - 1),
        dias_m2 = (31+28) + ((dias_m2/2) * 31) + ((dias_m2/2)-1) * 30; //osea que m1 daria impar.

    if ((dias_m2!= 1)&&(dias_m2!= 2)&&((dias_m2%2)== 0))
        dias_m2 = (31+28) + ((dias_m2/2)*31) + ((dias_m2/2)-2) * 30;

    dias_d2 = d2;

    dias_bisiesto_2 = (a2 - 1900)/4;

    cant_dias_2 = dias_a2 + dias_m2 + dias_d2 + dias_bisiesto_2;

    dias_transcurridos = cant_dias_2 - cant_dias_1;

    return dias_transcurridos;

}