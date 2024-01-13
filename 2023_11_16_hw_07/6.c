#include <stdio.h>

unsigned int acounter(void);

int main(void)
{
	puts("Enter a string with the dot at the end to count the number of 'a' character");

	printf("%u\n", acounter());

	return 0;
}

unsigned int acounter(void)
{
	char c;
	scanf("%c", &c);

	if (c != '.' && c != EOF)
	{
		if (c == 'a')
		{
			return 1 + acounter();
		}
		else
		{
			return acounter();
		}
	}

	return 0;
}
