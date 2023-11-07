#include <stdio.h>

int main(void)
{
    int a, b, c, d, e, max, min;
    puts("Enter five integers to get the sum of the maximum and minimum of them");

    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    max = a > b ? a : b;
    min = a < b ? a : b;

    max = max > c ? max : c;
    min = min < c ? min : c;

    max = max > d ? max : d;
    min = min < d ? min : d;

    max = max > e ? max : e;
    min = min < e ? min : e;

    puts("The sum of maximum and minimum entered integers:");
    printf("%d\n", max + min);

    return 0;
}
