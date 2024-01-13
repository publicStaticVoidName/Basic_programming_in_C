#include <stdio.h>
#include <stdlib.h>

int find_max_array(int size, int a[]);

int main(void)
{
	int temp_int;
	unsigned int len = 0;
	int *arr, *temp_arr;
	char c;

	puts("Enter integers and find out the maximum of them");

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

	printf("%d\n", find_max_array(len, arr));

	return 0;
}

int find_max_array(int size, int a[])
{
	int max = *a;

	for (unsigned int i = 0; i < size; i++)
	{
		if (max < *(a + i))
		{
			max = *(a +i);
		}
	}

	return max;
}
