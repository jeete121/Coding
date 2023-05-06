#include <bits/stdc++.h>
using namespace std;

void bubble_sort(long int a[], long int n)
{
    int round, j, temp;
    for (round = 1; round <= n - 1; round++)
    {
        for (j = 0; j <= n - 1 - round; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    long int n = 8, t = 5, x, i, j, k, y;
    long int a[n] = {2, 3, 1, 2, 3, 2, 3, 3};
    vector<vector<int>> cases = {{0, 3}, {4, 6}, {6, 7}, {3, 5}, {0, 7}};
    long int c[n];
    for (x = 0; x < n; x++)
    {
        c[x] = 0;
    }
    for (x = 0; x < t; x++)
    {
        i = cases[x][0];
        j = cases[x][1];
        k = 0;
        for (y = i; y <= j; y++)
        {
            c[k] = a[y];
            k++;
        }
        bubble_sort(c, k);
        cout << c[0] << endl;
    }
    return 0;
}
