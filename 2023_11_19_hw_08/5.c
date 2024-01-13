#include <stdio.h>

#define len 10

int main(void)
{
	int arr[len], spec_arr[len];
	unsigned int spec_len = 0;

	printf("Enter %u numbers to select those whose penultimate digit is zero\n", len);

	for (unsigned int i = 0; i < len; i++)
	{
		scanf("%d", arr + i);

		if (*(arr + i) % 100 / 10 == 0)
		{
			*(spec_arr + spec_len) = *(arr + i);
			spec_len++;
		}
	}

	for (unsigned int i = 0; i < spec_len; i++)
	{
		printf("%d ", *(spec_arr + i));
	}
	puts("");

	return 0;
}
