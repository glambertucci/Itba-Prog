#include <stdio.h>
#define TOO_BIG 1
#define OK 0
#define MAX 30

void keyboard (char *);

int keyboard (char input[MAX])
{
	char a=3;
	int i=0, clean;
	while ((a != '\n') && (i!=MAX))
	{
		a=getchar();
		input[i]=a;	//asigno letras
		i++;
	}
	while ((clean=getchar())!= '\n' );	///limpio buffer

	return a;
}
