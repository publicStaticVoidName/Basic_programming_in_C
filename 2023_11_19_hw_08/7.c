#include <stdio.h>

int main(void)
{
	unsigned int a;
	unsigned long int divisor = 10;

	puts("Enter a natural number to divide its digits");

	scanf("%u", &a);

	while (a / divisor > 0)
	{
		divisor *= 10;
	}

	divisor /= 10;

	while (divisor > 0)
	{
		printf("%u ", (unsigned int) (a / divisor) % 10);
		divisor /= 10;
	}
	puts("");

	return 0;
}
