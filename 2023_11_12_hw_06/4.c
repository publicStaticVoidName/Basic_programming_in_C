#include <stdio.h>

int is_happy_number(int n);
int main(void)
{
	int n;

	puts("Enter an integer to check if the product of its digits is equal to the sum of its digits");

	scanf("%d", &n);

	is_happy_number(n) ? puts("YES") : puts("NO");

	return 0;
}

int is_happy_number(int n)
{
	if (n == 0)
	{
		return 1;
	}

	int sum = 0;
	int product = 1;

	while (n)
	{
		sum += n % 10;
		product *= n % 10;
		n /= 10;
	}

	return sum == product ? 1 : 0;
}
