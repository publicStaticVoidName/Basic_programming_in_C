#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int var, a, b, c;
    puts("Enter a three-digits integer to get the largest digit");

    scanf("%d", &var);

    a = abs(var) % 10;
    b = abs(var) % 100 / 10;
    c = abs(var) / 100;

    puts("The largest digit:");
    if (a >= b)
    {
        printf("%d\n", (a >= c ? a : c));
    }
    else
    {
        printf("%d\n", (b >= c ? b : c));
    }

    return 0;
}
