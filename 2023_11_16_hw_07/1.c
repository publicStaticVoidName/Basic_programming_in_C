#include <stdio.h>

void print_num(unsigned int a);

int main(void)
{
	unsigned int a;

	puts("Enter an integer to get its digits");

	scanf("%u", &a);

	print_num(a);

	return 0;
}

void print_num(unsigned int a)
{
	if (a / 10 == 0)
	{
		printf("%u\n", a);
	}
	else
	{
		print_num(a / 10);
		printf("%u\n", a % 10);
	}
}
