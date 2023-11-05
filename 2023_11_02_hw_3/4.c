#include <stdio.h>

int main(void)
{
	int a, b, c;
	puts("Enter three integer to get their average");

	scanf("%d %d %d", &a, &b, &c);

	printf("%.2f\n", (double) (a + b + c) / 3);

	return 0;
}
