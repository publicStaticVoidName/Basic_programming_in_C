#include <stdio.h>

int main(void)
{
    int a, b;
    puts("Enter two integers to get them in non-decreasing order");

    scanf("%d %d", &a, &b);

    puts("Result:");
    if (a > b)
    {
        printf("%d %d\n", b, a);
    }
    else
    {
        printf("%d %d\n", a, b);
    }

    return 0;
}
