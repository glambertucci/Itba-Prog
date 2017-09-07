char seed_matrix[M][N] = {
	{' ',' ',' ',' ',' ',' '},
	{' ','*','*','*','*',' '},
	{' ','*','*','*',' ',' '},
	{' ','*','*','*','*',' '},
	{' ','*',' ',' ',' ',' '},
	{' ',' ','*','*',' ',' '}
};
////////////////////////////////////////////////////////////
/* copy_matrix: recibe una referencia a una matriz origen (src) y a una matriz  basicamente copiamos la seed al la posta
   destino (dst), y copia el contenido de la matriz origen en la matriz de destino*/
void copy_matrix (char src[][M], char dst[][M]); 

void copy_matrix (char src[][N], char dst[][N]){
	int i, j;
	for(i = 0; i < M; i++){
		for(j = 0; j < N; j++){
			dst[i][j] = src[i][j];
		}
	}
}