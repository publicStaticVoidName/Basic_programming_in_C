#include <stdio.h>

int main(void)
{
    int a, b;
    puts("Enter two integers to compare the firs with the second");

    scanf("%d %d", &a, &b);

    if (a > b)
    {
        puts("Above");
    }
    else if (b > a)
    {
        puts("Less");
    }
    else
    {
        puts("Equal");
    }

    return 0;
}
