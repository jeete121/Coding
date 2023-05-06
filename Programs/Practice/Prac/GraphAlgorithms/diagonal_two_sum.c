#include <stdio.h>
int main()
{
    int matrixA[3][3] = {{1, 3, 4}, {3, 4, 5}, {6, 3, 2}};
    int matrixB[3][3] = {{3, 2, 1}, {5, 4, 7}, {7, 8, 9}};
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                sum += matrixA[i][j];
                sum += matrixB[i][j];
            }
        }
    }

    printf("Sum of diagonal elements of two matrixes is %d", sum);
    return 0;
}