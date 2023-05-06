#include <stdio.h>
int main()
{
    int matrixA[3][3] = {{1, 3, 4}, {3, 4, 5}, {6, 3, 2}};
    int matrixB[3][3] = {{3, 2, 1}, {5, 4, 7}, {7, 8, 9}};
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

    printf("Multiplication of matrices is:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }
    return 0;
}