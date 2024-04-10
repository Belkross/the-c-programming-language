#include <stdio.h>

#define MIN_VALUE 0
#define MAX_VALUE 300
#define INTERVAL 20

float	convertFarenheitToCelsius(float farenheit)
{
	return (5.0 / 9.0) * (farenheit - 32.0);
}

int	main(void)
{
	printf("\nFarenheit - Celsius\n");
	for (int farenheit = MAX_VALUE; farenheit >= MIN_VALUE; farenheit = farenheit
		- INTERVAL)
	{
		printf("%3d %5.1f\n", farenheit, convertFarenheitToCelsius(farenheit));
	}
}
