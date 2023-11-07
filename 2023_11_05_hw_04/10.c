#include <stdio.h>

int main(void)
{
    int a;
    puts("Enter the month number to find out the time of year");

    scanf("%d", &a);

    switch (a)
    {
        case 1:
        case 2:
        case 12: puts("winter"); break;
        case 3:
        case 4:
        case 5: puts("spring"); break;
        case 6:
        case 7:
        case 8: puts("summer"); break;
        case 9:
        case 10:
        case 11: puts("autumn"); break;
        default:
            puts("Incorrect input.");
            break;
    }

    return 0;
}
