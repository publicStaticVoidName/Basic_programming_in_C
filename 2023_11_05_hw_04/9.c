#include <stdio.h>

int main(void)
{
    int a, b, c;
    puts("Enter three integers and check if these numbers from an increasing sequence");

    scanf("%d %d %d", &a, &b, &c);

    if (a < b && b < c)
    {
        puts("YES");
    }
    else
    {
        puts("NO");
    }

    return 0;
}
