#include <stdio.h>

#define len 10

int main(void)
{
	int arr[len], arr_of_frequency[len] = {0}, temp;
	unsigned int index_of_max = 0;

	printf("Enter %u integer and find out the most common ones\n", len);

	for (unsigned int i = 0; i < len; i++)
	{
		scanf("%d", arr + i);
	}

	for (unsigned int i = 0; i < len; i++)
	{
		for (unsigned int j = i + 1; j < len; j++)
		{
			if (*(arr + i) == *(arr + j))
			{
				*(arr_of_frequency + i) += 1;
				*(arr_of_frequency + j) += 1;
			}
		}
	}

	temp = *arr_of_frequency;
	for (unsigned int i = 1; i < len; i++)
	{
		if (temp < *(arr_of_frequency + i))
		{
			temp = *(arr_of_frequency + i);
			index_of_max = i;
		}
	}

	printf("%d\n", *(arr + index_of_max));

	return 0;
}
