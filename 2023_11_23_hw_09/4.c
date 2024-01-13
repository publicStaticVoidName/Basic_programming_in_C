#include <stdio.h>
#include <stdlib.h>

int is_two_same(int size, int a[]);

int main(void)
{
	int temp_int;
	unsigned int len = 0;
	int *arr, *temp_arr;
	char c;

	puts("Enter integers and check if there are duplicates");

	while (scanf("%d%c", &temp_int, &c) == 2)
	{
		temp_arr = (int *) realloc(arr, (len + 1) * sizeof(int));

		if (temp_arr == NULL)
		{
			return -1;
		}
		else
		{
			arr = temp_arr;
			len++;
			*(arr + len - 1) = temp_int;
		}

		if (c == '\n')
		{
			break;
		}
	}

	is_two_same(len, arr) ? puts("YES") : puts("NO");

	return 0;
}

int is_two_same(int size, int a[])
{
	unsigned int len = size;
	int *arr = a;

	for (unsigned int i = 0; i < len; i++)
	{
		for (unsigned int j = i + 1; j < len; j++)
		{
			if (*(arr + i) == *(arr + j))
			{
				return 1;
			}
		}
	}

	return 0;
}
