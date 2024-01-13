#include <stdio.h>

#define len 12
#define shift 4

int main(void)
{
	int arr[len];

	printf("Enter %u integer and get the same numbers cycllically shifted to the right by %u\n", len, shift);

	for (unsigned int i = 0; i < len; i++)
	{
		scanf("%d", arr + i);
	}

	for (unsigned int i = len - shift; i % len != len - shift -1; i++)
	{
		printf("%d ", *(arr + (i % len)));
	}
	printf("%d\n", *(arr + len - shift - 1));

	return 0;
}
