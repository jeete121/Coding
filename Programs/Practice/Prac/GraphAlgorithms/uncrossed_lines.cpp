#include <bits/stdc++.h>
using namespace std;

int maxUncrossedLines(vector<int> &A, vector<int> &B)
{
    int n = A.size(), m = B.size();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {

            //if any array is empty then
            //dp[i][j]=0
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            //if both are same then update result
            //1 more than the previous
            else if (A[i - 1] == B[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            //else max of both values
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int main()
{
    vector<int> A = {1, 4, 2};
    vector<int> B = {1, 2, 4};
    cout << maxUncrossedLines(A, B);
    return 0;
}