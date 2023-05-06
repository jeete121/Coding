#include <stdio.h>
#include <limits.h>

int main()
{
    int matrix[][3] = {{1, 2, 3}, {5, 4, 3}, {2, 8, 9}};

    int n = 3;

    for (int i = 0; i < n; i++)
    {
        int maximum = INT_MIN;
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] > maximum)
            {
                maximum = matrix[i][j];
            }
        }
        printf("Maximum of %d row is %d\n", i, maximum);
    }
    return 0;
}