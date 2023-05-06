#include <stdio.h>

void multiplyMatrices(int matrixA[][3], int matrixB[][3])
{
    int matrixC[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrixC[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                matrixC[i][j] = matrixC[i][j] + matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrixA[i][j] = matrixC[i][j];
        }
    }
}

int main()
{
    int matrixA[][3] = {{1, 3, 4}, {3, 2, 5}, {5, 3, 6}};
    int matrixB[][3] = {{3, 2, 4}, {5, 2, 4}, {1, 4, 2}};

    multiplyMatrices(matrixA, matrixB);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matrixA[i][j]);
        }
        printf("\n");
    }
    return 0;
}