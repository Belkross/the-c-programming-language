#include <stdio.h>

int	main(void)
{
	int input;

	while ((input = getchar()) != EOF)
	{
		if (input == '\t')
			printf("\\t");
		else if (input == '\\')
			printf("\\\\");
		else if (input == '\b')
			printf("\\b");
		else
			putchar(input);
	}
}