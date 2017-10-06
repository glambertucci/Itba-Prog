#include "MatrixLogic.h"
#include "Standard.h"

void transferMat(char copyfrom [HEIGHT][WIDTH], char copyto [HEIGHT][WIDTH])
{
	int m, n;

	for(m = 0; m<HEIGHT; m++) //Aunque el cuadrado exterior siempre sea cero, para reutilizar
	{							//la funcion copia cualquier ancho y cualquier alto.
		for(n = 0; n<WIDTH; n++)  //idem
		{
			copyto[m][n]=copyfrom[m][n];
		}
	}
}

void initMatrix (char mat1[HEIGHT][WIDTH])
{
	int fil_count,col_count;
	for (fil_count=0; fil_count <= (HEIGHT); fil_count++)
	{
		for (col_count=0;col_count<=(WIDTH);col_count++)
	
		{
			mat1 [fil_count][col_count]=DEAD;
		}
		(mat1)[fil_count][0]=DEAD;
	}
}
