#include <stdio.h>
int main()
{
    int n, m;
    printf("Enter the dimension of the matrix: ");
    scanf("%d%d", &n, &m);

    int matrx[n][m];
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matrx[i][j]);
        }
    }

    printf("Matrix is: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", matrx[i][j]);
        }
        printf("\n");
    }
    return 0;
}