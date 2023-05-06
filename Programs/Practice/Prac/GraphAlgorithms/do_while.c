#include <stdio.h>

int main()
{
    int n = 5;
    printf("Numbers tiil %d are\n", n);
    int i = 0;
    do
    {
        printf("%d ", i);
        i++;
    } while (i <= n);

    return 0;
}