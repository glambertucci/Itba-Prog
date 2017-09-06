#include <stdio.h>
ENUM status {DEAD, ALIVE} //DEAD = 0; ALIVE = 1
#define REALHEIGHT 8
#define REALWIDTH 8
#define HEIGHT 7
#define WIDTH 7

int CellStatus (int filas, int column)  //Prototipo de CellStatus

int main (void)
    {
        int matrix[HEIGHT][WIDTH];


    }

int CellStatus (int fila, int column, int matrix [HEIGHT][WIDTH])
    {
        int Actual_Cell;
        int Neighbour_Alive = 0:
        int Destiny;
        int aux_column = column-1;


        Actual_Cell = matrix [fila] [column];

        for(matrix [fila-1][aux_column]; aux column <= column+1; aux_column ++) //analizo el estado de las 3 celulas superiores a la actual:
            {if (matrix[fila-1][aux_column] == ALIVE)                           //diagonal superior izquierda, superior y
                Neighbour_Alive ++;                                             //diagonal superior derecha
            }
       aux_column = 0;

        if(matrix[fila][column-1] == ALIVE) //analizo el estado de la celula laterale izquierda a la actual.
                Neighbour_Alive ++;


        if(matrix[fila][column+1] == ALIVE) //analizo el estado de la celula lateral derecha a la actual.
                Neighbour_Alive ++ 1;


        for(matrix [fila+1][aux_column]; aux column <= column+1; aux_column ++) //analizo el estado de las 3 celulas inferiores a la actual:
            {if (matrix[fila+1][aux_column] == ALIVE)                           //diagonal inferior izquierda, inferior y
                Neighbour_Alive ++;                                             //diagonal inferior derecha
            }

        Destiny = cell_fate (Neighbour_Alive,Actual_Cell);

    return Destiny;

    }
