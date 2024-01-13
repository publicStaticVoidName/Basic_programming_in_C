#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int ch;
	char *str = malloc(1), *temp_str;
	unsigned int len = 0;

	FILE *fin, *fout;
	fin = fopen("in.txt", "r");
	fout = fopen("out.txt", "w");

	while ((ch = getc(fin)) != EOF)
	{
		if (strchr(str, ch) == NULL && ch != ' ')
		{
			temp_str = realloc(str, ++len * sizeof(char));

			if (temp_str == NULL)
			{
				return -1;
			}

			str = temp_str;
			str[len - 1] = ch;

			putc(ch, fout);
		}
	}

	fclose(fin);
	fclose(fout);

	return 0;
}
