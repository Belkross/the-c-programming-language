#include <stdio.h>

int	main(void)
{
	int minValue, maxValue, interval;
	float farenheit, celsius;

	minValue = 0;
	maxValue = 300;
	interval = 20;
	farenheit = minValue;

	printf("\nFarenheit - Celsius\n\n");

	while (farenheit <= maxValue)
	{
		celsius = (5.0 / 9.0) * (farenheit - 32.0);
		printf("%5.0f %6.1f\n", farenheit, celsius);
		farenheit = farenheit + interval;
	}
}