#include <stdio.h>

#define len 10

int main(void)
{
	int arr[len];

	printf("Enter %u integer to sort it last digits\n", len);

	for (unsigned int i = 0; i < len; i++)
	{
		scanf("%d", arr + i);
	}

	for (unsigned int i = 0; i < len; i++)
	{
		for (unsigned int j = 0; j < len; j++)
		{
			if (*(arr + j) % 10 == i)
			{
				printf("%d ", *(arr + j));
			}
		}
	}
	puts("");

	return 0;
}
