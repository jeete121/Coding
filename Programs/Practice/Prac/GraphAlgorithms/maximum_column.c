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
            if (matrix[j][i] > maximum)
            {
                maximum = matrix[j][i];
            }
        }
        printf("Maximum of %d column is %d\n", i, maximum);
    }

    return 0;
}