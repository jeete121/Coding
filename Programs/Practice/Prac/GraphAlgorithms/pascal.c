#include <stdio.h>
int main()
{
    int rows;
    int val;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    for (int i = 0; i < rows; i++)
    {
        //print the spaces
        for (int space = 1; space <= rows - i; space++)
        {
            printf("  ");
        }

        //print the values
        for (int j = 0; j <= i; j++)
        {
            //if first and last
            if (j == 0 || j == i)
            {
                val = 1;
            }
            else
            {
                val = val * (i - j + 1) / j;
            }

            printf("%4d ", val);
        }
        printf("\n");
    }
    return 0;
}
