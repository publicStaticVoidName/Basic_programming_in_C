#include <stdio.h

int main(void)
{
	unsigned short int a, b;
	unsigned int sum_of_squares = 0;

	puts("Enter two integers and get the sum of the squares of the numbers"
		"from the first number to the second");

	scanf("%hu %hu", &a, &b);

	for (unsigned int i = a; i <= b; i++)
	{
		sum_of_squares += i*i;
	}

	printf("%d\n", sum_of_squares);

	return 0;
}
