#include "GameLogic.h"
#include "MatrixLogic.h"
#include "Standard.h"

void nextGen(char matrix[][WIDTH], char auxmatrix[][WIDTH])
{

	int m=1, n=1;
	int cellstate;

	for(m = 1; m <= ((HEIGHT)-(2)); m++) //Ignorando la primera fila, hasta la cantidad total de filas menos dos.
	{
		for(n = 1; n <= ((WIDTH)-(2)); n++) //Ignorando la primera columna, hasta la cantidad totales de columnas menos dos.
		{
			cellstate=cellStatus(m, n, matrix); //Se fija si la fila m columna n va a estar viva o muerta
			if (cellstate == DEAD)	    	//Lo escribo en una matrix auxiliar, para no perturbar
				auxmatrix[m][n] = DEAD; 	//el analisis siguiente. 
			else
				auxmatrix[m][n] = ALIVE;

		}//columna
	}//fila

	transferMat(auxmatrix, matrix); //Transfiere la matriz auxiliar a la matriz real
}


int cellStatus (int m, int n, char matrix[][WIDTH])
{
      char current_cell = 0;
      int neighbour_alive = 0;
      int destiny = 0;

      current_cell = matrix [m] [n];   //estado actual de la celula, Dead o Alive
	if (matrix [m-1] [n-1] == ALIVE)	//analizo la celula diagonal superior izquierda
		neighbour_alive++;
	
	if (matrix [m-1] [n] == ALIVE)	//analizo la celula superior central
		neighbour_alive++;
	
	if (matrix [m-1] [n+1] == ALIVE)	//analizo la celula diagonal superior derecha 
		neighbour_alive++;
	
	if (matrix [m] [n-1] == ALIVE)	//analizo la celula izquierda
		neighbour_alive++;
	
	if (matrix [m] [n+1] == ALIVE)	//analizo la celula derecha
		neighbour_alive++;
	
	if (matrix [m+1] [n-1] == ALIVE)	//analizo la celula diagonal inferior izquierda
		neighbour_alive++;
	
	if (matrix [m+1] [n] == ALIVE)	//analizo la celula inferior central
		neighbour_alive++;
	
	if (matrix [m+1] [n+1] == ALIVE)	//analizo la celula diagonal inferior derecha
		neighbour_alive++;
	
      destiny = cellFate (neighbour_alive, current_cell);

	return destiny;

}

int cellFate(int nalive, int status)
{
	int fate;           //Esta variable contiene al destino de la celula analizada en función de la cantidad de vecinos 
   switch(nalive)
    {				         //Que se decide con este break
        		case 2:             //Se evalúa solo el 2 y el 3 ya que cualquier otro caso implica la muerte.
                	{	
                		if(status == ALIVE)
                		{
                   			fate = ALIVE;
                    			break;
                		}
                		else
                		{
                    			fate = DEAD;
                    			break;
				}                	
                	}
        		case 3:
			{
                		fate = ALIVE; 
                		break;
			}
        			
        		default:
			{
                		fate = DEAD;
			}
    }
    return fate;
}