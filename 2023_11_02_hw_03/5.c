#include <stdio.h>

int main(void)
{
	int a;
	puts("Enter a three-digit integer to get the product of its digits");

	scanf("%d", &a);

	printf("%d\n", (a % 10) * (a % 100 / 10) * (a / 100));

	return 0;
}
