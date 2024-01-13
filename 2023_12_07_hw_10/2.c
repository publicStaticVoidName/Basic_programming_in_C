#include <stdio.h>

int main(void)
{
	int ch;

	FILE *fin, *fout;
	fin = fopen("in.txt", "r");
	fout = fopen("out.txt", "w");

	if (fin == NULL || fout == NULL)
	{
		return 1;
	}

	while ((ch = getc(fin)) != EOF)
	{
		switch (ch)
		{
			case 'a':
				ch = 'b';
				break;
			case 'b':
				ch = 'a';
				break;
			case 'A':
				ch = 'B';
				break;
			case 'B':
				ch = 'A';
				break;
			default:
				break;
		}

		putc(ch, fout);
	}

	return 0;
}
