#include <time.h>

void delay(unsigned int secs)
{
	
	unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.

}