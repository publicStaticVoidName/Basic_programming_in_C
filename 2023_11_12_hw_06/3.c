#include <stdio.h>

unsigned int nod(unsigned int a, unsigned int b);

int main(void)
{
	unsigned int a, b;

	puts("Enter two natural numbers to find their greatest common divisor");

	scanf("%u %u", &a, &b);

	printf("%u\n", nod(a, b));

	return 0;
}


unsigned int nod(unsigned int a, unsigned int b)
{
	unsigned int r = 1;

	while (r != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}
