#include <stdio.h>

int main()
{
    int n = 3;
    int matrix[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int sum = 0;
    for (int i = 0; i < n; i++)
    {

        //sum of first row and last row
        if (i == 0 || i == n - 1)
        {
            for (int j = 0; j < n; j++)
            {
                sum = sum + matrix[i][j];
            }
        }
        else
        {
            //first element
            sum = sum + matrix[i][0];

            //last element
            sum = sum + matrix[i][n - 1];
        }
    }

    printf("Sum of boundary elements is %d", sum);
    return 0;
}