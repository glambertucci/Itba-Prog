
void select_mode(void)
{
	int release = STOP;
	char Classic[MAX_OPERATORS] = {"+-*/&|^"};  //{"+-*/&|^"};		//Símbolos 
	char Letters[MAX_OPERATORS] = {"srmdaox"}; //{"srmdaox"};		//Letras 
	char option[2];
	
	while (release == STOP)
	{
		printf("Seleccione el modo de los operadores ingresando:\n");
		printf("1 Si desea los simbolos clásicos para operar + - * / & | ^\n");
		printf("2 Si desea las letras s r m d a o x\n");
		option[0] = getchar();
		option[1] = getchar();
		if (option[1] == '\n')
		{
			switch (option[0])
			{
				case '1': allocate_operations(Classic); release = CONTINUE ; break;
				case '2': allocate_operations(Letters); release = CONTINUE ; break;
				default : printf("\nCARACTER O SELECCIÓN INVÁLIDA\n\n"); release = STOP ; break;
			}
		}
		else
		{
			printf("\nCARACTER O SELECCIÓN INVÁLIDA\n\n");
			release = STOP ;
			while(getchar() != '\n')
			{
			}		
		}

	}
}

//

void allocate_operations (char *option_selected)
{
	int counter = 0;
	double(*sum_pointer)(double, double);
	double(*res_pointer)(double, double);
	double(*mul_pointer)(double, double);
 	double(*div_pointer)(double, double);
	double(*and_pointer)(double, double);
	double(*or_pointer)(double, double);
	double(*xor_pointer)(double, double);
	sum_pointer = &sum;
	res_pointer = &res;
	mul_pointer = &mul;
	div_pointer = &div;
	and_pointer = &and;
	or_pointer = &or;
	xor_pointer = &xor;
	
	*(operator + counter) = *(option_selected + counter);
	add_operation(*(option_selected + counter), sum_pointer, counter);
	counter++;
	
	operator [counter] = *(option_selected + counter);
	add_operation(*(option_selected + counter), res_pointer, counter);
	counter++;

	operator [counter] = *(option_selected + counter);
	add_operation(*(option_selected + counter), mul_pointer, counter);
	counter++;

	operator [counter] = *(option_selected + counter);
	add_operation(*(option_selected + counter), div_pointer, counter);
	counter++;
	
	operator [counter] = *(option_selected + counter);
	add_operation(*(option_selected + counter), and_pointer, counter);
	counter++;

	operator [counter] = *(option_selected + counter);
	add_operation(*(option_selected + counter), or_pointer, counter);
	counter++;

	operator [counter] = *(option_selected + counter);
	add_operation(*(option_selected + counter), xor_pointer, counter);
	counter++;
}

//

void add_operation (char operator, double (*a) (double, double), int counter )
{
	*(actions + counter) = a;
}

//
