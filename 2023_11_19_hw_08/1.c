#include <stdio.h>

int main(void)
{
	int a;
	double sum = 0;

	puts("Enter five integers to get the average value");

	for (unsigned int i = 0; i < 5; i++)
	{
		scanf("%d", &a);
		sum += (double) a;
	}

	printf("%.3f\n", sum / 5);

	return 0;
}
