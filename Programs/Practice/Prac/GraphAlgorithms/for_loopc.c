#include <stdio.h>

int main()
{
    long int a = 8, b = 11, i;

    for (i = a; i <= b; i++)
    {
        if (i == 0)
        {
            printf("zero\n");
        }
        if (i == 1)
        {
            printf("one\n");
        }
        if (i == 2)
        {
            printf("two\n");
        }
        if (i == 3)
        {
            printf("three\n");
        }
        if (i == 4)
        {
            printf("four\n");
        }
        if (i == 5)
        {
            printf("five\n");
        }
        if (i == 6)
        {
            printf("six\n");
        }
        if (i == 7)
        {
            printf("seven\n");
        }
        if (i == 8)
        {
            printf("eight\n");
        }
        if (i == 9)
        {
            printf("nine\n");
        }
        if (i > 9 && (i & 1))
        {
            printf("odd\n");
        }
        if (i > 9 && !(i & 1))
        {
            printf("even\n");
        }
    }
    return 0;
}
