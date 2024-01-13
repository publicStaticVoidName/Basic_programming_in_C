#include <stdio.h>

void func(int a, int b);

int main(void)
{
	int a, b;

	puts("Enter two integer a and b to get the sequence from a to b");

	scanf("%d %d", &a, &b);

	func(a, b);

	return 0;
}

void func(int a, int b)
{
	if (a == b)
	{
		printf("%d\n", a);
	}
	else
	{
		printf("%d ", a);
		if (a < b)
		{
			func(a + 1, b);
		}
		else
		{
			func(a - 1, b);
		}
	}
}
