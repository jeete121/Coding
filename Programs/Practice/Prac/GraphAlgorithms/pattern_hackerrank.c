#include <stdio.h>

int main()
{

    int n = 4;
    int p = n;
    n = 2 * n - 1;
    int x = n;
    int arr[101][101];
    int i, k = 0, l = 0;
    int m = n;
    while (k < m && l < n)
    {
        for (i = l; i < n; i++)
        {
            arr[k][i] = p;
        }
        k++;
        for (i = k; i < m; i++)
        {
            arr[i][n - 1] = p;
        }
        n--;
        if (k < m)
        {
            for (i = n - 1; i >= l; i--)
            {
                arr[m - 1][i] = p;
            }
            m--;
        }
        if (l < n)
        {
            for (i = m - 1; i >= k; i--)
            {
                arr[i][l] = p;
            }
            l++;
        }
        p--;
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
