#include <stdio.h>

int main()
{
    int matrixA[][3] = {{1, 2, 3}, {3, 4, 5}, {5, 6, 7}};
    int matrixB[][3] = {{3, 4, 2}, {4, 6, 2}, {3, 2, 5}};

    int n = 3, m = 3;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrixA[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    printf("Addition of matrices is\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", matrixA[i][j]);
        }
        printf("\n");
    }
    return 0;
}