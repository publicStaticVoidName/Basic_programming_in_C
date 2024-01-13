#include <stdio.h>

int main(void)
{
	unsigned int a, temp, sum = 0, product = 1;

	puts("Enter a nutural number to find lucky numbers in the range from 10 to the entered number");

	scanf("%u", &a);

	for (unsigned int i = 10; i <= a; i++)
	{
		temp = i;

		while (temp)
		{
			sum += temp % 10;
			product *= temp % 10;
			temp /= 10;
		}

		if (sum == product)
		{
			printf("%u ", i);
		}

		sum = 0;
		product = 1;
	}
	puts("");

	return 0;
}
