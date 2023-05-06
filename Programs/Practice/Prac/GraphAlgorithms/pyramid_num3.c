#include <stdio.h>

int main()
{
    int n;
    int num;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    printf("Enter a number which is to be printed in pattern: ");
    scanf("%d", &num);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            printf(" ");
        }
        for (int j = n - 1 - i; j <= n - 1 + i; j++)
        {
            printf("%d", num);
        }
        printf("\n");
    }
    return 0;
}