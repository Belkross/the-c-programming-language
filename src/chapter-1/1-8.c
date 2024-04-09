#include <stdio.h>

int	main(void)
{
	int	input;

	long space, tabulation, newline;
	space = 0;
	tabulation = 0;
	newline = 0;
	while ((input = getchar()) != EOF)
	{
		if (input == '\n')
			++newline;
		else if (input == '\t')
			++tabulation;
		else if (input == ' ')
			++space;
	}
	printf("newline: %ld - tabulation: %ld - space: %ld\n", newline, tabulation,
		space);
}
