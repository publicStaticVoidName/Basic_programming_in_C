#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double mean(unsigned int len, int *arr);
int *trace(unsigned int len, int *arr);

int main(void)
{
	puts("Enter the integer values of a 5x5 square matrix. "
	"The program will calculate the average trace value of the matrix "
	"and return the number of positive elements greater than this value");

	unsigned int len = 25;
	unsigned int tr_len = 5;
	int arr[len];

	for (unsigned int i = 0; i < len; i++)
	{
		scanf("%d", (arr + i));
	}

	int *tr;
	tr = trace(len, arr);
	double average_trace_el;
	unsigned int counter = 0;

	average_trace_el = mean(tr_len, tr);

	for (unsigned int i = 0; i < len; i++)
	{
		if (*(arr + i) > average_trace_el && *(arr + i) > 0)
		{
			counter++;
		}
	}
	printf("%d\n", counter);

	return 0;
}

int *trace(unsigned int len, int *arr)
{
	unsigned int trace_len;
	trace_len = (unsigned int) sqrt(len);
	int *trace;
	trace = (int*) malloc(trace_len * sizeof(int));

	for (unsigned int i = 0, j = 0; i < trace_len; i++, j += trace_len + 1)
	{
		*(trace + i) = *(arr + j);
	}

	return trace;
}

double mean(unsigned int len, int *arr)
{
	int sum = 0;
	for (unsigned int i = 0; i < len; i++)
	{
		sum += *(arr + i);
	}

	return (double) sum / len;
}
