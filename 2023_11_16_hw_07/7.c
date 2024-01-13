#include <stdio.h>

int recurs_power(int a, unsigned short int n);

int main(void)
{
	int a;
	unsigned short int n;

	puts("Enter a base a and exponent n to calculate a^n");

	scanf("%d %hu", &a, &n);

	printf("%d\n", recurs_power(a, n));

	return 0;
}

int recurs_power(int a, unsigned short int n)
{
	if (n > 0)
	{
		return a * recurs_power(a, n - 1);
	}
	else
	{
		return 1;
	}
}
