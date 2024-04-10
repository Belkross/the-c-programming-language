#include <stdio.h>

#define NOT_A_SPACE 'a'

int	main(void)
{
	int input, lastCharacter;

	lastCharacter = NOT_A_SPACE;
	while ((input = getchar()) != EOF)
	{
		if ((lastCharacter != ' ') || input != ' ')
			putchar(input);

		lastCharacter = input;
	}
}