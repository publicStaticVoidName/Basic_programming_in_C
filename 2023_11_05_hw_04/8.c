#include <stdio.h>

int main(void)
{
    int a, b, c, d, e, min;
    puts("Enter five integers to get the smallest one");

    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    min = a < b ? a : b;
    min = min < c ? min : c;
    min = min < d ? min : d;
    min = min < e ? min : e;

    printf("%d\n", min);

    return 0;
}
