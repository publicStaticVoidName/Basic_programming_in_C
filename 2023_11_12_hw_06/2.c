#include <stdio.h>

unsigned long int pow(unsigned char a, unsigned char n);

int main(void)
{
	unsigned char n;

	puts("Enter the number of a chessboard square to find out the number of grains on that square");

	scanf("%hhu", &n);

	printf("%lu\n", pow(2, n - 1));

	return 0;
}

unsigned long int pow(unsigned char a, unsigned char n)
{
	unsigned long int res = 1;
	for (unsigned int i = n; i > 0; i--)
	{
		res *= a;
	}

	return res;
}
