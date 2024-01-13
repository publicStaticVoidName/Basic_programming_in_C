#include <stdio.h>

unsigned int ones_counter(unsigned int a);

int main(void)
{
	unsigned int a;

	puts("Enter a natural number to find out the number of ones in its binary notation");

	scanf("%u", &a);

	printf("%d\n", ones_counter(a));

	return 0;
}

unsigned int ones_counter(unsigned int a)
{
	if (a > 1)
	{
		return (a % 2) + ones_counter(a / 2);
	}
	else
	{
		return a;
	}
}
