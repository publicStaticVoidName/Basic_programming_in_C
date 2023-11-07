#include <stdio.h>

int main(void)
{
    int a, b, c;
    puts("Enter three integers to find out if there is a triangle with sides of this length");

    scanf("%d %d %d", &a, &b, &c);

    if (a > 0 && b > 0 && c > 0 && (a + b) > c && (a + c) > b && (b + c) > a)
    {
        puts("YES");
    }
    else
    {
        puts("NO");
    }

    return 0;
}
