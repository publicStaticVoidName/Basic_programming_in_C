#include <stdio.h>
#include <stdlib.h>

void sort_even_odd(int n, int a[]);

int main(void)
{
	int temp_int;
	unsigned int len = 0;
	int *arr, *temp_arr;
	char c;

	puts("Enter integers and ");

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

	sort_even_odd(len, arr);


	for (unsigned int i = 0; i < len; i++)
	{
		printf("%d ", *(arr + i));
	}
	puts("");

	return 0;
}

void sort_even_odd(int n, int a[])
{
	int temp_int;
	unsigned int len = n;
	int *arr = a;
	int prev_odd = 0, odd_index;

	for (unsigned int i = 0; i < len; i++)
	{
		if (*(arr + i) % 2 == 1 && prev_odd == 0)
		{
			odd_index = i;
			prev_odd = 1;
		}
		else if (*(arr + i) % 2 == 0 && prev_odd == 1)
		{
			unsigned int j = i;

			while (j > odd_index)
			{
				temp_int = *(arr + j);
				*(arr + j) = *(arr + j - 1);
				*(arr + j - 1) = temp_int;

				j--;
			}
			odd_index++;
		}
		if (*(arr + i) % 2 == 1)
		{
			prev_odd = 1;
		}
		else
		{
			prev_odd = 0;
		}
	}
}
