// On macos, to input EOF, you need to use Ctrl+D

#include <stdio.h>

int	main(void)
{
	int input;

	while ((input = getchar() != EOF))
	{
		printf("%d\n", input);
	}

	printf("%d - pour EOF\n", input);
}