#include <stdio.h>

int main(void)
{
    int a, b, c;
    puts("Enter three integers to get the largest one");

    scanf("%d %d %d", &a, &b, &c);

    puts("The largest integer:");
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
