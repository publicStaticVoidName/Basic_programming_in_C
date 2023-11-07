#include <stdio.h>

int main(void)
{
	int a, b, c;
	puts("Enter three integer to get their sum and product");

	scanf("%d %d %d", &a, &b, &c);

	printf("%d+%d+%d=%d\n", a, b, c, a + b + c);
	printf("%d*%d*%d=%d\n", a, b, c, a * b * c);

	return 0;
}
