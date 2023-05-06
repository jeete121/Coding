#include <stdio.h>

int main()
{
    int matrix[][4] = {{1, 0, 0, 0}, {1, 3, 0, 0}, {3, 4, 7, 0}, {3, 2, 1, 3}};

    int n = 4;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = i + 1; j < n; j++)
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
        printf("Lower Triangular Matrix\n");
    }
    else
    {
        printf("Not a Lower Triangular Matrix\n");
    }
    return 0;
}