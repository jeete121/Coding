#include <stdio.h>

int main()
{
    int matrix[][4] = {{1, 2, 3, 5}, {4, 5, 6, 6}, {4, 6, 3, 2}};

    int n = 3, m = 4;

    int colSum[m];
    for (int i = 0; i < m; i++)
    {
        colSum[i] = 0;
    }
    int rowSum[n];
    for (int i = 0; i < n; i++)
    {
        rowSum[i] = 0;
    }

    //find sum of each rows
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum = sum + matrix[i][j];
        }
        rowSum[i] = sum;
    }

    //find sum of each columns
    for (int j = 0; j < m; j++)
    {

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = sum + matrix[i][j];
        }
        colSum[j] = sum;
    }

    printf("Row Sum is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", rowSum[i]);
    }
    printf("\n");
    printf("Column Sum is:\n");
    for (int i = 0; i < m; i++)
    {
        printf("%d ", colSum[i]);
    }
    return 0;
}