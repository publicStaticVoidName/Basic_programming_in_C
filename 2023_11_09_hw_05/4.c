#include <stdio.h>

int main(void)
{
	unsigned int number, rebmun = 0;
	puts("Enter an integer to see if its all digits is even");

	scanf("%u", &number);

	while (number)
	{
		rebmun *= 10;
		rebmun += number % 10;
		number /= 10;
	}

	printf("%u\n", rebmun);

	return 0;
}
