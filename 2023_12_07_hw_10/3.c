#include <stdio.h>
#include <stdlib.h>

int comp(const void *i, const void *j);

int main(void)
{
	int ch;

	int *arr, *temp_arr;
	unsigned int len = 0;

	FILE *fin, *fout;
	fin = fopen("in.txt", "r");
	fout = fopen("out.txt", "w");

	ch = getc(fin);

	while (ch != EOF)
	{
		if (ch == '0')
		{
			temp_arr = (int *) realloc(arr, ++len * sizeof(int));

			if (temp_arr == NULL)
			{
				return -1;
			}
			else
			{
				arr = temp_arr;
				*(arr + len - 1) = 0;
			}
		}
		else if (ch >= '1' && ch <= '9')
		{
			temp_arr = (int *) realloc(arr, ++len * sizeof(int));

			if (temp_arr == NULL)
			{
				return -1;
			}
			else
			{
				arr = temp_arr;
				*(arr + len - 1) = ch - '0';
			}

			ch = getc(fin);

			while (ch >= '0' && ch <= '9')
			{
				*(arr + len - 1) = *(arr + len - 1) * 10 + (ch - '0');
				ch = getc(fin);
			}
		}

		ch = getc(fin);
	}

	fclose(fin);
	fclose(fout);

	qsort(arr, len, sizeof(int), comp);

	for (unsigned int i = 0; i < len; i++)
	{
		fprintf(fout, "%d ", *(arr + i));
	}

	return 0;
}

int comp(const void *i, const void *j)
{
	return *(int *)i - *(int *)j;
}
