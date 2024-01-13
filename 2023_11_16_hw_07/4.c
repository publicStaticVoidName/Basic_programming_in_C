#include <stdio.h>

void filter(void);
int main(void)
{
	puts("Enter a sequenc of integer with 0 at the end to get only odd number");

	filter();
	puts("");

	return 0;
}

void filter(void)
{
	int a;
	scanf("%d", &a);

	if (a % 2 == 1 || a % 2 == -1)
	{
		printf("%d ", a);
	}

	if (a != 0)
	{
		filter();
	}
}
