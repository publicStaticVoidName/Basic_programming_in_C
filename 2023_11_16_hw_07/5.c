#include <stdio.h>

int akkerman(unsigned int n, unsigned int m);

int main(void)
{
	unsigned int n, m;

	puts("Enter a non-negative integer n and m to get the value of the Ackerman function");

	scanf("%u %u", &n, &m);

	printf("%d\n", akkerman(n, m));

	return 0;
}

int akkerman(unsigned int n, unsigned int m)
{
	if (n == 0)
	{
		return m + 1;
	}

	if (m == 0)
	{
		return akkerman(n - 1, 1);
	}

	return akkerman(n - 1, akkerman(n, m - 1));
}
