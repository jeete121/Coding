#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    int space = 0;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < space; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= 2 * (n - i) - 1; j++)
        {
            printf("*");
        }
        printf("\n");
        space++;
    }
    return 0;
}