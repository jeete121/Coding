#include <stdio.h>

int main()
{
    int matrixA[][3] = {{1, 2, 3}, {3, 4, 5}, {5, 6, 7}};
    int matrixB[][3] = {{3, 4, 2}, {4, 6, 2}, {3, 2, 5}};

    int n = 3;

    int matrixC[3][3];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrixC[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                matrixC[i][j] = matrixC[i][j] + matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    printf("Multiplication of matrices is\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }
    return 0;
}