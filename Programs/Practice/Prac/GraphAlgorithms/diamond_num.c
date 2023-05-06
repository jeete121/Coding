#include <stdio.h>

int main()
{
    int n, num;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    printf("Enter a number which want to print in pattern: ");
    scanf("%d", &num);
    int spaceCount = n - 1;

    for (int i = 1; i <= n; i++)
    {

        //print number of spaces
        for (int j = 1; j <= spaceCount; j++)
        {
            printf(" ");
        }

        //print the *
        for (int j = 1; j < 2 * i; j++)
        {
            printf("%d", num);
        }

        //print new line
        printf("\n");

        //decrement the count
        spaceCount--;
    }
    spaceCount = 1;

    for (int i = 1; i <= n - 1; i++)
    {

        //print spaces
        for (int j = 1; j <= spaceCount; j++)
        {
            printf(" ");
        }

        //print *
        for (int j = 1; j < 2 * (n - i); j++)
        {
            printf("%d", num);
        }

        printf("\n");
        spaceCount++;
    }

    return 0;
}