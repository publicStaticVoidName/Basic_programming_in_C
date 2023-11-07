#include <stdio.h>

int main(void)
{
    int x1, y1, x2, y2;
    double k, b;
    puts("Enter the coordinates of two points to get k and b in the equation y(x) = k*x + b");

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    k = (double) (y1 - y2) / (x1 - x2);
    b = (double) (y1 * x2 - y2 * x1) / (x2 - x1);

    puts("k and b:")
    printf("%.2f %.2f\n", k, b);

    return 0;
}
