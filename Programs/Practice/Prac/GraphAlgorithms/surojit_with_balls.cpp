#include <bits/stdc++.h>
using namespace std;

long long maximumBalls(long long n, long long m,
                       long long arr[])
{
    long long res = -1, ans = 0;
    for (long long i = 0; i < n; i++)
    {
        if (arr[i] <= m)
        {
            ans += arr[i];
        }
        else
        {
            res = max(res, ans);
            ans = 0;
        }
    }
    res = max(res, ans);
    return res;
}
int main()
{
    long long n = 7, m = 2;

    long long arr[n] = {4, 2, 3, 5, 1, 1, 1};

    cout << maximumBalls(n, m, arr) << "\n";

    return 0;
}