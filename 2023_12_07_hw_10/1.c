#include <stdio.h>
#include <string.h>

int main(void)
{
	char ch, alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
	char *index;
	int arr[26] = {0};

	FILE *f;
	f = fopen("in.txt", "r");

	if (f == NULL)
	{
		return 1;
	}

	while ( (ch = getc(f)) != ' ')
	{
		index = strchr(alphabet, ch);
		*(arr + (index - alphabet) ) +=  1;
	}

	for (unsigned int i = 0; i < 26; i++)
	{
		if (*(arr + i) == 0)
		{
			*(arr + i) = 2;
		}
	}

	while ( (ch = getc(f)) != EOF && ch != '\n')
	{
		index = strchr(alphabet, ch);
		if (*(arr + (index - alphabet) ) < 2)
		{
			*(arr + (index - alphabet)) -= 1;
		}
	}
	fclose(f);

	f = fopen("out.txt", "w");

	if (f == NULL)
	{
		return 2;
	}

	for (unsigned int i = 0; i < 26; i++)
	{
		if (*(arr + i) == 0)
		{
			fprintf(f, "%c ", alphabet[i]);
		}
	}
	fclose(f);

	return 0;
}
