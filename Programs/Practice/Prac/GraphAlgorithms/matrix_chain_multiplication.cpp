#include <bits/stdc++.h>
using namespace std;

int matrixMultiplication(vector<int> &array)
{
    int n = array.size();

    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 1; i < n; i++)
    {
        dp[i][i] = 0;
    }

    for (int len = 2; len < n; len++)
    {
        for (int i = 1; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {

                int q = dp[i][k] +
                        dp[k + 1][j] +
                        array[i - 1] * array[k] * array[j];
                if (q < dp[i][j])
                    dp[i][j] = q;
            }
        }
    }
    return dp[1][n - 1];
}

int main()
{
    vector<int> array = {1, 2, 4, 3};

    cout << matrixMultiplication(array);

    return 0;
}