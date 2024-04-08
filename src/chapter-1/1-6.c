#include <stdio.h>

int	main(void)
{
	printf("%d\n", -1 == EOF);
	printf("%d\n", -1 != EOF);
}

/* The solution proposed by the book don’t seems to work. Maybe it comes from the compiler I use. */

// #include <stdio.h>

// int	main(void)
// {
// 	int	c;

// 	while (c = getchar() != EOF)
// 		printf("%d\n", c);
// 	printf("%d - pour EOF\n", c);
// }