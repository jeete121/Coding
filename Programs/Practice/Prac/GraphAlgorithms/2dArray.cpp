#include <bits/stdc++.h>
using namespace std;

int hourglassSum(vector<vector<int>> arr)
{

    int l, o = 1, sum, max1 = INT_MIN;
    for (int i = 0; i <= 3; i++)
    {
        int l = 0, m = 1, n = 2, x = 1;
        for (int j = 0; j <= 3; j++)
        {
            sum = arr[i][l] + arr[i][m] + arr[i][n] +
                  arr[i + 2][l] + arr[i + 2][m] + arr[i + 2][n] + arr[o][x];
            max1 = max(sum, max1);
            l = l + 1;
            m = m + 1;
            n = n + 1;
            x = x + 1;
        }
        o++;
    }
    return max1;
}
int main()
{

    vector<vector<int>> arr = {{1, 1, 1, 0, 0, 0},
                               {0, 1, 0, 0, 0, 0},
                               {1, 1, 1, 0, 0, 0},
                               {0, 0, 2, 4, 4, 0},
                               {0, 0, 0, 2, 0, 0},
                               {0, 0, 1, 2, 4, 0}};
    cout << hourglassSum(arr);
    return 0;
}
