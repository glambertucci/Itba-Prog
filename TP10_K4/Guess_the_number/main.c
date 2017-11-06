#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "get_char.h"
#include "nonblock.h"


#define MAX_NUM 9
#define MAX_TIME 30
#define PI 3.14159265359
#define TRYS 5
typedef char * string;
int main (void)
{
	    //MANEJO DEL TIEMPO
            unsigned int x_seconds=0;   
            unsigned int x_milliseconds=0;
            unsigned int time_in_secs=0;
            int time_left=0;
            // VARIABLES UTILES
            int safe_print=10;  //Asegura que no se imprima muchas veces el mensaje del tiempo

            //VARIABLES  DE JUEGO
            int win_number,trys=TRYS,trys2=TRYS;     
            char guess='g';
        
        
             //MENSAJES
            string msg_welcome="Ingrese cualquier caracter para comenzar\nTendra";
            string msg_welcome2="segundos para adivinar un numero entre los numeros 0 y";
            string msg_welcome3="Tendra", msg_welcome4="intentos", msg_time_left="Te quedan ";
            string msg_congrats="Felicitaciones, ha ganado",msg_lost="El tiempo termino, usted ha perdido";
            string msg_out_of_trys = "Se quedo sin intentos, usted ha perdido";

            srand (time(NULL)*PI);
            win_number= rand()%MAX_NUM;
            printf("%s %d %s %d\n%s% d %s \n",msg_welcome, MAX_TIME , msg_welcome2, MAX_NUM,msg_welcome3,TRYS,msg_welcome4);
            get_char();
            clock_t x_startTime,x_countTime;     
            time_in_secs=MAX_TIME; 
            x_startTime=clock();  // comienza reloj
            
            time_left=time_in_secs-x_seconds;   // inicio el tiempo restante

            while (((time_left>0)) && (guess!=win_number) && (trys!=0)) 
                {
                        x_countTime=clock();    //actualizo el timer
                        x_milliseconds=x_countTime-x_startTime;
                        x_seconds=(x_milliseconds/(CLOCKS_PER_SEC));

                        time_left=time_in_secs-x_seconds; 

                        if (!(time_left%1))
                        {
                            if (!(x_seconds==safe_print))
                            {
                            safe_print=x_seconds;
                            printf("\n%s: %d\n",msg_time_left, time_left);
                            }
                        }
                        nonblock(NB_ENABLE);
			if(trys!=trys2)
			{
			    printf("\n%s: %d %s \n",msg_time_left , trys, msg_welcome4);
			    trys2=trys;
			}
                        if (kbhit())
                        {
                            guess = get_char(); 
                            guess-='0';     // para convertir a numero
			    trys--;
                        }
                        nonblock(NB_DISABLE);
                }
            if(guess==win_number)
            {
                printf("\n%s\n",msg_congrats);
            }
	    else if (trys == 0 )
	    {
		printf("\n%s\n",msg_out_of_trys);
            }
            else 
            {
                printf( "\n%s\n",msg_lost);
            }    
return 0;
}
