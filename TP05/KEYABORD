#define MAX_LENGTH 30
#define FALSE 0
#define TRUE 1

int kbverif(stringarr[MAX_LENGTH])
{
	char c;
	int abort = FALSE;

	
	while ((counter <= MAX_LENGTH) && (abort == FALSE) && (c != 0))  //Loopea mientras falten elementos por analizar y no haya errores
	{
		c = stringarr[counter];	//C es la variable que usaré para analizar la validez de cada elemento del arreglo.
		
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == ' ')) //Si no es una letra o un espacio, produce un error. Si no, continúa.
		{
			counter++;
		}
		else
		{
			abort = TRUE;
		}
	}
	return abort;
}


void keyboard(stringarr[MAX_LENGTH])
{
	int counter=0;
	char c;
	
	while(( (c = getchar() ) != '\n') && (counter <= MAX_LENGTH))
	{
			stringarr[counter++]=c;
	}
}	
