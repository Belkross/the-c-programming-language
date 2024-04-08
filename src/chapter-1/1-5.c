#include <stdio.h>

float	convertFarenheitToCelsius(float farenheit)
{
	return (5.0 / 9.0) * (farenheit - 32.0);
}

int	main(void)
{
	printf("\nFarenheit - Celsius\n");
	for (int farenheit = 300; farenheit >= 0; farenheit = farenheit - 20)
	{
		printf("%3d %5.1f\n", farenheit, convertFarenheitToCelsius(farenheit));
	}
}
