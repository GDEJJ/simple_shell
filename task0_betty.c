#include <stdio.h>

/**
 * main - function that prints numbers from 1 to 100
 * Return: void
 */

int main(void)
{
	int i;

	for (i = 0 ; i <= 100 ; i++)
	{
		if (i == 100)
			printf("%d\n", i);
		else

		printf("%d, ", i);
	}
	return (0);
}
