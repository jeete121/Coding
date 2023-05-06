#include <bits/stdc++.h>
using namespace std;

int largestSquare(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    int m = matrix[0].size();

    int res = 0;
    int dp[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = matrix[i][j];
            if (i > 0 && j > 0 && matrix[i][j] == 1)
            {
                dp[i][j] = 1 + min(dp[i - 1][j],
                                   min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
            if (dp[i][j] > res)
                res = dp[i][j];
        }
    }
    return res;
}
int main()

{
    vector<vector<int>> matrix = {{1, 1, 1, 0, 0},
                                  {0, 1, 1, 1, 1},
                                  {1, 0, 1, 1, 1},
                                  {1, 1, 1, 1, 1}};

    cout << largestSquare(matrix);

    return 0;
}