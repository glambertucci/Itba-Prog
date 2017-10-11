#define OK 1
#define NOTOK 0
#define MAX 10
#define FALSE 0
#define TRUE 1
#include <stdio.h>
int verif (char input[MAX], int args);//la cantidad de argumentos


int verif (char input[MAX], int args)
{
	char index;
	int state,element=0,abort=FALSE;
	while(!abort)
	{
		index=input[element++];
		if ((((index>'0') && (index<'9') )|| (index=='.')))// ||(index == NOMBREDELGLOBALARRAYCONOP[0])||(index == NOMBREDELGLOBALARRAYCONOP[1])||(index == NOMBREDELGLOBALARRAYCONOP[2])||(index == NOMBREDELGLOBALARRAYCONOP[3])||(index == NOMBREDELGLOBALARRAYCONOP[4])||(index == NOMBREDELGLOBALARRAYCONOP[5])||(index == NOMBREDELGLOBALARRAYCONOP[6]) ) && (element!=args))
		{
			abort=FALSE;
		}
		else 
		{
			if (element==args)
			{
				state=OK;
				abort=TRUE;
			}
			else 
			{
				state=NOTOK;
				abort=TRUE;
			}
		}			
	}
	return state;
}