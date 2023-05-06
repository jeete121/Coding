#include <stdio.h>

int main()
{
    int matrix[][4] = {{1, 2, 3, 6}, {0, 1, 2, 3}, {0, 0, 4, 2}, {0, 0, 0, 3}};

    int n = 4;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < i; j++)
        {
            if (matrix[i][j] != 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            ans = 1;
            break;
        }
    }
    if (ans == 0)
    {
        printf("Upper Triangular Matrix\n");
    }
    else
    {
        printf("Not a Upper Triangular Matrix\n");
    }
    return 0;
}