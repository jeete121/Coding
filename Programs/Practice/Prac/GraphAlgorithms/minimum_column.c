#include <stdio.h>
#include <limits.h>

int main()
{
    int matrix[][3] = {{5, 2, 8}, {4, 4, 9}, {6, 8, 3}};

    int n = 3;

    for (int i = 0; i < n; i++)
    {
        int minimum = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (matrix[j][i] < minimum)
            {
                minimum = matrix[j][i];
            }
        }
        printf("Minimum of %d column is %d\n", i, minimum);
    }

    return 0;
}