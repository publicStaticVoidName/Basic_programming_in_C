#include <stdio.h>

int main(void)
{
	int a, flag = 1;
	puts("Enter an integer to see if its all digits is even");

	scanf("%d", &a);

	while (a)
	{
		if (a % 10 % 2 == 0)
		{
			a /= 10;
		}
		else
		{
			flag = 0;
			break;
		}
	}

	flag ? puts("YES") : puts("NO");

	return 0;
}
