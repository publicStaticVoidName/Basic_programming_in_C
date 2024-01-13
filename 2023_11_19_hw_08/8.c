#include <stdio.h>

int main(void)
{
	unsigned int a, digits_counter = 1, index_of_max;
	unsigned long int divisor = 10;
	int max;

	puts("Enter a natural number to get maximum number by using its digits");

	scanf("%u", &a);

	while (a / divisor > 0)
	{
		divisor *= 10;
		digits_counter++;
	}
	divisor /= 10;

	int arr[digits_counter];

	for (unsigned int i = 0; i < digits_counter; i++)
	{
		*(arr + i) = (a / divisor) % 10;
		divisor /= 10;
	}

	for (unsigned int i = 0; i < digits_counter; i++)
	{
		max = -1;

		for (unsigned int j = 0; j < digits_counter; j++)
		{
			if (max < *(arr + j))
			{
				max = *(arr + j);
				index_of_max = j;
			}
		}

		printf("%u", max);
		*(arr + index_of_max) = -1;
	}

	puts("");

	return 0;
}
