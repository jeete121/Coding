#include <stdio.h>

int main()
{
    int n;
    int num;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    printf("Enter a number which is to be printed in pattern: ");
    scanf("%d", &num);
    int space = 0;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < space; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= 2 * (n - i) - 1; j++)
        {
            printf("%d", num);
        }
        printf("\n");
        space++;
    }
    return 0;
}