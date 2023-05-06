#include <bits/stdc++.h>
using namespace std;

bool dp[100001];
void primeInitialize()
{

    memset(dp, true, sizeof(dp));
    dp[0] = false;
    dp[1] = false;
    for (int i = 2; i * i <= 100000; i++)
    {
        if (dp[i])
        {
            for (int j = i * i; j <= 100000; j += i)
                dp[j] = false;
        }
    }
}
int main()
{

    primeInitialize();
    int sum[100001];
    sum[0] = 0;
    sum[1] = 0;
    int cnt = 0;
    for (int i = 2; i <= 100000; i++)
    {
        if (dp[i] == 1)
            cnt++;
        if (dp[cnt] == 1)
            sum[i] = 1;
        else
            sum[i] = 0;
    }

    for (int i = 1; i <= 100000; i++)
        sum[i] += sum[i - 1];

    int l = 3, r = 10;

    int res = sum[r] - sum[l - 1];
    cout << res << "\n";
}