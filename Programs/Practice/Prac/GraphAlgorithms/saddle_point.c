#include <stdio.h>
#include <limits.h>

int main()
{
    int matrix[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int n = 3, m = 3;

    int rowMin[n];
    for (int i = 0; i < n; i++)
    {
        rowMin[i] = INT_MAX;
    }
    int colMax[m];
    for (int i = 0; i < m; i++)
    {
        colMax[i] = INT_MIN;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] < rowMin[i])
            {
                rowMin[i] = matrix[i][j];
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[j][i] > colMax[i])
            {
                colMax[i] = matrix[j][i];
            }
        }
    }
    int flag = 0;
    int saddle = -1;
    int x = -1, y = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == colMax[j] && matrix[i][j] == rowMin[i])
            {
                saddle = matrix[i][j];
                flag = 1;
                x = i;
                y = j;
               break;
            }
        }
    }
    if (flag == 0)
    {
        printf("No saddle point\n");
    }
    else
    {
        printf("Saddle point is (%d ,%d) with value %d", x, y, saddle);
    }

    return 0;
}