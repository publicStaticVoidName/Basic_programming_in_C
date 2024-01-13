#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a;
	puts("Enter an integer to see if it is a three-digit number");

	scanf("%d", &a);

	99 < abs(a) && abs(a) < 1000 ? puts("YES") : puts("NO");

	return 0;
}
