#include <stdio.h>

unsigned long int sum(unsigned int n);

int main(void)
{
	unsigned int n;

	puts("Enter an integer n to get a sum from one to n");

	scanf("%u", &n);

	printf("%lu\n", sum(n));

	return 0;
}

unsigned long int sum(unsigned int n)
{
	return (unsigned long int) n * (n + 1) / 2;
}
