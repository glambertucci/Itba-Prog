#include "Standard.h"
#include "MatrixLogic.h"

void transferMat(char copyfrom [][WIDTH], char copyto [][WIDTH])
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
