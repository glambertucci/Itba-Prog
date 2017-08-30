#include <stdio.h>
#define TERMINATOR 0
#define ASCII '0'


int make_num (char first,char second, char third, char fourth);
//This program recives 4 chars, every number that lacks the third and fourth char must be sent with the terminator in those positions
//if the input is correct, you'll get the composed number   
int make_num (char first,char second, char third, char fourth)
{
	int number;
	
	if (third == TERMINATOR)
	{
		number= (((first-ASCII)*10)+(second-ASCII));
	}	
	
	else 
	{
		number=(((first-ASCII)*1000)+((second-ASCII)*100)+((third-ASCII)*10)+(fourth-ASCII));
	}

	return number;
}
