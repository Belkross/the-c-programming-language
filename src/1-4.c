#include <stdio.h>

int	main(void)
{
	float celsius, farenheit;
	int minValue, maxValue, interval;

	minValue = -20;
	maxValue = 100;
	interval = 10;
	celsius = minValue;

	printf("\nCelsius - Farenheit\n\n");

	while (celsius <= maxValue)
	{
		farenheit = (celsius * (9.0 / 5.0)) + 32.0;
		printf("%3.0f %4.0f\n", celsius, farenheit);

		celsius = celsius + interval;
	}
}