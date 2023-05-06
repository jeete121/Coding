#include <stdio.h>
#include <limits.h>

int main()
{
    int matrix[][3] = {{1, 2, 3}, {5, 4, 3}, {2, 8, 9}};

    int n = 3;

    for (int i = 0; i < n; i++)
    {
        int minimum = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] < minimum)
            {
                minimum = matrix[i][j];
            }
        }
        printf("Minimum of %d row is %d\n", i, minimum);
    }
    return 0;
}