#include <stdio.h>

int main()
{
    int rows;
    int num;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter a number which is to be printed in pattern: ");
    scanf("%d", &num);

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= rows - i + 1; j++)
        {
            printf("%2d", num);
        }

        printf("\n");
    }
    return 0;
}