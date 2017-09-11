#include <stdio.h>
#define M 6 // Cantidad de filas
#define N 6
#define TIME 88889999
void welcomeMsg (void);
void printMatrix(char mat[M][N]);
void delay (void);

char seed_matrix [M][N] = {
	{' ',' ',' ',' ',' ',' '},
	{' ','*','*','*','*',' '},
	{' ','*','*','*',' ',' '},
	{' ','*','*','*','*',' '},
	{' ','*',' ',' ',' ',' '},
	{' ',' ','*','*',' ',' '}
};


int main (void)
{
	welcomeMsg();
	delay();
	printMatrix (seed_matrix);
	delay();
	printf("puto\n");
	putchar('n');
	putchar('\n');
	return 0;

}
void welcomeMsg (void)
{
	printf("Bienvenido al juego de la vida \n");
	printf("Configuracion: %dx%d \n",M,N);
	printf("-------------------- \n");
	printf("\n");
	printf("para avanzar a la siguiente generacion\n");
	printf("toque cualquier tecla\n");
}


void printMatrix(char mat[M][N]){
	int i, j;
	printf("\n");
	for (i = 0;i < N;i++){
		for (j = 0;j < M;j++){
			printf("|%c",mat[i][j]);
		}
		printf("|\n");
	}
	printf ("\n");
}
void delay (void){
int a;
int b=a=TIME;

	while(a)	//perdiendo el timepo
	{
		while(b)
		{
			b--;
		}
		a--;
	}
}