#include <bits/stdc++.h>
using namespace std;

void mindPlaces(int n, int m,
                vector<vector<int>> &arr, int x)
{

    int a1 = -1, a2 = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == x)
            {
                a1 = i;
                a2 = j;
                break;
            }
        }
    }
    cout << a1 << " " << a2 << "\n";
}
int main()
{
    int n = 5, m = 5;

    vector<vector<int>> arr = {{-10, -5, -3, 4, 9},
                               {-6, -2, 0, 5, 10},
                               {-4, -1, 1, 6, 12},
                               {2, 3, 7, 8, 13},
                               {100, 120, 130, 140, 150}};

    int x = 0;
    mindPlaces(n, m, arr, x);

    return 0;
}