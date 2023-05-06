#include <stdio.h>

int main()

{
    int n = 5;
    printf("Numbers till %d are:\n", n);

    int i = 0;
    while (i <= n)
    {
        printf("%d ", i);
        i++;
    }

    return 0;
}