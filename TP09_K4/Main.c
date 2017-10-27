int main (void)
{
	uint8_t *bitArray = NULL, state = 0, abort = 0, ketTest;
	char userInput;

	bitArray = bitArrayInit();		//Inicializaciones
	
	message(state);

	changemode(BUFFERING_OFF);
	keyTest = kbhit();
	
	while(!abort)
	{	
		while(!keyTest)
		{
			userInput = getch();

			switch(userInput)
			{
				case 'ESC': abort = 1; break;
				case 'b': blinkFunction(bitArray); break;
				default:
				{
					if((userInput >= 0)&&(userInput < 8))
					{
						toggleBitValue(PORTA, userInput);
						updateBitArray(bitArray);
						updateScreen(bitArray);
						break;
					}
				}
			}//switch
		}//kbhit while
	}//abort while

	return 0;
}