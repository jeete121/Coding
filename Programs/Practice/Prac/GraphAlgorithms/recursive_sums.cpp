#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long recursiveSum(long long m,
                       vector<vector<long long>> &arr)
{
    long long ans = 0;
    long long x = 0;
    for (long long i = 0; i < m; i++)
    {
        long long len = arr[i][0], d = arr[i][1];

        ans = len * d;
        while (ans)
        {
            x += ans % 10;
            ans = ans / 10;
        }
    }
    ans = x;
    while (ans >= 10)
    {
        long long res = 0;
        while (ans)
        {
            res += ans % 10;
            ans = ans / 10;
        }
        ans = res;
    }
    return ans;
}
int main()
{

    long long m = 3;

    vector<vector<long long>> arr = {{2, 1}, {1, 2}, {2, 9}};

    cout << recursiveSum(m, arr) << "\n";

    return 0;
}