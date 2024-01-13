#include <stdio.h>

int check_brackets(void);
int main(void)
{
	puts("Enter some brackets and got in the end to check ");

	check_brackets() ? puts("YES") : puts("NO");

	return 0;
}

int check_brackets(void)
{
	unsigned int left_brackets_counter = 0;
	char c;
	scanf("%c", &c);

	while (c != '.' && c != EOF)
	{
		if (c == '(')
		{
			left_brackets_counter++;
		}
		else if (c == ')' && left_brackets_counter == 0)
		{
			return 0;
		}
		else
		{
			left_brackets_counter--;
		}

		scanf("%c", &c);
	}

	return !left_brackets_counter;
}
